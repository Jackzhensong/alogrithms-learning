#include <bits/stdc++.h>
using namespace std;

/*
int fib(int n){
    if(n==1||n==2)
    return 1;
    else  return fib(n-1)+fib(n-2);
}
*/

int main()
{
    int f1 = 1, f2 = 1, f, k;
    cin >> k;
    if (k == 1 || k == 2)
        cout << f1;
    else
    {
        for (int i = 2; i < k; i++)
        {
            f = f2 + f1;
            f1 = f2;
            f2 = f;
        }
        cout << f;
    }
    return 0;
}