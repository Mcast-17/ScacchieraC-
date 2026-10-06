#include <iostream>
#include "Scacchiera.h"

int main()
{
/*Creiamo un oggetto di tipo Scacchiera.
Il costruttore della classe Scacchiera si occuperà automaticamente di:
- inizializzare le 64 caselle;
- posizionare 8 pedoni casualmente;
- posizionare 1 cavallo casualmente.
*/
    Scacchiera scacchiera;

    std::cout << "===== SCACCHIERA =====\n";

    /*Visualizziamo la scacchiera con tutti i pezzi presenti.*/
    scacchiera.stampa();

    //Cerchiamo quali Pedoni possono essere catturati dal cavallo.//
    std::cout << "\n===== PEDONI CATTURABILI =====\n";

    scacchiera.trovaPedoniCatturabili();

    //Il valore 0 indica che il programma è terminato correttamente.//
    return 0;
}
