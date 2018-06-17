#include "problem.h"
#include "withdraw.h"


int main()
{
    MEM *m=memory();

    int i,flag=0;
    printf("%s\n","Enter Account Number and PIN" );
    scanf("%d %d", &(m->account),&(m->pin));
    for(i=0; i<10; i++)
    {
        if( m->pin==m->pins[i] && m->account==m->acc[i] )
        {
            flag=1;
            break;
        }
    }
    m->loc=i;
    if(flag==1)
    {
        int choice;
m:
        printf( "\t\t***************  Main Menu Screen  *******************\n" );
        printf("SELECT YOUR OPTION\n");
        printf("1) Deposit\n");
        printf("2) Check Balance\n");
        printf("3) Withdraw\n");
        printf("4) Exit\n");
        printf("Enter your choice: \n");
        scanf("%d",&choice);
        if(choice >= 1 && choice <= 5)
        {
            switch(choice)
            {
            case 1:
                printf("SORRY CHECK BALANCE ONLY\n");
                break;
            case 2:
                printf("ONLY WITHDRAWS\n");
                break;
            case 3:
                withdraw();
                break;
            case 4:
                exit(0);

            }
        }
        else
        {
            printf("\nINVALID INPUT!! ENTER AGAIN\n");
            goto m;
        }
    }
    else
        printf("Either of them are incorrect\n");
}

