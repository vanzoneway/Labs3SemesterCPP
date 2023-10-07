#include "Meet.h"

void Meet::showMessage() const {
    cout << "Information about your Meet: \n" << info_ << endl;
}

void Meet::printTimeUntilDate() const {
    tm date_until = timeUntilDate();
    cout << "You have " << date_until.tm_year << "years, " << date_until.tm_mday << "days, " << date_until.tm_hour << "hours, "
    << date_until.tm_min << "mins, " << date_until.tm_sec << "seconds until your meeting" << endl;
}

