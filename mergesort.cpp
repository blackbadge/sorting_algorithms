#include <iostream>
#include <string>

using namespace std;


void merge(int A[], int l, int m, int r){
int i,j, k;
int n1=m-l+1;
int n2=r-m;
int L[n1], R[n2];

for(i=0;i<n1;i++){
    L[i]=A[l+i];
}
for(j=0;j<n2;j++){
    R[j]=A[m+1+j];
}

i=0;
j=0;
k=l;
while(i<n1 && j<n2){
    if(L[i]<=R[j])
   { A[k]=L[i];
    i++;
   }
    else
    {
    A[k]=R[j];
    j++;
    }
    k++;
}

while(i<n1){
    A[k]=L[i];
    
   i++;
    k++;
}
while(j<n2){
    A[k]=R[j];
    j++;
    k++;
}

}





void mergesort(int A[], int l,int r){
   if(l<r)
   { int m;
    m=l+(r-l)/2;
   
     mergesort(A,l,m);
   mergesort(A,m+1,r);
   merge(A,l,m,r);
   
   }   
    }


int main()
{
  int *A;
int n;
cout<<"n:";
cin>>n;

A=(int*)malloc(n*sizeof(n));
for(int i=0;i<n;i++){
    cin>>A[i];
}
mergesort(A,0,n-1);

for(int i=0;i<n;i++){
    cout<<A[i];
}
cout<<"done";
return 0;
}
