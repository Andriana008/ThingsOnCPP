#pragma once

class Animal
{
private:
	string animalName;
	int population;
	int dangerousLevel;
public:
	Animal() :
		animalName(""),
		population(0),
		dangerousLevel(0)
	{};
	Animal(string animalName,int population,int dangerousLevel) :
		animalName(animalName),
		population(population),
		dangerousLevel(dangerousLevel)
	{};
	Animal(const Animal& animal) :
		animalName(animal.animalName),
		population(animal.population),
		dangerousLevel(animal.dangerousLevel)
	{};
	
	int getDnageroutLevel()
	{
		return this->dangerousLevel;
	}
	
	void input(istream& file)
	{
		file >> this->animalName;
		file >> this->population;
		file >> this->dangerousLevel;
	}
	
	void print(ostream& file)
	{
		file << "    " << this->animalName<<"\n";
		file << "    " << this->population<<"\n";
		file << "    " << this->dangerousLevel << "\n";
	}
	~Animal()
	{
		this->animalName.clear();
	}
};