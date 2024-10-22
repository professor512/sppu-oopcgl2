/* Write a program in C++ to use map associative container. The keys will be the names of 
states and the Values will be the populations of the states. When the program runs, the user is 
prompted to type the Name of a state. The program then looks in the map, using the state name as 
an index and returns the Population of the state */

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Typedef for the map
    typedef map<string, int> mapType;
    mapType populationMap;

    // Insert values into the map
    populationMap.insert(pair<string, int>("Maharashtra", 7026357));
    populationMap.insert(pair<string, int>("Rajasthan", 6578936));
    populationMap.insert(pair<string, int>("Karnataka", 6678993));
    populationMap.insert(pair<string, int>("Punjab", 5789032));
    populationMap.insert(pair<string, int>("West Bengal", 6676291));

    mapType::iterator iter;
    cout << "======== Population of states in India ==========\n";
    cout << "\nSize of populationMap: " << populationMap.size() << "\n";

    string state_name;
    cout << "\nEnter name of the state: ";
    cin >> state_name;

    // Search for the state in the map
    iter = populationMap.find(state_name);
    if (iter != populationMap.end()) {
        cout << state_name << "'s population is " << iter->second << "\n";
    } else {
        cout << "Key is not in populationMap" << "\n";
    }

    populationMap.clear();  // Clear the map
    return 0;
}
