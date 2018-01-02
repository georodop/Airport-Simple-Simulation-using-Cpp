#include "airportc.h"
#include <fstream>                  //For ifstream
#include <cstdlib>                  //For exit
#include <sstream>          // for std::stringstream

void Airport::schedule_flight(const Flight &new_flight)
{
    m_timetable.insert(new_flight);
}


/*******************************************************************************
 *  Assumes well formated .csv file with head row and 6 columns like this:
 *      1) Flight ID
 *      2) destination;
 *      3) dep_time;
 *      4) duration;
 *      5) a_capacity;
 *      6) b_capacity;
 * 
 * ****************************************************************************/
void Airport::read_flights ( const char* filename )
{
    using std::ifstream;
    using std::cerr;
    using std::cout;
    using std::endl;
    
    std::ifstream csv(filename);
 
    // If we couldn't open the input file stream for reading
    if (!csv)
    {
        // Print an error and exit
        cerr << "Oh, " << filename << " could not be opened for reading!" << "\n";
        exit(1);
    }
 
    
    {//headrow is temp var just to skip first line
        string headrow;
        getline(csv, headrow);
    }
    
    //Read a csv file line by line
    while(csv)
    {
        std::string line;
        getline(csv, line);
        //Then read each line for comma separated variables
        if(!line.empty())
        {
            std::stringstream line_ss(line);
            int vars_count = 6;
            std::string vars[vars_count];
            int i(0);
            while(getline(line_ss, vars[i], ','))
            {
                if(!vars[i].empty())
                {
                    // cout << vars[i] << "\t";
                    i++;
                }
            }
            // cout << i << endl;
            std::stringstream var1(vars[1]);
            std::stringstream var2(vars[2]);
            std::stringstream var3(vars[3]);
            std::stringstream var4(vars[4]);
            std::stringstream var5(vars[5]);
            
            string destination;
            time_t dep_time;
            time_t duration;
            int a_capacity;
            int b_capacity;
            
            var1 >> destination;
            var2 >> dep_time;
            var3 >> duration;
            var4 >> a_capacity;
            var5 >> b_capacity;
            
            Flight flight(destination, dep_time, duration, a_capacity, b_capacity);
            Airport::schedule_flight(flight);
        }
    }
}



void Airport::show_timetable()
{
    using std::cout;
    using std::endl;
    
    Flights_list::iterator iter;
    // cout<<m_timetable.size()<<endl;
    // int ii=0;
    for(iter=m_timetable.begin(); iter!=m_timetable.end();++iter)
    {
        // ii+=1;
        // cout<<ii<<endl;
        cout << (*iter) << endl;
    }
}