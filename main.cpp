#include <iostream>
#include <fstream>
using namespace std;

struct Buses;
Buses * newBuses(int);
void insert(Buses*, string, int);
void printBuses(Buses*);

int main(int argc, char ** argv)
{
    string filename = argv[1];
    filename = filename.substr(6);
    ifstream file (filename);

    string line = "";
    bool first = true;
	Buses * b;

    while(getline(file,line))
    {
        if(line.length() != 0 && line.at(0) != '#')
        {
            if(first)
            {
				first = false;
                line = line.substr(line.find("\t")+1);
				b = newBuses(stoi(line));
            }
            else
            {
                string name = line.substr(0,line.find("\t")); 
                int number = stoi(line.substr(line.find("\t")+1));

				insert(b, name, number);
			}
        }
    }

	printBuses(b);
}
