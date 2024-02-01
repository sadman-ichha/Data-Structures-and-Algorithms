#include<iostream>
using namespace std;

class Sort {
private:
    const static int N = 100;
    int a[N];

public:
    Sort(){
        ;
    }

    void store(int n){
        int x;
        int i = 0;
        while(i < n){
            cin >> x;
            a[i] = x;
            i++;
        }
    }

    void print(int n){
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void merge(int p, int q, int r){
        int n1 = q - p + 1;
        int n2 = r - q;
        int L[n1+1];
        int R[n2+1];
        for(int i = 1; i <= n1; i++){
            L[i] = a[p + i - 1];
        }
        for(int j = 1; j <= n2; j++){
            R[j] = a[q + j];
        }
        L[n1+1] = 100000000;
        R[n2+1] = 100000000;
        int i = 1;
        int j = 1;
        for(int k = p; k <= r; k++){
            if(L[i] <= R[j]){
                a[k] = L[i];
                i = i + 1;
            }
            else {
                a[k] = R[j];
                j = j + 1;
            }
        }
    }

    void mergeSort(int p, int r){
        if(p < r){
            int q = (p + r) / 2;
            mergeSort(p,q);
            mergeSort(q+1,r);
            merge(p,q,r);
        }
    }

};

int main(){
    Sort s;
    int n;
    cout << "How many numbers you want to put in: ";
    cin >> n;
    cout << "Enter your numbers for array: ";
    s.store(n);
    cout << "Before Sorting:" << endl;
    s.print(n);
    int p = 0;
    s.mergeSort(p,n);
    cout << "After Sorting:" << endl;
    s.print(n);
    return 0;
}




