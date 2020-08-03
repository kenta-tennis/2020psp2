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

    int a=0;
    int id, GENDER;
    struct data sample[num];
    double HEIGHTS;
    int W_ID;

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

    fgets(buf,sizeof(buf),fp);
    while(fgets(buf,sizeof(buf),fp) != NULL)
    {
        sscanf(buf,"%d , %lf",&GENDER,&HEIGHTS);

        sample[a-1].gender = GENDER;
        sample[a-1].heights = HEIGHTS;
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
            if(sample[j-1].gender == 1)
            {
                printf("---\nID : %d\ngender : Male\nheights : %.2lf\n",sample[j].ID,sample[j-1].heights);
            }
            else
            {
                printf("---\nID : %d\ngender : Female\nheights : %.2lf\n",sample[j].ID,sample[j-1].heights);              
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
