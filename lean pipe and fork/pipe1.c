/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 17:25:01 by rmerzak           #+#    #+#             */
/*   Updated: 2021/12/25 22:20:29 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>



int main()
{
	int fd[1];
	
	// fd[0] -- read
	// fd[1] --write

	if ( pipe(fd) == -1)
	{
		printf("AN error ocurred with opening the pipe");
		return 1;
	}
	int id = fork();
	if (id == 0)
	{
		int a;
		a = 44;
		close(fd[0]);
		write(fd[1],&a,sizeof(int));
		close(fd[1]);
	}
	else
	{
		int y;
		close(fd[1]);
		read(fd[0],&y,sizeof(int));
		close(fd[0]);
		printf("GOT from child process %d\n",y);
		
	}



		return 0;
}
