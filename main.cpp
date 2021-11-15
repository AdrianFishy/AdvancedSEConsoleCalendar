#include <iostream>
#include <ctime>

int main() {
    bool run = true;


    time_t now = time(0);
    std::cout << "Number of sec since January 1,1970 is:: " << now << std::endl;

    tm *ltm = localtime(&now);

    // print various components of tm structure.
    std::cout << "Wday:" << ltm->tm_wday<<std::endl;
    std::cout << "Year:" << 1900 + ltm->tm_year<<std::endl;
    std::cout << "Month: "<< 1 + ltm->tm_mon<< std::endl;
    std::cout << "Day: "<< ltm->tm_mday << std::endl;
    std::cout << "Time: "<< 5+ltm->tm_hour << ":";
    std::cout << 30+ltm->tm_min << ":";
    std::cout << ltm->tm_sec << std::endl;


    std::cout << "MO        |DI        |MI        |DO        |FR        |SA        |SO        |" << std::endl;



    return 0;
}