

#ifndef S1_01_ACCEPTATION_H
#define S1_01_ACCEPTATION_H

#include "../inscription/inscription.h"
#include "../mission/mission.h"

    struct Acceptation{
            string vide;
            int idAccp;
            int ancienID;
            Entreprise* e;
            mission* m;
    };

    extern Acceptation* tabAttribue;
    extern const int tailleAttribue;
    extern int compteurAc;


    void acceptation();
    void initTabAttribue();
    void suppTabAttribue();
    void affichageAttribue();

#endif //S1_01_ACCEPTATION_H
