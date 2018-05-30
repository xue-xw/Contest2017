#include "contest.h"
#include<stdio.h>
using namespace std;
struct Activitiy
{
    long start, finish;
};

bool activityCompare(Activitiy s1, Activitiy s2)
{
    return (s1.finish < s2.finish);
}

void printMaxActivities(Activitiy arr[], int n)
{
    sort(arr, arr+n, activityCompare);
    int cnt = 1;
    int i = 0;
    for (int j = 1; j < n; j++)
    {
      if (arr[j].start > arr[i].finish)
      {
          i = j;
          cnt++;
      }
    }
    cout<<cnt;
}

int main()
{
    int n;
    cin>>n;
    Activitiy arr[n+1];
    for (int i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].finish;
    }
    printMaxActivities(arr, n);
    return 0;
}
