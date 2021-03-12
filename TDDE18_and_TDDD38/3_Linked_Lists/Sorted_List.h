#ifndef LIST_H
#define LIST_H
#include <string>

class Sorted_List{
  private:
      struct node
      {
        int data;
        node *next;
      };	
        /* data */
        node *head, *tail ;
  public:
      Sorted_List()
    {
        head = nullptr;
        tail = nullptr;
    }
    Sorted_List(Sorted_List&& other); //Move constructor
    Sorted_List(Sorted_List const& other); // copy constructor
    Sorted_List& operator=(Sorted_List const& other); // // Copy assignment operator
    Sorted_List & operator=(Sorted_List && other); // move assignment operator
    void createnode(int value); // create a new node 
    void display();    //Display function 
    void insert(int n);// Insert items in order 
    void insert_start(int value);// Insert a node at the begining 
    void insert_end(int value);//insert at the end 
    void insert_position(int pos, int value);// Insert a node in an specific position
    void delete_first();// delete the fist node
    void delete_last();//delete the last node
    void delete_position(int pos);  //delete an specific node 
    bool is_empty();// Check if there is anything in the list!
    std::string to_string();// transform node to string 
    std::string sort();// transform node to string 
    ~Sorted_List();// destructor 
    int size()const; // size of the list

};
#endif
