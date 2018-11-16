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

int state = 0;
int state1 = 0;

void main()
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
    sigaction(SIGINT, &act1, NULL);

    pid1 = pid2 = 0;
    
    if(pipe(p1) == -1) printf("fail to call pipe() #1\n");
    if(pipe(p2) == -1) printf("fail to call pipe() #2\n");

    if((pid1 = fork()) == -1) printf("fail to call fork() #1\n");
    if((pid2 = fork()) == -1) printf("fail to call fork() #2\n");
    
    while(1) {
    	if(pid1 > 0 && pid2 > 0) {
		strcpy(msg1, "");
		strcpy(msg2, "");

		printf("\n[server]: Let's start discussion!!\n");
		printf("[server]: Get a voice => ");
		gets(voice);
		if(strcmp(voice, "client1")==0) {
			strcpy(voice, "");
			kill(pid1, SIGINT);
		}
		else if(strcmp(voice, "client2")==0) {
			strcpy(voice, "");
			kill(pid2, SIGINT);
		}
		else {
			printf("[server] Oh... error! Just start [client1]\n");
			strcpy(voice, "");
			kill(pid1, SIGINT);
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
				}

			if(FD_ISSET(p2[0], &newset))
				if(read(p2[0], msg2, 100) > 0) {
				    printf("[client2] : %s\n", msg2);
				}

			newset = initset;
		}
    	}
    	else if(pid1 == 0 && pid2 > 0) {	
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
			kill(pid2, SIGKILL);
			kill(pid1, SIGKILL);
		}
		else {
			write(p1[1], msg1, 100);
			state++;
		}

		if(state == 1) {	
			state = 0;
			state1++;
			if(state1 != 3) {
				kill(pid1, SIGINT);
			}
		}

		if(state1 == 3 && state == 0) {
			printf("** please Turn change **\n");
			state = 0;
			state1 = 0;
			kill(parent_pid, SIGINT);
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
			state++;
		}

		if(state == 1) {	
			state = 0;
			state1++;
			if(state1 != 4) {
				kill(pid2, SIGINT);
			}
		}

		if(state1 == 4 && state == 0) {
			printf("** please Turn change **\n");
			state = 0;
			state1 = 0;
			kill(parent_pid, SIGINT);
		}
    	}
    }
}

void handle1() {
}
