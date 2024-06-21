#include "iostream"
#include "exit/exit.h"
#include "inscription/inscription.h"
#include "mission/mission.h"
#include "consultation/consultation.h"
#include "detail/detail.h"
#include "acceptation/acceptation.h"
#include "string"
#include "rapport/rapport.h"
#include "Recapitulatif/Recapitulatif.h"
#include "sous_traitance/sous_traitance.h"


struct Command{
        string command;
        void (*functionCommand)();
    };

int main() {
    Command commands[] = {
            {"inscription", inscription}, // Command 1
            {"mission", Mission},         // Command 2
            {"consultation", consultation},
            {"acceptation", acceptation },
            {"detail", detail},
            {"exit", fin},
            {"r" , Rapport},
           {"recapitulatif" , recapitulatif},
            {"sous-traitance" ,sous_traitance },
            {"afficherE", affichageEntreprise},
            {"afficherM", affichageMission},
            {"afficherA", affichageAttribue},

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
    fin();
}

//S1_01.exe < in-sp4-base.txt > test.txt
// fc /w out-sp4-base.txt test.txt

//S1_01.exe < in-sp3-base.txt > test.txt
// fc /w out-sp3-base.txt test.txt

//S1_01.exe < in-sp2-base.txt > test.txt
// fc /w out-sp2-base.txt test.txt

//S1_01.exe < in-sp1-base.txt > test.txt
// fc /w out-sp1-base.txt test.txt

//S1_01.exe < in-sp1-erreur.txt > test.txt
// fc /w out-sp1-erreur.txt test.txt

//inscription OP Operateur
//inscription IN Intervenant1
//inscription AG agence1
//mission 1 Mission1 5.00
//mission 1 Mission2 5.00
//mission 1 Mission3 5.00
//Sous-traitance 3 2 25.25
//
//rc 1
//ac 2 1
//ac 2 2
//ac 2 3
//rc 1


//inscription AG Agence
//inscription IN Intervenant1
//mission 1 Mission1 5.00
//recapitulatif 1
//acceptation 2 1
//recapitulatif 1
//recapitulatif 2
//r 1 0
//recapitulatif 1
//recapitulatif 2
//mission 1 Mission2 10.00
//consultation
//acceptation 2 2
//r 2 2