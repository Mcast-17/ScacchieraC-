#ifndef CAVALLO_H
#define CAVALLO_H

#include "Pezzo.h"

/*La classe Cavallo eredita dalla classe Pezzo.
Il Cavallo possiede quindi:
-Una riga,
-Una colonna,
-Un simbolo,
-I metodi ereditati dalla classe Pezzo.
La classe aggiunge la propria logica di movimento
*/

class Cavallo : public Pezzo
{
public:

    //Costruttore della classe Cavallo: r->Riga iniziale del Cavallo, c->Colonna iniziale del Cavallo//
    Cavallo(int r,int c);

    /*Verifica se una determinata posizione può essere raggiunta dal Cavallo:
    Il Cavallo si muove formando una "L" -> 2 caselle in una direzione;
                       -> 1 casella nella direzione perpendicolare*/
    bool movimentoValido(int nuovaRiga,int nuovaColonna) const;
};

#endif
