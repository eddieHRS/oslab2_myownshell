#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc,char* argv[])
{	
	char* tempfile = {"temp"};
	write(STDOUT_FILENO,"mysh> ",6);
	//  read from stdinput
	char m1_0[30] = {"echo"};
	char m1_1[30] = {"/tmp"};
	char m1_2[30];
	char m1_3[30];
	char* m1[4] = {m1_0,m1_1,m1_2,m1_3};
	m1[2] = NULL;

	char m2_0[30] = {"ls"};
	char m2_1[30] = {};
	char m2_2[30];
	char m2_3[30];
	char* m2[4] = {m2_0,m2_1,m2_2,m2_3};

	int rc = fork();
	if(rc < 0){
		write(STDERR_FILENO,"rc < 0",strlen("rc < 0"));
		exit(1);
	}
	if(rc == 0){
		close(STDOUT_FILENO);
		open(tempfile,O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
		execvp(m1[0],m1);
	}
	else{
		wait(NULL);
		char buf[20];
		int f = open(tempfile,O_RDONLY,S_IRWXU);
		read(f,buf,20);
		buf[strlen(buf) - 1] = '\0';
		strcat(m2[1],buf);
		m2[2] = NULL;
		execvp(m2[0],m2);
	}
	return 0;
	
}
