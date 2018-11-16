#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h> 
#include <sys/stat.h>
#include <pwd.h>
#include <dirent.h> 
#include <grp.h>
#include <time.h>
#include <fcntl.h>
#include <signal.h>
#include "command_functions.h"

int main() {
	pid_t original, my_parent_pid, original_child, my_pid;
	pid_t back_process;
	int i=0, bstate=0, back_state=0;
	char command[20];
	char *command_array[20];

	original = getpid(); // original pid (parent)
	my_parent_pid = getppid(); // original's parent

	while(1) {

		bstate = 0;

		// input command
		printf("## ");
		gets(command);

		// find '&' letter
		char *bptr = strchr(command, '&');			
		while(bptr != NULL) {
			bstate++;
			bptr = strchr(bptr+1, '&');
		}

		i=0;
		char * ptr = strtok(command, " ");  // divide string by ""
		while(ptr != NULL) {
			command_array[i] = ptr;
			i++;
			ptr = strtok(NULL, " ");		
		}

		original_child = fork();  // create child process

		// child process
		if(original_child == 0) {
			my_pid = getpid();  // child pid
			my_parent_pid = getppid();  // original pid

			if(strcmp(command_array[0], "flist")==0) {
				ls_command(command_array[1]);
						// if command_array = "spec" => show file list specipically
						// else if command_array = "simple" => show just file list
			}
			else if(strcmp(command_array[0], "copy")==0) {
				cp_command(command_array[1], command_array[2]);
						// file copy
			}
			else if(strcmp(command_array[0], "dcurrent")==0) {
				pwd_command();  // show current directory path 
			}
			else if(strcmp(command_array[0], "fread")==0 || strcmp(command_array[0], "fcreate")==0) {
				cat_command(command_array[0], command_array[1], command_array[2]); 
						// fread = cat file
					        // fcreate = cat > file OR cat >> file
			}
			else if(strcmp(command_array[0], "dcreate")==0) {
				mkdir_command(command_array[1]);
						// make directory, input path OR directory name
			}
			else if(strcmp(command_array[0], "fremove")==0) {
				rm_command(command_array[1]);
						// remove file, input path OR directory name
			}
			else if(strcmp(command_array[0], "dremove")==0) {
				rmdir_command(command_array[1]);
						// remove directory, input path OR directory name
			}
			else if(strcmp(command_array[0], "drename")==0 || strcmp(command_array[0], "frename")==0) {
				drename_command(command_array[1], command_array[2]);
						// file OR directory rename 
			}
			else if(strcmp(command_array[0], "dmove")==0) {
				cd_command(command_array[1]);
						// move directory (path : absolute/relative)
			}
			else if(strcmp(command_array[0], "fmove")==0) {
				mv_command(command_array[1], command_array[2]);
						// file move
			}
			else if(strcmp(command_array[0], "date")==0) {
				date_command();  
						// print current time
			}
			else if(strcmp(command_array[0], "sdate")==0) {
				execl("/bin/date", "date", 0, 0);
      				perror("execl() failure!\n\n");
						// print current time - using exec
			}
			else if(strcmp(command_array[0], "cmod")==0) {
				chmod_command(command_array[1], command_array[2]);
						// change file mode (mode type = number, string)
			}
			else if(strcmp(command_array[0], "pchatt")==0) {
				pchatt();
			}
			else if(strcmp(command_array[0], "process")==0) {
				system("ps");
			}
			else if(strcmp(command_array[0], "manual")==0) {
				manual();
						// show manual
			}
			else if(strcmp(command_array[0], "pexit")==0) {
				printf("Exit Shell Program\n");
				kill(my_parent_pid, SIGKILL);
				kill(my_pid, SIGKILL);
			}
			else if(strcmp(command_array[0], "")==0) {
				// do nothing, just new line
			}
			else {
				printf("There is no such command\n");
				printf("check the manual... ** [command] manual **\n");
			}

			exit(1);
		}
		// parent process
		else if(original_child > 0) {
			my_pid = getpid();

			// background process
			if(bstate > 0) {
				back_state++;
				printf("** [%d] background mode... **\n", original_child);
				back_process = original_child;
			}
			else {
				wait(0);
			}
		}
		// fail
		else {
			printf("fail to fork\n");
		}
	}
}
