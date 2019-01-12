/*Визначити два типи «Працівник» (ПІП, посада, зарплата) тa
 «Учень» (ПІП, група, спеціальність).
 Визначити тип «ПТУ» (назва,адреса, список працівників та
 список учнів).
 В текстовому файлі задано дані про 3 ПТУ міста.
 Зчитати дані у масив і вивести у Файл1 список всіх
 спеціальностей даного ПТУ (без повторів)
 та вказати кількість учнів за кожною спеціальністю.
 Видрукувати у Файл2 посортованих за зарплатою всіх
 працівників того ПТУ, в якому навчаються найбільше
 студентів.
 */
#pragma once
class Worker
{
private:
    string name;
    string position;
    int salary;
public:
    Worker()
    {
        this->name=" ";
        this->position=" ";
        this->salary=0;
    }
    Worker(string n,string p,int s)
    {
        this->name=n;
        this->position=p;
        this->salary=s;
    }
    Worker(const Worker &x)
    {
        this->name=x.name;
        this->position=x.position;
        this->salary=x.salary;
    }
    string getName()
    {
        return name;
    }
    string getPos()
    {
        return position;
    }
    int getSalary()
    {
        return salary;
    }
    virtual void print()
    {
        cout<<this->name<<" "<<this->position<<" "<<this->salary;
    }
    virtual void input(ifstream& file)
    {
        file>>this->name;
        file>>this->position;
        file>>this->salary;
    }
    virtual void output(ostream& file)
    {
        file<<"name "<<this->name;
        file<<"position "<<this->position;
        file<<"salary "<<this->salary;
    }
    
};

class Student
{
private:
    string name;
    int group;
    string specialization;
public:
    Student()
    {
        this->name=" ";
        this->specialization=" ";
        this->group=0;
    }
    Student(string n, string s,int g)
    {
        this->name=n;
        this->specialization=s;
        this->group=g;
    }
    Student(const Student & x)
    {
        this->name=x.name;
        this->specialization=x.specialization;
        this->group=x.group;
    }
    string getName()
    {
        return name;
    }
    string getSpec()
    {
        return specialization;
    }
    int getGroup()
    {
        return group;
    }
    
    virtual void print()
    {
        cout<<this->name<<" "<<this->specialization<<" "<<this->group;
    }
    virtual void input(ifstream &file)
    {
        file>>this->name;
        file>>this->specialization;
        file>>this->group;
    }
    virtual void output(ostream &file)
    {
        file<<"name "<<this->name;
        file<<"specialization "<<this->specialization;
        file<<"group "<<this->group;
    }
    
};


class PTY:
{
private:
    string name;
    string adress;
    Worker* arr1;
    int size1;
    Student* arr2;
    int size2;
public:
    PTY()
    {
        this->name=" ";
        this->adress=" ";
        Worker();
        Student();
    }
    string getName()
    {
        return name;
    }
    string getAdress()
    {
        return adress;
    }
    int getS()
    {
        return size1;
    }
    int getW()
    {
        return size2;
    }
    void print()
    {
        for(int i=0;i<size1;i++)
        {
           Worker[i].print();
        }
        for(int i=0;i<size2;i++)
        {
            Student[i].print();
        }
        cout<<"name "<<this->name;
        cout<<"adress "<<this->adress;
    }
    virtual void input(ifstream & file)
    {
        Worker::input(file);
        Student::input(file);
        file>>this->name;
        file>>this->adress;
    }
    virtual void output(ostream & file)
    {
        Worker::output(file);
        Student::output(file);
        file<<this->name;
        file<<this->adress;
    }

    
};






















