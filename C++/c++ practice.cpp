//1.
// #include<iostream>
// using namespace std;
// int main(){
//     cout<<"Hello World";
// }



//2.
// #include<iostream>

// int main(){
//     int a=10,b=20;

//   std::cout<<"Hello World";
//     std::cout<< "a"<<"b"; 
// }


//3.
// #include<iostream>
// using namespace std;
// int main(){
//     string first_name;
//     cout<<"Enter your First name:";
//     cin>>first_name;
//     cout<<"Hello "<<first_name<<" "<<endl;
//     cout<<"Welcome!";
    
// }


//4.
// #include<iostream>
// #include<cstring>
// using namespace std;

// class Student
// {
//     public:
//     int id;
//     char name[100];
// };

// int main(){
//     Student s1;
//     s1.id=5;
//     cout<<"Enter Name:";
//     cin.getline(s1.name,100);
    
//     cout<<"id:"<<s1.id<<endl;
//     cout<<"name:"<<s1.name<<endl;
// }
    
    
//5.
// #include<iostream>
// using namespace std;

// int main(){
//     cout<<"'C'\t'L'\t'I'\t'N'\t'I'\t'C'\n";
//     cout<<"\"Electronic\"\n";
// }
    
    
//6.
// #include<iostream>
// using namespace std;

// int main(){
//     string first_name;
//     cout<<"Enter ur First name:";
//     cin>>first_name;
//     cout<<"Hello "<<first_name<<"!"<<endl;
//     cout<<"Welcome!";
// }    

//7.
// #include<iostream>
// #include<iomanip>
// using namespace std;
// int main(){
//     float num=2.456;
//     cout<<"Original number is:"<<num;
//     cout<<"\n";
//     cout<<"The number with 3 significant figures is:";
//     cout<<"\n";
//     cout<<setprecision(2)<<num;
    
// }

//8.
// #include<iostream>
// #include<cstring>
// using namespace std;
// class Room{
//     public:
//     double length;
//     double breadth;
//     double height;
    
//     double calculateArea(){
//         return length*breadth;
//         height;
//     }
//     double calculateVolume(){
//         return length*breadth*height;
        
//     }
// };

// int main(){
//     Room room1;
//     room1.length=42.5;
//     room1.breadth=30.8;
//     room1.height=19.2;
    
//     cout<<"Area of Room = "<<room1.calculateArea()<<endl;
//     cout<<"Volume of Room = "<<room1.calculateVolume()<<endl;
    
    
// }

//9.
// #include<iostream>
// #include<string.h>
// using namespace std;
// class Employee
// {
//     public:
//     int id;
//     char name[100];
//     int salary;
    
// };
// int main(){
//     Employee e1,e2;
//     e1.id=1;
//     strcpy(e1.name,"Arnab");
//     e1.salary=20000;
    
//     e2.id=2;
//     strcpy(e2.name,"Soham");
//     e2.salary=30000;
    
//     cout<<"id:"<<e1.id<<endl;
//     cout<<"name:"<<e1.name<<endl;
//     cout<<"salary:"<<e1.salary<<endl<<endl;
    
    
//     cout<<"id:"<<e2.id<<endl;
//     cout<<"name:"<<e2.name<<endl;
//     cout<<"salary:"<<e2.salary<<endl;
    
// }


//10.
#include<iostream>
#include<cstring>
using namespace std;

class Employee
{
    public:
    int id;
    char name[100];
    int salary;
    
    void setdata()
    {
        id=1;
        strcpy(name,"Arnab");
        salary=20000;
        
    }
     
     void getdata()
     {
         cout<<"id:"<<id<<endl;
         cout<<"name:"<<name<<endl;
         cout<<"salary:"<<salary<<endl;
         
     }
};

  int main(){
      
      Employee e1,e2;
      e1.setdata();
      
      e1.getdata();
     
  }
     

    

    


    


