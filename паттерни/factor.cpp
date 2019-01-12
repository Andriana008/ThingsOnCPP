#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

int KG_FOR_FRUITS_SIK = 2;// per packet
int KG_FOR_VEGS_SIK = 3;
int KG_FOR_FRUITS_PURE = 5;
int KG_FOR_VEGS_PURE = 10;

class Juice
{
public:
    virtual string make_juice()=0;
    virtual int getKGForPack() = 0;
};

class Pure
{
public:
    virtual string make_pure()=0;
    virtual int getKGForPack() = 0;
};

class FruitJuice:public Juice
{
public:
    virtual string make_juice()
    {
        return "FruitJuice";
    }
    int getKGForPack()
    {
        return KG_FOR_FRUITS_SIK;
    }
};

class FruitPure:public Pure
{
public:
    virtual string make_pure()
    {
        return "FruitPure";
    }
    int getKGForPack()
    {
        return KG_FOR_FRUITS_PURE;
    }
};

class VegetableJuice:public Juice
{
public:
    virtual string make_juice()
    {
        return "VegetableJuice";
    }
    int getKGForPack()
    {
        return KG_FOR_VEGS_SIK;
    }
};

class VegetablePure:public Pure
{
public:
    virtual string make_pure()
    {
        return "VegetablePure";
    }
    int getKGForPack()
    {
        return KG_FOR_VEGS_PURE;
    }

};

class Factory
{
protected:
    map <string, int> products;
public:
    Factory(map <string, int> p) : products(p) {};
    virtual Juice* addJuice() = 0;
    virtual Pure* addPure() = 0;

};

class FruitFactory:public Factory
{
public:
    FruitFactory(map <string, int> p) : Factory(p) {}

    virtual Juice* addJuice()
    {
        return new FruitJuice();
    }
    virtual Pure* addPure()
    {
        return new FruitPure();
    }

};
class VegetableFactory:public Factory
{
public:
    VegetableFactory(map <string, int> p) : Factory(p) {}

    virtual Juice* addJuice()
    {
        return new VegetableJuice();
    }
    virtual Pure* addPure()
    {
        return new VegetablePure();
    }
};














