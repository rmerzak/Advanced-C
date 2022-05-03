/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:38:24 by rmerzak           #+#    #+#             */
/*   Updated: 2022/05/03 15:05:32 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

pthread_mutex_t mutex;
int mails = 0;
void *routine() {
	for (int i = 0; i < 100000; i++) {
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
	return (void *)0;
}

int main(void) {
	pthread_t th[4];
	int i;
	pthread_mutex_init(&mutex, NULL);
	for (i = 0; i < 4; i++ ) {
		if (pthread_create(th + i, NULL, &routine, NULL) != 0) {
			perror("Failed to create thread");
			return (1);
		}
		printf("Thread %d has started\n",i);

	}
	for (i = 0; i < 4; i++) {
		if (pthread_join(th[i], NULL) != 0) {
			return 2;
		}
		printf("Thread %d has finished\n",i);
	}
	printf("%d\n",mails);
}
