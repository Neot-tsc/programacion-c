#include "tad_cadena.h"

void leecad_rec(tcad, int);

//#########################################################################
void leecad(tcad cad){
    leecad_rec(cad,0);
}

int comparar_cad(tcad a, tcad b){
    return strcmp(a,b);
}



//#####################################################################################




void leecad_rec(tcad cad, int j){
    char c;
    c=getchar();
    if(c!=EOF && c!='\n' && j<max-1){
        cad[j]=c;
        leecad_rec(cad, j+1);
    }
    else{
        cad[j]='\0';
        while (c!=EOF && c!='\n')
            c=getchar();
    }
}
