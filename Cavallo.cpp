#include "Cavallo.h"
#include <cstdlib>

/*Costruttore della classe Cavallo:
Il Cavallo è rappresentato dal carattere 'C'.
Attraverso la lista di inizializzazione richiamiamo il costruttore della classe base Pezzo
*/

Cavallo::Cavallo(int r,int c):Pezzo(r,c,'C'){}

/*Verifica validità movimento:
Il Cavallo si muove sempre formando una "L": quindi 2 caselle in verticale e 1 in orizzontale oppure due caselle in orizzontale e 1 in verticale
Esempio:
 
    	X   X

    X           X

            C

    X           X

        X   X

    Prima di verificare il movimento controlliamo
    anche che la posizione di destinazione si trovi
    all'interno della scacchiera 8x8.
*/
bool Cavallo::movimentoValido(int nuovaRiga,int nuovaColonna) const
{
    //Controlliamo che la posizione di destinazione sia compresa tra 0 e 7//
    if(nuovaRiga < 0  || nuovaRiga >= 8 || nuovaColonna < 0 || nuovaColonna >= 8)
    {
        return false;
    }

    /*Calcolo della differenza assoluta tra posizione attuale e quella di destinazione*/
    int differenzaRiga = std::abs(nuovaRiga - riga);
    int differenzaColonna = std::abs(nuovaColonna - colonna);

    /*Il movimento del Cavallo è valido quando una coordinata varia di 2 caselle e l'altra di 1 casella*/
    if((differenzaRiga == 2 && differenzaColonna == 1) ||
       (differenzaRiga == 1 && differenzaColonna == 2))
    {
        return true;
    }

    return false;
}
