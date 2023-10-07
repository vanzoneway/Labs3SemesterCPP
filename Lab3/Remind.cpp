#include "Remind.h"


tm Remind::getTimeToRemind() {
    return time_to_remind_;
}

void Remind::setTimeToRemind(const tm &time_to_remind) {
    time_to_remind_ = time_to_remind;
}

void Remind::showMessage() const {
    cout << "Information about your Meet: \n" << info_ << endl;
}
