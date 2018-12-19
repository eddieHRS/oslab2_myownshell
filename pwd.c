#include "mysh.h"
void pwd(int IfReDirection,char* myargs[]){
	char buf[N];
	if(getcwd(buf,N) == NULL)
		write(STDERR_FILENO,error_message,strlen(error_message));
	if(IfReDirection == 0){
		//printf("%d\n", IfReDirection);
		printf("%s\n",buf);
	}
	else{
		int fn = open(myargs[1],O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
		if(fn == -1){
			write(STDERR_FILENO,error_message,strlen(error_message));
		}
		write(fn,buf,strlen(buf));
		close(fn);
	}
}
