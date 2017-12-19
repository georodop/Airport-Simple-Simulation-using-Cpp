/*******************************************************************************

********************************************************************************/

#include <iostream>
#include <cassert>
#include <string>
#include <sstream> // for std::stringstream
#include <fstream>
#include <cstdlib>
#include <ctime>
//Σημείωση: Για την υλοποίηση του χρόνου να χρησιμοποιήσετε τον τύπο time t οι δηλώσεις
//του οποίου βρίσκονται στο αρχείο-επικεφαλίδα ctime .

using std::cout;
using std::cin;
using std::string;

// Returns randomly true with a given probability between 0 and 1
// Assumes srand() has already been called
bool randomBoolWithProb(double probability)
{
    assert(probability>=0 && probability<=1);
    
    return rand()/(RAND_MAX+1.0) < probability;
}

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
// Assumes max - min <= RAND_MAX
int getRandomNumber(int min, int max)
{
    // static used for efficiency, so we only calculate this value once
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  
    // evenly distribute the random number across our range
    return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}


class Application
{
private:
    // το id του επιβάτη, 
    int id;
    
    // το όνομά του, 
    string fName;
    
    // επώνυμο, 
    string lName;
    
    // προορισμό, 
    int destination;

    // χρόνο που θέλει για να φτάσει στο αεροδρόμιο 
    // (δεν μπορεί να επιβιβαστεί σε αεροπλάνο με χρόνο αναχώρησης πριν από αυτόν), 
    int timeToTheAirport;

    // χρόνο που θέλει να έχει φτάσει στον προορισμό του 
    // (δεν μπορεί να επιβιβαστεί σε αεροπλάνο που φτάνει μετά από αυτόν τον χρόνο)
    int arrivalTimeLimit;

    // αν θέλει να είναι στην οικονομική θέση του αεροπλάνου ή όχι (θέσεις Α και Β). 
    bool firstClass;


public:
//Constructor:
// Μια αίτηση αρχικοποιείται με όλες τις παραπάνω παραμέτρους.

// Μπορούμε να ελέγξουμε αν μια πτήση πληρεί τους περιορισμούς μιας αίτησης ( matches ).

// Μπορούμε να ελέγξουμε αν μια αίτηση ζητά δέσμευση Α θέσης ( is luxury class ).

// Μπορούμε να ανακτήσουμε την ταυτότητα του επιβάτη που έκανε την αίτηση ( get id ).

// Μπορούμε να ανακτήσουμε το όνομα και το επώνυμο του επιβάτη που έκανε την αίτηση 
// (σαν συμβολοσειρά, χωρισμένα με ένα κενό) ( get name ).

// Μπορούμε να ανακτήσουμε το όριο χρόνου στο οποίο ο
// επιβάτης επιθυμεί να έχει φτάσει στον προορισμό του ( arrived by ).
    
    
};


class Flight
{
private:
// από τον προορισμό της,

// την ώρα αναχώρησης από το αεροδρόμιο,

// την διάρκεια της πτήσης και 

// το μέγιστο αριθμό επιβατών σε κάθε θέση (θέσεις Α και Β).

public:
// Μια πτήση αρχικοποιείται με όλες τις παραπάνω παραμέτρους. 

// Μια πτήση δέχεται μια αίτηση και αν ο αντίστοιχος επιβάτης χωράει στο αεροπλάνο,
//τον προσθέτει (σαν κλεισμένη θέση) ( add passenger ). 

// Δίδοντας ένα id επιβάτη, μπορούμε να ακυρώσουμε όλες τις κλεισμένες θέσεις για 
//αιτήσεις με το συγκεκριμένο id ( cancel reservations ).

// Μπορούμε να ανακτήσουμε την ώρα αναχώρησης της πτήσης ( departs at ).

// Μπορούμε να ανακτήσουμε την ώρα άφιξης της πτήσης στον προορισμό της ( arrives at ).

// Μπορούμε να ανακτήσουμε τον προορισμό της πτήσης ( get destination ).

// Μπορούμε να ανακτήσουμε τον αριθμό των διαθέσιμων θέσεων της πτήσης 
// (ανεξαρτήτως θέσης Α ή Β) ( get available ).

// Μπορούμε να ανακτήσουμε μια δομή με τις αιτήσεις που έχουν κλειστεί στην 
// συγκεκριμένη πτήση ( get bookings ).

};


class Airport
{
private:
//  Το αεροδρόμιο δουλεύει πάνω σε συγκεκριμένο χρονοδιάγραμμα και έχει σαν μια ενεργή πα-
// ράμετρο την τωρινή ώρα. Τόσο οι πτήσεις όσο και οι αιτήσεις δεν υφίστανται ανεξάρτητα από
// το αεροδρόμιο. Ο χρόνος ‘κυλά’ και στο πέρασμά του συμβαίνουν γεγονότα που περιγράφουμε
// στη συνέχεια.  
    time_t m_currentTime;
    // Το αεροδρόμιο έχει συγκεκριμένο αριθμό από σταθμούς ( terminals ) 
    int m_terminalsCount;





public:
// ́Ενα αεροδρόμιο αρχικοποιείται με παραμέτρους τον τωρινό χρόνο και τον αριθμό των σταθμών του. 
    Airport(time_t currentTime, int terminalsCount):
        m_currentTime(currentTime), m_terminalsCount(terminalsCount)
    {
        
    }

    // Μπορούμε να ανακτήσουμε τον τωρινό χρόνο ( get time ).
    time_t getTime() { return m_currentTime; }

    // Μπορούμε να δώσουμε όλες τις παραμέτρους μιας αίτησης και να προσθέσουμε την 
    //αίτηση στη λίστα αναμονής των αιτήσεων ( add application ).
    // ́Οταν γίνεται μια αίτηση στο αεροδρόμιο:
    //    - τότε προσπαθούμε να την καλύψουμε με διαθέσιμη πτήση, 
    //    - αλλιώς μπαίνει σε λίστα αναμονής 
    //      (μέχρι να οριστεί πτήση που να ταιριάζει με την αίτηση).  
    // Όταν ο τωρινός χρόνος περάσει τον χρόνο άφιξης που ορίστηκε στην
    //αίτηση, η αίτηση ακυρώνεται, διαγράφοντάς την από τη λίστα αναμονής.
    void addApplication(Application &newApplication)
    {
        
    }
    

    // Μπορούμε να δώσουμε ένα id και να διαγράψουμε όλες τις αιτήσεις με το
    //συγκεκριμένο id ( cancel applications ). Αυτές μπορεί να βρίσκονται στη λίστα αναμονής ή
    //να έχουν προσθέσει επιβάτες σε πτήσεις. Στη δεύτερη περίπτωση, θα ελευθερώσουμε τις θέσεις
    //στις πτήσεις. 
    //Returns if no application found with the given id
    bool cancelApplications(int id)
    {
        
    }

    // Μπορούμε να δώσουμε τις παραμέτρους μιας πτήσης και να ορίσουμε μια νέα πτήση 
    //και να ανακτήσουμε τον αριθμό του σταθμού στον οποίο βρίσκεται ( add flight ).
    //Κάθε πτήση καταλαμβάνει απευθείας έναν σταθμό.  
    //Αν δεν υπάρχει διαθέσιμος σταθμός, δεν μπορεί να προστεθεί η πτήση.  
    //Returns the terminal id for the new flight or -1 if no terminal available
    int addFlight(Flight &newflight)
    {
        
    }
    

    // Υπάρχει μια διαδικασία ακύρωσης πτήσης ( cancel flight ). Αυτή παίρνει σαν όρισμα τον αριθμό του
    //σταθμού στον οποίο βρίσκεται η πτήση και τη διαγράφει. Οι κρατήσεις της πτήσης που ακυρώ-
    //θηκαν εισάγονται στην αρχή της λίστας αναμονής των αιτήσεων.
    // Επίσης όταν ακυρώνεται μια πτήση, οι αιτήσεις μπαίνουν στην λίστα αναμονής 
    //(στην αρχή της).  Οι αιτήσεις μένουν στην λίστα αναμονής μέχρι να βρεθεί πτήση 
    //που να ταιριάζει ή μέχρι να ακυρωθούν.
    bool cancelFlight(int terminalId)
    {
        
    }

    // Μπορούμε να ανακτήσουμε τον αριθμό των ακυρωθέντων αιτήσεων ως τώρα συνολικά 
    //( failed applications ).
    int failedApplications()
    {
        
    }

    // Μπορούμε να εκτυπώσουμε τις διαθέσιμες πτήσεις καθώς και τις πληροφορίες της κάθε πτήσης, με σειρά
    //ώρας αναχώρησης ( show timetable ).
    void showTimetable()
    {
        
    }

    // Μπορούμε να εκτυπώσουμε τα ονοματεπώνυμα αυτών που οι αιτήσεις τους βρίσκονται 
    //στην λίστα αναμονής ( show people waiting ).
    //Prints the full names of the applicants in waiting list. Returns the count.
    int showPeopleWaiting()
    {
        
    }

    // Η διαδικασία flow time , με όρισμα το χρονικό διάστημα που θέλουμε να περάσει,
    //κινεί το χρόνο. Κατά την διαδικασία αυτή, κάθε πτήση που είναι να αναχωρήσει 
    //εντός αυτού του διαστήματος ελευθερώνει τον σταθμό που καταλαμβάνει και τα 
    //ονοματεπώνυμα των επιβατών που επιβαίνουν καθώς και ο προορισμός της εκτυπώνονται.
    //Επίσης, αιτήσεις που αναφέρονται στο διάστημα αυτό και δεν
    //ικανοποιήθηκαν διαγράφονται από τη λίστα αναμονής (ακυρώνονται).
    void flowTime(time_t duration)
    {
        
    }

};

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
    time_t currentTime(0);
    int terminalCount(0);
    Airport airport1(currentTime, terminalCount);

    // 2. Θα δίδονται στο αεροδρόμιο στοιχεία πτήσεων (από αρχείο).
    // We'll read from a file called Flights.csv
    ifstream inf("Flights.csv");
 
    // If we couldn't open the input file stream for reading
    if (!inf)
    {
        // Print an error and exit
        cerr << "Uh oh, Flights.csv could not be opened for reading!" << endl;
        exit(1);
    }
 
    // While there's still stuff left to read
    while (inf)
    {
        // read stuff from the file into a string and print it
        std::string strInput;
        getline(inf, strInput);
        // cout << strInput << endl;
    }

// 3. Θα δίδονται στο αεροδρόμιο στοιχεία αιτήσεων.

// 4. Θα γίνονται σχετικές εκτυπώσεις ώστε να παρουσιάζεται η κατάσταση του αεροδρομίου.

// 5. Θα κυλά το χρόνο κάποιο χρονικό διάστημα

// 6. Θα γίνονται σχετικές εκτυπώσεις ώστε να παρουσιάζεται η κατάσταση του αεροδρομίου.
    
    return 0;
}
