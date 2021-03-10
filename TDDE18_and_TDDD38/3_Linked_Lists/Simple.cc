#include<iostream>
using namespace std;

class List
{
public:
    // constructor
    List()
    {
        head = nullptr;
        tail = nullptr;
    }
    /*
    List(List const& other) { //copy constructor
         // perform a deep copy of the lists
    }
    //destructor   goes through each node in our list and calls delete on them
    ~List()
    {
    }
    List& operator=(List const& other); // copy assignment operator
    void remove()
    {
       Node * temp=first;
       first = first -> next;
       delete temp;
    }
     List(List&& other) // Move constructor (to limit copy pasting )
    {
    // perform the move by shuffling the first pointers
    // remove old content of the list
    // move content from other to this object
    }
    */

    void createnode(int value)
    {
        node * temp = new node; 
        temp-> data = value;
        temp-> next = nullptr; 
        if(head==nullptr){
            head= temp;
            tail = temp;
        } else {
            tail-> next = temp;
            tail = temp;
        }
        // node *temp = new node;// Node * temp{new Node{value}};
        // temp-> data = value;
        // temp -> next = NULL;
        // if(head==NULL){
        //     head = temp;
        //     tail = temp;
        //     temp = NULL;
        // }
        // else{
        //     tail -> next = temp;
        //     tail=temp;
        // }
    }

    //Display function 
    void display(){
        node *temp=new node;
        temp=head;
        while(temp!=nullptr)
    {
      cout<<temp->data<<"\t";
      temp=temp->next;
    }
    cout << endl;
  } 


// Insert a node at the begining 
void insert_start(int value)
{
    node * temp = new node; 
    temp -> next = head;
    temp -> data = value;
    head = temp;
}

//insert at the end 
void insert_end(int value)
{
    node * temp = new node; 
        temp-> data = value;
        temp-> next = nullptr; 
        tail-> next = temp;
            tail = temp;
}

// Insert a node in an specific position
  void insert_position(int pos, int value)
  {
    node * pre=new node;
    node * cur=new node;
    node * temp=new node;
    temp->data=value;
    cur=head;
    for(int i=1; i<pos; i++)
    {
      pre=cur;
      cur=cur->next;
    }
    pre->next=temp;	
    temp->next=cur;
    delete cur;
  }

// delete the fist node
  void delete_first()
  {
      node *temp = new node;
      temp=head; 
      head=head->next;
      delete temp;  
  }
//   void delete_first()
//   {
//     node *temp=new node;
//     temp=head;
//     head=head->next;
//     delete temp;
//   }

//delete the last node
  void delete_last()
  {
      node *current=new node;
      node *previous=new node;
      current = head;
      while(current-> next != nullptr){
          previous = current;
          current = current-> next;
      }
      delete current;
      tail= previous;
      //previous -> next = NULL
  }

  //delete an specific node 
  void delete_position(int pos)
  {
      node *current=new node;
      node *previous=new node;
      current = head; 
      for(int i=1; i< pos; i++)
      {
          previous = current;
          current = current -> next;
        }
        previous-> next = current-> next;
        delete current;
  }


// Check if there is anything in the list!
bool is_empty()
{
	return head==nullptr;
}


// to string 

string to_string(){
    node *cur = new node;
    node *pre = new node;
    cur = head;
    string object; 
    while(cur->next != nullptr)
    {
        pre = curr
        object += std::to_string(cur-> data);
        object += "\t";
        cur = cur-> next;
    }
    return object; 
}


    
private:
    struct node
  {
    int data;
    node *next;
  };	
    /* data */
    node *head, *tail ; 
};


int main()
{
    List obj;
    bool p = obj.is_empty();
    cout << p <<endl;
	obj.createnode(25);
	obj.createnode(50);
	obj.createnode(90);
	obj.createnode(40);
    p = obj.is_empty();
    cout << p <<endl;
    cout << "============ List======\n"<< endl;
    obj.display();
    cout << "============ Inserting At End======\n"<< endl;
    obj.insert_end(37);
    obj.display();
    cout << "============ Inserting At begining======\n"<< endl;
    obj.insert_start(47);
    obj.display();
    cout << "============ Inserting At middle======\n"<< endl;
    obj.insert_position(3,100);
    obj.display();
	cout<<"----------------Deleting At Start-----------------"<< endl;
    obj.delete_first();
    obj.display();
	cout<<"-----------------Deleing At End-------------------"<< endl;
    obj.delete_last();
    obj.display();
	cout<<"--------------Deleting At Particular--------------"<< endl;
    obj.delete_position(4);
    obj.display();
    cout << obj.to_string()<<endl;
    return 0;
}
