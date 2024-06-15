
#ifndef S1_01_MISSION_H
#define S1_01_MISSION_H
#include <string>
    using  namespace std;

    struct mission{
        int idMission;
        string nom;
        double prix;
    };

    extern int tailleTabM;
    extern mission* tabMission;
    extern int compteurM;


    void initTabMission(int taille);
    void suppTabMission();
    bool estDejaMission(int& id);
    void Mission( );
#endif //S1_01_MISSION_H
