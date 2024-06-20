
#include "acceptation.h"
#include "iostream"

    using namespace std;
    map<int,mission> tabAttribue;
    int compteurAc = 1;

    void acceptation(){
        int entrepriseId;
        int mission;
        bool verifA = true;

        cin >> entrepriseId >> mission;

        auto itEntreprise = tabEntreprise.find(entrepriseId);
        if (itEntreprise == tabEntreprise.end() || itEntreprise->second.roleEntreprise == "OP") {
            cout << "Entreprise incorrecte" << endl;
            verifA = false;
        }

        auto itMission = tabMissionNonAttribue.find(mission);
        if (itMission == tabMissionNonAttribue.end()) {
           cout << "Mission incorrecte" << endl;
            verifA = false;
        }


        if (verifA) {
            auto itMiss = tabMissionNonAttribue.find(mission);
            if (itMiss !=tabMissionNonAttribue.end()){
                itMiss->second.attribue = itEntreprise->second;
                tabAttribue.insert({mission,itMiss->second});
                tabMissionNonAttribue.erase(itMiss);
                cout << "Acceptation enregistree"<< endl;
            }
        }


    }
    void affichageAttribue() {
        for (const auto& item : tabAttribue) {
            std::cout << item.first << " "
            << item.second.nomMissions << " "
            << item.second.remunerations << " "
            << item.second.entreprisePublie.nomEntreprise <<" Attribue a "
            << item.second.attribue.nomEntreprise << std::endl;
        }
    }



