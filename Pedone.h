#ifndef PEDONE_H
#define PEDONE_H

#include "Pezzo.h"

/*Classe Pedone.
La classe Pedone eredita dalla classe Pezzo.
In questo modo il pedone possiede già:
- riga
- colonna
- simbolo
- metodi per ottenere queste informazioni
La classe Pedone aggiunge invece la propria logica relativa al movimento.*/
class Pedone : public Pezzo
{
public:

    /*Costruttore della classe Pedone.
        r -> riga iniziale del pedone
        c -> colonna iniziale del pedone
    */
    Pedone(int r, int c);

    /*
        Verifica se il movimento del pedone è valido.
        Questo metodo sovrascrive quello dichiarato
        nella classe base Pezzo.
    */
    bool movimentoValido(int nuovaRiga, int nuovaColonna) const;
};

#endif
