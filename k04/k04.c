#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct data
{
    int ID;
    int gender;
    double heights;
};

int num=15;
int main(void)
{
    char fname[FILENAME_MAX];
    char buf[256];
    FILE*fp;

    int a=0, g, id, W_ID;
    struct data sample[num];
    double h;

    printf("input the filename of sample heights ?:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample heights: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp = NULL)
    {
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL)
    {
        sscanf(buf,"%d,%lf",&g,&h);

        sample[a-1].gender = g;
        sample[a-1].heights = h;
        a++;
    }

    if(fclose(fp) == EOF)
    {
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("input the filename of sample ID ?:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample ID: %s\n",fname);

    fp = fopen(fname,"r");

    if(fp == NULL)
    {
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    a = 0;

    while(fgets(buf,sizeof(buf),fp) != NULL)
    {
        sscanf(buf,"%d",&id);
        sample[a].ID = id;
        a++;
    }

    if(fclose(fp) == EOF)
    {
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("Which ID's data do you want ?:");
    scanf("%d",&W_ID);

    int j=0,n=0;

    while(j <= num)
    {
        if(sample[j].ID == W_ID)
        {
            if(sample[j].gender == 1)
            {
                printf("---\nID : %d\ngender : Male\nheights : %.2lf\n",sample[j].ID,sample[j].heights);
            }
            else
            {
                printf("---\nID : %d\ngender : Female\nheights : %.2lf\n",sample[j].ID,sample[j].heights);              
            }
        }
        else
        {
            n = n+1;
        }
        j = j+1;
    }
    if(n == j)
    {
        printf("---\nNo data");
    }
    
    return 0;
}