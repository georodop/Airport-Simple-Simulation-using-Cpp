#include "airportc.h"
#include <fstream>                  //For ifstream
#include <cstdlib>                  //For exit

void Airport::schedule_flight(const Flight &new_flight)
{
    m_timetable.insert(new_flight);
}


void Airport::read_flights ( const char* filename )
{
    using std::ifstream;
    using std::cerr;
    using std::cout;
    using std::endl;
    
    std::ifstream inf(filename);
 
    // If we couldn't open the input file stream for reading
    if (!inf)
    {
        // Print an error and exit
        cerr << "Oh, " << filename << " could not be opened for reading!" << "\n";
        exit(1);
    }
 
    string destination;
    time_t dep_time;
    time_t duration;
    int a_capacity;
    int b_capacity;
    string headrow;
    getline(inf, headrow);
    
    // While there's still stuff left to read
    while (inf)
    {
        // read stuff from the file into a string and print it
        std::string line;
        getline(inf, line);
        cout << line << endl;
    }
    
    
}