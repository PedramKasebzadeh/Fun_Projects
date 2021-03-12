#include<iostream>
#include<vector>
#include<string>
#include"Sorted_List.h"

    void Sorted_List::createnode(int value)
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
    }

    //Display function 
    void Sorted_List::display(){
        node *temp=new node;
        temp=head;
        while(temp!=nullptr)
    {
      std::cout<<temp->data<<"\t";
      temp=temp->next;
    }
    std::cout << std::endl;
  } 


// Insert a node at the begining 
void Sorted_List::insert_start(int value)
{
    node * temp = new node; 
    temp -> next = head;
    temp -> data = value;
    head = temp;
}

//insert at the end 
void Sorted_List::insert_end(int value)
{
    node * temp = new node; 
        temp-> data = value;
        temp-> next = nullptr; 
        tail-> next = temp;
            tail = temp;
}

// Insert a node in an specific position
  void Sorted_List::insert_position(int pos, int value)
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
  void Sorted_List::delete_first()
  {
      node *temp = new node;
      temp=head; 
      head=head->next;
      delete temp;  
  }

//delete the last node
  void Sorted_List::delete_last()
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
      previous -> next = NULL;
  }

  //delete an specific node 
  void Sorted_List::delete_position(int pos)
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
bool Sorted_List::is_empty()
{
	return head==nullptr;
}
// transform node to string 
std::string Sorted_List::to_string(){
    node *cur = new node;
    cur = head;
    std::string object; 
    do{
        object += std::to_string(cur-> data)+  " ";
        cur = cur-> next;
    }
    while(cur != nullptr);
    return object; 
}


// Insert items in increasing order 
void Sorted_List::insert(int n){
    node *input = new node;
    input -> data = n;
    input -> next = nullptr;
    if(this->is_empty()){
        head = input;
        tail = input;
        return;
    }
    if(head->data >= n)
    {
        insert_start(n);
        return;
    } 
    if(tail->data <= n){
    insert_end(n);
    return;
    }
    if (size()==2)
    {       
            head -> next = input;
            input -> next = tail;
            return;
    } 
    node *curr = head;
    while(curr->next != nullptr && curr->next->data < n){
        curr=curr-> next;
    };
    input-> next = curr -> next;
    curr -> next = input;
    return;
}


// copy constructor
 Sorted_List::Sorted_List(Sorted_List const& other) { //
         // perform a deep copy of the lists
         node *temp = other.head;
         while (temp != nullptr )
         {
            insert_end(temp-> data);
            temp = temp->next;
         }
    }



//Move constructor
Sorted_List::Sorted_List(Sorted_List&& other) {
	head = other.head;     // move content from other to this object
	other.head = nullptr;     // remove old content of the list

}

//Move assignment operator
Sorted_List& Sorted_List::operator=(Sorted_List&& other){
    // this -> ~Sorted_List();
    // head = other.head;
    // other.head = nullptr;
    // return this; 
    std::swap(head,other.head);
    return *this;
}

// Copy assignment operator
Sorted_List& Sorted_List::operator=(Sorted_List const& other)
{
    this->~Sorted_List();
	if (other.size() == 0) return *this;


// remove previous list and deep copy other
return *this;
}

int Sorted_List::size() const {
	if (head == nullptr) {
		return 0;
	}
	int n = 0;
	node* curr = head;
	while (curr != nullptr) {
		n += 1;
		curr = curr->next;
	}
	return n;
}


// destructor 
Sorted_List::~Sorted_List()
{
    node * curr = head; 
    while (curr != nullptr){
        node* del = curr; 
        curr = curr -> next; 
        delete del;
    }
    head= nullptr;
}

/*
int main()
{
    Sorted_List obj;
    obj.insert(25);
	obj.insert(50);
    obj.insert(90);
	obj.insert(30);
	//obj.insert(40);
    //obj.insert(37);
    // obj.insert(1);
    obj.display();
    std::cout << "Size of the list"<<std::endl;
    std::cout << obj.size()<<std::endl;
    return 0;
}

*/


/*

    bool p = obj.is_empty();
    std::cout << p <<std::endl;
	obj.createnode(25);
	obj.createnode(50);
	obj.createnode(90);
	obj.createnode(40);
    p = obj.is_empty();
    std::cout << p <<std::endl;
    std::cout << "============ List======\n"<< std::endl;
    obj.display();
    std::cout << "============ Inserting At End======\n"<< std::endl;
    obj.insert_end(37);
    obj.display();
    std::cout << "============ Inserting At begining======\n"<< std::endl;
    obj.insert_start(47);
    obj.display();
    std::cout << "============ Inserting At middle======\n"<< std::endl;
    obj.insert_position(3,100);
    obj.display();
	std::cout<<"----------------Deleting At Start-----------------"<< std::endl;
    obj.delete_first();
    obj.display();
	std::cout<<"-----------------Deleing At End-------------------"<< std::endl;
    obj.delete_last();
    obj.display();
	std::cout<<"--------------Deleting At Particular--------------"<< std::endl;
    obj.delete_position(4);
    obj.display();
    std::cout<<"--------------print them as a string--------------"<< std::endl;
    std::cout << obj.to_string()<<std::endl;
    std::cout<<"--------------print size of the list--------------"<< std::endl;
    // obj.insert(10);
    // obj.insert(15);
    // obj.insert(12);
    // obj.insert(16);
    // obj.insert(13);
    //  obj.insert(4);
    // obj.insert(4);
    // obj.insert(4);
    // obj.insert(3);
    // obj.insert(-1);
    //obj.insert(0);
    //obj.insert(3);
    //Sorted_List obj;
    */