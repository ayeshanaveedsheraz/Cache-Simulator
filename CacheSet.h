#ifndef CACHESET_H
#define CACHESET_H

#include <vector>
#include "CacheLine.h"

using namespace std;

class CacheSet
{
public:

    vector<CacheLine> lines;

    CacheSet(int ways = 1)
    {
        lines.resize(ways);
    }

};

#endif