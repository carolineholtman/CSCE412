#include "Request.h"

#include <string>
#include <random>

Request::Request() {
    // Default constructor implementation
    IP_in = generateRandomIP();
    IP_out = generateRandomIP();
    std::mt19937 gen(std::random_device{}());
    time_cc = std::uniform_real_distribution<float>(2.0f, 20.0f)(gen);
    jobType = "S";// to be implemented with switch

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

Request::Request(const Request& other) {
    // Copy constructor implementation
    IP_in = other.IP_in;
    IP_out = other.IP_out;
    time_cc = other.time_cc;
    jobType = other.jobType;
}

Request& Request::operator=(const Request& other) {
    if (this != &other) {
        // Copy assignment implementation
        IP_in = other.IP_in;
        IP_out = other.IP_out;
        time_cc = other.time_cc;
        jobType = other.jobType;
    }
    return *this;
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

