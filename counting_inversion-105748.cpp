#include<iostream>
using namespace std;
int countin(int arr[],int n)
{
    int c = 0;
    for(int i= 0;i<n-1;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                c++;
            }
        }
    }
    return c;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int c = 0;c<n;c++)
    {
        cin >> arr[c];
    }
    cout << countin(arr,n);
}
