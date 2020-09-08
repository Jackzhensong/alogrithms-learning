#include<bits/stdc++.h>
using namespace std;

class Demo
{
    int id;

  public:
    Demo(int i)
    {
        id = i;
        cout << "id=" << id << " constructed" << endl;
    }
    ~Demo()
    {
        cout << "id=" << id << " destructed" << endl;
    }
};

Demo d1(1);

void func()
{
    static Demo d2(2);
    Demo d3(3);
    cout << "func" << endl;
}

int main() 
{
    Demo d4(4);
    d4 = 6;
    cout << "main" << endl;
    {
        Demo d5(5);
    }
    func();
    cout << "main end" << endl;
    return 0;
}