#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave, int a);
extern double var_online(double val, double ave, double ave2, int a);

int main(void)
{
    double val,ave=0,ave2=0,var=0,s_var;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    int a=0;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        a++;
        
        var = var_online(a,val,ave,ave2);
        ave = ave_online(a,val,ave);
        ave2 = ave_online(a,pow(val,2),ave2);
        

    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("%f\n",a);
    s_var = (a/(a-1))*var;

    printf("Average: %f\n",ave);
    printf("Var: %f\n",var);

    printf("suitei_Average: %f\n",ave);
    printf("suitei_Var: %f\n",s_var);

    return 0;


}

