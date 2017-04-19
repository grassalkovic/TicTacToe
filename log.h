#ifndef LOG_H
#define LOG_H

#include <fstream>
#include <string>

using namespace std;

class Log{
public:
    Log();
    Log( string file );
    ~Log();

    //output for string message
    bool write( string message );

    //overloaded output for string with int message
    bool write( string file, int line );

private:
    ofstream of;
};

#endif // MAIN_H
