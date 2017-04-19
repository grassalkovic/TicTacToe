#include <iostream>
#include <string>
#include "log.h"

Log::Log(){

}

Log::Log(string file)
{ 
    of.open("log.txt");
}

Log::~Log()
{
    if( of.is_open() )
    of.close();
}

//output for string message
bool Log::write( string message ){
    if( of.is_open() )
    {
        of << message << endl;
    } else {
        cout << message << endl;
    }


}

//overloaded output for string with int message
bool Log::write( string file, int line ){

    if( of.is_open() )
    {
        of << "File: " << file << " Line: " << line << endl;
    } else {
        cout << "File: " << file << " Line: " << line << endl;
    }
}
