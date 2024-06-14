#include "iostream"
#include "exit/exit.h"
#include "inscription/inscription.h"
#include "mission/mission.h"

void init(){
    initTabEntreprise(100);
    initTabEntreprise(100);
}
void supp(){
    suppTabEntreprise();
    suppTabEntreprise();
}

int main() {
    init();
    inscription();
    cout << "misssion";
    Mission();
    inscription();
    supp();
    return 0;
}