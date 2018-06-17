#include "problem.h"
#include "producer.h"

void Initialize()
{
    MEM *M = memory();
}
void *producer()
{
    int i=0,n;
    MEM *S = memory();
    sem_wait(&S->empty[S->loc]);
    int q;
    printf("Enter the Amount to be deposited\n");
    scanf("%d",&q);
    S->money[S->loc]=S->money[S->loc]+q;
    printf("Amount has been deposited.\n New Balance is : %d\n", S->money[S->loc]);

    sem_post(&S->empty[S->loc]);
    printf("THANK YOU FOR BANKING\n");
}


