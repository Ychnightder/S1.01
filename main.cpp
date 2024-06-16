#include "iostream"
#include "exit/exit.h"
#include "inscription/inscription.h"
#include "mission/mission.h"
#include "consultation/consultation.h"
#include "detail/detail.h"
#include "acceptation/acceptation.h"
#include "string"




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

    struct Command{
        string command;
        void (*functionCommand)();
    };

int main() {
    init();
    Command commands[] = {
            {"inscription", inscription}, // Command 1
            {"mission", Mission},         // Command 2
            {"consultation", consultation},
            {"acceptation", acceptation },
            {"detail", detail},
            {"exit", fin},
            {"rapport" , Rapport},
//            {"Recapitulatif" , Recapitulatif},
//            {"Sous-traitance" ,SousTraitance }
    };
    string operation;
    while (1){
        cin >> operation;
        for (Command cmd : commands) {
            if (cmd.command == operation){
                cmd.functionCommand();
            }
        }
    }
    supp();
    fin();
}



