#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VSTUP "knihy.txt"
#define VYSTUP "vypis_knih.html"

int bezPomlcek(char *ISBN){
    char pomocnaP[20];
    int i;
    int j = 0;
    for(i = 0; i < strlen(ISBN); i++){
        if(ISBN[i]!='-'){
            pomocnaP[j]=ISBN[i];
            j++;
        }
    }
    pomocnaP[j]='\0';
    strcpy(ISBN,pomocnaP);
    return strlen(pomocnaP);
}

int main(int argc, char** argv) {
    typedef struct{
        int idzbozi;
        char nazev[40];
        char nosic[20];
        int rok;
        int hmotnostVg;
        char ISBN[30];
    }KNIHA;
    KNIHA *knihy=NULL;
    char * pch;
    int pozice;
    int pocetRadku = 0;
    int i;
    int pocetKnih = 0;
    int pocetDVD = 0;
    int vahaKnih = 0;
    int maxRok = 0;
    int indexMax;
    int r;
    FILE * vstup;
    FILE * vystup;
    char mystring[100];
    
    vstup = fopen(VSTUP,"r");
    if(vstup==NULL){
        printf("Soubor %s se nepodarilo otevrit, program bude ukoncen. \n",VSTUP);
        return(EXIT_FAILURE);
    }
    
    while ( fgets (mystring , 100 , vstup) != NULL ){
        if(pocetRadku > 0){
            knihy = (KNIHA*) realloc (knihy, pocetRadku * sizeof(KNIHA));
                pch = strtok (mystring,";\n");
                pozice = 0;
                while(pch != NULL){
                    switch(pozice){
                        case 0:
                            knihy[pocetRadku-1].idzbozi=atoi(pch);
                            break;
                        case 1:
                            strcpy(knihy[pocetRadku-1].nazev,pch);
                            break;
                        case 2:
                            strcpy(knihy[pocetRadku-1].nosic,pch);
                            break;      
                        case 3:
                            knihy[pocetRadku-1].rok=atoi(pch);
                            break;
                        case 4:
                            knihy[pocetRadku-1].hmotnostVg=atoi(pch);
                            break;                              
                        case 5:
                            strcpy(knihy[pocetRadku-1].ISBN,pch);
                            break;                               
                    }
                pozice++;
                pch = strtok(NULL, ";\n");
            }
        }
        pocetRadku++;
    }
    pocetRadku--;
    for(i = 0;i < pocetRadku; i++){
        if(strcmp(knihy[i].nosic,"DVD")==0){
            pocetDVD++;
            strcpy(knihy[i].ISBN," ");
        }
        if(strcmp(knihy[i].nosic,"Kniha")==0){
            pocetKnih++;
            vahaKnih+=knihy[i].hmotnostVg;
        }
        if(maxRok < knihy[i].rok){
            maxRok = knihy[i].rok;
            indexMax = i;
        }
        printf("%9d %22s %8s %4d %4d %20s \n",
                knihy[i].idzbozi,knihy[i].nazev,
                knihy[i].nosic,knihy[i].rok,
                knihy[i].hmotnostVg,knihy[i].ISBN);
    }
    printf("Pocet radku je %d.\n",pocetRadku);
    printf("Pocet DVD je %d. \n",pocetDVD);
    printf("Pocet knih je %d. \n",pocetKnih);
    printf("Vaha knih je %d kg a %d g. \n",vahaKnih/1000, vahaKnih%1000);
    printf("Nejnovejsi kniha je %s a byla vydana v roce %d. \n",knihy[indexMax].nazev,maxRok);
    
    if(fclose(vstup)==EOF){
        printf("Soubor %s se nepodarilo uzavrit, program bude ukoncen. \n",VSTUP);
        return(EXIT_FAILURE);        
    }
    
    vystup = fopen(VYSTUP,"w");
    if(vystup == NULL){
        printf("Soubor %s se nepodarilo otevrit. \n",VYSTUP);
    }
    for(r=0; r <2; r++){
    fprintf(vystup, "<head>");
    fprintf(vystup, "</head>");
    fprintf(vystup, "<body>");
    fprintf(vystup, "<h1>Seznam knih s ISBN-10</h1>");
    fprintf(vystup, "<table>");
    fprintf(vystup, "<th>cislo</th>");
    fprintf(vystup, "<th>nazev</th>");
    fprintf(vystup, "<th>nosic</th>");
    fprintf(vystup, "<th>rok vydani</th>");
    fprintf(vystup, "<th>hmotnost</th>");    
    fprintf(vystup, "<th>ISBN</th>");
    for(i = 0; i < pocetRadku; i++){
        if(strcmp(knihy[i].nosic,"kniha")==0){
            fprintf(vystup,"<tr><td>%9d</td> <td>%21s</td>"
                    "<td>%8s</td> <td>%4d</td>"
                    "<td>%20s</td><td>%20s</td></tr>",
                    knihy[i].idzbozi,knihy[i].nazev,
                    knihy[i].nosic,knihy[i].rok,
                    knihy[i].hmotnostVg,knihy[i].ISBN);
        }
    }
    fprintf(vystup, "</table>");
    fprintf(vystup, "</body>");
    
    
    if(fclose(vystup)==EOF){
        printf("Soubor %s se nepodarilo uzavrit. \n",VYSTUP);
    }
    else{
        printf("Soubor %s byl vytvoren. \n",VYSTUP);
    }
    if(knihy!=NULL){
        free(knihy);
    }
    return (EXIT_SUCCESS);
}
