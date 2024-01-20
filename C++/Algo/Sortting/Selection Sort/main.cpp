#include<iostream>
using namespace std;

void selectionSort(int a[], int n){
    int min_id; // here min_id is to store index of minimum number
    for(int i = 0; i < n-1; i++){
        min_id = i;
        for(int j = i+1; j < n; j++){
            if(a[j] < a[min_id]){
                min_id = j;
            }
        }
        if(min_id != i){
            swap(a[min_id],a[i]);
        }
    }
}

void printArray(int a[], int n){ // here a[] is the array and n is the length
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {10, 2, 7, 9, 5};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout << "Before Sorting: ";
    printArray(arr,len);
    selectionSort(arr,len);
    cout << "After Sorting: ";
    printArray(arr,len);
    return 0;
}
