#include "problem.h"
#include "withdraw.h"
void notes(int money)
{
    int newmoney=money;
    int r2000,r500,r100,r200;
    r2000=newmoney/2000;
    newmoney=newmoney%2000;
    r500=newmoney/500;
    newmoney=newmoney%500;
    r200=newmoney/200;
    newmoney=newmoney%200;
    r100=newmoney/100;
    newmoney=newmoney%100;
    printf("\nRs. 2000: %d \n \nRs. 500: %d \n \nRs. 200: %d \n \nRs. 100: %d \n",r2000,r500,r200,r100);


}
void *withdraw()
{
    int i=0,n;
    MEM *S = memory();
    sem_wait(&S->empty[S->loc]);
    int q;
    printf("Enter the Amount to be Withdrawn\n");
    scanf("%d",&q);
    S->money[S->loc]=S->money[S->loc]-q;
    printf("Amount has been Withdrawn.\n New Balance is : %d\n", S->money[S->loc]);
    printf("Cash Notes are: \n");
    notes(q);
    sem_post(&S->empty[S->loc]);
    printf("THANK YOU FOR BANKING\n");
}
