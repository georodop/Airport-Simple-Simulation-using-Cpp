/*******************************************************************************

********************************************************************************/

#include <iostream>
#include <cassert>
#include <string>
#include <sstream>          // for std::stringstream
#include <ctime>            //For time_t
#include <cstdlib>          //For exit
#include "airportc.h"
#include "flightc.h"
#include "applicationc.h"

using std::cout;
using std::cin;
using std::string;




int main(int argc, char* argv[])
{
    using std::ifstream;
    using std::endl;
    using std::cerr;
    
// Το χρονικό διάστημα να δίδεται από τη γραμμή εντολής. 
	if (argc <= 1)
	{
		// On some operating systems, argv[0] can end up as an empty string instead of the program's name.
		// We'll conditionalize our response on whether argv[0] is empty or not.
		if (argv[0])
			std::cout << "Usage: " << argv[0] << " <number>" << '\n';
		else
			std::cout << "Usage: <program name> <number>" << '\n';
 
		exit(1);
	}
 
	std::stringstream convert(argv[1]); // set up a stringstream variable named convert, initialized with the input from argv[1]
 
    time_t duration;
	if (!(convert >> duration) || duration < 0) // do the conversion
	{
	    cerr << "The input given for duration seems invalid. Please try again, "
	            << "entering a positive integer for the duration\n";
        return 1;
	}
 
	std::cout << "Simulations duration: " << duration << " time units\n";

    
    // 1. Θα δημιουργείται ένα αεροδρόμιο
    struct tm t = {0};  // Initalize to all 0's
    t.tm_year = 117;    // 0 year is year-1900, so 117 = 2017
    t.tm_mon = 11;
    t.tm_mday = 1;
    t.tm_hour = 0;
    t.tm_min = 0;
    
    
    time_t currentTime(0);
    int terminalCount(0);
    currentTime = mktime(&t);
    Airport airport1(currentTime, terminalCount);

    // 2. Θα δίδονται στο αεροδρόμιο στοιχεία πτήσεων (από αρχείο).
    airport1.read_flights("Flights.csv");
    // We'll read from a file called Flights.csv

    // 3. Θα δίδονται στο αεροδρόμιο στοιχεία αιτήσεων.
    airport1.read_applications("Applications.csv");

// 4. Θα γίνονται σχετικές εκτυπώσεις ώστε να παρουσιάζεται η κατάσταση του αεροδρομίου.

    // 5. Θα κυλά το χρόνο κάποιο χρονικό διάστημα
    airport1.flow_time(duration);

// 6. Θα γίνονται σχετικές εκτυπώσεις ώστε να παρουσιάζεται η κατάσταση του αεροδρομίου.
    airport1.show_timetable();
    
    return 0;
}
