#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include"Phone.h"

void sortByBrand(Phone** array, int size)
{
	for (int i = 0; i<size; i++)
		for (int j = 0; j<size - 1 - i; j++)
		{
			Phone* temp;
			if (array[j]->getBrand()>array[j + 1]->getBrand())
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
}


 Phone DTOInput(string fileName ,Phone** phones,int size ,int& indexAtArray )
{
	 ifstream file(fileName , ios_base:: in );	
	 if (!file.is_open())
	{
		 cout << "can not  open  "<<fileName<< " , try again ...\n";
		 return **phones;
	}
	 int doWhile=size;
	 if (indexAtArray == 0)
	 {
		 doWhile = size / 2;
	 }
	 for ( ; indexAtArray< doWhile ; indexAtArray++)
	 {
		 int temp;
		 file >> temp;
		 if (temp == 1)
		 {
			 phones[indexAtArray] = new MobilePhone();
		 }
		 else
		 {
			 phones[indexAtArray] = new RadioPhone();
		 }

		 phones[indexAtArray]->input(file);
	 }

	 return **phones;
	
}
 

 void  DTOOutput (Phone** phones, int size)
 {
	 //open file and delete all information from it  and then input new information in empty file (out | trunc)
	 ofstream file("result.txt", ios_base::out | ios_base::trunc);
	 if (!file.is_open())
	 {
		 cout << "can not  open  result.txt , try again ...\n";
	 }
	 else
	 {
		 file << " \t\t\t  First  task  \n";
		 sortByBrand(phones, size);
		 file << "suma of phones of different brands : \n";
		 int suma = 0;
		 for (int i = 0; i < size - 1; i++)
		 {
			 suma += phones[i]->getPrice();
			 if (phones[i]->getBrand() != phones[i + 1]->getBrand())
			 {
				 file << phones[i]->getBrand() << " : " << suma << " $ \n";
				 suma = 0;
			 }
			 if (i == size - 2 && phones[i]->getBrand() == phones[i + 1]->getBrand())
			 {
				 suma += phones[i + 1]->getPrice();
				 file << phones[i + 1]->getBrand() << " : " << suma << " $ \n";
			 }
			 if (i == size - 2 && phones[i]->getBrand() != phones[i + 1]->getBrand())
			 {
				 suma = 0;
				 suma += phones[i + 1]->getPrice();
				 file << phones[i + 1]->getBrand() << " : " << suma << " $ \n";
			 }

		 }
		 file << "*****************\n";
		 file << "All phones sorted by brand  :\n ";
		 for (int i = 0; i < size; i++)
		 {
			 phones[i]->print(file);
		 }
		 file << " \t\t\t  Second task  \n";
		 file << " information about green phone(s)  :  \n";
		 for (int i = 0; i < size; i++)
		 {
			 if (dynamic_cast<MobilePhone*>(phones[i]) )
			 {
				 if (dynamic_cast<MobilePhone*>(phones[i])->getColor() == "green")
				 {
					 phones[i]->print(file);
				 } 
			 }
		 }
	 }
 }

int main()
{
	int index = 0;
	int size = 4;
	Phone** phones= new Phone*[size];
	**phones = DTOInput("file1.txt", phones ,size, index);
	**phones = DTOInput("file2.txt", phones, size, index);
	DTOOutput(phones, size);
	system("pause");
	return 0;
}