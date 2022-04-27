/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:19:32 by rmerzak           #+#    #+#             */
/*   Updated: 2021/12/23 23:13:51 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	int id =fork();
	int n;

	if (id == 0)
		n = 1;
	else
		n = 6;
	int i;
	if (id != 0)
		wait(NULL);
	for (i = n ; i < n + 5 ; i++)
	{
		printf("%d ",i);
		fflush(stdout);
	}
	printf("\n");
}

