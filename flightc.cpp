#include "flightc.h"

std::ostream& operator<<(std::ostream& os, const Flight& flight)  
{  
    os << flight.m_destination << '\t' << flight.m_dep_time << '\t' 
        << flight.m_duration << '\t' << flight.m_a_capacity << '\t' 
        << flight.m_b_capacity;
    return os;  
}  
