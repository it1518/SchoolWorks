
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VSTUP "datalog.csv"
#define VYSTUP "vystup.htm"
#define ODDELOVACE " \n"


int main(int argc, char** argv) {
    FILE *vstup;
    FILE *vystup;
    vstup = fopen(VSTUP, "r");
    vystup = fopen(VYSTUP, "w");
    
    typedef struct{
        char pc[10];
        char zacatek[10];
        char konec[10];
        int id;
    }PROXY;
    PROXY proxy[100];
    char *pch;
    char mystring[100];
    int pocetRadku = 0;
    int pozice;
    int i;
    
     while ( fgets (mystring , 100 , vstup) != NULL ){
         if(pocetRadku > 0){
             pch = strtok (mystring, ODDELOVACE);
             pozice = 0;
             while(pch != NULL){
                 switch(pozice){
                    case 0:
                        strcpy(proxy[pocetRadku -1].pc, pch);
                        break;
                     case 1:
                        strcpy(proxy[pocetRadku-1].zacatek, pch);
                        break;
                     case 2:
                        strcpy(proxy[pocetRadku-1].konec, pch);
                        break;
                     case 3:
                        proxy[pocetRadku-1].id = atoi(pch);
                        break;
                }
                pozice++;
                pch = strtok(NULL, ODDELOVACE);
             }
         }
         pocetRadku++;
     }
    pocetRadku--;
    
    printf("KONTROLNI VYPIS SETRIDENYCH DAT: \n");
    
    for(i = 0;i < pocetRadku; i++){ 
       printf("%5s %5s %5s %10d \n", proxy[i].pc, proxy[i].zacatek, proxy[i].konec, proxy[i].id); 
    }
       fprintf(vystup, "<head>");
       fprintf(vystup, "</head>");
       fprintf(vystup, "<body>");
       fprintf(vystup, "<h1>Prehled pripojeni</h1>");
       fprintf(vystup, "<table>");
       fprintf(vystup, "<th>pc</th>");
       fprintf(vystup, "<th>start</th>");
       fprintf(vystup, "<th>konec</th>");
       fprintf(vystup, "<th>minuty</th>");
       fprintf(vystup, "<th>data</th>"); 
       
       
    for(i = 0; i < pocetRadku; i++){
            fprintf(vystup,"<tr>"
                    "<td>PC</td>"
                    "<td>%s</td>"
                    "<td>%s</td>"
                    "<td>%d</td>"
                    "</tr>", proxy[i].zacatek, proxy[i].konec, proxy[i].id);
        
    }
    fprintf(vystup, "</table>");
    fprintf(vystup, "</body>");
    
    
    if (vstup == NULL){
        printf("Soubor %s nebyl otevren.\n", VSTUP);
        return (EXIT_FAILURE);
    }
     if (vystup==NULL){
        printf("Soubor %s nebyl otevren.\n", VYSTUP);
        return (EXIT_FAILURE);
    }
     else{
         printf("Soubor %s byl vytvoren \n", VYSTUP);
     }
    fclose(vstup);
    
    
    return (EXIT_SUCCESS);
}

