#include<iostream>
using namespace std;
void insertion_sort(int *arr,int n){
    if(n <= 1) return;
    insertion_sort(arr,n-1);
    int key = arr[n-1]; 
    int j = n-2;
    while(j >= 0 && arr[j] > key){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
}

void merge(int *arr, int low, int mid, int high){
    int i, j, k;
    int left = mid - low + 1;
    int right = high - mid;
    int left_arr[left],right_arr[right]; //Two split arrays
    
    for (i = 0;i<left;i++){ //Populating left array
        left_arr[i] = arr[low+i];
    }

    for (j = 0;j<right;j++){ //Populating right array
        right_arr[j] = arr[mid + j + 1];
    }

    i = 0;
    j = 0;
    k = low;

    while(i < left && j < right){
        if (left_arr[i] <= right_arr[j]){
            arr[k] = left_arr[i];
            i++;
        }
        else{
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }
    while (i < left){
        arr[k] = left_arr[i];
        i++;k++;
    }
    while(j < right){
        arr[k] = right_arr[j];
        j++;k++;
    }
}


void merge_sort(int *arr, int low, int high){
    if (low < high){
        int mid = low + (high - low)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int median3(int *arr, int low,int high){
    int mid = low + (high - low)/2;
    if (arr[low] > arr[mid])
        swap(arr[low],arr[mid]);
    if (arr[low] > arr[high])
        swap(arr[low],arr[high]);
    if (arr[mid] > arr[high])
        swap(arr[mid],arr[high]);
    swap(arr[mid],arr[high-1]);
    return arr[high-1];
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = median3(arr, low, high);
        int i = low - 1;
        int j = high;
        while (true) {
            do {
                i++;
            } while (arr[i] < pivot);
            do {
                j--;
            } while (arr[j] > pivot);
            if (i < j) {
                swap(arr[i], arr[j]);
            } else {
                break;
            }
        }
        swap(arr[i], arr[high - 1]);
        quick_sort(arr, low, i - 1);
        quick_sort(arr, i + 1, high);
    }
}



int main(){
    int array[5] = {5,4,3,2,1};
    int n = sizeof(array)/sizeof(int);
    //quick_sort(array,0,n);
    merge_sort(array,0,n);
    for (int i = 0;i<n;i++){
        cout << array[i];
    }
}