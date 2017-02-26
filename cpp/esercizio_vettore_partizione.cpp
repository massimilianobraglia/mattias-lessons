#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int leggi_numero() {
  int numero;
  cout << "Inserisci N" << endl;
  cin >> numero;
  
  return numero;
}

void stampa_vettore(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << "Posizione " << i << " valore " << v[i] << endl;
  }
}

vector<int> calcola_vettore_casuale(int N) {
  vector<int> v;
  srand(time(NULL));
 
  for (int i = 0; i < N; i++) {
    v.push_back(rand() % 1000);
  }

  return v;
}

vector<int> partiziona_vettore(vector<int> v, int posizione_elemento) {
  int elemento = v[posizione_elemento];
  vector<int> vettore_partizionato;
  
  for (int i = 0; i < v.size(); i++) {
    if (v[i] < elemento) {
      vettore_partizionato.push_back(v[i]);
    }
  }

  for (int i = 0; i < v.size(); i++) {
    if (v[i] == elemento) {
      vettore_partizionato.push_back(v[i]);
    }
  }  

  for (int i = 0; i < v.size(); i++) {
    if (v[i] > elemento) {
      vettore_partizionato.push_back(v[i]);
    }
  }

  return vettore_partizionato;
} 

int main() {
  int N = leggi_numero();
  vector<int> vettore_numeri_casuali = calcola_vettore_casuale(N);

  cout << "Vettore numeri casuali:" << endl;
  stampa_vettore(vettore_numeri_casuali);
  
  int posizione_casuale = rand() % N;

  cout << "Adesso partiziono il vettore sulla posizione " << posizione_casuale << " che corrisponde al valore " << vettore_numeri_casuali[posizione_casuale] << endl << endl;
  
  vector<int> vettore_partizionato = partiziona_vettore(vettore_numeri_casuali, posizione_casuale);

  cout << "Ho appena partizionato il vettore. Il risultato è il seguente:" << endl;

  stampa_vettore(vettore_partizionato);

  cout << "grazie e arrivederci!" << endl;
}

