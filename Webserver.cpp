#include "Webserver.h"
#include <iostream>
#include <string>

// Constructor
Webserver::Webserver() {
    // Initialize server
    isProcessing = false;
    

}


bool Webserver::getIsProcessing() const {
    return isProcessing;
}

void Webserver::processRequest(const Request req) {
    // Process the incoming request
    isProcessing = true;
    std::cout << "Processing request from IP: " << req.getIPIn() << std::endl;
    //code to make the server wait for the time specified in the request
    isProcessing = false;
}


