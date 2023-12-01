//
// Created by PC on 04.10.2023.
//

#ifndef LAB4_MEET_H
#define LAB4_MEET_H

#include "BCalendar.h"

class Meet : public BCalendar {
public:
    explicit Meet(const tm& data)
    : BCalendar(data)
    {}
    void showMessage() const override;
    void printTimeUntilDate() const;

};


#endif //LAB4_MEET_H
