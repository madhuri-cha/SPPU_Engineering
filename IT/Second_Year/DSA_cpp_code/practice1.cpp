#include<iostream>
using namespace std;

struct stud
{
    int rollno;
    string name;
    float sgpa;

};
class info
{
    public :
    struct stud s[20];
    int n;
    void getdata()
    {
        cout<<"enter student";
        cin>>n;
       for( int i=0;i < n ;i++)
       {
              cin>>s[i].rollno;
              cin>>s[i].name;
              cin>>s[i].sgpa;
        }
    }
    
    void bubblesort()
    {   struct stud temp;
        for( int i = 0; i<=n-1;i++)
       {
          for( int j = 0; j < n-1-i;j++)
           {
            if(s[j+1].rollno <  s[j].rollno )
            {
             temp = s[j];
             s[j] = s[j+1];
             s[j+1] = temp;  
            }
           }
       }
    }
    
    void insertionsort()
    {
        int i;
         int j;
        struct stud key;
       for( i =1;i < n ; i ++)
       {
        key = s[i];
        j = i-1;
        for( j = 0;j > n;j--)
        {
          if( j >= 0 && (s[j].name > key.name) )
          {
            s[j+1] = s[j];
            j--;
          }
          s[j+1] = key;
        }
        
       }
    }
     void display()
    {
        cout<<"enter info :";
        for(int i = 0 ; i<n ;i++)
        {
            cout<<s[i].rollno<<"\t";
            cout<<s[i].name<<"\t";
            cout<<s[i].sgpa;
            cout<<"\n";
        }
    }
   void quicksort(int start , int end)
   {
     int i,j;
     int pivote;
     struct stud temp;
     if(start<end)
     {
    
        while(i<j)
        {  
             pivote = start;
            i = start;
            j = end;
            if(s[i].sgpa >= s[pivote].sgpa)
            {
             i++;
            }
            if(s[j].sgpa < s[pivote].sgpa)
            {
                j--;
            }
            if (i<j)
            {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            }
        }
        temp = s[pivote];
             s[pivote]=s[j];
             s[j]= temp;
             quicksort(start , j-1);
             quicksort(j+1,end);
     }
 }
   void linearsearch(float element)
   {
    int i;
    for( i = 0; i < n;i++)
     {
        if(s[i].sgpa == element)
        {
            cout<<"found";
        }
       
     }
 }
   void binarysearch(string key)
   {
    int low = 0;
    int high = n-1;
    int mid;
   
    
     int found = 0;
    while(low<=high)
    {  mid =(low + high)/2;
        if(s[mid].name == key)
        {
            
            found =1;
        }
        if(s[mid].name < key)
        {
            low = mid+1;
        }
        else
         {high = mid-1;}
    }
    if(found==1)
    {
        cout<<"found";
    }
    else 
  {  cout<<"not found"; }
}

};
int main()
{
    info obj;
    int choice;
    int element;
    string key;
    do {
    cout<<"choice";
    cin>>choice;
    
    switch(choice)
      {
      case 1:
       obj.getdata();
       obj.bubblesort();
     obj.display();
    break;

    case 2:
     obj.getdata();
    obj.insertionsort();
    obj.display();
    break;

    case 3 :
     obj.getdata();
     obj.quicksort(0,obj.n-1);
     obj.display();
     break;

    case 4 :
     obj.getdata();
     cout<<"sgpa";
     cin>>element;
     obj.linearsearch(element);
     obj.display();
     break;

    case 5 :
     obj.getdata();
     cout<<"key";
     cin>>key;
     obj.bubblesort();
     obj.binarysearch(key);
     obj.display();
     break;
      
     
    }

 }while(choice!=6);

    return 0;
}
