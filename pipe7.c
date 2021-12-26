/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 21:11:16 by rmerzak           #+#    #+#             */
/*   Updated: 2021/12/26 21:44:29 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int p1[2];
	int p2[2];
	if (pipe(p1) == -1)
	{
		return 1;
	}
	if (pipe(p2) == -1)
	{
		return 25;
	}
	
	int pid = fork();
	if (pid == -1)
	{
		printf("failed to create a process\n");
		return 2;
	}
	if (pid == 0)
	{
		close(p1[1]);
		close(p2[0]);
		int x;
		if (read(p1[0],&x,sizeof(x)) == -1)
		{
			return 3;
		}
		printf("Received %d\n",x);
		x *= 4;
		if (write(p2[1],&x,sizeof(x)) == -1)
		{
			return 4;
		}
		printf("send 4*x to the father\n");
		close(p1[0]);
		close(p2[1]);
	}
	else
	{
		close(p1[0]);
		close(p2[1]);
		int y,z;
		y = 3;
		if (write(p1[1],&y,sizeof(int)) == -1)
			return 5;
		printf("sending the number to the child\n");
		if(read(p2[0],&z,sizeof(int)) == -1)
			return 6;
		printf("the return from the child is %d\n",z);
		wait(NULL);
		close(p1[1]);
		close(p2[0]);
	

	}
}	


