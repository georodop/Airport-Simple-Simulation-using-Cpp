#ifndef AIRPORTC_H
#define AIRPORTC_H

#include <iostream>

#include <ctime>            //For time_t
#include "appslistc.h"
#include "applicationc.h"
#include "flightc.h"
#include "flightslistc.h"

class Airport
{
private:
//  Το αεροδρόμιο δουλεύει πάνω σε συγκεκριμένο χρονοδιάγραμμα και έχει σαν μια ενεργή πα-
// ράμετρο την τωρινή ώρα. Τόσο οι πτήσεις όσο και οι αιτήσεις δεν υφίστανται ανεξάρτητα από
// το αεροδρόμιο. Ο χρόνος ‘κυλά’ και στο πέρασμά του συμβαίνουν γεγονότα που περιγράφουμε
// στη συνέχεια.  
    time_t m_current_time;
    // Το αεροδρόμιο έχει συγκεκριμένο αριθμό από σταθμούς ( terminals ) 
    int m_terminals_count;
    
    Apps_list m_people_waiting;
    
    Flights_list m_timetable;

public:
// ́Ενα αεροδρόμιο αρχικοποιείται με παραμέτρους τον τωρινό χρόνο και τον αριθμό των σταθμών του. 
    Airport(time_t current_time, int terminals_count):
        m_current_time(current_time), m_terminals_count(terminals_count)
    {
        
    }

    // Μπορούμε να ανακτήσουμε τον τωρινό χρόνο ( get time ).
    time_t get_time() { return m_current_time; }

    // Μπορούμε να δώσουμε όλες τις παραμέτρους μιας αίτησης και να προσθέσουμε την 
    //αίτηση στη λίστα αναμονής των αιτήσεων ( add application ).
    // ́Οταν γίνεται μια αίτηση στο αεροδρόμιο:
    //    - τότε προσπαθούμε να την καλύψουμε με διαθέσιμη πτήση, 
    //    - αλλιώς μπαίνει σε λίστα αναμονής 
    //      (μέχρι να οριστεί πτήση που να ταιριάζει με την αίτηση).  
    // Όταν ο τωρινός χρόνος περάσει τον χρόνο άφιξης που ορίστηκε στην
    //αίτηση, η αίτηση ακυρώνεται, διαγράφοντάς την από τη λίστα αναμονής.
    void add_application(const Application &application)
    {
        m_people_waiting.push_back( application );
    }
    

    // Μπορούμε να δώσουμε ένα id και να διαγράψουμε όλες τις αιτήσεις με το
    //συγκεκριμένο id ( cancel applications ). Αυτές μπορεί να βρίσκονται στη λίστα αναμονής ή
    //να έχουν προσθέσει επιβάτες σε πτήσεις. Στη δεύτερη περίπτωση, θα ελευθερώσουμε τις θέσεις
    //στις πτήσεις. 
    //Returns false if no application found with the given id
    bool cancel_applications(const int &id)
    {
        
        
    }

    // Μπορούμε να δώσουμε τις παραμέτρους μιας πτήσης και να ορίσουμε μια νέα πτήση 
    //και να ανακτήσουμε τον αριθμό του σταθμού στον οποίο βρίσκεται ( add flight ).
    //Κάθε πτήση καταλαμβάνει απευθείας έναν σταθμό.  
    //Αν δεν υπάρχει διαθέσιμος σταθμός, δεν μπορεί να προστεθεί η πτήση.  
    //Returns the terminal id for the new flight or -1 if no terminal available
    int add_flight(Flight &new_flight)
    {
        
    }
    
    //Adds a flight in the timetable
    void schedule_flight(const Flight &new_flight);

    // Υπάρχει μια διαδικασία ακύρωσης πτήσης ( cancel flight ). Αυτή παίρνει σαν όρισμα τον αριθμό του
    //σταθμού στον οποίο βρίσκεται η πτήση και τη διαγράφει. Οι κρατήσεις της πτήσης που ακυρώ-
    //θηκαν εισάγονται στην αρχή της λίστας αναμονής των αιτήσεων.
    // Επίσης όταν ακυρώνεται μια πτήση, οι αιτήσεις μπαίνουν στην λίστα αναμονής 
    //(στην αρχή της).  Οι αιτήσεις μένουν στην λίστα αναμονής μέχρι να βρεθεί πτήση 
    //που να ταιριάζει ή μέχρι να ακυρωθούν.
    bool cancel_flight(int terminal_id)
    {
        
    }

    // Μπορούμε να ανακτήσουμε τον αριθμό των ακυρωθέντων αιτήσεων ως τώρα συνολικά 
    //( failed applications ).
    int failed_applications()
    {
        
    }

    // Μπορούμε να εκτυπώσουμε τις #διαθέσιμες πτήσεις# καθώς και τις 
    //πληροφορίες της κάθε πτήσης, με σειρά ώρας αναχώρησης ( show timetable ).
    void show_timetable();

    // Μπορούμε να εκτυπώσουμε τα ονοματεπώνυμα αυτών που οι αιτήσεις τους βρίσκονται 
    //στην λίστα αναμονής ( show people waiting ).
    //Prints the full names of the applicants in waiting list. Returns the count.
    int show_people_waiting()
    {
        
    }

    // Η διαδικασία flow time , με όρισμα το χρονικό διάστημα που θέλουμε να περάσει,
    //κινεί το χρόνο. Κατά την διαδικασία αυτή, κάθε πτήση που είναι να αναχωρήσει 
    //εντός αυτού του διαστήματος ελευθερώνει τον σταθμό που καταλαμβάνει και τα 
    //ονοματεπώνυμα των επιβατών που επιβαίνουν καθώς και ο προορισμός της εκτυπώνονται.
    //Επίσης, αιτήσεις που αναφέρονται στο διάστημα αυτό και δεν
    //ικανοποιήθηκαν διαγράφονται από τη λίστα αναμονής (ακυρώνονται).
    void flow_time(const time_t &duration, const time_t &step = 60)
    {
        time_t end_time = m_current_time + duration;
        while(m_current_time<end_time)
        {
            m_current_time+=step;
            std::cout << m_current_time << "\n";
        }
        
    }
    
    void read_flights ( const char* filename );

};


#endif