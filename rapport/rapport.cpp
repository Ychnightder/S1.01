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

    bool verifiMissio(int idc){
        for (int i = 0; i < compteurAc; ++i) {
            if (tabAttribue[i].m->idAncienMission == idc){
                return true;
            }
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
        int idMission = 1;
        int codeRapport = 1 ;
        bool verifrapport = true;

//        cin >> idMission;
//        cin >> codeRapport;

        if (!verifiCode(codeRapport)){
            cout << "Code de retour incorrect" << endl;
            verifrapport = false;
        }

        if (!verifiMissio(idMission)){
            cout << "Mission incorrecte" << endl;
            verifrapport = false;
        }

//        if (verifrapport) {
//            for (int i = 0; i < compteurAc; ++i) {
//                if (tabAttribue[i].m->idAncienMission == idMission) {
//                    switch (codeRapport) {
//                        case ZERO:
//                            tabAttribue[i].m->detail = getDetail(codeRapport);
//                            cout << "Rapport enregistre" << endl;
//                            break;
//
//                        case UN:
//                        case DEUX:
//                        case TROIS:
//                            tabAttribue[i].m->detail = getDetail(codeRapport);
//                            tabAttribue[i].m->idMission = compteurM + 1;
//                            tabAttribue[i].m->prix = majorerMission(tabAttribue[i].m->prix, codeRapport);
//                            RepublierMission(tabAttribue[i].m->idAncienMission, tabAttribue[i].m->nom, tabAttribue[i].m->prix);
//                            cout << "Rapport enregistre (" << compteurM << ")" << endl;
//                            tabAttribue[i].m = nullptr;
//                            tabAttribue[i].e = nullptr;
//                            break;
//                    }
//                    break;
//                }
//            }
//        }


        if (verifrapport){
            for (int i = 0; i < compteurAc; ++i) {
                if (tabAttribue[i].m->idAncienMission == idMission){
                    switch (codeRapport) {
                        case ZERO:
                            tabAttribue[i].m->detail = getDetail(codeRapport);
                            break;

                        case UN:
                            tabAttribue[i].m->detail = getDetail(codeRapport);
                            break;

                        case DEUX:
                            tabAttribue[i].m->detail = getDetail(codeRapport);
                            break;

                        case TROIS:
                            tabAttribue[i].m->detail = getDetail(codeRapport);
                            break;
                    }
                    break;
                }
            }
            if (codeRapport != ZERO){
                for (int i = 0; i < compteurAc; ++i) {
                    if (tabAttribue[i].m->idAncienMission == idMission) {
                        compteurM++;
                        tabAttribue[i].m->idMission = tabAttribue[i].m->idAncienMission;
//                        tabAttribue[i].m->nomEntreprise = tabAttribue[i].e->nomEntreprise;
                        tabAttribue[i].m->prix = majorerMission(tabAttribue[i].m->prix , codeRapport);
                        RepublierMission(tabAttribue[i].m->idMission ,tabAttribue[i].m->nom,tabAttribue[i].m->prix );
                        cout << "Rapport enregistre ("<< compteurM <<")"<< endl;
                        tabAttribue[i].m = nullptr;
                        tabAttribue[i].e = nullptr;
                        break;
                    }
                }

            }
            else {
                cout << "Rapport enregistre" << endl;
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
            cout << "prixMission incorrect" <<endl;
        }

        return prixMission;
    }


