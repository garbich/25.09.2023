#include <iostream>
#include <vector>
using namespace std;

class AuthenticationException : public exception
{
public:
    AuthenticationException(string message) : exception(message.c_str()) {}
};

class User {
private:
    string name;
    int password;

public:
    User(string name, int password){
        this->name = name;
        this->password = password;
    }

    string getName(){
        return name;
    }

    int getPassword(){
        return password;
    }
};

class Register {
private:
    vector<User*> users;

public:

    void addUser(User* user){
        users.push_back(user);
    }

    int signIn(){
        string userName;
        int userPassword;

        cout << "Login in your account: " << endl;
        cout << "Name: ";
        cin >> userName;

        cout << "Password: ";
        cin >> userPassword;

        for (int i = 0; i < users.size(); i++){
            if (userName == users[i]->getName()){
                if (userPassword == users[i]->getPassword()){
                    cout << "You are logged into your account!!";
                    return 0;
                }
            }
        }
        throw AuthenticationException("Wrong username or password!");
        signIn();
    }
};





int main()
{
    vector<User*> users;
    Register* regist = new Register();

    try 
    {


        User* user1 = new User("Misha", 12345);
        User* user2 = new User("Kolya", 11111);
        User* user3 = new User("Alex", 121234);
      
        regist->addUser(user1);
        regist->addUser(user2);
        regist->addUser(user3);

        regist->signIn();
    }
    catch (const AuthenticationException& ex)
    {
        cout << ex.what() << endl;
        regist->signIn();
    }

    
}