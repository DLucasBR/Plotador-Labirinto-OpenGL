#include <stdio.h>
#include <stdlib.h>

struct mapa{
    char** matriz;
    int linhas;
    int colunas;
};
typedef struct mapa MAPA;

void lemapa(MAPA* m);
void alocamapa(MAPA* m);
void liberamapa(MAPA* m);
void imprimemapa(MAPA* m);
int getLarguraMapa();
