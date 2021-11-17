#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>

bool get_leap_year(int year);
int get_max_month_day_int(int month, int year);


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

    std::cout << "get_max: "<< get_max_month_day_int(ltm->tm_mday, ltm->tm_year)<< std::endl;

    std::cout << "MO        |DI        |MI        |DO        |FR        |SA        |SO        |" << std::endl;
    std::cout << "_____________________________________________________________________________" << std::endl;

    for (int i = 1; i < get_max_month_day_int(ltm->tm_mon, ltm->tm_year); i++){

        if ( i <= 9) {
            std::cout << i << "         |";
        }
        else {
            std::cout << i << "        |";
        }
        if ((i % 7) == 0){
            std::cout << std::endl;
        }
    }



    

    return 0;
}


std::string get_monthday_string (int month){
    std::string return_month_string;

    switch (month) {

        case 1:
            return_month_string = "Jan";
            break;

        case 2:
            return_month_string = "Feb";
            break;

        case 3:
            return_month_string = "Mar";
            break;

        case 4:
            return_month_string = "Apr";
            break;

        case 5:
            return_month_string = "Mai";
            break;

        case 6:
            return_month_string = "Jun";
            break;

        case 7:
            return_month_string = "Jul";
            break;

        case 8:
            return_month_string = "Aug";
            break;

        case 9:
            return_month_string = "Sep";
            break;

        case 10:
            return_month_string = "Okt";
            break;

        case 11:
            return_month_string = "Nov";
            break;

        case 12:
            return_month_string = "Dez";
            break;

    }
    return return_month_string;
}

int get_max_month_day_int (int month, int year) {
    int return_max_month_days;

    const int thirtyone = 31;
    const int thirty = 30;
    bool is_leap_year = get_leap_year(year);

    switch (month) {

        case 1:
            return_max_month_days = thirtyone;
            break;

        case 2:
            if (is_leap_year){
                return_max_month_days = 29;
            }
            else{
                return_max_month_days = 28;
            }
            break;

        case 3:
            return_max_month_days = thirtyone;
            break;

        case 4:
            return_max_month_days = thirty;
            break;

        case 5:
            return_max_month_days = thirtyone;
            break;

        case 6:
            return_max_month_days = thirty ;
            break;

        case 7:
            return_max_month_days = thirtyone;
            break;

        case 8:
            return_max_month_days = thirtyone;
            break;

        case 9:
            return_max_month_days = thirty;
            break;

        case 10:
            return_max_month_days = thirtyone;
            break;

        case 11:
            return_max_month_days = thirty;
            break;

        case 12:
            return_max_month_days = thirtyone;
            break;

    }
    return return_max_month_days;
}

bool get_leap_year (int year) {
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 ==0)) {

        return true;

    }
    else {

        return false;

    }
}