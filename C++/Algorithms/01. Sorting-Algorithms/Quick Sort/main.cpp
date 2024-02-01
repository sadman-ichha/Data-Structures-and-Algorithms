#include<iostream>
using namespace std;

int partition(int arr[], int p, int r){
    int x = arr[r];
    int i = p - 1;
    for(int j = p; j <= r-1; j++){
        if(arr[j] <= x){
            i = i+1;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}

void quickSort(int arr[], int p, int r){
    if(p < r){
        int q = partition(arr,p,r);
        quickSort(arr,p,q-1);
        quickSort(arr,q+1,r);
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    int arr[] = {7,8,6,1,0,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Before Sorting: ";
    printArray(arr,n);
    quickSort(arr,0,n-1);
    cout << "After Sorting: ";
    printArray(arr,n);
    return 0;
}
