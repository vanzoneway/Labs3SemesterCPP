//
// Created by PC on 04.10.2023.
//

#ifndef LAB4_BCALENDAR_H
#define LAB4_BCALENDAR_H


#include <ctime>
#include <string>
#include <iostream>
using namespace std;

class BCalendar{
protected:
    explicit BCalendar(const tm& date = {0, 0, 0, 0, 0, 0, 0, 0, 0})
            : date_(date)
    {}
    tm date_;
    string info_;

public:
    [[nodiscard]] tm timeUntilDate() const;
    [[nodiscard]] bool isExpiredDate() const;
    virtual void showMessage() const = 0;
    virtual ostream& print(ostream& out) const;
    virtual ~BCalendar() = default;
    void inputInformation(const string& info);
    friend std::ostream& operator<<(std::ostream& out, const BCalendar& b) ;


};


#endif //LAB4_BCALENDAR_H
