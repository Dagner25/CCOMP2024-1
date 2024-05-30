#include "Time.h"

int main (){
    Time wapeUp{6, 45, 0};
    const Time noon{12, 0, 0};

    wakeUp.setHour(18);
    noon.setHour(12);
    wakeUp.getHour();
    noon.getMinute();
    noon.toUniversalString();
    noon.toStandardString();
}