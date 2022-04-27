/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiprocess.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 16:07:03 by rmerzak           #+#    #+#             */
/*   Updated: 2021/12/25 17:24:26 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>

int main()
{
	int id1=fork();
	int id2=fork();
	if (id1 == 0)
	{
		if(id2 == 0)
			printf("process y\n");
		else
			printf("process  x\n");
	}
	else
	{
		if (id2 == 0)
			printf("procces z\n");
		else
			printf("process parent\n");
	}
	while(wait(NULL) != -1 || errno != ECHILD);
}
