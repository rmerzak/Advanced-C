/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 22:20:39 by rmerzak           #+#    #+#             */
/*   Updated: 2021/12/25 22:34:30 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
int main()
{
	int pipefds[2];
	char writemessage[2][20]={"hi","world"};
	char readmessage[20];
	
	if (pipe(pipefds) == -1)
	{
		printf("unable to creat pipe\n");
		return (0);
	}
	printf("write to pipe message 1 is %s\n",writemessage[0]);
	write(pipefds[1],writemessage[0],sizeof(writemessage[0]));
	read(pipefds[0],readmessage,sizeof(readmessage));
	printf("reading from pipe message 1 %s\n",readmessage);

	printf("write to pipe message 2 is %s\n",writemessage[1]);
	write(pipefds[1],writemessage[1],sizeof(writemessage[1]));
	read(pipefds[0],readmessage,sizeof(readmessage));
	printf("reading from pipe message 2 %s\n",readmessage);
}

