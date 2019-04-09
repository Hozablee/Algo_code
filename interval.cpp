#include<iostream>
#include<algorithm>
using namespace std;
struct Act
{
    int start,finish;
};
bool activityCompare(Act s1,Act s2)
{
    return (s1.finish < s2.finish);
}
int interval(Act arr[], int n)
{
    int c = 0;
    sort(arr,arr+n,activityCompare);
    int i = 0;
    for (int j=1;j<=n;j++)
    {
      if (arr[j].start >= arr[i].finish)
      {
          c++;
          i = j;
      }
    }
    return c;
}
int main()
{
    int n;
    cin >> n;
    Act arr[n];
    for(int i = 0;i<n;i++)
    {
        cin >> arr[i].start >> arr[i].finish;
    }
    cout << interval(arr, n);
}
