#include "mapa.h"
#include <windows.h>
#include <gl/glut.h>


#define TAMANHO_DA_TELA 600

struct coordenadas{

    int bordas;
    int dist_pontos;
    int tam_mapa;

};
typedef struct coordenadas COORDENADAS;

void desenhaLinhaHorizontal(int coluna, int linha, int distacia, int borda);
void desenhaLinhaVertical (int coluna, int linha, int distacia, int borda);
void calculaCoordenadasIniciais(COORDENADAS* c);
void desenhaLabirinto(COORDENADAS *c, MAPA *m);
void desenhaPontosMapa(int coluna,int linha, COORDENADAS *c);
void desenhaBordaMapa(int coluna, int linha, COORDENADAS* c);
void desenhaInteriorHorizontal(int coluna, int linha, COORDENADAS* c, MAPA* m);
void desenhaInteriorVertical(int coluna, int linha, COORDENADAS* c);
