#include <iostream>
#include <fstream>
#include "Webserver.h"
#include "Request.h"
#include "LoadBalancer.h"

int main() {

    //fields for user input
    int numServers, runTime;

    std::ifstream inputFile("userinputconfig.txt");
    if (inputFile.is_open()) {
        std::string line;
        size_t lineCount = 1;
        while(std::getline(inputFile, line)) {
            size_t equalSign = line.find('=');
            if(lineCount == 1){
                numServers = std::stoi(line.substr(equalSign+1));
            }
            else{
                runTime = std::stoi(line.substr(equalSign+1));
            }
            lineCount++;
        }
        inputFile.close();
    } else {
        std::cout<<"No userconfig.txt file found.\nUsing terminal input instead.\n";
        std::cout << "Enter the number of servers: ";
        std::cin >> numServers;
        std::cout << "Enter the runtime for Load Balancer (clock cycles): ";
        std::cin >> runTime;
    }

    std::ofstream outputLog("outputlog.txt");

    LoadBalancer lb(numServers, numServers*100);

    for(int i = 0; i < runTime; i++){
        lb.onClockTick(outputLog);
    }
    
    outputLog.close();

    return 0;
}