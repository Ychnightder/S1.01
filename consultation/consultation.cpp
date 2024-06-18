#include "consultation.h"
#include "iostream"
#include <iomanip>


    void consultation(){
        bool missionsNonAttribueesDisponibles = false;
        // Vérifier s'il y a au moins une mission non attribuée
        for (int i = 0; i < compteurM; ++i) {
            if (tabMissionNonAttribue[i].idMission > 0) {
                missionsNonAttribueesDisponibles = true;
                break;
            }
        }
        if (missionsNonAttribueesDisponibles) {
            for (int i = 0; i < compteurM; ++i) {
                if (tabMissionNonAttribue[i].idMission > 0) {
                    cout << tabMissionNonAttribue[i].idMission << " "
                         << tabMissionNonAttribue[i].nom << " "
                         << tabMissionNonAttribue[i].nomEntreprise << " "
                         << fixed << setprecision(2) << tabMissionNonAttribue[i].prix << " ("
                         << tabMissionNonAttribue[i].soustraitance << ")" << endl;
                }
            }
        }
        else {
            cout << "Aucune mission disponible" << endl;
        }
    }
