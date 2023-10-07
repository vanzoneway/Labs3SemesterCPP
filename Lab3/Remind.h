//
// Created by PC on 06.10.2023.
//

#ifndef LAB3_REMIND_H
#define LAB3_REMIND_H

#include "BCalendar.h"
class Remind : public BCalendar {
private:
    tm time_to_remind_;
public:
    explicit Remind(const tm& date)
    : BCalendar(date)
    {}

    void showMessage() const override;

    void setTimeToRemind(const tm& time_to_remind);

    tm getTimeToRemind();



};


#endif //LAB3_REMIND_H
