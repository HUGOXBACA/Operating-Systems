#include <pthread.h>

#include <semaphore.h>

#include <stdio.h>

#include <stdlib.h>

#define NITER 1000000

int cnt = 0;

sem_t mutex; // Create a semaphore mutex

void * Count(void *a)

{

int i, tmp;

for(i = 0; i < NITER; i++)

{

sem_wait(&mutex); // Wait on semaphore mutex. Other thread has to wait until released

tmp = cnt; // These lines are critical section.... As cnt is modified by both threads

tmp = tmp + 1;

cnt = tmp;

sem_post(&mutex); // Post on semaphore mutex... Now any of the threads can acquire it.

}

}

int main(int argc, char *argv[])

{

pthread_t tid1, tid2;

sem_init(&mutex, 0, 1); // Initialize semaphore. 0 means semaphore mutex is shared between threads

// 1 is the initial value of semaphore mutex

if(pthread_create(&tid1, NULL, Count, NULL))

{

printf("\n ERROR creating thread 1");

exit(1);

}

if(pthread_create(&tid2, NULL, Count, NULL))

{

printf("\n ERROR creating thread 2");

exit(1);

}

if(pthread_join(tid1, NULL))

{

printf("\n ERROR joining thread");

exit(1);

}

if(pthread_join(tid2, NULL))

{

printf("\n ERROR joining thread");

exit(1);

}

if (cnt < 2 * NITER)

printf("\n BOOM! cnt is [%d], should be %d\n", cnt, 2*NITER);

else

printf("\n OK! cnt is [%d]\n", cnt);

pthread_exit(NULL);

sem_destroy(&mutex);

}


