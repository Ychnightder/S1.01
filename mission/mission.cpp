#include <iostream>
#include <iomanip>
#include "mission.h"

     int tailleTabM = 500;
     mission* tabMissionNonAttribue = nullptr;
     int compteurM = 0;


    void initTabMission() {
        tabMissionNonAttribue = new mission[tailleTabM];
    }

    void suppTabMission(){
        delete[] tabMissionNonAttribue;
        tabMissionNonAttribue = nullptr;
    }


    void Mission(){
        int idEntreprise;
        string nom;
        double remuneration;

        bool  verifmission = true;

        cin >> idEntreprise;
        cin >> nom;
        cin >> remuneration;

        if(!verifOperateurId(idEntreprise)){
            cout << "Identifiant incorrect" <<endl;
            verifmission = false;
            return;
        }else if (remuneration < 0){
            cout << "Remuneration incorrecte" <<endl;
            verifmission = false;
        }

        if (verifmission) {
            for (int i = 0; i < tailleTabM; ++i) {
                if (tabMissionNonAttribue[i].nom.empty()){
                    tabMissionNonAttribue[i].idMission = compteurM + 1;
                    tabMissionNonAttribue[i].nom = nom;
                    tabMissionNonAttribue[i].prix = remuneration;
                    tabMissionNonAttribue[i].nomEntreprise = NomEntreprisePourMission(idEntreprise);
                    compteurM++;
                    cout << "Mission publiee (" << compteurM << ")" << endl;
                    break;
                }
            }
        }
        return;
    }

    void affichageMission(){
        for (int i = 0; i < getCompteurMission(); ++i) {
            cout << tabMissionNonAttribue[i].idMission << " " <<
                 tabMissionNonAttribue[i].nom << " " <<
                 tabMissionNonAttribue[i].prix << setprecision(2) <<" " <<
                 tabMissionNonAttribue[i].nomEntreprise << "\n";
        }
    }
    int getCompteurMission(){
    return compteurM;
    }
