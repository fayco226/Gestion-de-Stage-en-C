#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nom[50];
    char prenom[50];
    float salaire;
    char profSuivi[50];
    char entreprise[50];
} Stagiaire;

typedef struct
{
    char nom[50];
    char adresse[100];
} Entreprise;

typedef struct
{
    char nom[50];
    char prenom[50];
} Professeur;

void ajouterStagiaire()
{
    Stagiaire stagiaire;
    FILE *stagiairesFile = fopen("stagiaires.txt", "a");
    if (stagiairesFile == NULL)
    {
        printf("Erreur lors de l'ouverture des fichiers.\n");
        exit(1);
    }
    printf("Nom du stagiaire: ");
    scanf("%s", stagiaire.nom);
    printf("Prénom du stagiaire: ");
    scanf("%s", stagiaire.prenom);
    printf("Salaire du stagiaire: ");
    scanf("%f", &stagiaire.salaire);

// choix du prof de suivis
    printf("Choissez le prof de suivie:\n");
    FILE *professeursFile = fopen("professeurs.txt", "r");
    Professeur prof;
    int i =0;
    while (fscanf(professeursFile, "%[^,],%[^\n]\n", prof.nom, prof.prenom) != EOF) {
            i++;
            printf("%d) Nom:%s Prenom:%s \n", i, prof.nom, prof.prenom);
        }
    printf("%d", i);
    fclose(professeursFile);
    FILE *professeursFile1 = fopen("professeurs.txt", "r");
    int choixx;
    printf("Votre choix:");
    scanf("%d",&choixx);
    if (choixx<=i && choixx>0 )
    {
        Professeur prof2;
        i = 0;
        while (fscanf(professeursFile1, "%[^,],%[^\n]\n", prof2.nom, prof2.prenom) != EOF) {
            i++;
            if (choixx==i)
            {
                char nomProf[100]="";
                strcat(nomProf, prof2.nom);
                strcat(nomProf, " ");
                strcat(nomProf, prof2.prenom);
                printf("%s", nomProf);
                strcpy(stagiaire.profSuivi, nomProf);
            }
            printf("%d", i);
            
        }
    }
    fclose(professeursFile1);
//choix de l'entreprise
    printf("Choissez l'entreprise:\n");
    Entreprise entreprise;
    FILE *entreprisesFile = fopen("entreprises.txt", "r");
    i =0;
    while (fscanf(entreprisesFile, "%[^,],%[^\n]\n", entreprise.nom, entreprise.adresse) != EOF) {
            i++;
            printf("%d) Nom:%s Prenom:%s \n",i, entreprise.nom, entreprise.adresse);
        }
    fclose(entreprisesFile);
    FILE *entreprisesFile1 = fopen("entreprises.txt", "r");
    printf("Votre choix:");
    scanf("%d",&choixx);
    if (choixx<=i && choixx>0 )
    {
        i = 0;
        while (fscanf(entreprisesFile1, "%[^,],%[^\n]\n", entreprise.nom, entreprise.adresse) != EOF) {
            i++;
            if (choixx==i)
            {
                strcpy(stagiaire.entreprise, entreprise.nom);
            }
            
        }
    }
    fclose(entreprisesFile1);

    fprintf(stagiairesFile, "%s,%s,%.2f,%s,%s\n", stagiaire.nom, stagiaire.prenom, stagiaire.salaire, stagiaire.profSuivi, stagiaire.entreprise);

    fclose(stagiairesFile);
}

void ajouterEntreprise()
{
    Entreprise entreprise;
    FILE *entreprisesFile = fopen("entreprises.txt", "a");
    if (entreprisesFile == NULL)
    {
        printf("Erreur lors de l'ouverture des fichiers.\n");
        exit(1);
    }
    printf("Nom de l'entreprise: ");
    scanf("%s", entreprise.nom);
    printf("Adresse de l'entreprise: ");
    scanf("%s", entreprise.adresse);
    fprintf(entreprisesFile, "%s,%s\n", entreprise.nom, entreprise.adresse);
    fclose(entreprisesFile);
}

void ajouterProfesseur()
{
    FILE *professeursFile = fopen("professeurs.txt", "a");
    if (professeursFile == NULL)
    {
        printf("Erreur lors de l'ouverture des fichiers.\n");
        exit(1);
    }
    Professeur professeur;
    printf("Nom du professeur: ");
    scanf("%s", professeur.nom);
    printf("Prénom du professeur: ");
    scanf("%s", professeur.prenom);
    fprintf(professeursFile, "%s,%s\n", professeur.nom, professeur.prenom);
    fclose(professeursFile);
}

void afficherContenuFichier(char *nomFichier)
{
    FILE *file = fopen(nomFichier, "r");
    if (file != NULL)
    {
        int c;
        while ((c = fgetc(file)) != EOF)
        {
            putchar(c);
        }
        fclose(file);
    }
    else
    {
        printf("Erreur lors de l'ouverture du fichier %s.\n", nomFichier);
    }
}

void rechercherStagiairesParProf(char *nomProf) {
    FILE *file = fopen("stagiaires.txt", "r");
    if (file != NULL) {
        Stagiaire stagiaire;
        printf("Stagiaires suivis par %s :\n", nomProf);
        while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", stagiaire.nom, stagiaire.prenom, stagiaire.salaire, stagiaire.profSuivi, stagiaire.entreprise) != EOF) {
            if (strcmp(stagiaire.profSuivi, nomProf) == 0) {
                printf("Nom: %s, Prénom: %s,Salaire:%2f, Prof:%s, Entreprise: %s\n", stagiaire.nom, stagiaire.salaire, stagiaire.profSuivi, stagiaire.prenom, stagiaire.entreprise);
            }
        }
        fclose(file);
    }
}

void rechercherStagiairesParEntreprise(char *nomEntreprise) {
    FILE *file = fopen("stagiaires.txt", "r");
    if (file != NULL) {
        Stagiaire stagiaire;
        printf("Stagiaires de %s :\n", nomEntreprise);
        while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", stagiaire.nom, stagiaire.prenom, stagiaire.salaire, stagiaire.profSuivi, stagiaire.entreprise) != EOF) {
            if (strcmp(stagiaire.entreprise, nomEntreprise) == 0) {
                printf("Nom: %s, Prénom: %s,Salaire:%.2f, Prof:%s, Entreprise: %s\n", stagiaire.nom, stagiaire.salaire, stagiaire.profSuivi, stagiaire.prenom, stagiaire.entreprise);
            }
        }
        fclose(file);
    }
}

void menu(){
    printf("\nMenu:\n");
        printf("1. Ajouter un stagiaire\n");
        printf("2. Ajouter une entreprise\n");
        printf("3. Ajouter un professeur\n");
        printf("4. Afficher les stagiaire\n");
        printf("5. Afficher les entreprise\n");
        printf("6. Afficher les professeur\n");
        printf("7. Rechercher stagiares\n");
        printf("0. Quitter\n");
}

int main()
{

    int choix;
    do
    {
        menu();
        printf("Choix: ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            ajouterStagiaire();
            break;
        case 2:
            ajouterEntreprise();
            break;
        case 3:
            ajouterProfesseur();
            break;
        case 4:
            afficherContenuFichier("stagiaires.txt");
            break;
        case 5:
            afficherContenuFichier("entreprises.txt");
            break;
        case 6:
            afficherContenuFichier("professeurs.txt");
            break;
        case 7:
            int choixRechercher;
            printf("\n Recherche Stagiaires\n1)Par nom de prof\n2)Par entreprise\n");
            scanf("%d", &choixRechercher);
            if (choixRechercher==1)
            {
                char nomRecherche[50];
                printf("Nom: ");
                scanf("%s", &nomRecherche);
                rechercherStagiairesParProf(nomRecherche);
            }
            if (choixRechercher==2)
            {
                char nomRecherche[50];
                printf("Nom: ");
                scanf("%s", &nomRecherche);
                rechercherStagiairesParEntreprise(nomRecherche);
            }
            
            break;
        case 0:
            printf("Au revoir!\n");
            break;
        default:
            printf("Choix invalide\n");
        }
    } while (choix != 0);

    return 0;
}