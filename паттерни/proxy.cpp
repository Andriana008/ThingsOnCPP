/*14. Патерн  Proxy. Розробити класи для роботи з банківським клієнтським рахунком через кредитну картку. Продемонструвати роботу на прикладі.
*/
#include <iostream>
#include <vector>


using namespace std;

class ICard
{
protected:
    int balance;
public:
    virtual int checkBalance()=0;
    virtual int getMoney(int amount)=0;
    virtual int addMoney(int amount)=0;
    
};



class Card:public ICard
{
public:
    int checkBalance()
    {
        return balance;
    }
    int getMoney(int amount)
    {
        balance-=amount;
        if(balance<0)
        {
            throw invalid_argument("not enough money on account");
        }
        return balance;
    }
    int addMoney(int amount)
    {
        balance+=amount;
        return balance;
    }
};

class ProxyCard:public ICard
{
private:
    ICard *card;
 
public:
    ProxyCard() : card(new Card()) {
        balance = 0;
    }
    int checkBalance()
    {
        return card->checkBalance();
    }
    int getMoney(int amount)
    {
       return card->getMoney(amount);
    }
    int addMoney(int amount)
    {
       return card->addMoney(amount);
    }
};

int main()
{
 
    ICard *privat = new ProxyCard();
    cout<<privat->addMoney(100)<<endl;
    cout<<privat->checkBalance()<<endl;
    cout<<privat->getMoney(20)<<endl;
    cout<<privat->checkBalance()<<endl;
}
/*
//
//  main.cpp
//  Proxy
//
//  Created by Олег-Андрій Жук on 26.12.17.
//  Copyright © 2017 Олег-Андрій Жук. All rights reserved.
//

#include <iostream>
using namespace std;

class SuperBank {
protected:
    int curentMoney;
public:
    virtual ~SuperBank() {
        
    }
    virtual int cashState() = 0;
    virtual bool takeMoney(int) = 0; // true if success
    virtual void putMoney(int) = 0;
};

class RealBank : public SuperBank {
    int cashState() override
    {
        return curentMoney;
    }
    bool takeMoney(int ammount) override // true if success
    {
        if (ammount < curentMoney)
        {
            curentMoney -= ammount;
            return true;
        } else
        {
            return false; // not enough money
        }
    }
    void putMoney(int ammount) override
    {
        curentMoney += ammount;
    }
};

class Creditka : public SuperBank{
private:
    SuperBank *bank;
public:
    Creditka() : bank(new RealBank()) {
        curentMoney = 0;
    }
    virtual ~Creditka()
    {
        delete bank;
    }
    virtual int cashState()
    {
        cout << "На рахунку " << bank -> cashState() << " грн. Гарного дня!\n";
        return bank -> cashState();
    }
    virtual bool takeMoney(int ammount) // true if success
    {
        int newAmmount = ammount * 1.1; // відсоток за транзакцію ;)
        if (bank -> takeMoney(newAmmount))
        {
            cout << "Гроші знято! Комісія: " << ammount/10 << " грн.\n";
            return true;
        } else
        {
            cout << "Невдача. Недостатньо коштів на рахунку! (життя — це біль! )\n";
            return false; // not enough money
        }
    }
    virtual void putMoney(int ammount)
    {
        int newAmmount = ammount * 0.9;
        cout << "Успіх! Нараховано " << newAmmount << " грн. Комісія: " << ammount/10 << " грн. \n";
        bank -> putMoney(newAmmount);
    }
};

int main()
{
    SuperBank *privat = new Creditka();
    privat->putMoney(100);
    privat->cashState();
    privat->takeMoney(50);
    privat->cashState();
    
    return 0;
}
*/













