#include "iostream"
#include "exit/exit.h"
#include "inscription/inscription.h"
#include "mission/mission.h"
#include "consultation/consultation.h"

void init(){
    initTabEntreprise(100);
    initTabMission(100);
}
void supp(){
    suppTabEntreprise();
    suppTabMission();
}

int main() {
//    op orange 25 dupont 25.1
    init();
//    inscription();
    inscription();
    Mission();
//    Mission();
    consultation();
//
    supp();
    return 0;
}