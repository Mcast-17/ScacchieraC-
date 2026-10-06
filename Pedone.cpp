#include "Pedone.h"

/*Costruttore della classe Pedone.
Il pedone viene rappresentato dal carattere 'P';
Il costruttore richiama il costruttore della classe base Pezzo attraverso la lista di inizilizzazione*/

Pedone::Pedone(int r,int c):Pezzo(r,c,'P'){}

//Verifica se il movimento del pedone è valido//
bool Pedone::movimentoValido(int nuovaRiga,int nuovaColonna)const
{
    int diffRiga = nuovaRiga - riga;
    int diffColonna = nuovaColonna - colonna;

    if(diffColonna == 0 && (diffRiga == 1 || diffRiga == -1))
    {
        return true;
    }

    return false;
}
