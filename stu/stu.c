#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GetInput(char name[]);
struct Candidate
{
    char name[20];
    int count;
};
int main()
{
    struct Candidate candidates[3] = 
    {
        {"Biden"},
        {"Trump"},
        {"Bush"}
    };
    char name[20] = "";
    int n = 0;
    int i = 0;
    int v = 0;
    int invaild = 0;
    printf("please enter votes:");
    scanf_s("%d", &n);
    getchar();
    v = n;
    while (n)
    {
        int flag = 0;
        GetInput(name);
        for (i = 0; i < 3; i++)
        {
            if (!strcmp(name, candidates[i].name))
            {
                candidates[i].count++;
                flag = !flag;
                break;
            }
        }
        if (!flag)
        {
            invaild++;
        }
        n--;
    }
    printf("all: %d votes ; vaild: %d ; invaild: %d\n", v, v - invaild, invaild);
    for (i = 0; i < 3 ; i++)
    {
        printf("%s : %d\n", candidates[i].name, candidates[i].count);
    }
    
}

int GetInput(char name[])
{   
    printf("please vote:");
    gets(name);
    return 1;
}


