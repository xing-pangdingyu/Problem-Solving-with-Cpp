#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <iomanip>

enum class Day_in_Week { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

Day_in_Week read_day_in_week(const std::string& name) {
    std::string str;

    while (true) {
        std::cout << "Input the day in a week of " << name
                  << " in the format Mo, Tu, etc.: ";

        if ((std::cin >> str) && str.size() == 2) {

            char c_1 = static_cast<char>(std::tolower(static_cast<unsigned char>(str[0])));
            char c_2 = static_cast<char>(std::tolower(static_cast<unsigned char>(str[1])));

            if (c_1 == 'm' && c_2 == 'o') return Day_in_Week::Monday;
            if (c_1 == 't' && c_2 == 'u') return Day_in_Week::Tuesday;
            if (c_1 == 'w' && c_2 == 'e') return Day_in_Week::Wednesday;
            if (c_1 == 't' && c_2 == 'h') return Day_in_Week::Thursday;
            if (c_1 == 'f' && c_2 == 'r') return Day_in_Week::Friday;
            if (c_1 == 's' && c_2 == 'a') return Day_in_Week::Saturday;
            if (c_1 == 's' && c_2 == 'u') return Day_in_Week::Sunday;
        }
        std::cerr << "Invalid input. Please use format Mo, Tu, etc.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string read_24_hours_time(const std::string& name) {
    std::string str;

    while (true) {
        std::cout << "Input the time of " << name
                  << " in 24 hours (e.g. 13:30): ";

        if ((std::cin >> str) && str.size() == 5 && str[2] == ':') {
            std::string hour_str = str.substr(0, 2);
            std::string minute_str = str.substr(3, 2);

            if (std::isdigit(static_cast<unsigned char>(hour_str[0])) &&
                std::isdigit(static_cast<unsigned char>(hour_str[1])) &&
                std::isdigit(static_cast<unsigned char>(minute_str[0])) && 
                std::isdigit(static_cast<unsigned char>(minute_str[1]))) {

                int hour   = std::stoi(hour_str);
                int minute = std::stoi(minute_str);

                if (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59) {
                    return str;
                }
            }
        }
        std::cerr << "Invalid input. Please use format HH:MM "
                  << "(00 <= HH <= 23, 00 <= MM <= 59).\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

bool time_is_between(const std::string time_str, int after_hour, int after_minute,
                                           int before_hour, int before_minute) {

    int hour = std::stoi(time_str.substr(0, 2));
    int minute = std::stoi(time_str.substr(3, 2));

    if ((hour > after_hour || (hour == after_hour && minute >= after_minute)) &&
        (hour < before_hour || (hour == before_hour && minute < before_minute))) {
            return true;
        }
    return false;
}

int read_positive_int(const std::string& name) {
    int value = 0;

    while (true) {
        std::cout << "Input the value of " << name << ": ";

        if ((std::cin >> value) && value > 0) {
            return value;
        }
        std::cerr << "Invalid input for " << name << ".\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main()
{
    constexpr double daytime_weekday_fee = 0.40;
    constexpr double nondaytime_weekday_fee = 0.25;
    constexpr double weekend_fee = 0.15;

    double bill = 0;

	Day_in_Week day = read_day_in_week("phone call");
	std::string starting_time = read_24_hours_time("phone call");
    int length_call = read_positive_int("length of phone call");

    if (day == Day_in_Week::Saturday || day == Day_in_Week::Sunday) {
        bill = weekend_fee * length_call;
    } else if (time_is_between(starting_time, 8, 0, 18, 0)) {
        bill = daytime_weekday_fee * length_call;
    } else {
        bill = nondaytime_weekday_fee * length_call;
    }

    std::cout << std::fixed << std::setprecision(2);
	std::cout << "Bill: $" << bill << '\n';

	return 0;
}
