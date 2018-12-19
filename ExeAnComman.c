int ExeAnCommand(char* buf){
		char order[10];//type of operation such as "cd" "pwd" and so on
		char redirec[50];//path of redirection
		char m0[30];
		char m1[30];
		char m2[30];
		char m3[30];
		char m4[30];
		char* myargs[M] = {m0,m1,m2,m3,m4};
		int endswith = 0;//check if command ends with &
		int IfReDirection = SelectArgvAndCommand(buf,order,redirec,myargs,&endswith);


		//printf("%s**\n", order);
		if(strcmp("exit",order) == 0){
				exit(0);
		}
		else if(strcmp("cd",order) == 0){
				cd(myargs);
		}
		else if(strcmp("pwd",order) == 0){
				pwd(IfReDirection,myargs);
		}
		int ChildProcess[10] = {0};//pid of child that in background
		int cp = 0;
		int rc = fork();
		
		if(rc < 0){//fork failed
			write(STDERR_FILENO,error_message,strlen(error_message));
			exit(1);
		}
		else if(rc == 0){//in child process
			if(strcmp("ls",order) == 0){
				if(IfReDirection){
					printf("output in file '%s'\n",redirec);
					close(STDOUT_FILENO);
					//open file
					if(open(redirec,O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU) == -1){
						write(STDERR_FILENO,error_message,strlen(error_message));
					}
				}
				int i = 1;
				while(myargs[i] != NULL && strcmp(myargs[i],redirec)) i++;
				myargs[i] = NULL;
				execvp(myargs[0],myargs);
			}
			else if(strcmp(order,"pwd") && strcmp(order,"wait")){
				if(execvp(order,myargs) == -1){
					write(STDERR_FILENO,error_message,strlen(error_message));
					exit(1);
				}
			}
			if(endswith){
				delPidFromChild(ChildProcess,(int)getpid(),&cp);
			}
		
			exit(0);
		}

		else{
			if(endswith == 0){
				int rc_wait = waitpid(rc,NULL,0);
			}else{//command with &
				ChildProcess[cp++] = rc;
				printf("rc:%d cp:%d\n",rc,cp);
			}
			if(strcmp(myargs[0],"wait") == 0){
				//printf("wait %d\n",ChildProcess[0]);
				if(ChildProcess[0] != 0){
					int wp = waitpid(ChildProcess[0],NULL,0);
				}
			}	
		}
		return 0;
}
