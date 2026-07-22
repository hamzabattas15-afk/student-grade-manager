#include <stdio.h>

struct etudiant {
    char nom[30];
    char mention[20];
    float note[3];
    float moyenne;
};

int main() {
    int nb_etudiants;
    
    printf("Entrez le nombre d'etudiants: ");
    scanf("%d", &nb_etudiants);

    struct etudiant e[nb_etudiants];
    int i, j;

    // 1. Saisie des données
    for (i = 0; i < nb_etudiants; i++) {
        float somme = 0;
        printf("\n--- Etudiant %d ---\n", i + 1);
        printf("Le nom d'etudiant: ");
        scanf("%s", e[i].nom);

        // Loop ghir 3 مرات على حساب note[3]
        for (j = 0; j < 3; j++) {
            printf("La note %d: ", j + 1);
            scanf("%f", &e[i].note[j]);
            somme += e[i].note[j];
        }
        
        e[i].moyenne = somme / 3.0;
    }

    printf("\n================ RESULTATS ================\n");
    for (i = 0; i < nb_etudiants; i++) {
        printf("La moyenne de %s : %.2f --> Mention: ", e[i].nom, e[i].moyenne);
        
        if (e[i].moyenne >= 16) {
            printf("Tres Bien\n");
        } else if (e[i].moyenne >= 14) {
            printf("Bien\n");
        } else if (e[i].moyenne >= 12) {
            printf("Assez Bien\n");
        } else if (e[i].moyenne >= 10) {
            printf("Passable\n");
        } else {
            printf("Ajourne\n");
        }
    }

    printf("\n================ LES ETUDIANTS ADMIS ================\n");
    for (i = 0; i < nb_etudiants; i++) {
        if (e[i].moyenne >= 10) {
            printf("- %s (Moyenne: %.2f)\n", e[i].nom, e[i].moyenne);
        }
    }

    return 0;
}