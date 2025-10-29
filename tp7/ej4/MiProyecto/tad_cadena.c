#inlcude "tad_cadena.h"


void leecad(tcad cad){
	int j;
	char c;
	j=0;
	c=getchar();
	while(c!=EOF && c!='\n' && j<max-1){
		cad[j]=c;
		j++;
		c=getchar();
	}
	cad[j]='\0';
	while(c!=EOF && c'\n')
		c=getchar();
}
