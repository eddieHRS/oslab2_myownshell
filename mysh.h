#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#define N 512 // maximum length of a line of input to the shell
#define M 5 //length of argvs of each command

char error_message[30] = "An error has occurred\n";
int SelectArgvAndCommand(char* source,char* command,char* redirec, char* argvs[],int *endswith);
void cd(char* myargs[]);
void pwd(int IfReDirection,char* myargs[]);
int ExeAnCommand(char* buf);
void delPidFromChild(int* ChildProcess,int pid,int* len);
