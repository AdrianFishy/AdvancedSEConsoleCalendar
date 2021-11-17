#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>

bool get_leap_year(int year);
int get_max_month_day_int(int month, int year);
std::string  get_monthday_string (int month);
void clear_screen();


int main() {
    bool run = true;

    time_t now = time(0);
    tm *ltm = localtime(&now);
    int const yeardiff = 1900;
    int month_selected = ltm->tm_mon;
    int year_selected = ltm ->tm_year + yeardiff;
    int selected;
    do {
        std::cout << "year " << year_selected << std::endl;
        std::cout << "get_max: " << get_max_month_day_int(month_selected, year_selected) << std::endl;

        std::cout << get_monthday_string(month_selected) << " Year:  " << year_selected << std::endl;
        std::cout << "MO        |DI        |MI        |DO        |FR        |SA        |SO        |" << std::endl;
        std::cout << "_____________________________________________________________________________" << std::endl;

        for (int i = 1; i <= get_max_month_day_int(month_selected, year_selected); i++) {

            if (i <= 9) {
                std::cout << i << "         |";
            } else {
                std::cout << i << "        |";
            }
            if ((i % 7) == 0) {
                std::cout << std::endl;
            }
        }

        std::cout << std::endl;
        std::cout << "Bitte 2 für nächsten Monat und 1 für vorherigen Monat eingeben, 3 für exit: "  <<std::endl;
        std::cin >> selected;
        clear_screen();

        switch (selected) {

            case 1:
                month_selected -= 1;
                if (month_selected < 0){
                    month_selected = 11;
                    year_selected -= 1;
                }
                break;
            case 2:
                month_selected += 1;
                if (month_selected == 12){
                    month_selected = 0;
                    year_selected += 1;
                }
                break;
            case 3:
                run = false;
        }

    }while (run);


    

    return 0;
}


std::string get_monthday_string (int month){
    std::string return_month_string;

    switch (month) {

        case 0:
            return_month_string = "Jan";
            break;

        case 1:
            return_month_string = "Feb";
            break;

        case 2:
            return_month_string = "Mar";
            break;

        case 3:
            return_month_string = "Apr";
            break;

        case 4:
            return_month_string = "Mai";
            break;

        case 5:
            return_month_string = "Jun";
            break;

        case 6:
            return_month_string = "Jul";
            break;

        case 7:
            return_month_string = "Aug";
            break;

        case 8:
            return_month_string = "Sep";
            break;

        case 9:
            return_month_string = "Okt";
            break;

        case 10:
            return_month_string = "Nov";
            break;

        case 11:
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

        case 0:
            return_max_month_days = thirtyone;
            break;

        case 1:
            if (is_leap_year){
                return_max_month_days = 29;
            }
            else{
                return_max_month_days = 28;
            }
            break;

        case 2:
            return_max_month_days = thirtyone;
            break;

        case 3:
            return_max_month_days = thirty;
            break;

        case 4:
            return_max_month_days = thirtyone;
            break;

        case 5:
            return_max_month_days = thirty ;
            break;

        case 6:
            return_max_month_days = thirtyone;
            break;

        case 7:
            return_max_month_days = thirtyone;
            break;

        case 8:
            return_max_month_days = thirty;
            break;

        case 9:
            return_max_month_days = thirtyone;
            break;

        case 10:
            return_max_month_days = thirty;
            break;

        case 11:
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

void clear_screen()
{
    int n;
    for (n = 0; n < 10; n++)
        std::cout << "\n\n\n\n\n\n\n\n\n\n" << std::endl;
}