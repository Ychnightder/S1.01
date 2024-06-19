#include "rapport.h"
#include "iostream"
#include "../mission/mission.h"
#include "../acceptation/acceptation.h"

    using namespace  std;

     const int tailleTabR = 4;

    rapport tabRapport[tailleTabR] = {
            {ZERO , "Succes", 0},
            {UN,"Local non accessible" , 0},
            {DEUX,"Pas de signal dans le boitier general" , 0.055},
            {TROIS ,"Recepteur defectueux", 0.4 }
    };




    bool verifiCode(int c){
        return c == UN || c == DEUX || c == TROIS || c == ZERO;
    }

    bool verifiMissio(int id){
        auto it = tabAttribue.find(id);
        if (it != tabAttribue.end()){
            return true;
        }
        return false;
     }

    string getDetail(int cr){
        for (int i = 0; i < tailleTabR; ++i) {
            if (tabRapport[i].code == cr){
                return tabRapport[i].Signification;
            }
        }
        return "";
    }

    void Rapport(){
        int idMission ;
        int codeRapport  ;
        bool verifrapport = true;

        cin >> idMission >> codeRapport;

        if (!verifiCode(codeRapport)){
            cout << "Code de retour incorrect" << endl;
            verifrapport = false;
        }

        if (!verifiMissio(idMission)){
            cout << "Mission incorrecte" << endl;
            verifrapport = false;
        }

       if (verifrapport) {
           auto it = tabAttribue.find(idMission);
           if (it != tabAttribue.end()) {
               it->second.detail = getDetail(codeRapport);
               switch (codeRapport) {
                   case ZERO:
                       cout << "Rapport enregistre" << endl;
                       break;

                   case UN:
                   case DEUX:
                   case TROIS:
                       it->second.idMission = compteurMission;
                       it->second.remunerations = majorerMission(it->second.remunerations, codeRapport);
                       tabMissionNonAttribue.insert({compteurMission, it->second});
                       tabAttribue.erase(it);
                       cout << "Rapport enregistre (" << compteurMission++ << ")" << endl;
                       break;
               }
           }
        }
        return;
    }

    double getMajoration(int cr){
        for (int i = 0; i < tailleTabR; ++i) {
            if (tabRapport[i].code == cr){
                return tabRapport[i].majoration;
            }
        }
        return 0;
    }

    double majorerMission(double prixMission , double codeR){
            double Majoration = getMajoration(codeR);
            if(prixMission > 0) {
                double sommeAug = prixMission * Majoration;
                prixMission += sommeAug;
            } else  {
                cout << "prix Mission incorrect" <<endl;
            }
            return prixMission;
    }
