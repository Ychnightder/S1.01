#include <iostream>
#include "mission.h"

     int tailleTabM = 0;
     mission* tabMission = nullptr;
     int compteurM = 0;


    void initTabMission(int taille) {
        if (taille > 0) {
            tailleTabM = taille;
            tabMission = new mission[taille];
        } else {
            tabMission = nullptr;
        }
    }

    void suppTabMission(){
        delete[] tabMission;
        tabMission = nullptr;
    }

    bool estDejaMission(int& id){
        for (int i = 0; i < tailleTabM; ++i) {
            if(id == tabMission[i].idMission){
                return true;
            }
        }
        return false;
    }

    void Mission(){
        int id;
        string nom;
        double remuneration;
        bool  verifmission = true;
        cin >> id;
        cin >> nom;
        cin >> remuneration;

        mission missionTmp = *new mission;

        if(estDejaMission(id)){
            cout << "Identifiant incorrect" <<std::endl ;
            verifmission = false;
            return;
        }

        if (remuneration <= 0){
            cout << "Remuneration incorrecte" <<std::endl;
            verifmission = false;
            return;
        }

        if (verifmission) {
            for (int i = 0; i < tailleTabM; ++i) {
                if (tabMission[i].nom.empty()) {
                    tabMission[i].idMission = id;
                    tabMission[i].nom = nom;
                    tabMission[i].prix = remuneration;
                    tabMission->e = findEntreprise(id);
                    tabMission[i].soustraitance = 0;
                    compteurM++;
                    cout << "Mission publiee (" << compteurM << ")" << std::endl;
                    return;
                }
            }
        }

    }

    void affichageMission(){
        for (int i = 0; i < getCompteurMission(); ++i) {
            cout << tabMission[i].idMission << " " <<  tabMission[i].nom << " " << tabMission[i].prix <<" "<< tabMission[i].e << std::endl;
        }
    }
    int getCompteurMission(){
    return compteurM;
    }