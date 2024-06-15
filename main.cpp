#include "iostream"
#include "exit/exit.h"
#include "inscription/inscription.h"
#include "mission/mission.h"

void init(){
    initTabEntreprise(100);
    initTabMission(100);
}
void supp(){
    suppTabEntreprise();
    suppTabMission();
}

int main() {
    init();
//    inscription();
    Mission();
    Mission();
    Mission();

//    inscription();
    supp();
    return 0;
}