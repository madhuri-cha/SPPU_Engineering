#include<iostream>
using namespace std;
int main() {
    
  
    int arr[20];
    int n;
    cout<<"enter no  element ="<<endl;
    cin>>n;
   
    cout<<"array";
    for(int i =0 ; i< n ;i++)
    { 
      cin>>arr[i];

    }
    for( int k = 1;k < 3;k++)
    {
     int temp = arr[k];
     int j = k-1;
   
    while(temp <= arr[j] && j>=0) {
     arr[j+1] = arr[j];
     j = j-1;
       }
    arr[j+1] = temp;
    }
    
   cout<<"sorting array";
    for(int i = 0 ; i < n ; i++)
    { 
        cout<<arr[i]<<"\t";

    }
      return 0;
}

