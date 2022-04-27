#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char cwd[1000];
	printf("the current dir name is %s\n",getcwd(cwd,sizeof(cwd)));
}
