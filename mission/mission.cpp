#include <iostream>
//#include <iomanip>
#include "mission.h"

     int compteurMission = 1;
     map<int,mission> tabMissionNonAttribue;

    void Mission(){
        int idEntrepriseChoisie;
        string nomMission;
        double remuneration;

        bool  verifmission = true;
        cin >> idEntrepriseChoisie >> nomMission >> remuneration;

        // entreprise verification
        auto itEntreprise = tabEntreprise.find(idEntrepriseChoisie);
        if (itEntreprise == tabEntreprise.end() || itEntreprise->second.roleEntreprise != "OP") {
            cout << "Identifiant incorrect" << endl;
            verifmission = false;
        }

        // verification Remuneration
        if (remuneration < 0){
            cout << "Remuneration incorrecte" << endl;
            verifmission = false;
        }

        if (verifmission) {
            mission m = {compteurMission, nomMission, remuneration, 0, "", "" , "","","" , itEntreprise->second
                         };
            tabMissionNonAttribue.insert({compteurMission, m});
            cout << "Mission publiee (" << compteurMission << ")" << endl;
            compteurMission++;
        }
        return;
    }



    void affichageMission() {
        for (const auto& item : tabMissionNonAttribue) {
            std::cout << item.first << " " << item.second.nomMissions << " " << item.second.remunerations << " " << item.second.entreprisePublie.nomEntreprise << std::endl;
        }
    }
