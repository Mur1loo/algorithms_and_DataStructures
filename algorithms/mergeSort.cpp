#include <iostream>

void merge(int*, int*, int, int, int);

void mergeSort(int *vetor_original, int *vetor_auxiliar, int inicio, int fim) {
  int meio = (inicio + fim) / 2;
  if (inicio < fim) {
    mergeSort(vetor_original, vetor_auxiliar, inicio, meio);
    mergeSort(vetor_original, vetor_auxiliar, meio + 1, fim);
    merge(vetor_original, vetor_auxiliar, inicio, meio, fim);
  }
}

void merge(int *vetor_original, int *vetor_auxiliar, int inicio, int meio,
           int fim) {
  int left, i, right, k;

  left = inicio;
  i = inicio;
  right = meio+1;

  while ((left <= meio) && (right <= fim)) {
    if (vetor_original[left] <= vetor_original[right]) {
      vetor_auxiliar[i] = vetor_original[left];
      left++;
    } else {
      vetor_auxiliar[i] = vetor_original[right];
      right++;
    }
    i++;
  }

  if (left > meio) {
    for (k = right; k <= fim; k++) {
      vetor_auxiliar[i] = vetor_original[k];
      i++;
    }
  } else {
    for (k = left; k <= meio; k++) {
      vetor_auxiliar[i] = vetor_original[k];
      i++;
    }
  }

  for (int a = inicio; a <= fim ; a++) {
    vetor_original[a] = vetor_auxiliar[a];
  }
}


int main() {

  int tamanho;
  std::cin >> tamanho;

  int vetor_original[tamanho];
  int vetor_auxiliar[tamanho];

  for (int i = 0; i < tamanho; i++) {
    std::cin >> vetor_original[i];
  }

  mergeSort(vetor_original, vetor_auxiliar, 0, tamanho - 1);

  for (int k = 0; k < tamanho; k++) {
    std::cout << vetor_original[k] << " ";
  }

  return 0;
}
