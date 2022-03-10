// Copyright 2021 NNTU-CS
void quickSort(int* array, int low, int high) {
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;

    while (i <= j) {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);
}
int binSearch(int *arr, int left, int right, int number) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == number)
            return binSearch(arr, left, mid-1, number)+
            binSearch(arr, mid+1, right, number)+1;
        else if (arr[mid] > number)
            return binSearch(arr, left, mid-1, number);
        return binSearch(arr, mid + 1, right, number);
    }
    return 0;
}

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int* arr, int len, int value) {
    quickSort(arr, 0, len-1);
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = len-1; j > i; j--) {
            if (arr[i]+arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    quickSort(arr, 0, len-1);
    int count = 0;
    for (int i = 0; i < len; i++) {
        count += binSearch(&arr[i+1], 0, len-i, value - arr[i]);
    }
    return count;
}
