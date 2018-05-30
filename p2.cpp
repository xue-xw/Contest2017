#include "contest.h"
#include<stdio.h>
using namespace std;

int main()
{
  int n;
  cin>>n;

  int rank[n+1],suit[n+1];
  for (int i=1;i<=n;i++) {
    char ch;
    cin>>ch;
    if (2<=ch && ch<=9) rank[i]=int(ch);
    if (ch=='A')rank[i]=1;
    if (ch=='T')rank[i]=10;
    if (ch=='J')rank[i]=11;
    if (ch=='Q')rank[i]=12;
    if (ch=='K')rank[i]=13;
    cin>>ch;
    if (ch=='s') {suit[i]=1;}
    if (ch=='h') {suit[i]=2;}
    if (ch=='c') {suit[i]=3;}
    if (ch=='d') {suit[i]=4;}
  }
  int f[60][5];
  for (int i=1;i<=n;i++) {
    f[i][1]=0;
    f[i][2]=0;
    f[i][3]=0;
    f[i][4]=0;
    f[i][suit[i]]=1;
    int max1=1,k1;
    for (int j=1;j<i;j++) {
      if (suit[j]==suit[i] && rank[j]<rank[i]){
        if (f[j][suit[i]]>max1){
          max1=f[j][suit[i]];
          k1=j;
        }
      }
    }
    int max2=1,k2;
    for (int j=1;j<i;j++) {
      if (suit[j]!=suit[i] && f[j][suit[i]]==0) {
        if (f[j][suit[j]]>max2){
          max2=f[j][suit[j]];
          k2=j;
        }
      }
    }
    if (max1>max2) {
      f[i][1]=f[k1][1];
      f[i][2]=f[k1][2];
      f[i][3]=f[k1][3];
      f[i][4]=f[k1][4];
      f[i][suit[i]]=max1+1;
    } else{
      f[i][1]=f[k2][1];
      f[i][2]=f[k2][2];
      f[i][3]=f[k2][3];
      f[i][4]=f[k2][4];
      f[i][suit[i]]=max2+1;
    }
  }
  int max=-1;
  for (int i=1;i<=n;i++){
    if(f[i][1]>max)max=f[i][1];
    if(f[i][2]>max)max=f[i][2];
    if(f[i][3]>max)max=f[i][3];
    if(f[i][4]>max)max=f[i][4];
  }
  cout<<n-max;
  return 0;
}
