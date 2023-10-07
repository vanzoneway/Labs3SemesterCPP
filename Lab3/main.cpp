#include <string>
#include <array>
#include "Meet.h"
#include "Task.h"
#include "Remind.h"




int main() {
    tm time_one = {0, 10, 18, 11, 12, 124};
    tm time_two = {30, 25, 7, 5, 8, 122};
    tm time_three = {10, 5, 12, 6, 3, 123};
    Meet meet(time_one);
    Task task(time_two);
    Remind remind(time_three);
    meet.printTimeUntilDate();
    meet.inputInformation("An important meeting with curator");
    cout << meet;
    task.inputInformation("Do my lab till tomorrow!");
    task.addExtraInfo("Else you might be kicked from the uni\n");
    task.showExtraInfo();
    cout << task;





    return 0;
}
