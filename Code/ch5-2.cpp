#include<bits/stdc++.h> //矩阵转置
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n][m],b[m][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cin >> a[i][j];

    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            b[i][j] = a[j][i];
            cout << b[i][j] <<" ";
        }
        cout<<endl;
    }
    return 0; 
}