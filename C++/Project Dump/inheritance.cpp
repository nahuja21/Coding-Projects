/// @file Inheritance.cpp
/// @brief Inheritance final for 298 class
/// @author nahuja@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++

#include <iostream> 
#include <tuple>    
#include <cmath>   
#include <random>   
#include <ctime>    

class Shape
{
    public:
        Shape(double dHeight, double dWidth);
        virtual ~Shape();
        virtual void scale(double dScaleFactor) = 0;
        virtual double area() = 0;
        virtual double perimeter() = 0;
        virtual void displayProperties();


    protected:
        double m_dHeight;
        double m_dWidth;
        std::string m_strType;
};

Shape::Shape(double dHeight, double dWidth) : m_dHeight(dHeight), m_dWidth(dWidth), m_strType("Shape")
{

}

Shape::~Shape()
{
	std::cout << "Shape Destructor called" << std::endl;
} 

void Shape::displayProperties()
        {
        std::cout << "Shape type: " << m_strType << std::endl;
        std::cout << "Width: " << m_dWidth << std::endl;
        std::cout << "Height: " << m_dHeight << std::endl;
        }


class Rectangle : public Shape
{
    public:
    Rectangle(double dHeight, double dWidth);
    virtual ~Rectangle();
    void scale(double dScaleFactor);
    double area();
    double perimeter();
};

Rectangle::Rectangle(double dHeight, double dWidth) : Shape(dHeight, dWidth)
{
	this->m_strType = "Rectangle";
}

Rectangle::~Rectangle()
{
	std::cout << "Rectangle Destructor called" << std::endl;
} 


void Rectangle::scale(double dScaleFactor)
    {
        m_dHeight *= dScaleFactor;
        m_dWidth *= dScaleFactor;
    }
    double Rectangle::area()
    {
        return m_dHeight * m_dWidth;
    }
    double Rectangle::perimeter()
    {
        return 2 * (m_dHeight + m_dWidth);
    }


class Circle : public Shape
{
    public:
    Circle(double dHeight, double dWidth);
    virtual ~Circle();
    void scale(double dScaleFactor);
    double area();
    double perimeter();
    
};

Circle::Circle(double dHeight, double dWidth) : Shape(dHeight, dWidth)
{
	this->m_strType = "Circle";
}

Circle::~Circle()
{
	std::cout << "Circle Destructor called" << std::endl;
} 

void Circle::scale(double dScaleFactor)
{
    m_dHeight *= dScaleFactor;
    m_dWidth *= dScaleFactor;
}
double Circle::area()
{
    return 0.25 * M_PI * m_dHeight * m_dHeight;
}
double Circle::perimeter()
{
    return M_PI * m_dHeight;
}

int main()
{
    Rectangle* p_shapeRectangle = new Rectangle(2.0, 3.0);
    Circle* p_shapeCircle = new Circle(2.0, 2.0);

    Shape* p_shapes[2];

    p_shapes[0] = p_shapeCircle;
    p_shapes[1] = p_shapeRectangle;

    for (int i = 0; i < 2; i++)
    {
        p_shapes[i]->displayProperties();
        std::cout << "Area: " << p_shapes[i]->area() << std::endl;
        std::cout << "Perimeter: " << p_shapes[i]->perimeter() << std::endl;
        p_shapes[i]->scale(2);
        p_shapes[i]->displayProperties();
        std::cout << "Area: " << p_shapes[i]->area() << std::endl;
        std::cout << "Perimeter: " << p_shapes[i]->perimeter() << std::endl;
    }
    delete p_shapeCircle;
    delete p_shapeRectangle;

    return 0;
}



