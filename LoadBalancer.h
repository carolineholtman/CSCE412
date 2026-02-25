#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <string>
#include <vector>

class LoadBalancer
{
private:
    // Private member variables
    std::vector<Requests> requestQueue; // Queue of incoming requests
    
    
public:
    // Constructor
    // generate random in & out IPs, time to be processed, and job types
    LoadBalancer();
    
    // Destructor
    //~LoadBalancer();
    
    // Public member functions

};

#endif // LOADBALANCER_H