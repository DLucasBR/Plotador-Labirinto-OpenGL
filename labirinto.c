/*tudo o que acrescentei esta nesse arquivo*/
#include "desenho.h"



/****Minhas Variaveis*/
MAPA m;
COORDENADAS c;
/********************/


/*Exemplo generico do site onde onde Jorge pegou o material*/
void Desenha(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     glClear(GL_COLOR_BUFFER_BIT);

     glColor3f(1.0f, 0.0f, 0.0f);
     glPointSize(3);
     glLineWidth(3);

     /*****Ver desenho.c*****/
     desenhaLabirinto(&c,&m);
    /***********************/

     glFlush();
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
                   if(h == 0) h = 1;

                   glViewport(0, 0, w, h);

                   glMatrixMode(GL_PROJECTION);
                   glLoadIdentity();

                   if (w <= h)
                           gluOrtho2D (0.0f, TAMANHO_DA_TELA, 0.0f, TAMANHO_DA_TELA*h/w);
                   else
                           gluOrtho2D (0.0f, TAMANHO_DA_TELA*w/h, 0.0f, TAMANHO_DA_TELA);
}

void Inicializa (void)
{
    lemapa(&m);
    /*PS: esta lendo o arquivo mapa2.txt*/
    imprimemapa(&m);

    calculaCoordenadasIniciais(&c);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(TAMANHO_DA_TELA,TAMANHO_DA_TELA);
     glutInitWindowPosition(300,50);
     glutCreateWindow("I have no idea what i'm doing");
     glutDisplayFunc(Desenha);
     glutReshapeFunc(AlteraTamanhoJanela);
}

int main(void)
{
     Inicializa();
     glutMainLoop();

     return 0;
}
