♟️ Scacchiera C++ — Gestione dei pezzi e movimento del Cavallo

Progetto sviluppato in C++ per simulare una semplice scacchiera 8×8 e la gestione di alcuni pezzi degli scacchi attraverso i principali concetti della Programmazione Orientata agli Oggetti (OOP).
Il programma genera casualmente una scacchiera contenente 8 Pedoni e 1 Cavallo, impedendo la sovrapposizione dei pezzi, visualizza la configurazione ottenuta e individua i Pedoni che possono 
essere catturati dal Cavallo.

---

🎯 Obiettivi del progetto

Il progetto è stato realizzato con l'obiettivo di applicare concretamente:

- Programmazione Orientata agli Oggetti
- Classi e oggetti
- Ereditarietà
- Polimorfismo
- Metodi virtuali puri
- Classe astratta
- "dynamic_cast"
- Gestione dinamica della memoria
- Puntatori
- "vector" della STL
- Array bidimensionali
- Generazione di numeri casuali
- Controllo delle posizioni
- Separazione tra file ".h" e ".cpp"

---

♟️ Funzionamento

All'avvio viene creata una scacchiera di dimensione 8×8.

Il programma:

1. Inizializza le 64 caselle.
2. Genera casualmente 8 Pedoni.
3. Controlla che ogni posizione sia libera prima di inserire un nuovo pezzo.
4. Genera casualmente 1 Cavallo.
5. Controlla nuovamente che la posizione del Cavallo sia libera.
6. Visualizza la scacchiera nel terminale.
7. Individua il Cavallo.
8. Analizza le sue possibili mosse.
9. Verifica quali caselle raggiungibili contengono un Pedone.
10. Mostra i Pedoni che il Cavallo può catturare.

---

🧱 Struttura del progetto
<pre>
Scacchiera/
│
├── main.cpp
│
├── Pezzo.h
├── Pezzo.cpp
│
├── Pedone.h
├── Pedone.cpp
│
├── Cavallo.h
├── Cavallo.cpp
│
├── Scacchiera.h
├── Scacchiera.cpp
│
└── README.md
</pre>
---

🏗️ Architettura delle classi

La classe "Pezzo" rappresenta la classe base del progetto.

Da essa derivano i diversi tipi di pezzo.

                 ┌───────────────┐
                 │    Pezzo      │
                 │  classe base  │
                 └───────┬───────┘
                         │
              ┌──────────┴──────────┐
              │                     │
       ┌──────▼──────┐       ┌──────▼──────┐
       │   Pedone    │       │   Cavallo   │
       └─────────────┘       └─────────────┘

La classe "Pezzo" contiene le informazioni comuni:

- riga
- colonna
- simbolo

e definisce il metodo virtuale puro: virtual bool movimentoValido(int nuovaRiga,int nuovaColonna) const = 0;

In questo modo ogni classe derivata può implementare la propria regola di movimento.

---

🔹 Classe "Pezzo"

"Pezzo" è la classe base astratta del progetto.

Contiene:

int riga;
int colonna;
char simbolo;

e mette a disposizione alcuni getter:

int getRiga() const;
int getColonna() const;
char getSimbolo() const;

Il distruttore è virtuale:

virtual ~Pezzo();

Questo permette di eliminare correttamente gli oggetti derivati attraverso un puntatore alla classe base.

---

🔹 Classe "Pedone"

La classe "Pedone" eredita da "Pezzo".

Il Pedone viene utilizzato nel progetto principalmente come pezzo che può essere catturato dal Cavallo.

La sua posizione viene gestita attraverso la classe base.

---

🔹 Classe "Cavallo"

La classe "Cavallo" eredita anch'essa da "Pezzo".

Il Cavallo implementa il proprio metodo:

movimentoValido()

seguendo la classica regola di movimento del Cavallo negli scacchi.

Un Cavallo può muoversi secondo una delle otto combinazioni:

(-2,-1)   (-2,+1)

(-1,-2)   (-1,+2)

(+1,-2)   (+1,+2)

(+2,-1)   (+2,+1)

---

🔹 Classe "Scacchiera"

La classe "Scacchiera" gestisce l'intero ambiente di gioco.

Contiene:

char celle[8][8];

per rappresentare le caselle e:

std::vector<Pezzo*> pezzi;

per memorizzare i pezzi presenti.

L'utilizzo di "vector<Pezzo*>" permette di gestire contemporaneamente oggetti di tipo "Pedone" e "Cavallo" attraverso puntatori alla classe base.

---

🧠 Polimorfismo

Uno degli aspetti principali del progetto è il polimorfismo.

La scacchiera non deve conoscere direttamente il tipo concreto di ogni elemento del vettore:

std::vector<Pezzo*> pezzi;

Può quindi contenere:

Pezzo*
 ├── Pedone
 └── Cavallo
 Per individuare il tipo concreto di un oggetto viene utilizzato "dynamic_cast".

Esempio:

Cavallo* cavallo = dynamic_cast<Cavallo*>(pezzo);

e:

Pedone* pedone = dynamic_cast<Pedone*>(pezzo);

---

💾 Gestione della memoria

I pezzi vengono creati dinamicamente:

Pedone* pedone = new Pedone(riga, colonna);

e:

Cavallo* cavallo = new Cavallo(riga, colonna);

Successivamente vengono inseriti nel vector: pezzi.push_back(pezzo);

La memoria viene liberata nel distruttore della classe "Scacchiera": delete pezzi[i];

Questo evita di lasciare in memoria gli oggetti creati dinamicamente.

---

🎲 Posizionamento casuale

Il programma genera casualmente la posizione dei pezzi utilizzando: std::rand()

Le coordinate vengono generate nell'intervallo:

0 → 7

prima per la riga e poi per la colonna.

Prima di inserire ogni pezzo viene verificato che la casella non sia già occupata.

In questo modo non possono essere presenti due pezzi nella stessa posizione.

---

🗺️ Rappresentazione della scacchiera

Le coordinate interne utilizzano valori da "0" a "7".

La visualizzazione converte invece le coordinate in una rappresentazione simile a quella di una vera scacchiera:

    a b c d e f g h

8   b P b n b n P n   8
7   n b n b n b n P   7
6   b n b P b n b n   6
5   n b n P C b n b   5
4   b n b n b n P n   4
3   n b n b n b n b   3
2   b n b n b n b n   2
1   n b P b P b n b   1

    a b c d e f g h

Dove:

- "b" = casella scura
- "n" = casella chiara
- "P" = Pedone
- "C" = Cavallo

---

♞ Ricerca dei Pedoni catturabili

Dopo aver stampato la scacchiera, il programma individua il Cavallo e analizza le sue possibili destinazioni.

Per ogni movimento:

1. viene calcolata la nuova posizione;
2. viene verificato che la posizione sia dentro la scacchiera;
3. viene verificata la validità del movimento;
4. viene controllato se nella destinazione è presente un pezzo;
5. viene verificato se il pezzo è un Pedone.

Se tutte le condizioni sono rispettate, il Pedone viene indicato come catturabile.

Esempio:

===== PEDONI CATTURABILI =====

Cavallo in e5 puo' catturare:

- Pedone in g4

---

🛠️ Tecnologie utilizzate

Tecnologia| Utilizzo
C++| Linguaggio principale
OOP| Struttura del progetto
STL| Utilizzo di "vector"
"dynamic_cast"| Identificazione dei tipi derivati
Puntatori| Gestione degli oggetti
"new" / "delete"| Gestione dinamica della memoria
Array bidimensionali| Rappresentazione della scacchiera
"rand()"| Posizionamento casuale

---

▶️ Compilazione ed esecuzione

Il progetto può essere aperto con un IDE compatibile con C++, ad esempio Dev-C++.

È necessario compilare tutti i file ".cpp":

main.cpp
Pezzo.cpp
Pedone.cpp
Cavallo.cpp
Scacchiera.cpp

e successivamente avviare il programma.

---

📌 Possibili sviluppi futuri

Il progetto può essere esteso introducendo:

- ♜ Torre
- ♝ Alfiere
- ♛ Regina
- ♚ Re
- gestione di due giocatori
- turni di gioco
- movimento manuale dei pezzi
- cattura effettiva dei pezzi
- controllo delle mosse disponibili
- controllo dello scacco
- scacco matto
- rappresentazione grafica della scacchiera
- gestione delle partite
- salvataggio e caricamento delle configurazioni

---

📚 Competenze dimostrate

Il progetto rappresenta un progetto pratico sui principali concetti della programmazione C++ orientata agli oggetti.

In particolare permette di dimostrare la capacità di lavorare con:

C++ → OOP → Ereditarietà → Polimorfismo → Puntatori → STL → Gestione della memoria → Strutture dati → Logica algoritmica

---

👨‍💻 Autore

Mattia Castiello

Progetto personale realizzato per consolidare le competenze di programmazione C++ e Programmazione Orientata agli Oggetti.
