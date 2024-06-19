
#ifndef S1_01_MISSION_H
#define S1_01_MISSION_H
#include <string>
#include "../inscription/inscription.h"
#include "../rapport/rapport.h"

using  namespace std;

    struct mission{
        int idMission;
        int idAncienMission;
        string nomEntreprise;
        string nom;
        double prix;
        int soustraitance;
        string detail;
    };

    extern int tailleTabM;
    extern mission* tabMissionNonAttribue;
    extern int compteurM;


    void initTabMission();
    void suppTabMission();
    void Mission();
    void RepublierMission( int idEntreprise , string nom , double remuneration );
    void affichageMission();
#endif //S1_01_MISSION_H
