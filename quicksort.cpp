#include <iostream>

int partition(int *V, int inicio, int fim){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = V[inicio];

    while(esq<dir){
        while(V[esq] <= pivo && esq<=fim){
            esq++;
        }
        while(V[dir] > pivo && dir>=0){
            dir--;
        }
        if(esq < dir){
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }
    V[inicio] = V[dir];
    V[dir] = pivo;
    return dir;
}

void quicksort(int *V, int inicio, int fim){
    int pivo;
    if(inicio<fim){
        pivo = partition(V, inicio, fim);
        quicksort(V, inicio, pivo-1);
        quicksort(V,pivo+1,fim);
    }
}


int main(){
    int V[7] = {23, 4, 67, 8, 90, 54, 21};
    quicksort(V, 0, 6);
    for(int i=0; i<7; i++){
        std::cout << V[i] << " ";
    }

    return 0;
}