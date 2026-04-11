#include<iostream>
using namespace std;
int main() {
int low,high,mid;
int array[5];
cout<<"element"<<endl;
for(int i = 0;i<5; i++){
 cin>>array[i];
}   
int key;
cout<<"the no you want to be search =";
cin>>key;
 
low = 0;
high = 4;
mid =  (low + high)/2;

while(low<=high)
{

 if(  array[mid] < key)
 { low = mid+1;
    
 }
else if(array[mid] == key) 
 {
  cout<<"element found :"<<key;
  break;
 }
else
 
 high = mid - 1;
 

mid = (low+high)/2;
 }  
if(low > high)
cout<<"\n the num not fnd"<<key;
cout<<endl;
return 0; 
 }