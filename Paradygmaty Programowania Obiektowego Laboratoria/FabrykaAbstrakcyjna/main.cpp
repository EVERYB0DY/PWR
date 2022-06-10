#include "Interfejs.h"

int main()
{
    ListaObecnosci* lista = new ListaObecnosci();


    Interfejs* gui = new Interfejs(lista);
    

    return 0;
}