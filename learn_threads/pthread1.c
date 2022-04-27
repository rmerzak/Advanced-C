/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:43:06 by rmerzak           #+#    #+#             */
/*   Updated: 2022/04/27 20:52:50 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message_function(void *ptr);

int main(void) {
	pthread_t	thread1, thread2;
	char		*message1 = "theard 1";
	char		*message2 = "thread 2";
	int			iret1, iret2;

	//creation d'un thread
	
	iret1 = pthread_create(&thread1, NULL, print_message_function, (void *) message1);
	iret2 = pthread_create(&thread2, NULL, print_message_function, (void *) message2);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("thread 1 return: %d\n",iret1);
	printf("thread 2 return: %d\n",iret2);
	exit(0);
	return (0);
}
void *print_message_function(void *ptr)
{
	char *str;
	
	str = (char *)ptr;
	printf("%s\n",str);
	return (void *)0;
	pthread_exit(NULL);
}
