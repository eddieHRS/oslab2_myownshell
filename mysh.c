#include <mysh.h>
int main(int argc,char* argv[])
{	
	if(argc == 1){
		while(1){
			write(STDOUT_FILENO,"mysh> ",6);
			//  read from stdinput
			char buf[N];
			int flag = read(STDIN_FILENO,buf,N);

			if(flag <= 0){
				write(STDERR_FILENO,error_message,strlen(error_message));
				exit(1);
			}
			buf[flag] = '\0';
			//printf("buf: %s\n",buf);
			ExeAnCommand(buf);
		}
	}
	else{
		FILE* f = fopen(argv[1],"r");
		if(f == NULL){
			write(STDERR_FILENO,error_message,strlen(error_message));
		}
		else{
			char buf[N];
			while(fgets(buf,N,f) != NULL){
				// printf("buf: %s\n",buf);
				write(STDOUT_FILENO,"mysh> ",6);
				write(STDOUT_FILENO,buf,strlen(buf));
				ExeAnCommand(buf);
			}
		}
	}
	
	return 0;
	
}





//IfReDirection = 0 for no redirection and IfReDirection = 1 for with redirection






