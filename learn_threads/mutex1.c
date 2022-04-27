/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:53:16 by rmerzak           #+#    #+#             */
/*   Updated: 2022/04/27 21:20:57 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *functionC();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

int main(void) {
	int rc1, rc2;
	pthread_t thread1, thread2;

	if ((rc1 = pthread_create(&thread1, NULL, &functionC, NULL)))
		printf("thread creation failed\n");
	if ((rc2 = pthread_create(&thread2, NULL, &functionC, NULL)))
		printf("thread creation failed\n");
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	exit(0);
	return (0);
}
void *functionC()
{
	pthread_mutex_lock(&mutex1);
	counter++;
	printf("counter value: %d\n",counter);
	pthread_mutex_unlock(&mutex1);
	return (void *)0;
}
