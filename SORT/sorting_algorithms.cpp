#include<iostream>
#include<chrono>

using namespace std;

void bubble_sort(int arr[], int n)
{
    int temp, i , j = 0;
    for (i = 0; i<n-1;i++)
    {
        for (j = 0;j<n-i-1;j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp; 
            }
        }
    }
}

void selection_sort(int arr[], int n) 
{ 
    int i, j, min_idx,temp; 
  
    for (i = 0; i < n-1; i++) 
    { 

        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  

           if(min_idx != i)
           {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
           } 

    } 
}

void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

int main() 
{ 
    int arr[5000],arr1[5000],arr2[5000]; 
    int N = sizeof(arr) / sizeof(arr[0]);  
    int i,j;
    for (i = 0,j = 5000;i < 5000,j>0;i++,j--){
    		arr[i] = j;
    		arr1[i] = j;
    		arr2[i] = j;
    }

    auto start = std::chrono::high_resolution_clock::now();
    bubble_sort(arr, N); 
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "Execution time Bubble sort: " << duration <<"nanoseconds" << std::endl;
		//printArray(arr,N);
		 
    start = std::chrono::high_resolution_clock::now();
    selection_sort(arr1,N);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "Execution time Selection sort: " << duration <<"nanoseconds" << std::endl;
		//printArray(arr1,N);
		 
    start = std::chrono::high_resolution_clock::now();
    insertion_sort(arr2,N);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "Execution time Insertion sort: " << duration <<"nanoseconds" << std::endl;
    //printArray(arr2,N);
    return 0; 
}

