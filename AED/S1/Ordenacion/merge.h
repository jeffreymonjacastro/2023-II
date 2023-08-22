template<typename T>
void merge(T* arr, int start, int middle, int end){
    int i = start; // inicio de la izq
    int j = middle + 1; // inicio de la der
    int k = 0; // contador

    // Array temporal para guardar los valores ordenados
    T* temp = new T[end - start + 1];

    // Comparar los valores de la izq y der
    while (i <= middle && j <= end){
        // Si el valor del array izq es menor que el de la der, lo agrega al array temporal
        if (arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;

        // Si el valor del array der es menor que el de la izq, lo agrega al array temporal
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Si quedan elementos en la mitad izq, los agrega al array temporal
    while (i <= middle){
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Si quedan elementos en la mitad der, los agrega al array temporal
    while (j <= end){
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copia los valores del array temporal al array original
    for (int m = start; m <= end; m++){
        arr[m] = temp[m - start];
    }
}

template<typename T>
void mergeSort(T* arr, int start, int end){
    // Caso base
    if (start == end) return;

    // Hallar la mitad del array
    int middle = (start + end) / 2;

    // Mitad izquierda
    mergeSort(arr, start, middle);

    // Mitad derecha
    mergeSort(arr, middle + 1, end);

    // Merge
    merge(arr, start, middle, end);
}


