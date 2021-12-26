/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 20:26:28 by rmerzak           #+#    #+#             */
/*   Updated: 2021/12/23 21:18:38 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#define MAX_COUNT 100

void child_process(void);
void parent_process(void);

int main()
{
	 int id=fork();
	if (id == 0)
		child_process();
	else
		parent_process();
}

void child_process(void)
{
	int i;

	i = 0;
	while (++i <= MAX_COUNT)
		printf("this line is from child i=%d\n",i);
	printf("fin child process\n");
}

void parent_process(void)
{
	int i;

	i = 0;
	while (++i <= MAX_COUNT)
		printf("this line is from parent i=%d\n",i);
	printf("fin parent process\n");
}


