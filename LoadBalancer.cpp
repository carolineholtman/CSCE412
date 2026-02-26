#include "LoadBalancer.h"
#include <random>
#include <sstream>
#include <string>
#include <fstream>

LoadBalancer::LoadBalancer(int serverNums, int requestQueueNums) {
    // Constructor implementation
    for (int i = 0; i < serverNums; i++) {
        servers.push_back(Webserver());
    }
    for (int i = 0; i < requestQueueNums; i++) {
        requestQueue.push(Request());
    }
    time = 0;
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
    requestQueue.push(Request());
}

void LoadBalancer::assignRequest() {
    if(!requestQueue.empty()) {
        for (Webserver& server : servers) {
            if (!server.getIsProcessing()) {
                while(!IPRangeBlocker(requestQueue.front().getIPIn())) {
                    requestQueue.pop();
                    if(requestQueue.empty()) {
                        return;
                    }
                }
                server.processRequest(requestQueue.front());
                requestQueue.pop();
                break;
            }
        }
    }
}

bool LoadBalancer::IPRangeBlocker(const std::string& ip) {
    // Implement logic to block certain IP ranges
    int first, second, third, fourth;
    std::istringstream ss(ip);
    char d;
    if(ss >> first >> d >> second >> d >> third >> d >> fourth) {
        // Example: Block IPs in the range
        if(first<0 || first>255 || second<0 || second>255 || third<0 || third>255 || fourth<0 || fourth>255 || d != '.') {
            return false; // Invalid IP format
        }

    }
    else{
        return false; // Invalid IP format
    }

    // a is 0 (invalid source), 127 (loopback), or 10 (private network)
    if(first == 0 || first == 127 || first == 10)
        return false;

    // private network 172.16-31.x.x
    if(first == 172 && (second >= 16 && second <= 31))
        return false;

    //private network 192.168.x.x
    if(first == 192 && second == 168)
        return false;

    // link-local address 169.254.x.x
    if(first == 169 && second == 254)
        return false;   
    
    // Multicast and reserved IPs
    if(first >= 224)
        return false; 
    

    return true;

    }


void LoadBalancer::onClockTick(std::ofstream& outputLog) {
    time++;

    std::mt19937 gen(std::random_device{}());
    if (std::uniform_int_distribution<>(1, 10)(gen) <= 3) // 30% chance each cycle
        addRequest();


    for(int i = 0; i < servers.size(); i++) {
        servers[i].onClockTick();
        if(servers[i].getIsProcessing()) {
            outputLog << "Time: " << std::to_string(time) << " - Server " << std::to_string(i+1) << " is processing a request.\n";
        }
        else{

            assignRequest();
            outputLog << "Time: " << std::to_string(time) << " - Server " << std::to_string(i+1) << " was idle but received a new request\n";
        }
    }


    //Implement Queue logic add / remove servers
    if(requestQueue.size() < servers.size() * 50) {
        removeServer();
        outputLog << "Time: " << std::to_string(time) << " - Server " << std::to_string(servers.size()) << " was removed.\n";
        
    }
    else if(requestQueue.size() > servers.size() * 80) {
        addServer();
        outputLog << "Time: " << std::to_string(time) << " - Server " << std::to_string(servers.size()) << " was added.\n";
    }
    outputLog << "\n";

}