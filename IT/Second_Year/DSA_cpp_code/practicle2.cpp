#include<iostream>
using namespace std;
class queue
{
private:
    int front ,rear;
    int *arr;
    int n;
public:
  queue(int size)
    {
        n = size;
        arr = new int[n];
        front = rear = -1;
    }
    bool isempty()
    {
        return (front == -1 && rear == -1);
    }
    bool isfull()
    {
        return(front == (rear + 1) %n);
    }
    void intit()
    {
        for(int i =0; i < n - 1 ;i++)
        {
            arr[i] = 0;
        }
    }
 void enqueue ()
     {
      if(isfull ())
      {
	     cout << "Queue is full." << endl;
	     return;
      }
    int no;
    cout << "Enter enqueue:" << endl;
    cin >> no;
    if (isempty())
      {
	     front = 0;
      }
    rear = (rear + 1) % n;
    arr[rear] = no;// if i want print no. then arr[rear]=no. 
  } 
    void dequeue()
    {
       if(isempty())
       {
        cout<<"empty"<<endl;
        return;
       }
       cout<<"delete element :"<<arr[front]<<endl;
       if(front == rear)
       {
        front = rear = -1;
       }
       else
      {
         front = (front+1)%n;
      }
    }
    void show()
    {
        if(isempty())
        {
            cout<<"empty"<<endl;
            return;
        }
        else {
        int i = front;
        cout<<"contain";
        while(true)
        {
            cout<<arr[i]<<" ";
            if(i == rear)
            {
                break;
            }
            i =(i+1)%n;
        }
        cout<<"front :"<<front<<"rear :"<<rear<<endl;
       }
    }

};

int main()
{
  int n;
  cout<<"size :";
  cin>>n;
  queue obj(n);
  
  
     int choice ;
     cout << "enter your choice:" << endl;
      cout << "1.enqueue" << endl;
      cout << "2.dequeue" << endl;
      cout << "3.show enqueue" << endl;
      cout << "4.exit." << endl;
        cout<<"enter choice :"; 
        cin>>choice;
          switch(choice)
        {
            case 1:
            obj.enqueue();
            obj.show();
            break;
            case 2:
            obj.dequeue();
            obj.show();
            break;
            case 3:
            obj.show();
            break;
           default :
           cout<<"exit";
     
    } 

    return 0;
}
