/*Патерн “Прототип”. Розробити програму для утворення екзаменаційної відомості: студенти-оцінки певної групи, предмет, викладач. Передбачити можливість клонування відомостей, та метод очищення даних про оцінки, зміну предмета та зміна викладача. Передбачити пул відомостей за групами, з якого можна брати відомості і клонувати для інших предметів
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<string>
using namespace std;

struct StudentPoint
{
    string name;
    int points;
    StudentPoint() :name(""), points(0) {};
    StudentPoint(string n, int p) : name(n), points(p) {};
};


class INote
{
public:
    virtual INote* clone() = 0;
    virtual void getInfo() = 0;
    virtual void deleteAllPoints() = 0;
    virtual void changeSubject(string s) = 0;
    virtual void changeTeacher(string n) = 0;
    virtual void addStudent(StudentPoint sp) = 0;
};

class Note : public INote
{
private:
    vector<StudentPoint> students;
    string subject;
    string teacherName;
public:
    Note() : students(0), subject(""), teacherName("") {};
    Note(string subject, string teacherName, StudentPoint sp) :subject(subject), teacherName(teacherName)
    {
        this->students.push_back(sp);
    };
    Note(string subject, string teacherName, vector<StudentPoint> sp) :subject(subject), teacherName(teacherName)
    {
        this->students.swap(sp);
    };
    Note(Note& note)
    {
        this->subject = note.subject;
        this->teacherName = note.teacherName;
        this->students.clear();
        this->students.swap(note.students);
    }
    void addStudent(StudentPoint sp)
    {
        this->students.push_back(sp);
    }
    
    void deleteAllPoints()
    {
        for_each(this->students.begin(), this->students.end(), [&](StudentPoint sp) {sp.points = 0; });
    }
    
    void changeSubject(string newSubject)
    {
        this->subject = newSubject;
    }
    
    void changeTeacher(string newTeacher)
    {
        this->subject = newTeacher;
    }
    
    size_t getStudentsQuantity()
    {
        return this->students.size();
    }
    
    INote* clone()
    {
        return new Note(this->subject, this->teacherName, this->students);
    }
    
    void setData(ifstream& ifs)
    {
        ifs >> this->subject;
        ifs >> this->teacherName;
        int studentsAmount;
        ifs >> studentsAmount;
        StudentPoint tmp;
        while (studentsAmount--)
        {
            ifs >> tmp.name;
            ifs >> tmp.points;
            this->students.push_back(tmp);
        }
    }
    
    void getInfo()
    {
        cout << "subject : " << this->subject<<"\n";
        cout << "teacher : " << this->teacherName<<"\n";
        cout << "group list :\n";
        for(auto item=students.begin();item!=students.end();item++)
        {
            cout << (*item).name << " - " << (*item).points << "\n";
        }
        cout << "______________________\n";
    }
};

vector<Note*> NOTES;

class DataPull
{
private:
public:
    static void CREATEPULL()
    {
        ifstream ifs("/Users/Andriana/Desktop/dz_programming/2 year/Prototype1/Prototype1/data.txt");
        if (!ifs.is_open() )
        {
            throw fstream::failure("can not create pull from file\n");
        }
        Note* tmp = new Note();
        while (!ifs.eof())
        {
            tmp->setData(ifs);
            NOTES.push_back(tmp);
            tmp = new Note();
        }
        delete tmp;
    }
    
    static Note* getNoteByCode(size_t code)
    {
        
        auto it = find_if(NOTES.begin(), NOTES.end(), [&](Note* item) {return item->getStudentsQuantity() == code; });
        
        return new Note(**it);
    }
    
};



int main()
{
    try
    {
        DataPull::CREATEPULL();
        INote* note = DataPull::getNoteByCode(2);
        INote* cloned = note->clone();
        note->getInfo();
        cloned->getInfo();
        note = DataPull::getNoteByCode(3);
        note->getInfo();
        cloned->getInfo();
        note->addStudent(StudentPoint("rrr",32));
        note->getInfo();
        cloned->getInfo();
    }
    catch (exception e)
    {
        cout << e.what();
    }
    system("pause");
    return 0;
}

