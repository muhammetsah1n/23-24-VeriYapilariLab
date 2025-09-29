#include <stdio.h>

int main(){

    int matrix[5][5],sum;

    for (int i=0;i<5;i++){

        for (int j=0;j<5;j++){

            scanf("%d",&matrix[i][j]);

        }

    }

    for (int i=0;i<5;i++){

        sum=0;

        for (int j=0;j<5;j++){

            sum+=matrix[i][j];

        }

        for (int j=0;j<5;j++){

            matrix[j][i]+=sum;

        }

    }

    for (int i=0;i<5;i++){

        sum=0;

        for (int j=0;j<5;j++){

            sum+=matrix[j][i];

        }

        for (int j=0;j<5;j++){

            matrix[i][j]+=sum;

        }

    }

    for (int i=0;i<5;i++){

        for (int j=0;j<5;j++){

            printf("%d ",matrix[i][j]);

        }
        printf("\n");

    }

    return 0;
}