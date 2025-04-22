//1

#include<iostream>
#include<cstring>
using namespace std;

class Laptop{
    private:
    string name;
    double price;
  string processor;

public:

    Laptop(string name, double price,string processor) : name(name), price(price), processor(processor) {}


  string getName()
  const { return name; }
  double getPrice()
  const { return price; }
  string getProcessor()
  const { return processor; }


    void setName(const string& newName) { name = newName; }
    void setPrice(double newPrice) { price = newPrice; }
    void setProcessor(const string& newProcessor) { processor = newProcessor; }


    void displayInfo() const {
        cout << "Name:" << name << endl;
        cout << "Price:" << price <<endl;
        cout << "Processor:" << processor <<endl;
    }
};

int main() {

    Laptop HP("HP Victus", 67000, "Intel Core i5");
    Laptop Macbook("Apple MacBook Pro", 120000, "Apple M4");


    HP.displayInfo();
    cout << endl;

    Macbook.displayInfo();
    cout << endl;

    HP.setName("Updated HP Victus");
    HP.setPrice(70000);
    HP.setProcessor("Intel Core i7\n");

    HP.displayInfo();

    Macbook.setName("Updated Apple MacBook Pro ");
    Macbook.setPrice(140000);
    Macbook.setProcessor("Apple M4 Pro");

    Macbook.displayInfo();

}



//2

#include<iostream>
#include<cstring>
using namespace std;

class BankAccount {
private:
	string accountNumber;
	double balance;
	string ownerName;

public:

	BankAccount(string accountNumber, double balance,string ownerName) : accountNumber(accountNumber), balance(balance), ownerName(ownerName) {}

	void credit(double amount) {
		if(amount>0) {
			balance +=amount;
			cout<<"Amount credited in your account:"<<amount<<endl;
		}
		else {
			cout<<"Cannot Credited."<<endl;
		}

	}
	void debit(double amount) {
		if(amount>0 && amount <=balance) {
			balance -=amount;
			cout<< "Amount debited from your account:"<<amount<<endl;

		}
		else {
			cout<<"Insufficient balance."<<endl;

		}
	}

	void displayBalance() const {
		cout<<"Account Holder:"<<ownerName<<endl;
		cout<<"Current Balance:"<<balance<<endl;
		cout<<"Account Number:"<<accountNumber<<endl;
	}


};

int main() {
	BankAccount
	account1("2345678901\n",80000,"Sohan Tiwari");
	BankAccount
	account2("1234353768",120000,"Wasim Shaikh");

	account1.displayBalance();
	cout<<endl;
	
	account2.displayBalance();
	cout<<endl;
	
	
	account1.credit(10000);
    account1.debit(50000);
    account1.displayBalance();
    
    account2.credit(5000);
    account2.debit(40000);
    account2.displayBalance();

}




//3

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class Shape {
private:
    string color;
    double area;

public:
    Shape(const string& initialColor, double initialArea) : color(initialColor), area(initialArea) {}

    string getColor() const {
        return color;
    }

    double getArea() const {
        return area;
    }

    void setColor(const string& newColor) {
        color = newColor;
    }

    void setArea(double newArea) {
        area = newArea;
    }

    virtual void calculateArea() = 0; 
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(const string& initialColor, double initialRadius)
        : Shape(initialColor, 0.0), radius(initialRadius) {}

    void calculateArea() override {
        double circleArea = M_PI * radius * radius;
        setArea(circleArea);
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(const string& initialColor, double initialWidth, double initialHeight)
        : Shape(initialColor, 0.0), width(initialWidth), height(initialHeight) {}

    void calculateArea() override {
        double rectArea = width * height;
        setArea(rectArea);
    }
};

int main() {
    Circle circle("Green", 8);
    Rectangle rectangle("Blue", 6, 9);

    circle.calculateArea();
    rectangle.calculateArea();

    cout << "Circle area: " << circle.getArea() << endl;
    cout << "Rectangle area: " << rectangle.getArea() << endl;

    return 0;
}





//4

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


class Shape {
public:
    virtual void displayDetails() {
    cout << "Shape: Unknown" <<endl;
    }
    virtual ~Shape() = default; 
};

class Circle : public Shape {
public:
    Circle(double radius) : radius_(radius) {}

    void displayDetails() override {
    cout << "Shape: Circle, Radius: " << radius_ <<endl;
    }

private:
    double radius_;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : width_(width), height_(height) {}

    void displayDetails() override {
      cout << "Shape: Rectangle, Width: " << width_ << ", Height: " << height_ <<endl;
    }

private:
    double width_, height_;
};

class Triangle : public Shape {
public:
    Triangle(double base, double height) : base_(base), height_(height) {}

    void displayDetails() override {
    cout << "Shape: Triangle, Base: " << base_ << ", Height: " << height_ <<endl;
    }

private:
    double base_, height_;
};

int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Triangle(3.0, 7.0));

    for (Shape* shape : shapes) {
        shape->displayDetails();
    }

   
    for (Shape* shape : shapes) {
        delete shape;
    }
    return 0;
}




//5

#include<iostream>
#include<stdexcept>
#include<cmath>
using namespace std;

class Calculator{
    public:
    double add(double a,double b)
        {return a+b;}
     double subtract(double a,double b)
     {return a-b;}
     double multiply(double a,double b)
     { return a*b;}
     double divide(double a,double b)
     {if (b==0){
         throw runtime_error("Can't divide by zero!");
     }
     return a/b;
     }
    
};

int main(){
    Calculator calc;
    cout<<"Add:"<<calc.add(8,4)<<endl;
    cout<<"Subtract:"<<calc.subtract(7,5)<<endl;
    cout<<"Multiply:"<<calc.multiply(8,6)<<endl;
    
    try{
        cout<<"Divide:"<<calc.divide(10,2)<<endl;
        cout<<"Divide by zero attempt:"<<calc.divide(9,0)<<endl;
        
    }
    catch(const runtime_error&error){
        cerr<<"Error:"<<error.what()<<endl;
    }
}




//6

#include <iostream>
#include <fstream>
using namespace std;

class FileManager 
{
public:
    void readFile(const string& filename) 
    {
        fstream file(filename);
        if (!file.is_open()) 
        {
            throw runtime_error("Unable to open file.");
        }

        string line;
        while (getline(file, line)) 
        {
            cout << line << endl;
        }

        file.close();
    }
};

int main() 
{
    FileManager fm;
    try
    {
        fm.readFile("data.txt");
    }
    catch (const exception& e) 
    {
        cout << "Exception: " << e.what() << endl;
    }
}





//7

#include<iostream>
#include<string.h>
using namespace std;

class Vehicle {
public:
    virtual void startEngine() = 0;
    virtual void drive() = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void startEngine() override {
        cout << "Starting Car engine" << endl;
    }
    void drive() override {
        cout << "Driving Car\n" << endl;
    }
};

class Bike : public Vehicle {
public:
    void startEngine() override {
        cout << "Starting Bike engine" << endl;
    }
    void drive() override {
        cout << "Riding Bike" << endl;
    }
};

int main() {
    Car car;
    Bike bike;
    
    Vehicle* vehicles[2];
    vehicles[0] = &car;
    vehicles[1] = &bike;
    
    for (int i = 0; i < 2; ++i) {
        vehicles[i]->startEngine();
        vehicles[i]->drive();
    }

    
}




    
