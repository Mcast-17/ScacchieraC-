#ifndef SCACCHIERA_H
#define SCACCHIERA_H

#include <vector>
#include "Pezzo.h"

/*
    Classe Scacchiera.

    Gestisce:
    1. Le caselle della scacchiera.
    2. I pezzi presenti.
    3. Il posizionamento casuale.
    4. La stampa della scacchiera.
    5. La ricerca dei Pedoni catturabili dal Cavallo.
*/

class Scacchiera
{
private:

    // Dimensione della scacchiera.
    static const int SIZE = 8;

    /*
        Matrice utilizzata per rappresentare
        graficamente le caselle.
    */
    char celle[SIZE][SIZE];

    /*
        Vettore di puntatori alla classe base Pezzo.

        Grazie al polimorfismo possiamo inserire
        sia Pedoni che Cavalli.
    */
    std::vector<Pezzo*> pezzi;

    // Inizializza le caselle della scacchiera.
    void inizializzaCelle();

    // Controlla se una posizione è valida.
    bool posValida(int riga, int colonna) const;

public:

    // Costruttore.
    Scacchiera();

    // Distruttore.
    ~Scacchiera();

    // Aggiunge un pezzo alla scacchiera.
    void aggiungiPezzo(Pezzo* pezzo);

    /*
        Posiziona casualmente:
        - 8 Pedoni
        - 1 Cavallo
    */
    void posizionamentoPezziCasualmente();

    // Stampa la scacchiera.
    void stampa() const;

    // Trova i Pedoni catturabili dal Cavallo.
    void trovaPedoniCatturabili() const;
};

#endif
