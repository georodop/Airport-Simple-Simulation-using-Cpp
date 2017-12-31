#include "airportc.h"


void Airport::schedule_flight(const Flight &new_flight)
{
    m_timetable.insert(new_flight);
}