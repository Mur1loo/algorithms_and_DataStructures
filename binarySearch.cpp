#include <iostream>

int binary_search(int *A, int valor, int inicio, int fim){
    if(inicio <= fim){
        int meio = (inicio+fim)/2;
        if(A[meio] == valor){
            return meio;
        }else if(valor < A[meio]){
            return binary_search(A, valor, inicio, meio-1);
        }else{
            return binary_search(A, valor, meio+1, fim);
        }
    }
    return -1;

}

int main(){

    //CÓDIGO DE EXEMPLO
    int V[5] = {1, 34, 63, 76, 92};

    std::cout<< binary_search(V,6,0,4);

    return 0;
}
