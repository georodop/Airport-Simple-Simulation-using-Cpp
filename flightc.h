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
    int m_a_capacity;
    int m_b_capacity;
    
    Apps_list m_bookings;

public:
    // Μια πτήση αρχικοποιείται με όλες τις παραπάνω παραμέτρους. 
    Flight
    (
        const string &destination, 
        const time_t &dep_time, 
        const time_t &duration,
        const int &a_capacity,
        const int &b_capacity
    ):  
        m_destination(destination),
        m_dep_time(dep_time),
        m_duration(duration),
        m_a_capacity(a_capacity),
        m_b_capacity(b_capacity)
    {
        
    }

    // Μια πτήση δέχεται μια αίτηση και αν ο αντίστοιχος επιβάτης χωράει στο αεροπλάνο,
    //τον προσθέτει (σαν κλεισμένη θέση) ( add passenger ). 
    // Returns if the passenger was added or not
    bool add_passenger(const Application &passenger);

    // Δίδοντας ένα id επιβάτη, μπορούμε να ακυρώσουμε όλες τις κλεισμένες θέσεις για 
    //αιτήσεις με το συγκεκριμένο id ( cancel reservations ).
    bool cancel_reservations(const int &id);
    
    // Μπορούμε να ανακτήσουμε την ώρα αναχώρησης της πτήσης ( departs at ).
    inline time_t departs_at() const { return m_dep_time; }

    // Μπορούμε να ανακτήσουμε την ώρα άφιξης της πτήσης στον προορισμό της ( arrives at ).
    inline time_t arrives_at() const { return (m_dep_time + m_duration); }

    // Μπορούμε να ανακτήσουμε τον προορισμό της πτήσης ( get destination ).
    string get_destination() const{ return m_destination; }

    // Μπορούμε να ανακτήσουμε τον αριθμό των διαθέσιμων θέσεων της πτήσης 
    // (ανεξαρτήτως θέσης Α ή Β) ( get available ).
    int get_available() const {}

    // Μπορούμε να ανακτήσουμε μια δομή με τις αιτήσεις που έχουν κλειστεί στην 
    // συγκεκριμένη πτήση ( get bookings ).
    Apps_list get_bookings() const;
    
    bool operator< (const Flight &right) const
    {
        return m_dep_time < right.m_dep_time;
    }

};

#endif