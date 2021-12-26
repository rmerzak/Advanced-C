/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 22:34:38 by rmerzak           #+#    #+#             */
/*   Updated: 2021/12/26 00:46:00 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int pipefd[2];

	char writemessages[2][20]={"hi","world"};
	char readmessage[20];

	if (pipe(pipefd) == -1)
	{
		printf("enable to open the pipe\n");
		return 1;
	}
	int pid=fork();
	if (pid == 0)
	{
		read(pipefd[0],readmessage,sizeof(readmessage));
		printf("child process-reading from pipe message 1 %s\n",readmessage);
		read(pipefd[0],readmessage,sizeof(readmessage));
		printf("child process-reading from pipe message 2 %s\n",readmessage);
	}
	else
	{
		printf("parent process writing to pipe --- %s\n",writemessages[0]);
		write(pipefd[1],writemessages[0],sizeof(writemessages[0]));
		printf("parent process writing to pipe --- %s\n",writemessages[1]);
		write(pipefd[1],writemessages[1],sizeof(writemessages[1]));
	}
}



