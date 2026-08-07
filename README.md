# Cache Simulator in C++
## Lab Project: Cache Simulator in C++**

## Overview
This project is a console-based Cache Simulator developed in C++. It simulates the behavior of a CPU cache and supports Direct-Mapped, Set-Associative, and Fully Associative cache organizations. The simulator processes a memory trace file and reports cache performance statistics.

## Features
* Configure Cache Size
* Configure Block Size
* Configure Associativity
* Supports:
  * Direct-Mapped Cache
  * Set-Associative Cache
  * Fully Associative Cache
* Replacement Policies:
  * LRU (Least Recently Used)
  * FIFO (First In First Out)
  * Random
* Load memory trace from a file
* Run complete simulation
* Step-by-step simulation
* Reset cache
* Display cache contents
* Display statistics:
  * Hits
  * Misses
  * Evictions
  * Hit Rate
  * Miss Rate

## Project Files

* `main.cpp`
* `Cache.h`
* `Cache.cpp`
* `CacheLine.h`
* `CacheSet.h`
* `TraceParser.h`
* `TraceParser.cpp`
* `trace.txt`
* `README.md`

## Requirements
- Visual Studio Code
- G++ Compiler 
- Windows Operating System

## Compilation
Using G++:
```
g++ main.cpp Cache.cpp TraceParser.cpp -o CacheSimulator
```
## Running
Windows:
CacheSimulator.exe

Linux / macOS:
```
./CacheSimulator
```

## Menu
========== CACHE SIMULATOR ==========

1. Configure Cache
2. Load Trace
3. Run Simulation
4. Step Simulation
5. Reset Cache
6. Display Cache
7. Display Statistics
8. Exit

## Input Validation
The simulator validates the following:
* Cache Size must be a power of 2.
* Block Size must be a power of 2.
* Associativity must be a power of 2.
* Cache Size must be divisible by Block Size.
* Associativity cannot exceed the total number of cache blocks.
* Total cache blocks must be divisible by associativity.
* Replacement policy must be 1 (LRU), 2 (FIFO), or 3 (Random).

## Trace File Format
Each line of the trace file should contain a memory operation followed by a hexadecimal address.
Example:
R 0x1000
W 0x1004
R 0x2000
R 0x1000
Where:
- `R` = Read
- `W` = Write

## Replacement Policies

### LRU (Least Recently Used)
Replaces the cache line that has not been used for the longest time.

### FIFO (First In First Out)
Replaces the cache line that was inserted first.

### Random
Randomly selects a cache line for replacement.

## Output
After simulation, the program displays:
* Total Hits
* Total Misses
* Total Evictions
* Hit Rate
* Miss Rate

## Author
**Ayesha Naveed**
- LinkedIn: [Your Name](https://www.linkedin.com/in/your-username/)
- GitHub: [Your Name](https://github.com/your-username)


