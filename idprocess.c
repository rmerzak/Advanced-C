/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idprocess.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 17:22:56 by rmerzak           #+#    #+#             */
/*   Updated: 2021/12/24 18:16:44 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>

int main()
{
	int id = fork();
	if (id != 0)
		wait(NULL);
	if (id == 0)
		printf("curent ID : %d ,parent ID :%d =====> child process\n",getpid(),getppid());
	else
		printf("curent ID : %d ,parent ID :%d =====> parent process\n",getpid(),getppid());
}
