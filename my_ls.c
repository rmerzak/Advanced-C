#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc,char **argv)
{
	DIR *dir;
	struct dirent *dirp;
	int i;
	int fw,fr,fx;

	i = 0;
	if (argc != 2)
		printf("ERROR");
	dir = opendir(argv[1]);
	if(dir == NULL)
		printf("cant open check your droit acces");
	while((dirp = readdir(dir)) != NULL)
	{
		fr = access(dirp->d_name,R_OK);
		fw = access(dirp->d_name,W_OK);
		fx = access(dirp->d_name,X_OK);
		if(fr)
			printf("%c",'R');
		if(fw)
			printf("%c",'W');
		if(fx)
			printf("%c",'X');
		printf("---%d---%s\n",i++,dirp->d_name);
	}
	closedir(dir);
}
