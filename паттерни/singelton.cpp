/*
 Результати розв’язування задачі:
 1) UML-діаграма класів;
 2) реалізація на С++,
 3) Рев’ю напарника, зауваження виправити і додати до розв’язку
 «Патерн Singleton». Розорбити консольну програму, що дозволяє ввести дані для аутентифікації користувача (логін, пароль). У випадку успішної аутентифікації вивести повідомленння «Welcome < user login >», а у випадку невдалої аутентифікації – повідомлення про помилку. Персональні дані аутентифікованого користувача повинні бути заявлені як об'єкт в одному екземплярі (тобто Singleton).
*/

#include <iostream>
#include <string>
#include <set>

using namespace std;

//TODO class user ,not fields in class session
//DONE

class User
{
public:
    string login;
    string password;
    User()
    {
        login="";
        password="";
    }
    User(string l,string p)
    {
        this->login=l;
        this->password=p;
    }
    void create_user()
    {
        cout<<"Registration in our system"<<endl;
        cout<<"Enter login"<<endl;
        cin>>login;
        cout<<"Enter password"<<endl;
        cin>>password;
    }
};

class Session
{
private:
    static Session* instance;
    User user;
    Session(const User& u)
    {
        this->user=u;
    }
public:
    static Session* get_instance(const User& user)
    {
        
        instance = new Session(user);
        if(instance==nullptr)
        {
            instance = new Session(user);
        }
        return instance;
    }
    static void exit()
    {
        instance=nullptr;
    }
};

Session* Session::instance = 0;

//TODO seperate function not method of class
//DONE

void login(const User& real_user)
{
    cout<<"Cheking registration in our system"<<endl;
    cout<<"Enter login and password"<<endl;
    string entered_login,entered_password;
    cin>>entered_login>>entered_password;
        if(entered_login==real_user.login && entered_password==real_user.password)
        {
            Session::get_instance(real_user);
            cout<<"Welcome user :"<<real_user.login<<endl;
        }
        else
        {
            cout<<"This user "<<entered_login<<" doesnt exist at the program"<<endl;
        }
}
void logout()
{
    Session::exit();
    cout<<"goodbye"<<endl;
}

int main()
{
    User user1;
    
    user1.create_user();
    
    login(user1);
}
