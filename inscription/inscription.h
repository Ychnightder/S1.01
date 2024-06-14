

#ifndef S1_01_INSCRIPTION_H
#define S1_01_INSCRIPTION_H
#include <string>
using namespace std;


extern const int nbRole;
extern const char* roleTab[];

extern int tailleTab;
extern std::string* tabNom;
extern int compteur;

void initTabNom(int taille);
void suppTabNom();
void ajouterDansTabNom(std::string& nom);
void inscription();

#endif //S1_01_INSCRIPTION_H
