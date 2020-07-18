#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
double a;
extern double ave_online(double val,double ave);
extern double var_online(double val, double ave, double ave2);

int main(void)
{
    double val,ave=0,ave2=0,var=0,s_var;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;

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
        
        var = var_online(val,ave,ave2);
        ave = ave_online(val,ave);
        ave2 = ave_online(pow(val,2),ave2);
        

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

double ave_online(double val,double ave)
{
    double average;
    average = ((a-1)*ave)/a + val/a;

    return average;
}
double var_online(double val,double ave,double ave2)
{
    double var;
    var = ((a-1)*ave2)/a + pow(val,2)/a - pow(((a-1)*ave)/a + val/a,2);

    return var;
}