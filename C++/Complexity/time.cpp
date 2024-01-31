#include <iostream>
using namespace std;

int main()
{   
    int i =0,j=0;
    int n = 3;
    for (i = 1; i <= n; i++)
    {
        
        for ( j = 1; j <= i * i; j++)
        {
            cout << j << " Ichha" << endl;
        }
    }

    return 0;
}
