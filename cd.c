void cd(char* myargs[]){
	char* path = getenv("HOME");
	if(myargs[1] != NULL)
		path = myargs[1];

		int flag = chdir(path);
		if(flag == -1)
			write(STDERR_FILENO,error_message,strlen(error_message));
		else{
			char buf[100];
			printf("%s\n",getcwd(buf,100));
		}
}

