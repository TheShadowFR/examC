#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// takuzu

// 1 - creer une fonction qui prend la variable solution, et la variable tableauJoueur (par exemple) : un tableau rempli de 0, cette fonction doit copier certaines valeurs (grace au rand() % N) 
// de solution dans tableauJoueur afin d'initialiser une grille jouable ( car solution est bel est bien la solution, donc pas jouable par définition. ).
// un parametre doit permettre de verifier la condition de victoire en un seul coup (proposer votre façon de faire :) ) 

// 2- une fonction saisir qui demande au joueur de saisir 3 informations: i, j , et v qui permettront de placer la valeur v aux coordonnées (i,j)

// 3- apres chaque coordonnées il faut verifier les regles du sudoku sur le tableauJoueur donc : 

    // - la fonction verifierLigneColonne ( qui verifie les lignes et les colonnes  sur lesquelles sont la nouvelle valeur)
    // - la fonction verifierGrille (qui fait ceci pour toute la grille et permet de definir la condition de victoire)

// 4 - Ecrire le code principal qui permet de jouer au joueur :  le programme prend fin quand on gagne 
int generer(int solution[8][8], int tableauJoueur[8][8]){

        for(int i=0;i<8; ++i){
            for(int j=0; j<8; ++j){  
                int hazard = rand()%2;
                if (hazard){
                    tableauJoueur[i][j] = solution[i][j];  
                }
            }
        }
        return 0;
    }

int afficher(int tableau[8][8]){
    printf("---------------------------------");  
    printf("\n");
    for(int i=0;i<8; ++i){
        for(int j=0; j<8; ++j){  
            printf("%d ", tableau[i][j]);
        }
        printf("\n");
    }
    printf("---------------------------------");  
    printf("\n");
}

int verifierLigneColone(int tab[8][8], int saisieX, int saisieY, int reponse){
    printf("je verifie ligne/colone %d %d %d %d", tab[8][8], saisieX, saisieY, reponse);
    return 0;
}

int verifierGrille(int tab[8][8]){
    printf("je verifie grille %d", tab[8][8]);
    return 0;
}
int saisir(int tableau[8][8]){
    int saisieX = 0;
    int saisieY = 0;
    int reponse = 0;
    int tabVerif[8][8];

    printf("Choisissez les coordonnees x/y de la case a modifier: ");
    scanf("%d %d", &saisieX, &saisieY);
    printf("%d %d\n", saisieX, saisieY);
    printf("Choisisser entre 1 et 0: ");
    scanf("%d", &reponse);
    printf("%d\n", reponse);

    for(int i=0;i<8; ++i){
        for(int j=0; j<8; ++j){  
            tabVerif[i][j] = tableau[i][j];
        }
    }
    tabVerif[saisieX][saisieY] = reponse;
    for(int i=0;i<8; ++i){
        for(int j=0; j<8; ++j){  
            printf("%d ", tabVerif[i][j]);
        }
        printf("\n");
    }
    verifierLigneColonne(tabVerif, saisieX, saisieY, reponse);
    verifierGrille(tabVerif);
    return 0;
}



int main(){
    // Ne pas toucher le code entre les commentaires
    srand( time( NULL ) );


    int i, j, k;
    printf("SOLUTION");  
    printf("\n");  
    printf("---------------------------------");  
    printf("\n");  

    int solution[8][8] = {
        {1,1,0,1, 0,1,0,0},
        {0,0,1,0, 1,0,1,1},
        {0,1,0,0, 1,1,0,1},
        {1,0,1,1, 0,0,1,0},
    
        {1,0,1,0, 0,1,1,0},
        {0,1,0,1, 1,0,0,1},
        {1,1,0,0, 1,0,1,0},
        {0,0,1,1, 0,1,0,1}
    };


    for(i=0;i<8; ++i) 
    {
    for(j=0; j<8; ++j)
        printf("%d ", solution[i][j]);
    printf("\n");  
    }
    printf("---------------------------------");  
    printf("\n");  
    //toucher le code entre les commentaires 
    int tableauJoueur[8][8] = {
            {3,3,3,3, 3,3,3,3},
            {3,3,3,3, 3,3,3,3},
            {3,3,3,3, 3,3,3,3},
            {3,3,3,3, 3,3,3,3},
        
            {3,3,3,3, 3,3,3,3},
            {3,3,3,3, 3,3,3,3},
            {3,3,3,3, 3,3,3,3},
            {3,3,3,3, 3,3,3,3}
        };

    generer(solution, tableauJoueur);
    while (true)
    {
        afficher(tableauJoueur);
        saisir(tableauJoueur);
    }
    
    
    
    


    //Ne pas toucher au code ci dessous
    system("pause");
    return 0;
}

