
void merge(int* arr, int start, int middle, int end){
    int i = start;
    int j = middle + 1;
    int k = 0;

    int* temp = new int[end - start + 1];

    while (i <= middle && j <= end){
        if (arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= middle){
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= end){
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int m = start; m <= end; m++){
        arr[m] = temp[m - start];
    }

    delete [] temp;
}

void mergeSort(int* arr, int start, int end){
    if (start == end) return;
    int middle = (start + end) / 2;

    mergeSort(arr, start, middle);

    mergeSort(arr, middle + 1, end);

    merge(arr, start, middle, end);
}

