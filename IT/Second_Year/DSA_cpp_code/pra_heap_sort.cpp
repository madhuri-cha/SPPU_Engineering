#include <iostream>
using namespace std;

class Minheap
{
public:
  int *array;
  
  int capacity;
  int heap_size;

public:
  Minheap(int cap)
  {
    heap_size = 0;
    capacity = cap;
    array = new int[cap];
  }

  int parent(int i)
  {
    return (i - 1) / 2;
  }

  int left_child(int i)
  {
    return (2 * i + 1);
  }

  int right_child(int i)
  {
    return (2 * i + 2);
  }

  int getMinvalue()
  {
    return array[0];
  }

  int insert(int key)
  {
    if (heap_size == capacity)
    {
      cout << "Overflow \n";
    }

    heap_size++;
    int i = heap_size - 1; // beacuse element is stored at last position
    array[i] = key;
    // for maintaninig min heap property we use while loop
    while (i != 0 && array[parent(i)] > array[i])
    {
      int temp;
      temp = array[i];
      array[i] = array[parent(i)];
      array[parent(i)] = temp;
      i = parent(i);
    }
  }

  
  int display()
  {
    for (int i = 0; i < heap_size; i++)
    {
      cout << array[i] << endl;
    }
  }
};
int main()
{
  int n;
  cout << "Enter no of element to be sort " << endl;
  cin >> n;
  cout << "Heap is created \n";
  Minheap obj(n);
     int choice;
  int val;

  while (choice != 3)

  {
  
    cout << "enter : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Insert Opertion \n";
      cout << "Insert the value : ";
      cin >> val;
      obj.insert(val);
      break;

    case 2:
      cout << " Get min value : \n ";
      cout<< obj.getMinvalue()<<endl;
      cout << "Sorting is : ";
      obj.display();
      break;
    
    default:
      cout << "done !!";
    }
  }
  return 0;
}