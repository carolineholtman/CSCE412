#include "LoadBalancer.h"

LoadBalancer::LoadBalancer() {
    // Constructor implementation
}


void LoadBalancer::addServer() {
    //adds new webserver to current list of servers
    servers.push_back(Webserver());
}

void LoadBalancer::removeServer() {
    //removes a webserver from the current list of servers
    if (!servers.empty()) {
        servers.pop_back();
    }
}

void LoadBalancer::addRequest() {
    //adds a new request to the current list of requests to simulate new requests being added in real time
    requestQueue.push_back(Request());
}

void LoadBalancer::assignRequest() {
    if(!requestQueue.empty()) {
        for (Webserver& server : servers) {
            if (!server.getIsProcessing()) {
                server.processRequest(requestQueue.back());
                requestQueue.pop_back();
                break;
            }
        }
    }
}