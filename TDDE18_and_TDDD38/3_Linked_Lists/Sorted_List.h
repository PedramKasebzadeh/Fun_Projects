#ifndef LIST_H
#define LIST_H
#include <string>

class Sorted_List{
  private:
    struct Node
    {
      int value{};
      Node * next{};
    };
    Node * head{};
    Node * copy(Node const *n)const;
  public:
    Sorted_List();
    Sorted_List(Sorted_List const & other);
    Sorted_List(Sorted_List && other);
    Sorted_List & operator =(Sorted_List const & other);
    Sorted_List & operator =(Sorted_List && other);
    ~Sorted_List();

    bool is_empty() const;    
    void remove(int val);
    void insert(int val);
    void insert(int val, Node* curr);
    int pop();
    int size();
    std::string print_list();


};

#endif