#include <stdio.h>
#include <stdlib.h>

typedef struct eleve{
    char* nom;
    char* prenom;
    int age;
    int note;
}eleve;

int main()
{
    eleve tabEleve[3];

    eleve eleve1, eleve2, eleve3;
    eleve1.nom = "toto";
    eleve2.nom = "tata";
    eleve3.nom =  "titi";

    eleve1.prenom = "ptoto";
    eleve2.prenom = "ptata";
    eleve3.prenom =  "ptiti";

    eleve1.age = 11;
    eleve2.age = 12;
    eleve3.age = 13;

    eleve1.note = 1;
    eleve2.note = 2;
    eleve3.note = 3;

    tabEleve[0] = eleve1;
    tabEleve[1] = eleve2;
    tabEleve[2] = eleve3;

    int i;
    for(i=0;i<3;i++){
        printf("Eleve nom :%s, prenom :%s, age :%d, note :%d\n",tabEleve[i].nom, tabEleve[i].prenom, tabEleve[i].age, tabEleve[i].note);
    }

    return 0;
}
