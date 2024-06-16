#include "rapport.h"
#include "iostream"
#include "../mission/mission.h"

using namespace  std;



    bool verifiCode(int c){
        return c == UN || c == DEUX || c == TROIS || c == ZERO;
    }


    void Rapport(){
        int idMission;
        int codeRapport;
        bool verifrapport = true;
        cin >> idMission;
        cin >> codeRapport;

        for (int i = 0; i < getCompteurMission(); ++i) {
            if (idMission != tabMission[i].idMission){
                cout << "Mission incorrecte ";
                verifrapport = false;
                break;
            }
        }
        if (!verifiCode(codeRapport)){
            cout << "Code de retour incorrect";
            verifrapport = false;
            return;
        }

        if (verifrapport){

            for (int i = 0; i < getCompteurMission(); ++i) {
                if (tabMission[i].idMission == idMission){
                    rapport rapporGenerale = *new rapport;

                    switch (codeRapport) {
                        case ZERO:
                            rapporGenerale.detail ="Succes";
                            rapporGenerale.majoration = 0;
                            break;

                        case UN:
                            rapporGenerale.detail ="Local non accessible";
                            rapporGenerale.majoration = 0;
                            break;
                        case DEUX:
                            rapporGenerale.detail ="Pas de signal dans le boitier general";
                            rapporGenerale.majoration = 0.055;
                            break;

                        case TROIS:
                            rapporGenerale.detail ="Recepteur defectueux";
                            rapporGenerale.majoration = 0.4;
                            break;
                    }
                    tabMission[i].rapport =rapporGenerale;
                    break;
                }
            }

        }
    }
