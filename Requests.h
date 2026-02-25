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
    // generate random in & out IPs, time to be processed, and job types
    Requests();
    
    // Destructor
    //~Requests();
    
    // Public member functions
    // getters for IPs, time, and job type
    std::string getIPIn() const;
    std::string getIPOut() const;
    float getTimeCC() const;
    std::string getJobType() const;
};

#endif // REQUESTS_H