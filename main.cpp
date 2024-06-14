#include "iostream"
#include "exit/exit.h"
#include "inscription/inscription.h"
void init(){
    initTabNom(100);
}
void supp(){
    suppTabNom();
}

int main() {
    init();
    string r,nom;
    inscription();
    inscription();
    supp();
    return 0;
}