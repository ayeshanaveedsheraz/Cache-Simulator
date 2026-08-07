#ifndef CACHELINE_H
#define CACHELINE_H

class CacheLine
{
public:

    bool valid;
    unsigned long long tag;

    int lastUsed;
    int insertedTime;


    CacheLine()
    {
        valid = false;
        tag = 0;
        lastUsed = 0;
        insertedTime = 0;
    }
};

#endif