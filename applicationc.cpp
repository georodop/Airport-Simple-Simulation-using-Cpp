#include <string>

#include "applicationc.h"
#include "flightc.h"



// Μπορούμε να ελέγξουμε αν μια πτήση πληρεί τους περιορισμούς μιας αίτησης ( matches ).
bool Application::matches(const Flight &flight, const time_t &time_now)
{
    //Compare destination
    //if(m_destination.compare(flight.get_destination))
        //Check if there are available seats
        if(flight.get_available()) 
            //Compare flight arrives_at with application's arrived_by
            if(flight.arrives_at() <= arrived_by())
                //Compare flight dep. time with appl. time at airport
                if(flight.departs_at() >= time_at_airport(time_now))
                    return true;
         
    return false;
    
}
