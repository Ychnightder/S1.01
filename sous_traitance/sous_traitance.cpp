

#include <iostream>
#include "sous_traitance.h"
#include "../inscription/inscription.h"
#include "../mission/mission.h"
#include "../acceptation/acceptation.h"



using namespace std;


void sous_traitance(){
    int entrepriseAg;
    int missionId;
    double remuneration;
    bool  verifss = true;
    cin >> entrepriseAg >> missionId >> remuneration;

    auto itEntreprise = tabEntreprise.find(entrepriseAg);
    if (itEntreprise == tabEntreprise.end() || itEntreprise->second.roleEntreprise != "AG") {
        cout << "Entreprise incorrecte sst" << endl;
        verifss = false;
    }


    auto itMission = tabMissionNonAttribue.find(missionId);
    if (itMission == tabMissionNonAttribue.end() && itMission->second.soustraitances < 5) {
        cout << "Mission incorrecte" << endl;
        verifss = false;
    }

    if (remuneration < 0){
        cout << "Remuneration incorrecte" << endl;
        verifss = false;
    }

    if (verifss){
        auto it = tabMissionNonAttribue.find(missionId);

        mission updatedMission = it->second;
        tabAttribue.insert({it->first, it->second});
        tabMissionNonAttribue.erase(it);
        updatedMission.idMission = compteurMission;
        updatedMission.entreprisePublie.nomEntreprise = itEntreprise->second.nomEntreprise;
        updatedMission.remunerations = remuneration;
        updatedMission.soustraitances++;
        tabMissionNonAttribue.insert({compteurMission , updatedMission});
        cout << "Sous-traitance enregistree (" << compteurMission << ")" << endl;
        compteurMission++;
    }
}