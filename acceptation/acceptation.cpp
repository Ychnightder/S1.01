
#include "acceptation.h"
#include "iostream"

#include "iomanip"
    using namespace std;

    Acceptation* tabAttribue = nullptr;
    const int tailleAttribue = 500;
    int compteurAc = 0;

    void initTabAttribue() {
            tabAttribue = new Acceptation[tailleAttribue];
    }

    void suppTabAttribue(){
        delete[] tabAttribue;
        tabAttribue = nullptr;
    }

    void acceptation(){
        int entrepriseId;
        int mission;
        bool verifA = true;

        cin >> entrepriseId;
        cin >> mission;

        bool entrepriseCorrecte = false;
        for (int i = 0; i < compteurEntreprise; ++i) {
            if (tabEntreprise[i].idEntreprise == entrepriseId && tabEntreprise[i].roleEntreprise != "OP") {
                entrepriseCorrecte = true;
                break;
            }
        }

        if (!entrepriseCorrecte) {
            cout << "Entreprise incorrecte" << endl;
            verifA = false;
        }

        bool missionCorrecte = false;
        for (int i = 0; i < compteurM; ++i) {
            if (tabMissionNonAttribue[i].idMission == mission) {
                missionCorrecte = true;
                break;
            }
        }

        if (!missionCorrecte) {
            cout << "Mission incorrecte" << endl;
            verifA = false;
        }

        if (verifA) {
            for (int i = 0; i < compteurEntreprise; ++i) {
                if (tabEntreprise[i].idEntreprise == entrepriseId) {
                    for (int j = 0; j < compteurM; ++j) {
                        if (tabMissionNonAttribue[j].idMission == mission) {
                            for (int k = 0; k < tailleAttribue; ++k) {

                                    tabAttribue[k].idAccp = compteurAc + 1;
                                    tabAttribue[k].e = &tabEntreprise[i];
                                    tabAttribue[k].m = &tabMissionNonAttribue[j];
                                    tabAttribue[k].m->idAncienMission = tabMissionNonAttribue[j].idMission;
                                    tabAttribue[k].ancienID = tabMissionNonAttribue[j].idMission; // au cas ou?

                                    tabMissionNonAttribue[j].idMission = -1;
                                    compteurAc++;
                                    cout << "Acceptation enregistree" << endl;
                                    return;
                                }
                            }
                        }
                    }
                }
            }


    }
void affichageAttribue() {

    for (int i = 0; i < compteurAc; ++i) {
        if (tabAttribue[i].idAccp != 0) {
            cout<< "newID: " << tabAttribue[i].idAccp << "\tancien: "
                 << tabAttribue[i].m->idMission << "\tnom entreprise publiee : "
                 << tabAttribue[i].m->nomEntreprise  << "\tnom Mission : "
                 << tabAttribue[i].m->nom << "\tentreprise accepte : "
                 << tabAttribue[i].e->nomEntreprise;
        }
    }
}
//inscription OP Operateur
//        inscription AG Agence
//inscription IN Intervenant1
//        mission 1 Mission1 5.00
//detail 1
//acceptation 2 1
//consultation
//        r 1 0
//consultation
//        mission 1 Mission2 10.00
//consultation
//        acceptation 2 2
//affichageA