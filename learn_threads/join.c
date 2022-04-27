/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:21:04 by rmerzak           #+#    #+#             */
/*   Updated: 2022/04/27 22:03:12 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 10

void *thread_function(void *);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

int main(void) {
	pthread_t thread_id[NTHREADS];

	for (int i = 0; i < NTHREADS; i++) {
		pthread_create(&thread_id[i], NULL, thread_function, NULL);
	}
	for (int j = 0; j < NTHREADS; j++){
		pthread_join(thread_id[j], NULL);
	}
	printf("Final counter value : %d\n", counter);
	exit(0);
	return (0);
}
void *thread_function() {
	printf("Tread number %ld\n",pthread_self());
	pthread_mutex_lock(&mutex1);
	counter++;
	pthread_mutex_unlock(&mutex1);
	return (void *) 0;
}
