//Pattern Facade. User want to draw some shape. He can create some shapes with default parameters and some shapes with specified parameters.
//He does not know about the process how they are drawn. He only say facade which shape and which parameters he want.

#include<iostream>
#include<string>
#include<exception>
#include<cmath>

#define DEFAULTSIZE 20;
#define DEFAULTCOLOR "achromatic";

using namespace std;

//Скорупський Review
//Перевірив роботу Тютюнника Мар'яна (варіант 26(12))
//Переконався, що ідею паттерну реалізовано правильно.
//Незначні зауваження щодо назв.
//Програма працює правильно.

class Shape
{
private:
	string color;
public:
	Shape()
	{
		color = DEFAULTCOLOR;
	}
	void AddColor(string colorOfCircle)
	{
		color = colorOfCircle;
	}
	void ShowResult()
	{
		cout << color << " ";
	}
};

class Circle : public Shape
{
private:
	double radius;
public:
	Circle()
	{
		radius = DEFAULTSIZE;
	}
	void SetRadius(double radiusOfCircle)
	{
		radius = radiusOfCircle;
	}
	void ShowResult()
	{
		cout << "Circle" << " ";
		Shape::ShowResult();
		cout << radius << endl;
	}
};

class Square : public Shape
{
private:
	double area;
public:
	Square()
	{
		int defaultSize = DEFAULTSIZE;
		area = pow(defaultSize, 2);
	}
	void SetArea(double areaOfSquare)
	{
		area = areaOfSquare;
	}
	void ShowResult()
	{
		cout << "Square" << " ";
		Shape::ShowResult();
		cout << area << endl;
	}
};

class Triangle : public Shape
{
private:
	double perimeter;
public:
	Triangle()
	{
		perimeter = 3 * DEFAULTSIZE;
	}
	void SetPerimeter(double perimeterOfTriangle)
	{
		perimeter = perimeterOfTriangle;
	}
	void ShowResult()
	{
		cout << "Triangle" << " ";
		Shape::ShowResult();
		cout << perimeter << endl;
	}
};

//Пропоную переназвати клас в те яку роль він виконує наприклад юзерський інтерфейс чи ShapeDrawer/Maker
//бо фасад це просо назва паттерну
class ShapeDrawer
{
private:
	Circle circle;
	Square square;
	Triangle triangle;
public:
	//Конструктори треба дописати навіть якшо вони просто викликатимуть конструктори без параметрів всіх форм
	ShapeDrawer() 
	{
		Circle circle;
		Square square;
		Triangle triangle;
	}
	void DrawCircle(string color = "", double radius = 0.0)
	{
		if (!color.empty())
		{
			circle.AddColor(color);
		}
		if (radius != 0.0)
		{
			if (radius < 0)
			{
				throw exception("Radius can't be negative");
			}
			else
			{
				circle.SetRadius(radius);
			}
		}
		circle.ShowResult();
	}
	void DrawSquare(string color = "", double area = 0.0)
	{
		if (!color.empty())
		{
			square.AddColor(color);
		}
		if (area != 0.0)
		{
			if (area < 0)
			{
				throw exception("Area can't be negative");
			}
			else
			{
				square.SetArea(area);
			}
		}
		square.ShowResult();
	}
	void DrawTriangle(string color = "", double perimeter = 0.0)
	{
		if (!color.empty())
		{
			triangle.AddColor(color);
		}
		if (perimeter != 0.0)
		{
			if (perimeter < 0)
			{
				throw exception("Perimeter can't be negative");
			}
			else
			{
				triangle.SetPerimeter(perimeter);
			}
		}
		triangle.ShowResult();
	}
};

void main()
{
	try
	{
		ShapeDrawer facade;
		cout << "Shape | Color | Additional parameter" << endl << endl;
		//Drawing circle with default parameters
		facade.DrawCircle();
		//Drawing circle with the specified color
		facade.DrawCircle("yellow");
		//Drawing circle with the specified color and radius
		facade.DrawCircle("green", 22);
		cout << "Circles were drawn successfully" << endl << endl;
		//Drawing square with default parameters
		facade.DrawSquare();
		//Drawing square with the specified color
		facade.DrawSquare("red");
		//Drawing square with the specified color and area
		facade.DrawSquare("grey", 12);
		cout << "Squares were drawn successfully" << endl << endl;
		//Drawing triangle with default parameters
		facade.DrawTriangle();
		//Drawing triangle with the specified color
		facade.DrawTriangle("black");
		//Drawing triangle with the specified color and perimeter
		facade.DrawTriangle("blue", 5);
		cout << "Triangles were drawn successfully" << endl << endl;
	}
	catch (exception& exception)
	{
		cout << exception.what() << endl;
	}
	system("pause");
}