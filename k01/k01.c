#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave2, int a)
{
    ave2 = ((a-1)*ave2+val)/a;

    return ave2;
}
extern double var_online(double val, double ave3, double save, int a)
{
    return ((a-1)*save+val)/a-pow((((a-1)*ave3+val)/a),2);
}

int main(void)
{
    double val,ave=0,save=0,ave3=0,pm,samplemean,samplevariance,populationmean,populationvariance;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    int a;
    a=0;

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
        
        ave = ave_online(a,val,ave);

        samplevariance = var_online(a,val,save,ave3);

        save = ((a-1)*save+val*val)/a;
        ave3 = ((a-1)*ave3+val)/a;
        
        samplemean = ave;

    }

    populationvariance = a*samplevariance/(a-1);
    populationmean = samplemean;

    pm = pow(populationvariance/a,0.5);

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("sample mean = %lf\n",samplemean);
    printf("sample variance = %lf\n",samplevariance);
    printf("population mean = %lf,pm = %lf\n",populationmean,pm);
    printf("population variance = %lf\n",populationvariance);

    return 0;


}

