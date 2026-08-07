#ifndef CACHE_H
#define CACHE_H

#include <vector>
#include "CacheSet.h"

using namespace std;


class Cache
{
public:

    int cacheSize;
    int blockSize;
    int associativity;

    int numberOfSets;

    int hits;
    int misses;
    int evictions;
    int currentTime;
    int replacementPolicy;


    vector<CacheSet> sets;


    Cache(int cSize, int bSize, int ways, int policy)
    {

        cacheSize = cSize;
        blockSize = bSize;
        associativity = ways;

        hits = 0;
        misses = 0;
        evictions = 0;
        currentTime = 0;
        replacementPolicy = policy;



        int totalBlocks = cacheSize / blockSize;

        numberOfSets = totalBlocks / associativity;


        for(int i = 0; i < numberOfSets; i++)
        {
            sets.push_back(CacheSet(associativity));
        }
    }


    void displayCache();

bool access(unsigned long long address);

void insertBlock(unsigned long long address);

unsigned long long getOffset(unsigned long long address);

unsigned long long getIndex(unsigned long long address);

unsigned long long getTag(unsigned long long address);

void resetCache();

void displayStatistics();

};


#endif