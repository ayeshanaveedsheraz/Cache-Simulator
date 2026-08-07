#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Cache.h"
#include "TraceParser.h"

using namespace std;

bool isPowerOfTwo(int n)
{
    if(n <= 0)
        return false;

    return (n & (n - 1)) == 0;
}


int main()
{
    srand(time(0));

    Cache* cache = nullptr;
    TraceParser parser;

    int choice;

    vector<Trace> traces;

    int currentTrace = 0;


    while(true)
    {
        cout << "\n========== CACHE SIMULATOR ==========\n";

        cout << "1. Configure Cache\n";
        cout << "2. Load Trace\n";
        cout << "3. Run Simulation\n";
        cout << "4. Step Simulation\n";
        cout << "5. Reset Cache\n";
        cout << "6. Display Cache\n";
        cout << "7. Display Statistics\n";
        cout << "8. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;


        switch(choice)
        {

        case 1:
        {
            int cacheSize;
            int blockSize;
            int ways;
            int policy;


cout << "Enter Cache Size (bytes): ";
cin >> cacheSize;

cout << "Enter Block Size (bytes): ";
cin >> blockSize;

cout << "Enter Associativity (ways): ";
cin >> ways;

if(!isPowerOfTwo(cacheSize))
{
    cout << "\nError: Cache Size must be a power of 2.\n";
    break;
}

if(!isPowerOfTwo(blockSize))
{
    cout << "\nError: Block Size must be a power of 2.\n";
    break;
}

if(cacheSize % blockSize != 0)
{
    cout << "\nError: Cache Size must be divisible by Block Size.\n";
    break;
}

int totalBlocks = cacheSize / blockSize;

if(!isPowerOfTwo(ways))
{
    cout << "\nError: Associativity must be a power of 2.\n";
    break;
}

if(ways <= 0)
{
    cout << "\nError: Associativity must be greater than 0.\n";
    break;
}

if(ways > totalBlocks)
{
    cout << "\nError: Associativity cannot exceed total cache blocks.\n";
    break;
}

if(totalBlocks % ways != 0)
{
    cout << "\nError: Total Blocks must be divisible by Associativity.\n";
    break;
}
            cout << "\nSelect Replacement Policy\n";
            cout << "1. LRU\n";
            cout << "2. FIFO\n";
            cout << "3. Random\n";

            cout << "Enter Policy: ";
            cin >> policy;


            if(cache != nullptr)
            {
                delete cache;
            }


            cache = new Cache(cacheSize, blockSize, ways, policy);


            cout << "\nCache Created Successfully.\n";

            break;
        }



        case 2:
        {
            string filename;


            cout << "\nEnter Trace File Name: ";
            cin >> filename;


            if(parser.loadFile(filename))
            {
                traces = parser.traces;

                currentTrace = 0;

                cout << "\nTrace Loaded Successfully.\n";
                cout << "Total Instructions: "
                     << traces.size() << endl;
            }


            break;
        }



        case 3:
        {
            if(cache == nullptr)
            {
                cout << "\nCreate Cache First.\n";
                break;
            }


            if(traces.empty())
            {
                cout << "\nLoad Trace File First.\n";
                break;
            }


            cout << "\nRunning Simulation...\n";


            while(currentTrace < traces.size())
            {
                cache->access(traces[currentTrace].address);

                currentTrace++;
            }


            cout << "\nSimulation Completed.\n";


            cache->displayStatistics();


            break;
        }



        case 4:
        {
            if(cache == nullptr)
            {
                cout << "\nCreate Cache First.\n";
                break;
            }


            if(currentTrace >= traces.size())
            {
                cout << "\nNo More Trace Instructions.\n";
                break;
            }



            cout << "\nStep "
                 << currentTrace + 1
                 << endl;


            cout << "Operation: "
                 << traces[currentTrace].operation
                 << endl;


            cout << "Address: "
                 << traces[currentTrace].address
                 << endl;



            bool result =
            cache->access(traces[currentTrace].address);



            if(result)
                cout << "Result: HIT\n";
            else
                cout << "Result: MISS\n";



            currentTrace++;


            cache->displayStatistics();


            break;
        }




        case 5:
        {
            if(cache == nullptr)
            {
                cout << "\nCreate Cache First.\n";
                break;
            }


            cache->resetCache();

            currentTrace = 0;


            break;
        }




        case 6:
        {
            if(cache != nullptr)
                cache->displayCache();

            else
                cout << "\nCache not created.\n";


            break;
        }



        case 7:
        {
            if(cache != nullptr)
                cache->displayStatistics();

            else
                cout << "\nCache not created.\n";


            break;
        }



        case 8:
        {
            if(cache != nullptr)
                delete cache;


            cout << "\nExiting Simulator...\n";

            return 0;
        }



        default:
            cout << "\nInvalid Choice.\n";

        }

    }


    return 0;
}