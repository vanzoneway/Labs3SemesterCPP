#include "BCalendar.h"
#include <iostream>
using namespace std;


void BCalendar::inputInformation(const string &info) {
    info_ = info;
}

std::ostream &operator<<(ostream &out, const BCalendar &b){
    return b.print(out);
}

ostream &BCalendar::print(ostream &out) const{
    out << "Information about your Meet: \n" << info_ << endl;
    return out;
}

tm BCalendar::timeUntilDate() const {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    tm result{date_.tm_sec - now->tm_sec,date_.tm_min - now->tm_min,
              date_.tm_hour - now->tm_hour, date_.tm_mday - now->tm_mday,
              date_.tm_mon - now->tm_mon, date_.tm_year - now->tm_year };
    if (result.tm_mday < 0 )
        result.tm_mday += 30;
    if (result.tm_hour < 0)
        result.tm_hour += 24;
    if(result.tm_min < 0 )
        result.tm_min += 60;
    if(result.tm_sec < 0 )
        result.tm_sec += 60;

    if ( !isExpiredDate() )
        return result;
    return *now;
}

bool BCalendar::isExpiredDate() const {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    if(date_.tm_year - now->tm_year <= 1900 && date_.tm_mon - now->tm_mon <= 0 && date_.tm_mday - now->tm_mday <= 0)
        return true;
    return false;
}
