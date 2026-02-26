#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <string>
#include <vector>
#include <queue>
#include "Request.h"
#include "Webserver.h"

class LoadBalancer
{
private:
    // Private member variables
    std::queue<Request> requestQueue; // Queue of incoming requests
    std::vector<Webserver> servers; // List of available web servers
    int time;

    
public:
    // Constructor
    // generate random in & out IPs, time to be processed, and job types
    LoadBalancer(int serverNums, int requestQueueNums);
    
    void addServer();
    void removeServer();

    void addRequest();

    void assignRequest();

    static bool IPRangeBlocker(const std::string& ip);

    void onClockTick(std::ofstream& outputLog);
    

};

#endif // LOADBALANCER_H