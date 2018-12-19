void delPidFromChild(int* ChildProcess,int pid,int *len){
	int i = 0,j = 0;
	while(i <= *len){
		if(ChildProcess[i] == (int)getpid())
			i++;
		ChildProcess[j] = ChildProcess[i];
		i++;
		j++;
	}
	*len = j;
}

