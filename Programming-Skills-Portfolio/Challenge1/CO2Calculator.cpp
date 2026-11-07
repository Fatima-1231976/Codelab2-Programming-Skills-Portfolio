#include <iostream>
#include <string>
using namespace std;

double getDistance()
{
    double distance;
    cout << "Enter distance travelled (miles): ";
    cin >> distance;
    return distance;
}

string getFuelType()
{
    string fuel;
    cout << "Enter fuel type (diesel/petrol): ";
    cin >> fuel;
    return fuel;
}

double calculateCO2(double distance, string fuel)
{
    double litresUsed = (distance / 100.0) * 9.66;

    if (fuel == "diesel")
        return litresUsed * 2.68;
    else
        return litresUsed * 2.31;
}

int main()
{
    double distance = getDistance();
    string fuel = getFuelType();

    cout << "CO2 emissions: "
         << calculateCO2(distance, fuel)
         << " kg" << endl;

    return 0;
}