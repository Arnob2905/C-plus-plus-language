// Project 1. Time converter....

#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class TimeConverter
{
    public:
    int hours;
    int minutes;
    int seconds;
   

TimeConverter(int Totalseconds){
    hours=Totalseconds/3600;
    minutes=(Totalseconds%3600)/60;
    seconds=Totalseconds%60;
}

void secTotime(){
    cout<<"HH : MM : SS =>"<<hours<<":"<<minutes<<":"<<seconds;
   
}

};

int main(){
 int Totalseconds;
 cout << "Enter total seconds: ";
 cin >> Totalseconds;

    TimeConverter time(Totalseconds);
    time.secTotime(); 

}






#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class TimeConverter
{
    public:
    int Totalseconds;
    TimeConverter(int hours,int minutes,int seconds){
        Totalseconds=(seconds+(minutes*60)+(hours*3600));
        
        
    }
    void timeTosec(){
         cout<<"Total seconds: " << Totalseconds << endl;
    }
    
    
};

int main(){
    int hours,minutes,seconds;
     cout<<"Enter Hours: ";
        cin>> hours;
        cout<<"Enter minutes: ";
        cin>> minutes;
        cout<<"Enter seconds: ";
        cin>>seconds;

    
    
    TimeConverter time(hours,minutes,seconds);
    time.timeTosec(); 

}




