/***************************************************************
* The .h file is the header file.                              *
* This is where we put the class definition, but not actually  *
* implement it. You might think of a header file as similar to * 
* a function prototype.                                        *
***************************************************************/

//Node struct to hold data for singly linked list
struct Node
{
  int data;
  Node * next;

  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

//Queue class definition
class Queue
{
  //Your member variables (data) go in the private section
  private:
    Node * head;
    Node * tail;
    int size;
  
  //Your methods (class functions) go in the public section
  public:
    Queue();
    void Enqueue(int);
    int Dequeue();
    int Peek();
  void Reshuffle();
    void Print();
    bool isEmpty();
};