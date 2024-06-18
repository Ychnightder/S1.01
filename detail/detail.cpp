#include "iostream"
#include "detail.h"
using namespace std;

    void detail(){
        int idMission;
        cin >> idMission;

        for (int i = 0; i <getCompteurMission() ; ++i) {
            if (tabMissionNonAttribue[i].idMission == idMission){
                cout << tabMissionNonAttribue[i].idMission << " " << tabMissionNonAttribue[i].nom << " " << tabMissionNonAttribue[i].nomEntreprise << " " << tabMissionNonAttribue->prix << " " << "(" << tabMissionNonAttribue->soustraitance << ")\n";
                cout << tabMissionNonAttribue[i].rapport.detail;
                break;
            }
            else{
                cout << "Identifiant incorrect";
            }
        }

    }
