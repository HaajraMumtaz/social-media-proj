//#include <iostream>
//using namespace std;
//class Animal
//{
//public:
//	virtual char* speak()
//	{
//		return (char*)"speak() called.";
//	}
//	virtual ~Animal()
//	{
//		cout << "destructor of animal called" << endl;
//	}
//};
//
//
//class Dog : public Animal
//{
//public:
//	char* speak() override
//	{
//		return (char*)"woof";
//	}
//	~Dog()
//	{
//		cout << "destructor dog called" << endl;
//	}
//};
//
//class Cat : public Animal
//{
//public:
//	char* speak() override
//	{
//		return (char*)"mew";
//	}
//	~Cat()
//	{
//		cout << "destructor cat called" << endl;
//	}
//};
//
//class Sheep : public Animal
//{
//public:
//	char* speak() override
//	{
//		return (char*)"bleat";
//	}
//	~Sheep()
//	{
//		cout << "sheep des called" << endl;
//	}
//};
//
//class Cow : public Animal
//{
//public:
//	char* speak() override
//	{
//		return (char*)"moo";
//	}
//	~Cow()
//	{
//		cout << "cow des called" << endl;
//	}
//};
//
//
//class Shape
//{
//public:
//	virtual void draw() = 0;
//	virtual float area() = 0;
//	virtual float perimeter() = 0;
//	virtual ~Shape()
//	{
//		cout << "shape destructor called" << endl;
//	}
//};
//
//class Circle : public Shape
//{
//private:
//	float radius;
//public:
//	Circle(float r = 0)
//	{
//		radius = r;
//	}
//	void draw() override
//	{
//		cout << "drawing circle" << endl;
//	}
//	float area() override
//	{
//		return 3.1416f * radius * radius;
//	}
//	float perimeter() override
//	{
//		return 2 * 3.1416f * radius;
//	}
//	~Circle()
//	{
//		cout << "destructor of circle  called" << endl;
//	}
//};
//class Rectangle : public Shape
//{
//private:
//	float length, width;
//public:
//	Rectangle(float l = 0, float w = 0)
//	{
//		length = l;
//		width = w;
//	}
//	void draw() override
//	{
//		cout << "drawing rectangle" << endl;
//	}
//	float area() override
//	{
//		return length * width;
//	}
//	float perimeter() override
//	{
//		return 2 * (length + width);
//	}
//	~Rectangle()
//	{
//		cout << "destructor of rectangle called" << endl;
//	}
//};
//
//
//int main()
//{
//
//	Animal objAnimal;
//
//
//	Dog objDog;
//	Animal* ptrAnimal = &objAnimal;
//	Dog* ptrDog = &objDog;
//
//	cout << objAnimal.speak() << endl;
//
//	cout << objDog.speak() << endl;
//	cout << ptrAnimal->speak() << endl;
//
//	cout << ptrDog->speak() << endl;
//	cout << ptrDog->Animal::speak() << endl;
//
//
//
//	ptrAnimal = &objDog;
//	cout << ptrAnimal->speak() << endl;
//
//
//	const int size = 2;
//	Animal* myPets[size];
//	Cat cat;
//	Dog dog;
//
//	myPets[0] = &cat;
//	myPets[1] = &dog;
//
//	for (int i = 0; i < size; i++)
//	{
//		cout << myPets[i]->speak() << endl;
//	}
//
//	Animal* a1 = new Cat();
//
//
//	Animal* a2 = new Dog();
//	Animal* a3 = new Sheep();
//
//	Animal* a4 = new Cow();
//	cout << a1->speak() << endl;
//
//
//	cout << a2->speak() << endl;
//
//
//	cout << a3->speak() << endl;
//	cout << a4->speak() << endl;
//
//	delete a1;
//
//	delete a2;
//
//	delete a3;
//	delete a4;
//
//
//	Shape* s1 = new Circle(5.0f);
//	Shape* s2 = new Rectangle(4.0f, 3.0f);
//
//	s1->draw();
//	cout << "Area: " << s1->area() << endl;
//
//
//	cout << "Perimeter: " << s1->perimeter() << endl;
//
//	s2->draw();
//	cout << "Area: " << s2->area() << endl;
//
//	cout << "Perimeter: " << s2->perimeter() << endl;
//
//	delete s1;
//	delete s2;
//	system("pause");
//
//	return 0;
//}