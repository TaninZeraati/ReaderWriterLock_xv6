#include "types.h"
#include "user.h"
#include "fcntl.h"

int main(int argc,char *argv[])
{
    int first = atoi(argv[1]);
    int fff = 1;
    int rem;
    int final = 0;
    int Zero = 0, One = 0;
    int count = 0;
        int number[20];
    
    while ( first != 0 )
    {
        count ++;
        rem = first%2;
        if(first/2 != 0)
        {
            if(rem == 0)
                Zero ++;
            else
                One ++;
        }
  
        final = final + rem * fff;
        fff = fff*10;
        first = first/2;

    }

    for(int i=count-2; i>=0; i--)
    {
        number[i] = final%10;
        final = final/10;
    }

    init_rwp();
    int pid = fork();
    if (pid < 0)
    {
        printf(1, "Error forking.\n");
    }
    else if (pid > 0) // readers
    {
        for (int i=0; i < count-1; i++)
        {
            if(number[i] == 0)
            {
                pid = fork();
                if (pid < 0)
                {
                    printf(1, "Error forking.\n");
                }
                else if (pid == 0)
                {
                    reader(i);
                    exit();
                }
            }
        }
        for (int i=0; i < count-1; i++)
            wait();
    } 
    else //writers
    {
        for (int i=0; i < count-1; i++)
        {  
            if(number[i] == 1)
            {
                pid = fork();
                if (pid < 0)
                {
                    printf(1, "Error forking.\n");
                }
                else if (pid == 0)
                {
                    printf(1, "making writer\n");
                    writer(i);
                    exit();
                }
            }
        }
        for (int i=0; i < count-1; i++)
        {
            wait();
        }
        wait();
    }
    exit();
}