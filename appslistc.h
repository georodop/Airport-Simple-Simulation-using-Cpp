#ifndef APPSLISTC_H
#define APPSLISTC_H

#include "applicationc.h"
#include <deque>            //Why deque: http://www.gotw.ca/gotw/054.htm

class Apps_list
{
private:

public:
    std::deque<Application> m_applications;

};

#endif