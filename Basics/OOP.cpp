#include <iostream>
#include <vector>

class User
{
    std::string status="Gold";
    public:
        std::string First_name;
        std::string Last_name;
        std::string get_status()
        {
            return status; 
        }
        User(std::string First_name, std::string Last_name)
        {
            this-> First_name=First_name;
            this->Last_name=Last_name;
        }
};

int add_user_if_not_exist(std::vector<User> &users, User user)
{
    for(int i=0; i <users.size(); i++)
    {
        if(users[i].First_name==user.First_name &&
           users[i].Last_name==user.Last_name)
        {
            return i;
        }
    }
    users.push_back(user);
    return users.size()-1;
}
int main()
{
     
    return 0;
}

/*
std::vector<User> users;
   // users.push_back(User());

    User user1, user2, user3;
    user1.First_name = "ped"; 
    user1.Last_name = "kas"; 
    
    user2.First_name = "par"; 
    user2.Last_name = "kas"; 
    
    user3.First_name = "kam"; 
    user3.Last_name = "rad"; 

    users.push_back(user1);
    users.push_back(user2);
    users.push_back(user3);

    User user;
    user.First_name = "ped";
    user.Last_name = "kase";
   
    std::cout << add_user_if_not_exist(users,user) << std::endl;
    */