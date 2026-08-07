#ifndef TRACEPARSER_H
#define TRACEPARSER_H

#include <string>
#include <vector>

using namespace std;


struct Trace
{
    char operation;
    unsigned long long address;
};


class TraceParser
{

public:

    vector<Trace> traces;


    bool loadFile(string filename);

};

#endif