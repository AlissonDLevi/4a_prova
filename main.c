#include<stdlib.h>
#include<stdio.h>
#include<math.h>


void rotas(){
    FILE *f = fopen("tourar9152.tour", "r");
    int a, b;
    fscanf(f, "%d", &a);
    fscanf(f, "%d", &b);
    while (!feof(f)){
        printf("Rotas %d %d\n", a, b);
        a = b;
        fscanf(f, "%d", &b);
    }
    fclose(f);
}

int main(){
    FILE *arquivo = fopen("ar9152.tsp", "r");
    int c;
    float la;
    float lg;
    int N = 9152;
    double cidLa[N];
    double cidLg[N];

    double *grafo;
    grafo = (double*)malloc(N*N*sizeof(double));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            grafo[i*N + j] = 0.;
        }
    }
    
    int k=0;
    while (!feof(arquivo))
    {
        fscanf(arquivo, "%d %f %f", &c, &la, &lg);
        cidLa[k] = la;
        cidLg[k] = lg;
        k++;
    }
    fclose(arquivo);
    int menor = sqrt(pow(cidLa[0] - cidLa[1], 2) + pow(cidLg[0] - cidLg[1], 2));
    int cidades[10]; 
    int distancia[10];
    int pMenorJ = 1;
    for (int i =0; i< N;i++){
        if(i != k==0){
           
            pMenorJ = i;
            grafo[i*N + 0] = sqrt(pow(cidLa[0] - cidLa[i], 2) + pow(cidLg[0] - cidLg[i], 2));
            if (grafo[i*N+0] < menor && grafo[i*N+0] != 0){
                menor = grafo[i*N+0]; 
                for(int j =0 ; j<10; j++){
                    for(int d=0; d<10; d++){
                        cidades[j]== pMenorJ;
                        distancia[d]== menor;
                        
                    }
                }
                
            }
        }
    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            printf("%d %d", pMenorJ, menor); 
        }
    }
   
}