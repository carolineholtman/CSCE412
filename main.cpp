#include <iostream>
#include <fstream>
#include "Webserver.h"
#include "Request.h"
#include "LoadBalancer.h"

int main() {

    //fields for user input
    int numServers, runTime;

    std::ifstream inputFile("userconfig.txt");
    if (inputFile.is_open()) {
        std::string line;
        while(std::getline(inputFile, line)) {
            
        }
        inputFile.close();
    } else {
        std::cout<<"No userconfig.txt file found.\nUsing terminal input instead.\n";
        std::cout << "Enter the number of servers: ";
        std::cin >> numServers;
        std::cout << "Enter the runtime for Load Balancer (clock cycles): ";
        std::cin >> runTime;
    }



    return 0;
}