
#include "acceptation.h"
#include "iostream"
    using namespace std;
    int comteurAc = 0;
    void initTabAttribue(int taille) {
        if (taille > 0) {
            tailleAttribue = taille;
            tabAttribue = new Acceptation[taille];
        } else {
            tabAttribue = nullptr;
        }
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
            if (tabMission[i].idMission == mission) {
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
                        if (tabMission[j].idMission == mission) {
                            for (int k = 0; k < tailleAttribue; ++k) {
                                if (tabAttribue[k].idA.empty()) {
                                    tabAttribue[k].e = &tabEntreprise[i];
                                    tabAttribue[k].m = &tabMission[j];
                                    comteurAc++; // Incrémente le compteur d'attributions
                                    cout << "Acceptation enregistree" << endl;
                                    return; // Quitte la fonction après attribution
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