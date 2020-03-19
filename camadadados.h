#ifndef RASTROSLI2_CAMADADADOS_H
#define RASTROSLI2_CAMADADADOS_H
typedef enum
{
    VAZIO,
    BRANCA,
    PRETA
} CASA;
typedef struct
{
    int coluna;
    int linha;
} COORDENADA;
typedef struct
{
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;
typedef JOGADA JOGADAS[32];
typedef struct
{
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;

ESTADO *inicializar_estado();

int obter_jogador_atual(ESTADO *estado);

int obter_numero_de_jogadas(ESTADO *estado);

COORDENADA *obter_ultima_jogada (ESTADO *estado);

char *conversorultimajogada (COORDENADA *c);

CASA obter_estado_casa(ESTADO *e, COORDENADA c);
#endif //RASTROSLI2_CAMADADADOS_H
