#include "iostream"
#include "exit/exit.h"
#include "inscription/inscription.h"
#include "mission/mission.h"
#include "consultation/consultation.h"
#include "detail/detail.h"
#include "acceptation/acceptation.h"

void init(){
    initTabEntreprise(100);
    initTabMission(100);
    initTabAttribue(100);
}
void supp(){
    suppTabEntreprise();
    suppTabMission();
    suppTabAttribue();
}

int main() {
//    op orange
//    25 dupont 25.1
    init();
//    inscription();
    inscription();
    Mission();
//    Mission();
    consultation();
//
    Rapport();

    detail();

    supp();
    Exit();
}