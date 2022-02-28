#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void init_zero_matrix(float matrix[3][3]);
void print_matrix(const float matrix[3][3]);
void add_matrices(const float a[3][3], const float b[3][3], float c[3][3]);
void init_identity_matrix(float matrix[3][3]);
void multiple_scalar(float matrix[3][3], float scalar);
void multiply_matrices(float matrix1[3][3], float matrix2[3][3], float matrix3[3][3]);
void transform_point(float vector[3], float matrix[3][3]);
void print_vector(float  vector[3]);
void shift(float vector[3][3]);
void rotate(float vector[3][3]);
void scale(float vector[3][3]);

int main()
{
    float a[3][3] = {
        { 1.0f, -2.0f,  3.0f},
        { 5.0f, -3.0f,  0.0f},
        {-2.0f,  1.0f, -4.0f}
    };
	float b[3][3];
	float c[3][3];

    init_zero_matrix(b);
    b[1][1] =  8.0f;
    b[2][0] = -3.0f;
    b[2][2] =  5.0f;

    print_matrix(a);
    print_matrix(b);

    add_matrices(a, b, c);

    print_matrix(c);

    float d[3][3];

    init_identity_matrix(d);
    print_matrix(d);
    multiple_scalar(d,5.5);
    print_matrix(d);
    float e[3][3];
    multiply_matrices(c,d,e);
    print_matrix(e);
    float vector1[] = {3.2,5.4,1.0};
    print_vector(vector1);
    transform_point(vector1,d);
    print_vector(vector1);
    shift(vector1);
    print_vector(vector1);


    return 0;
}
void init_zero_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = 0.0;
        }
    }
}

void print_matrix(const float matrix[3][3])
{
    int i;
    int j;
    printf("Matrix:\n");
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%4.4f ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("----------------------------------------------------\n");
}

void add_matrices(const float a[3][3], const float b[3][3], float c[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}


void init_identity_matrix(float matrix[3][3]){

    int i,j;


    for(i=0; i<3; i++){
        for(j=0; j<3;j++){
            if( i==j){
                matrix[i][j]= 1.0f;
            }else{
                matrix[i][j]= 0;
            }
        }


    }

    return;

}

void multiple_scalar(float matrix[3][3], float scalar){

    int i,j;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            matrix[i][j]= matrix[i][j]*scalar;
        }
    }

    return ;
}


void multiply_matrices(float matrix1[3][3], float matrix2[3][3], float matrix3[3][3]){

    int i,j,k;

    for(i=0; i<3; i++){
        for(j=0 ; j<3; j++){
                matrix3[i][j]= 0;
            for(k=0; k<3;k++){
                matrix3[i][j] += matrix1[i][k]*matrix2[k][j];
            }
        }
    }

    return;


}


void transform_point( float vector[3], float matrix[3][3]){

    int i,j;
    float tmp[3];


    for(i=0; i<3; i++){
        tmp[i]= 0;
        for(j=0; j<3; j++){
            tmp[i]+= matrix[i][j]* vector[j];
        }
    }

    for(i=0; i<3; i++){
        vector[i]= tmp[i];
    }

    return ;
}

void print_vector( float vector[3]){

    int i;


    printf("Vector:\n");
    for(i=0; i<3; i++){
        printf("%.3f\n",vector[i]);
    }
    printf("----------------------------------------------------\n");

}

void shift(float vector[3][3]){

    float d1,d2, transformMatrix[3][3];


    init_identity_matrix(transformMatrix);
    printf("Mennyivel toljuk el az x koordinatat?\n");
    scanf("%f",&d1);
    printf("Mennyivel toljuk el az y koordinatat?\n");
    scanf("%f",&d2);
    transformMatrix[0][2] = d1;
    transformMatrix[1][2] = d2;

    transform_point(vector,transformMatrix);

    return;

}

void rotate(float vector[3][3]){

    double angle;
    float transformMatrix[3][3];


    init_identity_matrix(transformMatrix);
    printf("Forgatas merteke: ");
    scanf("%f",&angle);
    transformMatrix[1][1] = (float)cos(angle);
    transformMatrix[1][2] = (float)sin(angle);
    transformMatrix[2][1] = (float)(sin(angle)*(-1.0));
    transformMatrix[2][2] = (float)cos(angle);

    transform_point(vector,transformMatrix);

    return;
}

void scale(float vector[3][3]){

    float transformMatrix[3][3];
    float d1,d2;


    init_identity_matrix(transformMatrix);
    printf("Mennyi legyen az x koordinata atmeretezese?\n");
    scanf("%f",&d1);
    printf("Mennyi legyen az y koordinata atmeretezese?\n");
    scanf("%f",&d2);
    transformMatrix[1][1] = d1;
    transformMatrix[2][2] = d2;

    transform_point(vector,transformMatrix);

    return;
}
