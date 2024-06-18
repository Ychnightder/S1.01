
#include "acceptation.h"
#include "iostream"
    using namespace std;

    Acceptation* tabAttribue = nullptr;
    const int tailleAttribue = 500;
    int comteurAc = 0;

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
        for (int i = 0; i < getCompteurEntrprise(); ++i) {
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
        for (int i = 0; i < getCompteurMission(); ++i) {
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
            for (int i = 0; i < getCompteurEntrprise(); ++i) {
                if (tabEntreprise[i].idEntreprise == entrepriseId) {
                    for (int j = 0; j < getCompteurMission(); ++j) {
                        if (tabMissionNonAttribue[j].idMission == mission) {
                            for (int k = 1; k < tailleAttribue; ++k) {
                                if (tabAttribue[k].idA.empty()) {

                                    tabAttribue[k].e = &tabEntreprise[i];
                                    tabAttribue[k].m = &tabMissionNonAttribue[j];

                                    tabMissionNonAttribue[j].idMission = -1;
                                    tabMissionNonAttribue[j].nom = "";
                                    tabMissionNonAttribue[j].prix = 0.0;

                                    comteurAc++;
                                    cout << "Acceptation enregistree" << endl;
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }


    }
    int getCompteurAttribue(){
        return comteurAc;
    }