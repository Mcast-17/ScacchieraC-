#include "Pezzo.h"

// Costruttore della classe Pezzo.
Pezzo::Pezzo(int r, int c, char s)
{
    riga = r;
    colonna = c;
    simbolo = s;
}

// Distruttore virtuale.
Pezzo::~Pezzo()
{
}

// Restituisce la riga occupata dal pezzo.
int Pezzo::getRiga() const
{
    return riga;
}

// Restituisce la colonna occupata dal pezzo.
int Pezzo::getColonna() const
{
    return colonna;
}

// Restituisce il simbolo del pezzo.
char Pezzo::getSimbolo() const
{
    return simbolo;
}
