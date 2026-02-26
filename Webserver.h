#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <string>
#include <vector>
#include "Request.h"

class Webserver
{
private:
    // Private member variables
    Request requestProcessing;
    bool isProcessing;
    float timeRemaining;
    
    
public:
    // Constructor
    
    Webserver();

  
    // Destructor
    //~Webserver();
    
    // Public member functions
    //maybe implement a process function
    void processRequest(const Request req);

    bool getIsProcessing() const;
    void onClockTick();
    
};

#endif // WEBSERVER_H