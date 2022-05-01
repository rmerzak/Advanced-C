/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:36:08 by rmerzak           #+#    #+#             */
/*   Updated: 2022/05/01 18:58:36 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int i = 0;
pthread_mutex_t mutex;

void *routine() {
	for (int j = 0; j < 1000000; j++) {
		pthread_mutex_lock(&mutex);
		i++;
		pthread_mutex_unlock(&mutex);
	}
	return (void *) 0;
}

int main(int argc, char **argv)
{
	pthread_t t1;
	pthread_t t2;
	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		printf("Error");
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		printf("Error");
	if (pthread_join(t1, NULL) != 0)
		printf("Error");
	if (pthread_join(t2, NULL) != 0)
		printf("Error");
	pthread_mutex_destroy(&mutex);
	printf("%d\n",i);
	return (0);
}
