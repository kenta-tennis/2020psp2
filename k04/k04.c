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

int num=14;
int main(void)
{
    char fname[FILENAME_MAX];
    char buf[256];
    FILE*fp;

    int GENDER, id, W_ID, a;
    struct data sample[num];
    double HEIGHTS;

    printf("input the filename of sample heights ?:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample heights: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp == NULL)
    {
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    a = 0;
    while(fgets(buf,sizeof(buf),fp) != NULL)
    {
        sscanf(buf,"%d,%lf",&GENDER,&HEIGHTS);

        a = a+1;
        sample[a].gender = GENDER;
        sample[a].heights = HEIGHTS;
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
        a = a+1;
        sscanf(buf,"%d",&id);
        sample[a].ID = id;
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
