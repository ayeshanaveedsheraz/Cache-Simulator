#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "TraceParser.h"

using namespace std;

bool TraceParser::loadFile(string filename)
{
    traces.clear();

    ifstream file(filename);

    if(!file.is_open())
    {
        cout << "Error: Cannot open trace file\n";
        return false;
    }

    string line;

    while(getline(file, line))
    {
        if(line.empty())
            continue;

        stringstream ss(line);

        char op;
        string addressString;

        ss >> op >> addressString;

        unsigned long long address;

        stringstream converter;
        converter << hex << addressString;
        converter >> address;

        Trace t;
        t.operation = op;
        t.address = address;

        traces.push_back(t);
    }

    file.close();

    return true;
}