#include "contest.h"
#include<stdio.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long a[n+1];
    int from[n+1];

    for (int i=1;i<=n;i++){
        cin>>from[i];
        a[i]=2;
    }
    for (int i=2;i<=n;i++) {
      for (int j=from[i];j<=i-1;j++) {
        a[i]=(a[i]+a[j]) % 1000000007;
      }
    }
    long ans=0;
    for (int i=1;i<=n;i++) {
      ans=(ans+a[i])%1000000007;
    }
    cout<<ans;

    return 0;
}
