#include <stdio.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 10
#define KEY 111111111
extern void Initialize();
// A structure to store BUFER and semaphores for synchronization
typedef struct
{
    int a;
    int j,loc;
    int account,pin;
    int acc[BUFFER_SIZE],pins[BUFFER_SIZE],money[BUFFER_SIZE];
    sem_t empty[BUFFER_SIZE];
    //sem_t wr[BUFFER_SIZE];
    sem_t ri[BUFFER_SIZE];
} MEM;

// Method for shared memory allocation
static MEM *memory()
{
    key_t key = KEY;
    int shmid;
    shmid = shmget(key, sizeof(MEM), IPC_CREAT | 0666);
    return (MEM *) shmat(shmid, NULL, 0);
}


