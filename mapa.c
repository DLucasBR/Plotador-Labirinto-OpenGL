#include "mapa.h"

int larguraMapa = 0;

void lemapa(MAPA* m){

    int i;

    FILE* f;

    f = fopen("mapa.txt","r");
    if(f == 0){
        printf("Ocorreu um erro ao abrir o arquivo do mapa");
        exit(1);
    }

    fscanf(f,"%d %d",&(m->linhas),&(m->colunas));

    if(m->linhas != m->colunas){
        printf("O mapa deve ser quadrado! numero de linhas = numero de colunas");
        getchar();
        exit(1);
    }

    larguraMapa = m->linhas;
    alocamapa(m);

    for(i = 0; i < m->linhas ; i++)
        fscanf(f,"%s",m->matriz[i]);

    fclose(f);

}

void alocamapa(MAPA* m){
    int i;
    m->matriz = malloc(sizeof(char*) * m->linhas);
    for(i = 0 ; i < m->linhas ; i++)
        m->matriz[i] = malloc(sizeof(char) * m->colunas + 1);
}

void liberamapa(MAPA* m){
    int i;
    for(i = 0; i < m->linhas ; i++)
        free(m->matriz[i]);
    free(m->matriz);
}

void imprimemapa(MAPA* m) {
	int i;
	for(i = 0; i < m->linhas; i++) {
		printf("%s\n", m->matriz[i]);
	}
}

int getLarguraMapa(){

    return larguraMapa ? larguraMapa : -1;

}
