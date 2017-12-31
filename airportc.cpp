#include "airportc.h"
#include <fstream>                  //For ifstream
#include <cstdlib>                  //For exit

void Airport::schedule_flight(const Flight &new_flight)
{
    m_timetable.insert(new_flight);
}


void Airport::read_flights
(
    const char* filename, const int first_line, const int last_line
)
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
        cerr << "Uh oh, Flights.csv could not be opened for reading!" << endl;
        exit(1);
    }
 
    // While there's still stuff left to read
    string destination;
    time_t dep_time;
    time_t duration;
    int a_capacity;
    int b_capacity;
    string headrow;
    getline(inf, headrow);
    
    while (inf)
    {
        // read stuff from the file into a string and print it
        std::string line;
        getline(inf, line);
        cout << line << endl;
    }
    
    
}