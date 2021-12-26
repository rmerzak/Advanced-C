/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 01:27:48 by rmerzak           #+#    #+#             */
/*   Updated: 2021/12/26 19:31:47 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
char message[25] = "cela provient d'un tube";
int main()
{
	int p[2];
	if (pipe(p) == -1)
	{
		printf("enable to oen the pipe");
		return 1;
	}
	int pid = fork();
	if (pid == 0)
	{
		char c;
		close(p[1]);
	//	while(read(p[0],&c,1)>0)
	//	{
	//			printf("%c",c);
	//	}

		read(p[0],message,sizeof(message));
		printf("%s\n",message);
		close(p[0]);
		return 0;
	}
	else
	{
		close(p[0]);
		write(p[1],message,24);
		close(p[1]);
		return 0;
	}
}

