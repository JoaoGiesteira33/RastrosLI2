#include <stdio.h>
#include "camadadados.h"
#include "interface.h"
#include "logica.h"


int main()
{
    ESTADO *e = inicializar_estado();
    interpretador(e);

    return 0;
}
