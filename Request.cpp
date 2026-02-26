#include "Request.h"

#include <string>
#include <random>

Request::Request() {
    // Default constructor implementation
    IP_in = generateRandomIP();
    IP_out = generateRandomIP();
    std::mt19937 gen(std::random_device{}());
    time_cc = std::uniform_real_distribution<float>(2.0f, 20.0f)(gen);
    jobType = (std::uniform_int_distribution<>(0, 1)(gen) == 0) ? "S" : "P";// to be implemented with switch

}

std::string Request::generateRandomIP() {
    // Implementation to generate a random IP address
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);

    return std::to_string(dis(gen)) + "." +
           std::to_string(dis(gen)) + "." +
           std::to_string(dis(gen)) + "." +
           std::to_string(dis(gen));

}



std::string Request::getIPIn() const {
    return IP_in;
}

std::string Request::getIPOut() const {
    return IP_out;
}

float Request::getTimeCC() const {
    return time_cc;
}

std::string Request::getJobType() const {
    return jobType;
}

