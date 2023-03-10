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
int generer(int solution[8][8], int tableauJoueur[8][8], char difficulte){
        if (difficulte == 'Y'){
            for(int i=0;i<8; ++i){
                for(int j=0; j<8; ++j){  
                    tableauJoueur[i][j] = solution[i][j];  
                }
            }
            tableauJoueur[rand()%8][rand()%8] = 3;
        }else{
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
    }
int verifierTroisMemeChiffreLigne(int tab[8][8]){
    for (int i=0; i<8; i++){
        for (int j=0; j <8; j++){
            int memeCaractere = 0;
            for (int k = 0; k < 3; k++)
            {
                if (tab[i][j+k] == tab[i][j]){
                    memeCaractere++;
                }
                if (memeCaractere == 3){
                    return 0;
                }
            }
        }
    }
    return 1;
}
int verifierTroisMemeChiffreColonne(int tab[8][8]){                                     //ok
    for (int i=0; i<8; i++){
        for (int j=0; j <8; j++){
            int memeCaractere = 0;
            for (int k = 0; k < 3; k++)
            {
                if (tab[i+k][j] == tab[i][j]){
                    memeCaractere++;
                }
                if (memeCaractere == 3){
                    return 0;
                }
            }
        }
    }
    return 1;
}
int verifLigne(int tab[8][8]){
    int memeLigne = 0;
    for(int i = 0; i < 8 ; i++){
        for(int j = i+1 ; j < 8 ; j++)
        {
            for(int k = 0; k < 8 ; k++){
                if (tab[i][k] == tab[j][k]){
                        memeLigne++;
                }
            }
        }
    }
    if (memeLigne == 8){
        return 1;
    }else{
        return 0;
    }
    
}
int verifColonne(int tab[8][8]){
    int memeColonne = 0;
    for(int i = 0; i < 8 ; i++){
        for(int j = i+1 ; j < 8 ; j++)
        {
            for(int k = 0; k < 8 ; k++){
                if (tab[i][k] == tab[j][k]){
                        memeColonne++;
                }
            }
        }
    }
    if (memeColonne == 8){
        return 1;
    }else{
        return 0;
    }
}
int verifierNbChiffreLigne(int tab[8][8]){                                         //ok
    int nbligneValide = 0;
    for (int i=0; i<8; i++){
        int nb1 = 0;
        int nb0 = 0;
        for (int j=0; j <8; j++){
            if (tab[i][j] == 0){
                nb0++;
            }
            if (tab[i][j] == 1){
                nb1++;
            }
        }
        if (nb1 == nb0){
            nbligneValide++;
        }
    }
    if (nbligneValide == 8){
        return 1;
    }
    return 0;
}
int verifierNbChiffreColone(int tab[8][8]){                                                      // ok
    int nbColoneValide = 0;
    for (int i=0; i<8; i++){
        int nb1 = 0;
        int nb0 = 0;
        for (int j=0; j <8; j++){
            if (tab[j][i] == 0){
                nb0++;
            }
            if (tab[j][i] == 1){
                nb1++;
            }
        }
        if (nb1 == nb0){
            nbColoneValide++;
        }
    }
    if (nbColoneValide == 8){
        return 1;
    }
    return 0;
}



int verifierLigneColonne(int tab[8][8]){
    int verifValide = 0;
    if (verifierTroisMemeChiffreLigne(tab)){
        verifValide++;
        printf("verifierTroisMemeChiffreLigne\n");
    }    
    if (verifierTroisMemeChiffreColonne(tab)){
        verifValide++;
        printf("verifierTroisMemeChiffreColonne\n");
    }
    if (verifLigne(tab)){
        verifValide++;
        printf("verifLigne\n");
    }
    if (verifColonne(tab)){
        verifValide++;
        printf("verifColonne\n");
    }
    if (verifierNbChiffreLigne(tab)){
        verifValide++;
        printf("verifierNbChiffreLigne\n");
    }
    if (verifierNbChiffreColone(tab)){
        verifValide++;
        printf("verifierNbChiffreColone\n");
    }

        
    // verifValide = 6;
    printf("%d verif(s) ont etait valide(s)\n", verifValide);
        //verifierColone
    if (verifValide == 6){
        return 1;
    }else{
        return 0;
    }
}

int verifierGrille(int tab[8][8]){
    int grilleNonComplete = 0;
    for (int i = 0; i <8; i++){
        for (int j = 0; j<8; j++){
            if (tab[i][j] == 3){
                grilleNonComplete++;
            }
        }

    }
    if (grilleNonComplete == 0){
        return 1;
    }else{
        return 0;
    }
}

int afficher(int tableau[8][8]){
    printf("---------------------------------");  
    printf("\n");
    printf("   0 1 2 3 4 5 6 7\n");
    printf("   _______________\n");
    for(int i= 0;i<8; ++i){
        printf("%d |", i);
        for(int j=0; j<8; ++j){  
            printf("%d ", tableau[i][j]);
        }
        printf("\n");
    }
    printf("---------------------------------");  
    printf("\n");
}


void saisir(int tableau[8][8]){
    int saisieX = 0;
    int saisieY = 0;
    int reponse = 0;
    int gagnant = 0;

    printf("Choisissez les coordonnees x/y de la case a modifier: ");
    scanf("%d %d", &saisieX, &saisieY);
    printf("Choisisser entre 1 et 0: ");
    scanf("%d", &reponse);

    tableau[saisieX][saisieY] = reponse;

    if (verifierLigneColonne(tableau)){
        gagnant++;
    }
    if (verifierGrille(tableau)){
        gagnant++;
    }
    if (gagnant == 2){
        printf("Bienjoue vous avez gagne !!!!!!");
        exit(0);
    }

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
    char Rep;
    printf("Voulez vous un tableau facile ? (Y/N): ");
    scanf("%c", &Rep);
    generer(solution, tableauJoueur, Rep);
    while (true)
    {
        afficher(tableauJoueur);
        saisir(tableauJoueur);
    }

    //Ne pas toucher au code ci dessous
    system("pause");
    return 0;
}

