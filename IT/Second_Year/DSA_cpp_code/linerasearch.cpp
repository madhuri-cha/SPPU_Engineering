#include<iostream>
using namespace std;
int main()
{  
    int array[5];
    cout<<"element =";
    for(int i = 0; i<5 ;i++)
    { 
        cin>>array[i];
    }
    int key;

    cout<<"no you want be search =" ;
    cin>>key;
    int i;
    int index;
 
    int position;
    
    for(i=0;i<5;i++) {
  
    if(array[i]==key)
    {

       
        position = i; 
        cout<<"elementfound="<<key<<"at position"<< position;

        break;
    }

    
    } 
   return 0;
}