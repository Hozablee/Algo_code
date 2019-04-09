#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct Job
{
    int s, f, p;
};
bool compare(Job s1, Job s2)
{
    return (s1.f < s2.f);
}
int binarySearch(Job jobs[], int index)
{
    int lo = 0, hi = index - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (jobs[mid].f <= jobs[index].s)
        {
            if (jobs[mid + 1].f <= jobs[index].s)
                lo = mid + 1;
            else
                return mid;
        }
        else
            hi = mid - 1;
    }
    return -1;
}
int find_maxP(Job arr[], int n)
{
    sort(arr, arr+n, compare);
    int *table = new int[n];
    table[0] = arr[0].p;
    for (int i=1; i<n; i++)
    {
        int incl = arr[i].p;
        int l = binarySearch(arr, i);
        if (l != -1)
        {
            incl += table[l];
        }
        table[i] = max(incl, table[i-1]);
    }
    int result = table[n-1];
    delete[] table;
    return result;
}

int main()
{
    int n;
    cin >> n;
    Job arr[n];
    for(int i = 0;i<n;i++)
    {
        cin >> arr[i].s >> arr[i].f >> arr[i].p;
    }
    cout << find_maxP(arr, n);

}
