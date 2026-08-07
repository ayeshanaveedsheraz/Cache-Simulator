#include <iostream>
#include "Cache.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


void Cache::displayCache()
{
    cout << "\n========== CACHE ==========\n";


    for(int i = 0; i < numberOfSets; i++)
    {
        cout << "Set " << i << endl;


        for(int j = 0; j < associativity; j++)
        {
            cout << " Way " << j;


            if(sets[i].lines[j].valid)
            {
                cout << " : Valid = 1 Tag = "
                     << sets[i].lines[j].tag;
            }
            else
            {
                cout << " : Empty";
            }


            cout << endl;
        }

        cout << endl;
    }

    cout << "===========================\n";
}
unsigned long long Cache::getOffset(unsigned long long address)
{
    int offsetBits = log2(blockSize);

    return address & ((1ULL << offsetBits) - 1);
}


unsigned long long Cache::getIndex(unsigned long long address)
{
    int offsetBits = log2(blockSize);

    return (address >> offsetBits) & (numberOfSets - 1);
}


unsigned long long Cache::getTag(unsigned long long address)
{
    int offsetBits = log2(blockSize);

    int indexBits = log2(numberOfSets);

    return address >> (offsetBits + indexBits);
}
bool Cache::access(unsigned long long address)
{
    currentTime++;
    unsigned long long index = getIndex(address);

    unsigned long long tag = getTag(address);


    for(int i = 0; i < associativity; i++)
    {
        if(sets[index].lines[i].valid &&
           sets[index].lines[i].tag == tag)
        {
            hits++;
            sets[index].lines[i].lastUsed = currentTime;
            return true;   // HIT
        }
    }

    misses++;
    insertBlock(address);

    return false;   // MISS
}
void Cache::insertBlock(unsigned long long address)
{
    unsigned long long index = getIndex(address);

    unsigned long long tag = getTag(address);


    for(int i = 0; i < associativity; i++)
    {
        if(!sets[index].lines[i].valid)
        {
            sets[index].lines[i].valid = true;

            sets[index].lines[i].tag = tag;

            sets[index].lines[i].lastUsed = currentTime;
            sets[index].lines[i].insertedTime = currentTime;    

            return;
        }
    }
        // Set full hai, LRU replace karo

    // Set full hai

int replaceIndex = 0;

if(replacementPolicy == 1)   // LRU
{
    for(int i = 1; i < associativity; i++)
    {
        if(sets[index].lines[i].lastUsed <
           sets[index].lines[replaceIndex].lastUsed)
        {
            replaceIndex = i;
        }
    }
}
else if(replacementPolicy == 2)   // FIFO
{
    for(int i = 1; i < associativity; i++)
    {
        if(sets[index].lines[i].insertedTime <
           sets[index].lines[replaceIndex].insertedTime)
        {
            replaceIndex = i;
        }
    }
}
else if(replacementPolicy == 3)   // Random
{
    replaceIndex = rand() % associativity;
}

evictions++;

sets[index].lines[replaceIndex].tag = tag;
sets[index].lines[replaceIndex].valid = true;
sets[index].lines[replaceIndex].lastUsed = currentTime;
sets[index].lines[replaceIndex].insertedTime = currentTime;
}
void Cache::resetCache()
{
    hits = 0;
    misses = 0;
    evictions = 0;
    currentTime = 0;

    for(int i = 0; i < numberOfSets; i++)
    {
        for(int j = 0; j < associativity; j++)
        {
            sets[i].lines[j].valid = false;
            sets[i].lines[j].tag = 0;
            sets[i].lines[j].lastUsed = 0;
            sets[i].lines[j].insertedTime = 0;
        }
    }

    cout << "\nCache Reset Successfully.\n";
}

void Cache::displayStatistics()
{
    cout << "\n========== Statistics ==========\n";

    cout << "Hits      : " << hits << endl;
    cout << "Misses    : " << misses << endl;
    cout << "Evictions : " << evictions << endl;

    int total = hits + misses;

    if(total > 0)
    {
        cout << "Hit Rate  : " << (float)hits * 100 / total << "%" << endl;
        cout << "Miss Rate : " << (float)misses * 100 / total << "%" << endl;
    }

    cout << "================================\n";
}