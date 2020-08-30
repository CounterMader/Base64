//In The Name Of GOD
//Wrote By ali esmaeily

#include <stdio.h>

int strlen(char *a);

int main()
{
    // General Variables
    char data [] = "jadi";
    int cont1 [] = {0,2,4,4,2,6,0};
    int cont2 [] = {0,252,3,240,15,196,63};
    int action_number = (2 * strlen(data));
    int mem [30];
    int mem1 [30];
    int memptr = 1;
    char b64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                 "abcdefghijklmnopqrstuvwxyz"
                 "0123456789"
                 "+/";
    int flag = 0;

    if ((8 * strlen(data)) % 6 == 0)
        flag = 1;
    // Data Maker
    int m = 1;
    for (int i = 0;i < action_number;i++)
    {
        if (i % 2 == 0)
        {
            mem[i] = ((data[i/2] & cont2[m]) >> cont1[m]);
        }
        else
        {
            mem[i] = ((data[i/2] & cont2[m]) << cont1[m]);
        }
        if (m == 6)
            m = 1;
        else
            m ++;
    }
/*    //Debug Enviroment
    for (int l = 0;l < action_number; l++)
    {
        printf("mem ->%d\n",mem[l]);
        printf("\n");
    }
*/
    // Data linker
    mem1[0] = mem[0];
    for (int j = 1;j < action_number;j += 2)
    {
        if ((j + 1) % 6 == 0)
        {
            mem1[memptr] = mem[j];
            memptr++;
            j--;
        }
        else
        {
            mem1[memptr] = (mem[j] ^ mem[j + 1]);
            memptr ++;
        }
    }
    // Data Printer
    for (int l = 0;l < memptr;l++)
    {
        printf("%c",b64[mem1[l]]);
    }
    if (flag == 0)
        printf("==");
/*
    //Debug Envirment
    for (int l = 0;l < action_number; l++)
    {
        printf("mem ->%d\n",mem[l]);
        printf("mem1 ->%d\n",mem1[l]);
        printf("\n");
    }
*/
    printf("\n\a");
    return 0;
}
//Counting characters of string
int strlen(char *a)
{
    int i = 0;
    int res = 0;
    while (*(a + i) != '\0')
    {
        res ++;
        i ++;
    }
    return res;
}
