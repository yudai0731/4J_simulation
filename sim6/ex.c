#include<stdio.h>
#include<stdlib.h>
#define DIM 2

void multipleMatrix(double a[DIM][DIM+1],double b[DIM+1][1],double c[DIM][1]){
    int i,j,k;
    double tmp;
    tmp=0;
      for(i=0; i<DIM+1; i++){
        for(j=0; j<DIM; j++){
            c[i][j]=0;
            for(k=0; k<DIM+1; k++){
	            c[i][j]+=a[i][k]*b[k][j];
      }
    }
  }
}

void addVector(double a[DIM][1],double b[DIM][1],double c[DIM][1]){
    int i;
    for(i=0; i<DIM;i++){
        c[i][0] = a[i][0]+b[i][0];
    }
}

void scalerVector(double a[DIM][1],double h){
    int i;
    for(i=0; i<DIM;i++){
        a[i][0] *=h;
    }
}

void transformVector(double a[DIM][1],double b[DIM+1][1]){
    int i;
    b[0][0]=1;
    for(i=1; i<DIM+1;i++){
        b[i][0] = a[i-1][0];
    }
}

void setVector(double a[DIM][1],double b[DIM][1]){
    int i;
    for(i=0;i<DIM;i++){
        b[i][0] = a[i][0];
    }
}

int main(void){
    double h = 0.5;
    double lim=2.0;
    double step;
    int i;
    double initVector[DIM][1] ={{4},{6}};
    double transVector[DIM+1][1];
    double weightMatrix[DIM][DIM+1] = {{0,-0.5,0},
                                       {4,-0.1,-0.3}
                                       };
    double yiVector[DIM][1];
    double tmpVector[DIM][1];
    double resultVector[DIM][1];

    setVector(initVector,yiVector);
    for(step=h;step<=lim;step+=h){
        transformVector(yiVector,transVector);
        multipleMatrix(weightMatrix,transVector,tmpVector);
        scalerVector(tmpVector,h);
        addVector(yiVector,tmpVector,resultVector);
        printf("step = %0.2lf\n",step);
        for(i=0;i<DIM;i++){
            printf("y%d = %lf\n",i,resultVector[i][0]);
        }
        printf("\n");
        setVector(resultVector,yiVector);
    }
    return 0;
}