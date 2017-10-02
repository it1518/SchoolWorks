/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: student
 *
 * Created on 22. září 2017, 11:46
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VSTUP "skola.txt"
#define VYSTUP "skola.html"
#define VELIKOST 100
#define ODDELOVACE ";\n"


int main(int argc, char** argv) {
    typedef struct{
        char prijmeni[20];
        char jmeno[10];
        char narozen[20];
        int absence;
        char trida[5];
        char pohlavi[5];
    }ZACI;
    ZACI *zaci = NULL;
    FILE *vstup;
    FILE *vystup;
    char myString[VELIKOST];
    int i;
    char *ukazatel = NULL;
    int cisloRadku = -1;
    int girls = 0;
    int boys = 0;
    int celkemAbsence = 0;
    int nejIndex = 0;
    
    
    vstup = fopen(VSTUP, "r");
    vystup = fopen(VYSTUP, "w");
    if(vstup == NULL){
        printf("Soubor %s se nepodarilo otevrit. Program bude ukoncen. \n", VSTUP);
        return(EXIT_FAILURE);
    }
    if(vystup == NULL){
        printf("Soubor %s se nepodarilo otevrit. Program bude ukoncen. \n", VYSTUP);
        return(EXIT_FAILURE);
    }
    
    while(fgets(myString, VELIKOST, vstup) != NULL){
        if(cisloRadku == -1){
            cisloRadku++;
            continue;
        }    
        zaci = (ZACI*)realloc(zaci, sizeof(ZACI)*(cisloRadku +1));
        ukazatel = strtok(myString, ODDELOVACE);
        i = 0;
        while(ukazatel != NULL){
            switch(i){
                case 0:
                    strcpy(zaci[cisloRadku].prijmeni, ukazatel);
                    break;
                case 1:
                    strcpy(zaci[cisloRadku].jmeno, ukazatel);
                    break;
                case 2: 
                    strcpy(zaci[cisloRadku].narozen, ukazatel);
                    break;
                case 3: 
                    zaci[cisloRadku].absence = atoi(ukazatel);
                    celkemAbsence += zaci[cisloRadku].absence;
                    if(zaci[nejIndex].absence < zaci[cisloRadku].absence){
                        nejIndex = cisloRadku;
                    }
                    break;
                case 4:
                    strcpy(zaci[cisloRadku].trida, ukazatel);
                    break;
                case 5:
                    strcpy(zaci[cisloRadku].pohlavi, ukazatel);
                    if(ukazatel[0] == 'F'){
                        girls++;
                    }else{
                        boys++;
                    }
                    break;  
            }
            ukazatel = strtok(NULL, ODDELOVACE);
            i++;
        }
        cisloRadku++;
    }
    
    //VYPSÁNÍ DAT DO TERMINÁLU
    
    printf("KONTROLNI VYPIS DAT: \n");
    printf("-------------------------------------- \n");
    for(i = 0; i < cisloRadku; i++){
        printf("%10s %6s %10s %3d %3s %s \n", zaci[i].prijmeni, zaci[i].jmeno, zaci[i].narozen, zaci[i].absence, zaci[i].trida, zaci[i].pohlavi);
    }
    printf("-------------------------------------- \n");
    printf("Celkovy pocet zaku: %d \n", cisloRadku);
    printf("Pocet devcat: %d \n", girls);
    printf("Pocet chlapcu: %d \n", boys);
    printf("Celkem absence %d \n", celkemAbsence);
    printf("Prumerna absence na zaka je %.2f hodin. \n", ((float)celkemAbsence / cisloRadku));
    printf("Nejvyssi absenci %d hodin ma %s %s ze tridy %s. \n", zaci[nejIndex].absence, zaci[nejIndex].jmeno, zaci[nejIndex].prijmeni, zaci[nejIndex].trida);
    printf("\n");
    
    //TABULKA PRO HOLKY
    
    fprintf(vystup, "<h1>HOLKY</h1>");
    fprintf(vystup, "<table  style='background-color: red; padding: 3px;'>");
    fprintf(vystup, "<th>jmeno</th>"
                    "<th>prijmeni</th>"
                    "<th>datum narozeni</th>"
                    "<th>absence</th>");
    for(i = 0; i < cisloRadku; i++){
        if(zaci[i].pohlavi[0] == 'F'){
            fprintf(vystup, "<tr><th>%s</th><th>%s</th><th>%s</th><th>%d</th></tr>", zaci[i].jmeno, zaci[i].prijmeni, zaci[i].narozen, zaci[i].absence);
        }
    }
    fprintf(vystup, "</table>");
    
    //TABULKA PRO KLUKY
      
    fprintf(vystup, "<h1>KLUCI</h1>");
    fprintf(vystup, "<table  style='background-color: green; padding: 3px;'>");
    fprintf(vystup, "<th>jmeno</th>"
                    "<th>prijmeni</th>"
                    "<th>datum narozeni</th>"
                    "<th>absence</th>");
    for(i = 0; i < cisloRadku; i++){
        if(zaci[i].pohlavi[0] == 'M'){
            fprintf(vystup, "<tr><th>%s</th><th>%s</th><th>%s</th><th>%d</th></tr>", zaci[i].jmeno, zaci[i].prijmeni, zaci[i].narozen, zaci[i].absence);
        }
    }
    fprintf(vystup, "</table>");
    
    //ZAVŘENÍ SOUBORŮ
    
    if(fclose(vstup) == EOF){
        printf("Soubor %s se nepodarilo uzavrit. Program bude ukoncen. \n", VSTUP);
        return(EXIT_FAILURE);
    }
    if(fclose(vystup) == EOF){
        printf("Soubor %s se nepodarilo uzavrit. Program bude ukoncen. \n", VYSTUP);
        return(EXIT_FAILURE);
    }else{
        printf("Byl vytvoren soubor %s. \n", VYSTUP);
    }
    return (EXIT_SUCCESS);
}

