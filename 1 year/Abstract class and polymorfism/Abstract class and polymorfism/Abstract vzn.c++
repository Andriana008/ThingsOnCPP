/*Визначити абстрактний тип для представлення Навчального закладу, похідні абстрактні Вищий н.з., Середній н.з. Та відповідні похідні Університет, Академія, Школа. Ввести дані про 10 навчальних закладів. Вивести їх у алфавітному порядку назв. Вивести ті вищі н.з., кількість студентів в яких перевищує задане число.
*/

#include <iostream>
#include <string>
using namespace std;
 
 int main()
{
	EducationCenter*edu[10];
	char s;
	for(int i=0;i<10;i++)
	{
	   cin>>s;
	   switch(s)
	   case 1:edu[i]=new Vzn;
	       edu[i]->input();
	
	
	
	return 0;
}
 
class EducationCenter
{
	protected:
		string name;
	public:
			EducationCenter():name(" "){};
			virtual void print()=0;
			virtual ~EducationCenter()
			{
			 this->name.clear();	
			 }
};
class Vnz:public EducationCenter
			{
				protected:
					string category;
				public:
					Vnz():EducationCenter(),category(" "){};
					virtual ~Vnz()
					{
						this->category.clear();
					}
                    virtual void print()
                    {
                    	cout<<name<<category<<endl;
                    }

			};
class Univer:public Vnz
{
	protected:
		string * faculty;
	public:
		Univer():Vnz(),faculty(NULL){};
		//copy constructor,operator =,destructor;
		void print()
		{
		  Vnz::print();	
		}
};
