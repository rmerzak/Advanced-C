/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:31:53 by rmerzak           #+#    #+#             */
/*   Updated: 2021/12/26 20:57:48 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	int arr[]={1,2,3,4,1,2};
	int fd[2];
	int start;
	int end;
	int arrsize = sizeof(arr) / sizeof(int);

	if (pipe(fd) == -1)
	{
		printf("enable to open the pipe\n");
		return 1;
	}
	int id = fork();
	if (id == -1)
	{
		return 2;
	}
	if (id == 0)
	{
		start = 0;
		end = arrsize / 2;
	}
	else
	{
		start = arrsize / 2;
		end = arrsize;
	}
	//wait(NULL);
	int sum,i;

	i = start;
	sum = 0;
	while(i<end)
	{
		sum += arr[i];
		i++;
	}
	printf("%d\n",sum);
	if (id == 0)
	{
		close(fd[0]);
		write(fd[1],&sum,sizeof(int));
		close(fd[1]);
	}
	else
	{
		int y;
		close(fd[1]);
		read(fd[0],&y,sizeof(int));
		int total;
		total = y + sum;
		printf("total sum is %d\n",total);
		wait(NULL);
	}


}
