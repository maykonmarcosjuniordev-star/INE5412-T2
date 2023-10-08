#include <iostream>
#include <vector>
#include "timer.hpp"

class Replace {
public:
    Replace();
    Replace(const std::string& algorithm) {
        this->algorithm = algorithm;
        algorithm_init(algorithm);
        current_time.start();
    }
    void replace();
    void set_algorithm(const std::string& algorithm);
    void algorithm_init(std::string algorithm);

    std::string algorithm;
    Timer current_time;
    std::vector<int> file_queue;
    int page_faults = 0;
    int page_hits = 0;
    

};