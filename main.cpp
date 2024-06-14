#include "iostream"
#include "exit/exit.h"
#include "inscription/inscription.h"
void init(){
    initTabEntreprise(100);
}
void supp(){
    suppTabEntreprise();
}

int main() {
    init();
    inscription();
    inscription();
    supp();
    return 0;
}