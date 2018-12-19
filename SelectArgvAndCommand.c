int SelectArgvAndCommand(char* source,char* command,char* redirec, char* argvs[],int* endswith){
	//printf("source:%s**\n",source);
	int len = strlen(source);
	int i = 0,j = 0,k = 0,IfReDirection = 0;
	while(i < len - 1){
		char temp[100];
		j = 0;
		while(source[i] != ' ' && i < len - 1 && source[i] != '>'){
			temp[j] = source[i];
			j++;
			i++;
		}
		if(j > 0){
			temp[j] = '\0';
			strcpy(argvs[k++],temp);
			if(IfReDirection)
				strcpy(redirec,temp);
		}
		//printf("%s %d\n",redirec,i);
		while(source[i] == ' ' || source[i] == '>'){
			if(source[i] == '>')
		 		IfReDirection = 1;
			i++;
		}
	}
	strcpy(command,argvs[0]);
	//printf("command in saac:%s\n",command);
	// char t[100] = "./";
	// strcat(t,argvs[0]);
	// strcpy(argvs[0],t);;

	// for(i = 0; i < k; i++)
	// 	printf("argvs[%d] : %s\n",i,argvs[i]);

	if(strcmp(argvs[k-1],"&") == 0){
		*endswith = 1;
		argvs[k-1] = NULL;
	}
	else
		argvs[k] = NULL;
	//printf("tre:%d\n", IfReDirection);
	return IfReDirection;
}

