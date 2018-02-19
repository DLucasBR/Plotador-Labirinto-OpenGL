#include "desenho.h"


void desenhaLinhaHorizontal(int coluna,int linha, int distancia, int borda){
    /*desenha uma coluna horizontal na altura do parametro coluna partindo do
    ponto indicado no parametro linha até o ponto seguinte na horizontal*/
    glBegin(GL_LINE_STRIP);
        glVertex2i( (coluna - 1) * distancia + borda, (linha * distancia) + borda);
        glVertex2i( (coluna * distancia + borda ), (linha * distancia + borda));
    glEnd();
}

void desenhaLinhaVertical (int coluna, int linha, int distancia, int borda){
    glBegin(GL_LINE_STRIP);
        glVertex2i( (coluna * distancia) + borda, (linha - 1) * distancia + borda);
        glVertex2i( (coluna * distancia) + borda, (linha * distancia) + borda);
    glEnd();
}

void desenhaLabirinto(COORDENADAS *c, MAPA *m){

    int linha,coluna;

        for(linha = 0; linha < c->tam_mapa; linha++){
            for(coluna = 0 ; coluna < c->tam_mapa ; coluna++){
                switch (m->matriz[linha][coluna]){
                   case '.':
                       desenhaPontosMapa(coluna,linha,c);
                       break;
                   case '*':
                       desenhaBordaMapa(coluna,linha,c);
                       break;
                   case '_':
                       desenhaInteriorHorizontal(coluna,linha,c,m);
                       break;
                   case'|':
                       desenhaInteriorVertical(coluna,linha,c);
                       break;
                }
            }
        }
}

void desenhaBordaMapa(int coluna, int linha, COORDENADAS* c){
    if( !linha && coluna )
        desenhaLinhaHorizontal(coluna,linha,c->dist_pontos,c->bordas);
    if (linha == c->tam_mapa - 1 && coluna) /*Caso seja a ultima linha temos de deslocar sua coordenada x para um ponto adiante, lembre-se que a contagem comeca em 0*/
        desenhaLinhaHorizontal(coluna,linha ,c->dist_pontos,c->bordas);
    if (!coluna && linha )
        desenhaLinhaVertical (coluna ,linha,c->dist_pontos,c->bordas);
    if (coluna == c->tam_mapa - 1 && linha)
        desenhaLinhaVertical (coluna ,linha,c->dist_pontos,c->bordas);
}

void desenhaPontosMapa(int coluna, int linha, COORDENADAS *c){
        glBegin(GL_POINTS);
            glVertex2i( (coluna * c->dist_pontos) + c->bordas, (linha * c->dist_pontos) + c->bordas);
        glEnd();
}

void desenhaInteriorHorizontal(int coluna, int linha, COORDENADAS* c, MAPA* m){

    //fazer curva
    if(m->matriz[linha][coluna + 1] == '|' && m->matriz[linha + 1 ][coluna] != '|')
        desenhaLinhaHorizontal(coluna + 1,linha,c->dist_pontos,c->bordas);

    //fechar mapa quando na ultima coluna
    if(coluna == c->tam_mapa -1 &&  m->matriz[linha - 1 ][coluna] == '*')
        desenhaLinhaVertical(coluna,linha,c->dist_pontos,c->bordas);

    //fechar mapa na primeira coluna
    if(coluna == 0){
        desenhaLinhaHorizontal(coluna + 1,linha,c->dist_pontos,c->bordas);
        if(m->matriz[linha - 1][coluna] != '_')
            desenhaLinhaVertical(coluna,linha,c->dist_pontos,c->bordas);
    }else
        desenhaLinhaHorizontal(coluna,linha,c->dist_pontos,c->bordas);
}

 void desenhaInteriorVertical(int coluna, int linha, COORDENADAS* c){

    desenhaLinhaVertical(coluna,linha,c->dist_pontos,c->bordas);

}

void calculaCoordenadasIniciais(COORDENADAS* c){

    c->tam_mapa = getLarguraMapa();
    c->bordas = TAMANHO_DA_TELA/c->tam_mapa -1;
    c->dist_pontos = (TAMANHO_DA_TELA - 2*c->bordas)/c->tam_mapa -1;

    printf("%d %d ", c->bordas, c->dist_pontos);
}
