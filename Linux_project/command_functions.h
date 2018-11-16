void ls_command(char *state) 
{ 
	if(strcmp(state, "simple")==0) {
		// directory
		DIR *dirp; 
		struct dirent *dentry; 

	    	char *file_name;	// file name
		mode_t file_mode;	// file mode
	
		char *buf;		// time buffer
	    	struct stat file_info; 		// stat struct
		struct passwd *my_user;		// userID info struct

		int return_stat;
		int i=0;

		// current directory open
		if((dirp = opendir(".")) == NULL) {
			exit(1);
		} 
	
		printf("<< Output Order : file_name, userID >>\n");
		printf("----------------------------------------------------------------------------------------\n");

		// read directory component
		while(dentry = readdir(dirp)) {

			// if fail, show error message
			if ((return_stat = stat(dentry->d_name, &file_info)) == -1) {
				perror("Error : ");
				exit(0);
	    		}

			file_mode = file_info.st_mode;		// file mode
			my_user = getpwuid(file_info.st_uid);	// user name
		    	i++;

			// file name
			if(dentry->d_ino != 0) {
				printf("%s", dentry->d_name);

				if(S_ISDIR(file_mode)) {
					printf("/\t");
				}
				else {
					printf("\t");
				}

				if(i==7) {
					printf("\n");
					i=0;
				}
			}
		} 

		printf("USER=%s\t\n", my_user->pw_name); 	// user name

		closedir(dirp);
	}
	else if(strcmp(state, "spec")==0) {
		// directory
		DIR *dirp; 
		struct dirent *dentry; 

	    	char *file_name;	// file name
		mode_t file_mode;	// file mode
	
		char *buf;		// time buffer
	    	struct stat file_info; 		// stat struct
		struct passwd *my_user;		// userID info struct
	    	struct group  *my_group;	// groupID info struct

		int return_stat;
		int total=0;		// total number of blocks

		// current directory open
		if((dirp = opendir(".")) == NULL) {
			exit(1);
		} 
	
		printf("<< Output Order : type, mode, hardlink, userID, groupID, size, file_name, last_access_date >>\n");
		printf("--------------------------------------------------------------------------------------------\n");

		// read directory component
		while(dentry = readdir(dirp)) {

			// if fail, show error message
			if ((return_stat = stat(dentry->d_name, &file_info)) == -1) {
				perror("Error : ");
				exit(0);
	    		}

			// file mode information
			file_mode = file_info.st_mode;
			showRWX(file_mode);	// file mode info show number value -> string value
	
			// hard link
			printf("%d\t", file_info.st_nlink);
	
			// userID and groupID information
			my_user = getpwuid(file_info.st_uid);	// getpwuid : st_uid(number value) -> user name
		    	my_group = getgrgid(file_info.st_gid);	// getgrgid : st_gid(number value) -> group name
			printf("%s\t", my_user->pw_name); 	// user
			printf("%s\t", my_group->gr_name); 	// group
	
			// file size
			printf("%d\t", file_info.st_size);

			// file name
			if(dentry->d_ino != 0) {
				printf("%20s\t", dentry->d_name);

				// total number of blocks
				if(strcmp(dentry->d_name, ".") == 0 || strcmp(dentry->d_name, "..") == 0) {
					total += 0;
				}
				else {
					total += file_info.st_blocks/2;
				}
			}

			// last access time information
			buf = ctime(&(file_info.st_atime)); // localtime : express time function
			printf("%s", buf);             // time info -> string
		} 

		printf("Total number of bloks : %d\n", total);

		closedir(dirp);
	} 
}

void showRWX(file_mode){

	// Is it directory or normal file or link file ?? - type info
	if (S_ISDIR(file_mode))  printf("d");  		// directory
	else if(S_ISLNK(file_mode))  printf("l");	// link file
	else  printf("-");				// normal file

	printf("  ");
		
	// rwx print
	if (file_mode & S_IRUSR)  printf("r");
	else  printf("-");
		
	if (file_mode & S_IWUSR)  printf("w");	
	else  printf("-");
		
	if (file_mode & S_IXUSR)  printf("x");	
	else  printf("-"); 
		
	if (file_mode & S_IRGRP)  printf("r");
	else  printf("-");
		
	if (file_mode & S_IWGRP)  printf("w");	
	else  printf("-");
		
	if(file_mode & S_IXGRP)  printf("x");
	else  printf("-"); 
		
	if (file_mode & S_IROTH)  printf("r");
	else  printf("-");
		
	if (file_mode & S_IWOTH)  printf("w");
	else  printf("-");
		
	if(file_mode & S_IXOTH)  printf("x");
	else  printf("-");

	printf("    ");
}

void cp_command(char *copy, char *copied)
{
    char block[BUFSIZ];
    int fdin, fdout;
    int nread;

    fdin = open(copy, O_RDONLY); // original file
    fdout = open(copied, O_WRONLY | O_CREAT | O_TRUNC, 0644); // new file

    nread = read(fdin, block, sizeof(block)); // read

    write(fdout, block, nread);  //write

    printf("Copy Complete\n");

    close(fdin);
    close(fdout);
}

void pwd_command() {
	char cwd[1024];

	if(getcwd(cwd, sizeof(cwd)) != NULL) {
		printf("Current working directory : %s\n", cwd);
	}
}

void cat_command(char *command, char *parameta1, char *parameta2) {
	int fdin, fdout;
	ssize_t nread;
	char buffer[1024]="";

	if(strcmp(command, "fread")==0) {
		fdin = open(parameta1, O_RDONLY);
		
		if(fdin > 0) {
			read(fdin, buffer, sizeof(buffer));
			printf("----file contents----\n");
			puts(buffer);		 
			fclose(fdin);
		}
	}
	else if(strcmp(command, "fcreate")==0) {
		if(strcmp(parameta1, ">")==0) {
			fdout = open(parameta2, O_WRONLY | O_CREAT | O_APPEND, 0644);

			printf("Input file contents : ");
			gets(buffer);

			write(fdout, buffer, strlen(buffer));
			fclose(fdout);
		}
		else if(strcmp(parameta1, ">>")==0) {
			fdout = open(parameta2, O_WRONLY | O_CREAT | O_TRUNC, 0644);

			printf("** The existing contents will be deleted. **\n");
			printf("Input file contents : ");
			gets(buffer);

			write(fdout, buffer, strlen(buffer));
			fclose(fdout);
		}
	}
}

void mkdir_command(char *directory_name) {
	struct stat st = {0};

	if(stat(directory_name, &st) == -1) {
		mkdir(directory_name, 0644);
		printf("Complete to make directory\n");
	}
}

void rm_command(char *file_name) {
	remove(file_name);
	printf("Complete to delete file\n");
}

void rmdir_command(char *directory_name) {
	struct stat st = {0};

	if(stat(directory_name, &st) == 0) {
		rmdir(directory_name);
		printf("Complete to delete directory\n");
	}
}

void drename_command(char *current_name, char *new_name) {
	rename(current_name, new_name);
	printf("Complete to rename\n");
}

void cd_command(char *path) {
	char cwd[1024], result[1024];
	int state=0, state2=0;
	char *ptr, *ptr2;

	// find '/' letter
	ptr = strchr(path, '/');			
	while(ptr != NULL) {
		state++;
		ptr = strchr(ptr+1, '/');
	}

	ptr2 = strtok(path, ".");			
	while(ptr2 != NULL) {
		state2++;
		ptr2 = strtok(NULL, ".");
	}
	
	// default path = /home
	if(strcmp(path, "default")==0) {
		strcpy(result, "/home");
	}
	//absolute path
	else if(state > 0) {
		strcpy(result, path);
	}
	// relative path
	else if(state2 > 0) {
		getcwd(cwd, sizeof(cwd));
		strcat(cwd, ptr2);
		strcpy(result, cwd);
	}
	// relative path
	else if(strcmp(path, "..")==0) {
		strcpy(result, "..");
	}

	// result path
	if(chdir(result) == -1) {
		printf("There is no such path...\n");
	}
	
	getcwd(result, sizeof(result));
	printf("Result path : %s\n", result);
}

void mv_command(char *file_name, char *path) {
	char *create_file = path;
	char block[BUFSIZ];
    	int fdin, fdout;
    	int nread;

	// make new file string
    	strcat(create_file, "/");
	strcat(create_file, file_name);
	
	fdin = open(file_name, O_RDONLY); // original file
    	fdout = open(create_file, O_WRONLY | O_CREAT | O_TRUNC, 0644); // new file

	// copy file
    	nread = read(fdin, block, sizeof(block)); // read
    	write(fdout, block, nread);  //write

	close(fdin);
    	close(fdout);

	// delate original file
	remove(file_name);
	printf("Complete to move file\n");
}

void chmod_command(char *file_name, char *mode) {
	mode_t result_mode = strtol("0000", 0, 8);
	mode_t number_mode = strtol(mode, 0, 8);

	// find '|' letter then separate
	char *ptr = strtok(mode, "|");
	
	while(ptr != NULL) {
		if(strcmp(ptr, "S_IRUSR")==0) {
			result_mode |= strtol("0400", 0, 8);
			chmod(file_name, result_mode);
		}
		else if(strcmp(ptr, "S_IWUSR")==0) {
			result_mode |= strtol("0200", 0, 8);
			chmod(file_name, result_mode);
		}
		else if(strcmp(ptr, "S_IXUSR")==0) {
			result_mode |= strtol("0100", 0, 8);
			chmod(file_name, result_mode);
		}
		else if(strcmp(ptr, "S_IRGRP")==0) {
			result_mode |= strtol("0040", 0, 8);
			chmod(file_name, result_mode);
		}
		else if(strcmp(ptr, "S_IWGRP")==0) {
			result_mode |= strtol("0020", 0, 8);
			chmod(file_name, result_mode);
		}
		else if(strcmp(ptr, "S_IXGRP")==0) {
			result_mode |= strtol("0010", 0, 8);
			chmod(file_name, result_mode);
		}
		else if(strcmp(ptr, "S_IROTH")==0) {
			result_mode |= strtol("0004", 0, 8);
			chmod(file_name, result_mode);
		}
		else if(strcmp(ptr, "S_IWOTH")==0) {
			result_mode |= strtol("0002", 0, 8);
			chmod(file_name, result_mode);
		}
		else if(strcmp(ptr, "S_IXOTH")==0) {
			result_mode |= strtol("0001", 0, 8);
			chmod(file_name, result_mode);
		}
		else chmod(file_name, number_mode);

		ptr = strtok(NULL, "|");
	}
	printf("Complete to change file mode\n");
}

void date_command() {
	time_t timer = time(NULL);
	struct tm *t;
	char month[10];
	char day[10];

	t = localtime(&timer);

	// month
	if(t->tm_mon == 0) strcpy(month, "Jan");
	else if(t->tm_mon == 1) strcpy(month, "Feb");
	else if(t->tm_mon == 2) strcpy(month, "Mar");
	else if(t->tm_mon == 3) strcpy(month, "Apr");
	else if(t->tm_mon == 4) strcpy(month, "May");
	else if(t->tm_mon == 5) strcpy(month, "Jun");
	else if(t->tm_mon == 6) strcpy(month, "Jul");
	else if(t->tm_mon == 7) strcpy(month, "Aug");
	else if(t->tm_mon == 8) strcpy(month, "Sep");
	else if(t->tm_mon == 9) strcpy(month, "Oct");
	else if(t->tm_mon == 10) strcpy(month, "Nov");
	else if(t->tm_mon == 11) strcpy(month, "Dec");
	
	// week day
	if(t->tm_wday == 0) strcpy(day, "Sun");
	else if(t->tm_wday == 1) strcpy(day, "Mon");
	else if(t->tm_wday == 2) strcpy(day, "Tue");
	else if(t->tm_wday == 3) strcpy(day, "Wed");
	else if(t->tm_wday == 4) strcpy(day, "Thu");
	else if(t->tm_wday == 5) strcpy(day, "Fri");
	else if(t->tm_wday == 6) strcpy(day, "Sat");

	printf("Current time/date : ");
	printf("%d-%s-%d(%s) :: %d:%d:%d\n",t->tm_year+1900, month, t->tm_mday, day, t->tm_hour, t->tm_min, t->tm_sec);
}

void manual() {
	printf("\n<< Myshell Manual >>\n\n");
	printf("[command] : <flist> <option>\n");
	printf("\t=> printf file list. This command is same to 'ls' \n\n");
	printf("\t=> option = 'simple' : ls command.  option = 'spec' : ls -l command. \n\n");
	printf("[command] : <copy> <file name you want to copy> <copied file name>\n");
	printf("\t=> copy file. This command is same to 'cp' \n\n");
	printf("[command] : <dcurrent>\n");
	printf("\t=> show current path. This command is same to 'pwd' \n\n");
	printf("[command] : <fread> <file name>\n");
	printf("\t=> read the file. This command is same to 'cat'\n\n");
	printf("[command] : <fcreate> < '>' OR '>>' > <file name>\n");
	printf("\t=> '>' paste existing content. This command is same to 'cat >' \n");
	printf("\t=> '>>' delete existing content and create new one. This command is same to 'cat >>'\n\n");
	printf("[command] : <dcreate> <directory name>\n");
	printf("\t=> create directory. This command is same to 'mkdir' \n\n");
	printf("[command] : <fremove> <file name>\n");
	printf("\t=> remove file. This command is same to 'rm' \n\n");
	printf("[command] : <dremove> <directory name>\n");
	printf("\t=> remove directory. This command is same to 'rmdir' \n\n");
	printf("[command] : <drename> <directory name> <new directory name>\n");
	printf("\t=> rename the directory. This command is same to 'rename'\n\n");
	printf("[command] : <frename> <file name> <new file name>\n");
	printf("\t=> rename the file name. This command is same to 'rename'\n\n");
	printf("[command] : <dmove> <path>\n");
	printf("\t=> move directory. This command is same to 'cd'\n\n");
	printf("[command] : <fmove> <file name> <path>\n");
	printf("\t=> move file to different directory. This command is same to 'mv'\n\n");
	printf("[command] : <date>\n");
	printf("\t=> show current date\n\n");
	printf("[command] : <cmod> <file name> <new mode>\n");
	printf("\t=> change file's mode \n\n");
	printf("[command] : <process>\n");
	printf("\t=> show process list\n\n");
	printf("[command] : <pchatt>\n");
	printf("\t=> discussion program using unnamed pipe\n\n");
	printf("[command] : <pexit>\n");
	printf("\t=> exit the Myshell program\n\n");
}

int state = 0;
int state1 = 0;

void pchatt()
{
    int p1[2], p2[2];
    pid_t parent_pid = getpid();
    char msg1[100], msg2[100], voice[50];
    pid_t pid1, pid2;
    fd_set initset, newset;

    static struct sigaction act1;
    void handle1();
    act1.sa_handler = handle1;
    sigfillset(&(act1.sa_mask));
    sigaction(SIGUSR1, &act1, NULL);

    pid1 = pid2 = 0;
    
    if(pipe(p1) == -1) printf("fail to call pipe() #1\n");
    if(pipe(p2) == -1) printf("fail to call pipe() #2\n");

    if((pid1 = fork()) == -1) printf("fail to call fork() #1\n");

    if(pid1>0) {
    	if((pid2 = fork()) == -1) printf("fail to call fork() #2\n");
    }
    
    while(1) {
    	if(pid1 > 0 && pid2 > 0) {
		strcpy(msg1, "");
		strcpy(msg2, "");

		printf("\n[server]: Let's start discussion!!\n");
		printf("[server]: Get a voice => ");
		gets(voice);
		if(strcmp(voice, "client1")==0) {
			strcpy(voice, "");
			kill(pid1, SIGUSR1);
		}
		else if(strcmp(voice, "client2")==0) {
			strcpy(voice, "");
			kill(pid2, SIGUSR1);
		}
		else {
			printf("[server] Oh... error! Just start [client1]\n");
			strcpy(voice, "");
			kill(pid1, SIGUSR1);
		}

		close(p1[1]); 
		close(p1[1]);

		FD_ZERO(&initset);
		FD_SET(p1[0], &initset);
		FD_SET(p2[0], &initset);

		newset = initset;
		while(select(p2[0] + 1, &newset, NULL, NULL, NULL) > 0) {
			if(FD_ISSET(p1[0], &newset))
				if(read(p1[0], msg1, 100) > 0) {
				    printf("[client1] : %s\n", msg1);

				    if(strcmp(msg1, "Turn change") == 0) {
				    	break;
				    }
				}

			if(FD_ISSET(p2[0], &newset))
				if(read(p2[0], msg2, 100) > 0) {
				    printf("[client2] : %s\n", msg2);

				    if(strcmp(msg2, "Turn change") == 0) {
				    	break;
				    }
				}

			newset = initset;
		}
    	}
    	else if(pid1 == 0 && pid2 == 0) {	
			close(p1[0]); 
			close(p2[0]); 
			close(p2[1]);

			pause();
			printf("\n[client1] : ");
			gets(msg1);
			    
			if(strcmp(msg1, "bye")==0) {
				printf("[client1] : Disconnect...\n");
				printf("\n[server] : Discussion Stopped...\n");
				kill(parent_pid, SIGKILL);
				kill(getppid()+2, SIGKILL);
				kill(getpid(), SIGKILL);
			}
			else {
				write(p1[1], msg1, 100);
				if(strcmp(msg1, "Turn change")!=0) {
					kill(getppid()+2, SIGUSR1);
				}
			}

    	}
    	else if(pid1 > 0 && pid2 == 0) {
			close(p1[0]); 
			close(p1[1]); 
			close(p2[0]);

			pause();
			printf("\n[client2] : ");
			gets(msg2);
			       
			if(strcmp(msg2, "bye")==0) {
				printf("[client2] : Disconnect...\n");
				printf("\n[server] : Discussion Stopped...\n");
				kill(parent_pid, SIGKILL);
				kill(pid1, SIGKILL);
				kill(pid2, SIGKILL);
			}
			else {
				write(p2[1], msg2, 100);
				if(strcmp(msg2, "Turn change") != 0) {
					kill(pid1, SIGUSR1);
				}
			}
    	}
    }
}

void handle1() {
}


