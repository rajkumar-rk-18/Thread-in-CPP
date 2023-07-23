#include <iostream>
#include<thread>//Include thread
#include<mutex>//Include mutex

using namespace std;
mutex m; //Declare mutex

//Thread 1
void fun1(int a)
{
    m.lock();//This mutex lock helps to prevent multiple accessing
    cout<<"Even numbers "<<endl;
    for(int i=1;i<=a;i++)
    {
        if(i%2==0)
            cout<<i<<" ";
    }
    cout<<endl;
    m.unlock();//This mutex unlock gives the access to next thread
}

//Thread 2
void fun2(int a)
{
    m.lock();
    cout<<"Odd numbers"<<endl;
    for(int j=1;j<=a;j++)
    {
        if(j%2!=0)
            cout<<j<<" ";
    }
    cout<<endl;
    m.unlock();
}
int main()
{
    int n;//n refers to the range of numbers
    cout<<" Main function starts "<<endl;
    cout<<"Enter range"<<endl;
    cin>>n;
    thread t1(&fun1,n);
    thread t2(&fun2,n);

    t1.join();//t1.join waits untill thread 1 completed
    t2.join();//t2,join will wait for thread 2 to complete
    cout<<"Main Function ends"<<endl;
    return 0;
}
