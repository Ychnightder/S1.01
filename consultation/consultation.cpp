#include "consultation.h"

#include "iostream"

    void consultation(){
        if (getCompteurMission() == 0 || tabMission == nullptr){
            cout << "Aucune mission disponible";
        }
        else{
            for (int i = 0; i < getCompteurMission(); ++i) {
                cout << tabMission[i].idMission <<" "<< tabMission[i].nom<<" " <<tabMission[i].e->nomEntreprise<<" " <<tabMission->prix <<" "<<"("<<tabMission->soustraitance<<")\n";
            }
        }
    }
