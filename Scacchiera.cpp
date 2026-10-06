#include "Scacchiera.h"
#include "Pedone.h"
#include "Cavallo.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

/*
    ============================================================
    COSTRUTTORE
    ============================================================
*/
Scacchiera::Scacchiera()
{
    // Inizializza le caselle della scacchiera.
    inizializzaCelle();

    // Inizializza il generatore di numeri casuali.
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    // Posiziona automaticamente i pezzi.
    posizionamentoPezziCasualmente();
}


/*
    ============================================================
    DISTRUTTORE
    ============================================================
*/
Scacchiera::~Scacchiera()
{
    /*
        I pezzi sono stati creati con new,
        quindi dobbiamo eliminarli con delete.
    */
    for (int i = 0; i < static_cast<int>(pezzi.size()); i++)
    {
        delete pezzi[i];
    }

    // Svuotiamo il vector.
    pezzi.clear();
}


/*
    ============================================================
    INIZIALIZZAZIONE DELLE CASELLE
    ============================================================
*/
void Scacchiera::inizializzaCelle()
{
    for (int riga = 0; riga < SIZE; riga++)
    {
        for (int colonna = 0; colonna < SIZE; colonna++)
        {
            /*
                Alterniamo i colori delle caselle.

                'b' = casella scura
                'n' = casella chiara
            */
            if ((riga + colonna) % 2 == 0)
            {
                celle[riga][colonna] = 'b';
            }
            else
            {
                celle[riga][colonna] = 'n';
            }
        }
    }
}


/*
    ============================================================
    CONTROLLO POSIZIONE
    ============================================================
*/
bool Scacchiera::posValida(int riga, int colonna) const
{
    if (riga < 0)
    {
        return false;
    }

    if (riga >= SIZE)
    {
        return false;
    }

    if (colonna < 0)
    {
        return false;
    }

    if (colonna >= SIZE)
    {
        return false;
    }

    return true;
}


/*
    ============================================================
    AGGIUNTA PEZZO
    ============================================================
*/
void Scacchiera::aggiungiPezzo(Pezzo* pezzo)
{
    if (pezzo != NULL)
    {
        pezzi.push_back(pezzo);
    }
}


/*
    ============================================================
    POSIZIONAMENTO CASUALE DEI PEZZI
    ============================================================

    Vengono inseriti:

    - 8 Pedoni
    - 1 Cavallo

    Nessun pezzo può occupare la stessa posizione.
*/
void Scacchiera::posizionamentoPezziCasualmente()
{
    int pedoniInseriti = 0;

    /*
        --------------------------------------------------------
        INSERIMENTO DEGLI 8 PEDONI
        --------------------------------------------------------
    */
    while (pedoniInseriti < 8)
    {
        // Generiamo una posizione casuale.
        int riga = std::rand() % SIZE;
        int colonna = std::rand() % SIZE;

        // All'inizio consideriamo la posizione libera.
        bool posizioneOccupata = false;

        /*
            Controlliamo tutti i pezzi già presenti.
        */
        for (int i = 0; i < static_cast<int>(pezzi.size()); i++)
        {
            Pezzo* pezzo = pezzi[i];

            if (pezzo->getRiga() == riga &&
                pezzo->getColonna() == colonna)
            {
                posizioneOccupata = true;
                break;
            }
        }

        /*
            Se la posizione è libera,
            creiamo un nuovo Pedone.
        */
        if (!posizioneOccupata)
        {
            Pedone* pedone = new Pedone(riga, colonna);

            aggiungiPezzo(pedone);

            pedoniInseriti++;
        }
    }


    /*
        --------------------------------------------------------
        INSERIMENTO DEL CAVALLO
        --------------------------------------------------------
    */
    bool cavalloInserito = false;

    while (!cavalloInserito)
    {
        // Generiamo una posizione casuale.
        int riga = std::rand() % SIZE;
        int colonna = std::rand() % SIZE;

        // Controlliamo se la posizione è occupata.
        bool posizioneOccupata = false;

        /*
            Controlliamo tutti i pezzi già presenti.
        */
        for (int i = 0; i < static_cast<int>(pezzi.size()); i++)
        {
            Pezzo* pezzo = pezzi[i];

            if (pezzo->getRiga() == riga &&
                pezzo->getColonna() == colonna)
            {
                posizioneOccupata = true;
                break;
            }
        }

        /*
            Se la posizione è libera,
            creiamo il Cavallo.
        */
        if (!posizioneOccupata)
        {
            Cavallo* cavallo = new Cavallo(riga, colonna);

            aggiungiPezzo(cavallo);

            cavalloInserito = true;
        }
    }
}


/*
    ============================================================
    STAMPA DELLA SCACCHIERA
    ============================================================
*/
void Scacchiera::stampa() const
{
    std::cout << "\n";

    // Intestazione delle colonne.
    std::cout << "    a b c d e f g h\n";
    std::cout << "\n";

    /*
        Scorriamo le 8 righe.
    */
    for (int riga = 0; riga < SIZE; riga++)
    {
        /*
            Stampiamo il numero della riga.

            Internamente abbiamo:
            0 -> 8
            1 -> 7
            ...
            7 -> 1
        */
        std::cout << 8 - riga << "   ";

        /*
            Scorriamo le 8 colonne.
        */
        for (int colonna = 0; colonna < SIZE; colonna++)
        {
            /*
                Partiamo dal simbolo della casella.
            */
            char simboloCasella = celle[riga][colonna];

            /*
                Controlliamo se sulla casella
                è presente un pezzo.
            */
            for (int i = 0; i < static_cast<int>(pezzi.size()); i++)
            {
                Pezzo* pezzo = pezzi[i];

                if (pezzo->getRiga() == riga &&
                    pezzo->getColonna() == colonna)
                {
                    /*
                        Se troviamo un pezzo,
                        sostituiamo il simbolo della
                        casella con quello del pezzo.
                    */
                    simboloCasella = pezzo->getSimbolo();

                    break;
                }
            }

            // Stampiamo la casella.
            std::cout << simboloCasella << " ";
        }

        /*
            Numero della riga sulla destra.
        */
        std::cout << "  " << 8 - riga << "\n";
    }

    // Intestazione inferiore.
    std::cout << "\n";
    std::cout << "    a b c d e f g h\n";
}


/*
    ============================================================
    RICERCA DEI PEDONI CATTURABILI
    ============================================================
*/
void Scacchiera::trovaPedoniCatturabili() const
{
    /*
        Puntatore al Cavallo.

        Inizialmente non abbiamo trovato nessun Cavallo.
    */
    const Cavallo* cavallo = NULL;


    /*
        --------------------------------------------------------
        CERCHIAMO IL CAVALLO
        --------------------------------------------------------
    */

    for (int i = 0; i < static_cast<int>(pezzi.size()); i++)
    {
        Pezzo* pezzo = pezzi[i];

        /*
            dynamic_cast controlla se il Pezzo
            è effettivamente un Cavallo.
        */
        cavallo = dynamic_cast<Cavallo*>(pezzo);

        if (cavallo != NULL)
        {
            break;
        }
    }


    /*
        Se non abbiamo trovato il Cavallo,
        terminiamo la funzione.
    */
    if (cavallo == NULL)
    {
        std::cout << "Nessun cavallo presente sulla scacchiera.\n";
        return;
    }
    
    /*
        --------------------------------------------------------
        POSIZIONE DEL CAVALLO
        --------------------------------------------------------
    */

    int rigaCavallo = cavallo->getRiga();
    int colonnaCavallo = cavallo->getColonna();


    /*
        Array utilizzato per convertire
        la colonna numerica nella lettera.
    */
    const char colonne[] =
    {
        'a',
        'b',
        'c',
        'd',
        'e',
        'f',
        'g',
        'h'
    };


    /*
        Stampiamo la posizione del Cavallo.
    */
    std::cout << "Cavallo in "
              << colonne[colonnaCavallo]
              << 8 - rigaCavallo
              << " puo' catturare:\n\n";


    /*
        Variabile che indica se abbiamo trovato
        almeno un Pedone catturabile.
    */
    bool pedoneTrovato = false;


    /*
        --------------------------------------------------------
        MOVIMENTI POSSIBILI DEL CAVALLO
        --------------------------------------------------------

        Ogni elemento contiene:

        [0] = variazione della riga
        [1] = variazione della colonna
    */
    const int movimenti[8][2] =
    {
        {-2, -1},
        {-2,  1},
        {-1, -2},
        {-1,  2},
        { 1, -2},
        { 1,  2},
        { 2, -1},
        { 2,  1}
    };


    /*
        --------------------------------------------------------
        ANALISI DELLE 8 POSSIBILI MOSSE
        --------------------------------------------------------
    */

    for (int i = 0; i < 8; i++)
    {
        /*
            Calcoliamo la nuova posizione.
        */
        int nuovaRiga =
            rigaCavallo + movimenti[i][0];

        int nuovaColonna =
            colonnaCavallo + movimenti[i][1];


        /*
            Se la posizione è fuori dalla scacchiera,
            passiamo alla mossa successiva.
        */
        if (!posValida(nuovaRiga, nuovaColonna))
        {
            continue;
        }


        /*
            Controlliamo che il movimento
            sia valido per il Cavallo.
        */
        if (!cavallo->movimentoValido(nuovaRiga, nuovaColonna))
        {
            continue;
        }


        /*
            ----------------------------------------------------
            CERCHIAMO UN PEZZO NELLA CASELLA DI DESTINAZIONE
            ----------------------------------------------------
        */

        for (int j = 0; j < static_cast<int>(pezzi.size()); j++)
        {
            Pezzo* pezzo = pezzi[j];

            /*
                Controlliamo se il pezzo si trova
                nella posizione di destinazione.
            */
            if (pezzo->getRiga() == nuovaRiga &&
                pezzo->getColonna() == nuovaColonna)
            {
                /*
                    Controlliamo se il pezzo
                    è un Pedone.
                */
                Pedone* pedone =
                    dynamic_cast<Pedone*>(pezzo);

                if (pedone != NULL)
                {
                    /*
                        Stampiamo la posizione
                        del Pedone catturabile.
                    */
                    std::cout << "- Pedone in "
                              << colonne[nuovaColonna]
                              << 8 - nuovaRiga
                              << "\n";

                    pedoneTrovato = true;
                }

                /*
                    Abbiamo trovato il pezzo
                    nella casella, quindi non serve
                    controllare gli altri pezzi
                    per questa posizione.
                */
                break;
            }
        }
    }


    /*
        Se nessun Pedone è stato trovato,
        mostriamo il relativo messaggio.
    */
    if (!pedoneTrovato)
    {
        std::cout << "- Nessun pedone catturabile.\n";
    }
}
