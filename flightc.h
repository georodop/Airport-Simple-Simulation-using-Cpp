#ifndef FLIGHTC_H
#define FLIGHTC_H 

#include <string>
#include <ctime>            //For time_t

#include "appslistc.h"
#include "applicationc.h"

using std::string;

class Flight
{
private:
    // από τον προορισμό της,
    string m_destination;
    
    // την ώρα αναχώρησης από το αεροδρόμιο,
    time_t m_dep_time;
    
    // την διάρκεια της πτήσης και 
    time_t m_duration;
    
    // το μέγιστο αριθμό επιβατών σε κάθε θέση (θέσεις Α και Β).
    int m_luxury_max_capacity;
    int m_economy_max_capacity;
    
    Apps_list m_bookings;

public:
    // Μια πτήση αρχικοποιείται με όλες τις παραπάνω παραμέτρους. 
    Flight();       //ToDo

    // Μια πτήση δέχεται μια αίτηση και αν ο αντίστοιχος επιβάτης χωράει στο αεροπλάνο,
    //τον προσθέτει (σαν κλεισμένη θέση) ( add passenger ). 
    // Returns if the passenger was added or not
    bool add_passenger(const Application &passenger);

    // Δίδοντας ένα id επιβάτη, μπορούμε να ακυρώσουμε όλες τις κλεισμένες θέσεις για 
    //αιτήσεις με το συγκεκριμένο id ( cancel reservations ).
    bool cancel_reservations(const int &id);
    
    // Μπορούμε να ανακτήσουμε την ώρα αναχώρησης της πτήσης ( departs at ).
    time_t departs_at();

    // Μπορούμε να ανακτήσουμε την ώρα άφιξης της πτήσης στον προορισμό της ( arrives at ).
    time_t arrives_at();

    // Μπορούμε να ανακτήσουμε τον προορισμό της πτήσης ( get destination ).
    string get_destination();

    // Μπορούμε να ανακτήσουμε τον αριθμό των διαθέσιμων θέσεων της πτήσης 
    // (ανεξαρτήτως θέσης Α ή Β) ( get available ).
    int get_available();

    // Μπορούμε να ανακτήσουμε μια δομή με τις αιτήσεις που έχουν κλειστεί στην 
    // συγκεκριμένη πτήση ( get bookings ).
    Apps_list get_bookings();

};

#endif