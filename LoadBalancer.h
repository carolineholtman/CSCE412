#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <string>
#include <vector>
#include "Request.h"
#include "Webserver.h"

class LoadBalancer
{
private:
    // Private member variables
    std::vector<Request> requestQueue; // Queue of incoming requests
    std::vector<Webserver> servers; // List of available web servers
    int time;

    
public:
    // Constructor
    // generate random in & out IPs, time to be processed, and job types
    LoadBalancer();
    
    void addServer();
    void removeServer();

    void addRequest();

    void assignRequest();
    

};

#endif // LOADBALANCER_H