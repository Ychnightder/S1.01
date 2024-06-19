#include "iostream"
#include "exit/exit.h"
#include "inscription/inscription.h"
#include "mission/mission.h"
#include "consultation/consultation.h"
#include "detail/detail.h"
#include "acceptation/acceptation.h"
#include "string"




void init(){
    initTabEntreprise();
    initTabMission();
    initTabAttribue();
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
            {"r" , Rapport},
//            {"Recapitulatif" , Recapitulatif},
//            {"Sous-traitance" ,SousTraitance },
            {"affichageE", affichageEntreprise},
            {"affichageM", affichageMission},
            {"affichageA", affichageAttribue}


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



//S1_01.exe < in-sp2-base.txt > test.txt
// fc /w out-sp2-base.txt test.txt

//S1_01.exe < in-sp1-base.txt > test.txt
// fc /w out-sp1-base.txt test.txt


//
//inscription op orange
//inscription in vert
//inscription ag rouge
//mission 1 m1 25.55
//acceptation 2 1
//affichageA