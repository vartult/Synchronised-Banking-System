#include "problem.h"
#include "producer.h"

int main()
{
    MEM *m=memory();
    int i;
    int flag=0;
    for(i=0; i<10; i++)
    {
        m->acc[i]=i;
        m->pins[i]=(i)*10;
        m->money[i]=i*100;
    }

    for(i=0; i<10; i++)
    {
        sem_init(&m->empty[i],1,1);
        sem_init(&m->ri[i],1,BUFFER_SIZE);
    }
    printf("%s\n","Enter Account No and PIN" );
    scanf("%d %d", &(m->account),&(m->pin));
    for(i=0; i<10; i++)
    {
        if(m->pin==m->pins[i] && m->account==m->acc[i] )
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
                producer();
                break;
            case 2:
                printf("ONLY DEPOSITS\n");
                break;
            case 3:
                printf("ONLY DEPOSITS\n");
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
