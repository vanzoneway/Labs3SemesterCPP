//
// Created by PC on 06.10.2023.
//

#ifndef LAB3_TASK_H
#define LAB3_TASK_H

#include "BCalendar.h"

class Task : public BCalendar {
private:
    string add_info_aboutTask_;
public:
    explicit Task(const tm& date)
    : BCalendar(date)
    {}

    void showMessage() const override;

    void addExtraInfo(const string& extra_info);

    void showExtraInfo() const;


};


#endif //LAB3_TASK_H
