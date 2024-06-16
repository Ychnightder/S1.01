

#ifndef S1_01_RAPPORT_H
#define S1_01_RAPPORT_H
#include "string"

using namespace std;

enum CodeRapport {
    ZERO = 0,
    UN = 1,
    DEUX = 2,
    TROIS = 3
};


    struct rapport{
        string detail;
         double majoration;
    };

    void Rapport();
    bool verifiCode(int c);
#endif //S1_01_RAPPORT_H
