
#include <iostream>
#include <string>
using namespace std;

class Vehicle 
{
	
private:
    string vehicleID;
    string manufacturer;
    string model;
    int year;
    static int totalVehicles;

public:
    Vehicle() 
	{
        vehicleID = "";
        manufacturer = "";
        model = "";
        year = 0;
        totalVehicles++;
    }

    Vehicle(string id, string man, string mod, int y) 
	{
        vehicleID = id;
        manufacturer = man;
        model = mod;
        year = y;
        totalVehicles++;
    }
	  
    ~Vehicle() 
	{
        totalVehicles--;
    }
	
	
    static int getTotalVehicles() 
	{
        return totalVehicles;
    }

    void display() const 
	{
        cout << "ID: " << vehicleID << ", Manufacturer: " << manufacturer<< ", Model: " << model << ", Year: " << year << endl;
    }

    string getID() const {
	 return vehicleID; 
	 }
};
int Vehicle::totalVehicles = 0;


class Car : public Vehicle 
{
private:
    string fuelType;

public:
    Car(string id, string man, string mod, int y, string fuel) : Vehicle(id, man, mod, y) 
	{
        fuelType = fuel;
    }

    void display() const {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class ElectricCar : public Car 
{
private:
    int batteryCapacity;

public:
    ElectricCar(string id, string man, string mod, int y, string fuel, int battery) : Car(id, man, mod, y, fuel) 
	{
        batteryCapacity = battery;
    }

    void display() const {
        Car::display();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};

class SportsCar : public ElectricCar 
{
private:
    int topSpeed;

public:
    SportsCar(string id, string man, string mod, int y, string fuel, int battery, int speed) : ElectricCar(id, man, mod, y, fuel, battery) 
	{
        topSpeed = speed;
    }

    void display() const 
	{
        ElectricCar::display();
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
    }
};

class Aircraft {
	
private:
    int flightRange;

public:
    Aircraft(int range) 
	{
        flightRange = range;
    }

    void showFlightInfo() const 
	{
        cout << "Flight Range: " << flightRange << " km" << endl;
    }
};

class FlyingCar : public Car, public Aircraft 
{
public:
    FlyingCar(string id, string man, string mod, int y, string fuel, int range)
        : Car(id, man, mod, y, fuel), Aircraft(range) 
		{
			
		}

    void display() const 
	{
        Car::display();
        Aircraft::showFlightInfo();
    }
};

class Sedan : public Car 
{
public:
    Sedan(string id, string man, string mod, int y, string fuel)
        : Car(id, man, mod, y, fuel) 
		{
		 
		}
};

class SUV : public Car 
{
public:
    SUV(string id, string man, string mod, int y, string fuel)
        : Car(id, man, mod, y, fuel) 
		{
		 
		}
};
	
class VehicleRegistry 
{
private:
    Vehicle* vehicles[100];
    int count;

public:
    VehicleRegistry() 
	{
        count = 0;
    }

    void addVehicle(Vehicle* v) 
	{
        if (count < 100) 
		{
            vehicles[count++] = v;
        }
    }

    void displayAll() const 
	{
        for (int i = 0; i < count; i++)  
		{
            cout << "\nVehicle " << i + 1 << ":\n";
            vehicles[i]->display();
        }
    }

    void searchByID(string id) const 
	{
        for (int i = 0; i < count; i++) 
		{
            if (vehicles[i]->getID() == id) 
			{
                vehicles[i]->display();
                return;
            }
        }
        cout << "Vehicle with ID " << id << " not found." << endl;
    }

    ~VehicleRegistry() 
	{
        for (int i = 0; i < count; i++) 
		{
            delete vehicles[i];
        }
    }
};

int main() 
{
    VehicleRegistry registry;
    int choice;
   
    do {
        cout << "\n--- Vehicle Registry Menu ---\n"<<endl;
        cout << "1. Add Vehicle"<<endl;
        cout << "2. View All Vehicles"<<endl;
        cout << "3. Search by ID"<<endl;
        cout << "4. Total Vehicles"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter choice (in no.): ";
        cin >> choice;

        string id, man, mod, fuel;
        int year, battery, speed, range;
        
        

        switch (choice) 
		{
            case 1:
                int type;
                cout << "-----Select Vehicle Type-----"<<endl;
                cout << "1. Car"<<endl;
                cout << "2. Electric Car"<<endl;
                cout << "3. Sports Car"<<endl;
                cout << "4. Flying Car"<<endl;
                cout << "5. Sedan"<<endl;
                cout << "6. SUV"<<endl;
                cout << "Enter type: ";
                cin >> type;
                switch (type) 
				{
                    case 1:
                        cout << "Enter ID: "; 
						cin >> id;
                        cout << "Enter Manufacturer: "; 
						cin >> man;
                        cout << "Enter Model: "; 
						cin >> mod;
                        cout << "Enter Year: "; 
						cin >> year;
                        cout << "Enter Fuel Type: "; 
						cin >> fuel;
                        registry.addVehicle(new Car(id, man, mod, year, fuel));
                        break;
                    case 2:
                        cout << "Enter ID: "; 
						cin >> id;
                        cout << "Enter Manufacturer: "; 
						cin >> man;
                        cout << "Enter Model: "; 
						cin >> mod;
                        cout << "Enter Year: "; 
						cin >> year;
                        cout << "Enter Fuel Type: "; 
						cin >> fuel;
                        cout << "Enter Battery Capacity: "; 
						cin >> battery;
                        registry.addVehicle(new ElectricCar(id, man, mod, year, fuel, battery));
                        break;
                    case 3:
                        cout << "Enter ID: "; 
						cin >> id;
                        cout << "Enter Manufacturer: "; 
						cin >> man;
                        cout << "Enter Model: "; 
						cin >> mod;
                        cout << "Enter Year: "; 
						cin >> year;
                        cout << "Enter Fuel Type: "; 
						cin >> fuel;
                        cout << "Enter Battery Capacity: "; 
						cin >> battery;
                        cout << "Enter Top Speed: "; 
						cin >> speed;
                        registry.addVehicle(new SportsCar(id, man, mod, year, fuel, battery, speed));
                        break;
                    case 4:
                        cout << "Enter ID: "; 
						cin >> id;
                        cout << "Enter Manufacturer: "; 
						cin >> man;
                        cout << "Enter Model: "; 
						cin >> mod;
                        cout << "Enter Year: "; 
						cin >> year;
                        cout << "Enter Fuel Type: "; 
						cin >> fuel;
                        cout << "Enter Flight Range: "; 
						cin >> range;
                        registry.addVehicle(new FlyingCar(id, man, mod, year, fuel, range));
                        break;
                    case 5:
                        cout << "Enter ID: "; 
						cin >> id;
                        cout << "Enter Manufacturer: "; 
						cin >> man;
                        cout << "Enter Model: "; 
						cin >> mod;
                        cout << "Enter Year: "; 
						cin >> year;
                        cout << "Enter Fuel Type: "; 
						cin >> fuel;
                        registry.addVehicle(new Sedan(id, man, mod, year, fuel));
                        break;
                    case 6:
                        cout << "Enter ID: "; 
						cin >> id;
                        cout << "Enter Manufacturer: "; 
						cin >> man;
                        cout << "Enter Model: "; 
						cin >> mod;
                        cout << "Enter Year: "; 
						cin >> year;
                        cout << "Enter Fuel Type: "; 
						cin >> fuel;
                        registry.addVehicle(new SUV(id, man, mod, year, fuel));
                        break;
                    default:
                        cout << "Invalid vehicle type.\n";
                }
                break;
            case 2:
                registry.displayAll();
                break;
            case 3:
                cout << "Enter Vehicle ID to search: ";
                cin >> id;
                registry.searchByID(id);
                break;
            case 4:
                cout << "Total Vehicles: " << Vehicle::getTotalVehicles() << endl;
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}
 
