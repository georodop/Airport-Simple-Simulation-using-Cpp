#ifndef APPLICATIONC_H
#define APPLICATIONC_H

#include <ctime>            //For time_t
#include <string>
using std::string;

class Flight; 

class Application
{
private:
    // το id του επιβάτη, 
    int m_id;
    
    // το όνομά του, 
    string m_first_name;
    
    // επώνυμο, 
    string m_surname;
    
    // προορισμό, 
    string m_destination;

    // χρόνο που θέλει για να φτάσει στο αεροδρόμιο 
    // (δεν μπορεί να επιβιβαστεί σε αεροπλάνο με χρόνο αναχώρησης πριν από αυτόν), 
    time_t m_time_to_airport;

    // χρόνο που θέλει να έχει φτάσει στον προορισμό του 
    // (δεν μπορεί να επιβιβαστεί σε αεροπλάνο που φτάνει μετά από αυτόν τον χρόνο)
    int m_arrived_by;

    // αν θέλει να είναι στην οικονομική θέση του αεροπλάνου ή όχι (θέσεις Α και Β). 
    bool m_luxury_class;


public:
//Constructor:
// Μια αίτηση αρχικοποιείται με όλες τις παραπάνω παραμέτρους.
    Application
    (
        int id, string first_name, string surname, string destination,
        time_t time_to_airport, time_t arrived_by, bool luxury_class
    ):  m_id(id), m_first_name(first_name), m_surname(surname), 
        m_destination(destination), m_time_to_airport(time_to_airport),
        m_arrived_by(arrived_by), m_luxury_class(luxury_class)
    {
        
    }

    // Μπορούμε να ελέγξουμε αν μια πτήση πληρεί τους περιορισμούς μιας αίτησης ( matches ).
    bool matches(const Flight flight);
    
    // Μπορούμε να ελέγξουμε αν μια αίτηση ζητά δέσμευση Α θέσης ( is luxury class ).
    bool is_luxury_class() { return m_luxury_class; }

    // Μπορούμε να ανακτήσουμε την ταυτότητα του επιβάτη που έκανε την αίτηση ( get id ).
    int get_id() { return m_id; }

    // Μπορούμε να ανακτήσουμε το όνομα και το επώνυμο του επιβάτη που έκανε την αίτηση 
    // (σαν συμβολοσειρά, χωρισμένα με ένα κενό) ( get name ).
    string get_name() { return m_first_name + ' ' + m_surname; }
    
    // Μπορούμε να ανακτήσουμε το όριο χρόνου στο οποίο ο
    // επιβάτης επιθυμεί να έχει φτάσει στον προορισμό του ( arrived by ).
    time_t arrived_by() { return m_arrived_by; }
    
    // What time can the passenger be at the airport
    time_t time_at_airport(time_t time_now) { return m_time_to_airport + time_now; }
};


#endif