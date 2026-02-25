#ifndef REQUESTS_H
#define REQUESTS_H

#include <string>
#include <vector>

class Requests
{
private:
    // Private member variables
    std::string IP_in;
    std::string IP_out;
    float time_cc;
    std::string jobType;
    
public:
    // Constructor
    Requests();
    
    // Destructor
    ~Requests();
    
    // Public member functions
    // getters & setters for IPs, time, and job type
    
};

#endif // REQUESTS_H