#include "problem.h"
#include "consumer.h"

void *consumer()
{
    int n;
    MEM *s = memory();
    printf("CUSTOMER INTRESTED IN CHECKING BALANCE....WAITING...\n");
    sem_wait(&s->empty[s->loc]);
    sem_wait(&s->ri[s->loc]);
    printf("Account Information is: \n");
    printf("Account Number  : %d\n", s->acc[s->loc]);
    printf("Account Balance : %d\n", s->money[s->loc]);
    sem_post(&s->empty[s->loc]);
    sem_post(&s->ri[s->loc]);
    printf("THANK YOU FOR BANKING\n");
}




