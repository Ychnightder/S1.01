#include "iostream"
#include "detail.h"
using namespace std;

    void detail(){
        int idMission;
        cin >> idMission;

        for (int i = 0; i <getCompteurMission() ; ++i) {
            if (tabMission[i].idMission == idMission){
                cout << tabMission[i].idMission <<" "<< tabMission[i].nom<<" " <<tabMission[i].e->nomEntreprise<<" " <<tabMission->prix <<" "<<"("<<tabMission->soustraitance<<")\n";
                cout << tabMission[i].rapport.detail;
                break;
            }
            else{
                cout << "Identifiant incorrect";
            }
        }

    }
