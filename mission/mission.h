
#ifndef S1_01_MISSION_H
#define S1_01_MISSION_H
#include <string>
#include "../inscription/inscription.h"
#include "../rapport/rapport.h"

using  namespace std;

    struct mission{
        int idMission;
        string nomEntreprise;
        string nom;
        double prix;
        int soustraitance;
        rapport rapport;
    };

    extern int tailleTabM;
    extern mission* tabMissionNonAttribue;
    extern int compteurM;


    void initTabMission();
    void suppTabMission();
    void Mission();
    int getCompteurMission();
    void affichageMission();
#endif //S1_01_MISSION_H
