#include "Task.h"

void Task::showMessage() const {
    cout << "Information about your Task: \n" << info_ << endl;
}

void Task::addExtraInfo(const string &extra_info) {
    add_info_aboutTask_ = extra_info;
}

void Task::showExtraInfo() const {
    cout << "Something more about your task: \n" << add_info_aboutTask_ << endl;
}
