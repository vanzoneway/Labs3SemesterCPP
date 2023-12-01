//
// Created by PC on 06.10.2023.
//

#ifndef LAB4_REMIND_H
#define LAB4_REMIND_H

#include "BCalendar.h"
class Remind : public BCalendar {
private:
    tm time_to_remind_;
public:
    explicit Remind(const tm& date)
    : BCalendar(date)
    {}

    void showMessage() const override;




};


#endif //LAB4_REMIND_H
