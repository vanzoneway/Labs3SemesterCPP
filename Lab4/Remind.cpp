#include "Remind.h"


tm Remind::getTimeToRemind() {
    return time_to_remind_;
}



void Remind::showMessage() const {
    cout << "Information about your Meet: \n" << info_ << endl;
}
