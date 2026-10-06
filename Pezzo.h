#ifndef PEZZO_H
#define PEZZO_H

// Classe base Pezzo.
// Rappresenta un generico pezzo presente sulla scacchiera.
class Pezzo
{
protected:

    // Riga occupata dal pezzo.
    int riga;

    // Colonna occupata dal pezzo.
    int colonna;

    // Simbolo utilizzato per rappresentare il pezzo.
    char simbolo;

public:

    /*
        Costruttore della classe Pezzo.

        r -> riga iniziale
        c -> colonna iniziale
        s -> simbolo del pezzo
    */
    Pezzo(int r, int c, char s);

    // Distruttore virtuale.
    virtual ~Pezzo();

    // Restituisce la riga occupata dal pezzo.
    int getRiga() const;

    // Restituisce la colonna occupata dal pezzo.
    int getColonna() const;

    // Restituisce il simbolo del pezzo.
    char getSimbolo() const;

    /*
        Metodo virtuale puro.

        Ogni classe derivata dovrà implementare
        la propria regola di movimento.
    */
    virtual bool movimentoValido(int nuovaRiga,
                                 int nuovaColonna) const = 0;
};

#endif
