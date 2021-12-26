/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:55:56 by rmerzak           #+#    #+#             */
/*   Updated: 2021/12/26 01:27:39 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	int pipefds1[2];
	int pipefds2[2];

	char pipe1writemessage[20]="hi";
	char pipe2writemessage[20]="world";

	char readmessage[20];

	if (pipe(pipefds1) == -1)
	{
		printf("unable to create pipe 1\n");
		return (1);
	}

	if (pipe(pipefds2) == -1)
	{
		printf("unable to create pipe 1\n");
		return (1);
	}
	int pid=fork();
	if (pid != 0)
	{
		close(pipefds1[0]);
		close(pipefds2[1]);

		printf("in parent :writing to pipe 1 - message is %s\n",pipe1writemessage);
		write(pipefds1[1],pipe1writemessage,sizeof(pipe1writemessage));
		read(pipefds2[0],readmessage,sizeof(readmessage));
		printf("in parent reading from pipe 2 message is %s\n",readmessage);
	}
	else
	{
		close(pipefds1[1]);
		close(pipefds2[0]);

		read(pipefds1[0],readmessage,sizeof(readmessage));
		printf("in child :reading from pipe 1 - message is %s\n",readmessage);
		printf("in child writing to pipe 2 message is %s\n",pipe2writemessage);
		write(pipefds2[1],pipe2writemessage,sizeof(pipe2writemessage));

	}
}

