#pragma once
class Beverage
{
public:
    string description = "Unknown Beverage";
    virtual string getDescription()
    {
        return description;
    }
    virtual double cost()=0;
};

class Espresso:public Beverage {
public:
    Espresso()
    {
        description = "Espresso";
    }
    double cost()
    {
        return 10;
    }
};
class HouseBlend:public Beverage {
public:
    HouseBlend()
    {
        description = "HouseBlend";
    }
    double cost()
    {
        return 15;
    }
};
class DarkRoast:public Beverage {
public:
    DarkRoast()
    {
        description = "DarkRoast";
    }
    double cost()
    {
        return 20;
    }
};

class CondimentDecorator:public Beverage {
public:
    virtual string getDescription()=0;
};

class Chocolate:public CondimentDecorator {
public:
    Beverage *beverage;
    Chocolate(Beverage *beverage) {
        this->beverage = beverage;
    }
    string getDescription()
    {
        return beverage->getDescription( ) + ", Chocolate ";
    }
    double cost() {
        return 15 + beverage->cost();
    }
};
class Cream:public CondimentDecorator {
public:
    Beverage *beverage;
    Cream(Beverage *beverage) {
        this->beverage = beverage;
    }
    string getDescription()
    {
        return beverage->getDescription( ) + ", Cream ";
    }
    double cost() {
        return 9 + beverage->cost();
    }
};
class Milk:public CondimentDecorator {
public:
    Beverage *beverage;
    Milk(Beverage *beverage) {
        this->beverage = beverage;
    }
    string getDescription()
    {
        return beverage->getDescription( ) + ", Milk ";
    }
    double cost() {
        return 12 + beverage->cost();
    }
};
