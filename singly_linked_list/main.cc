#include <iostream>
using namespace std;


#include "value_t.h"
#include "list_t.h"
#include "functions.h"


int main() {

  int n;

  cout << "Inserisci la dimensione della lista: ";
  cin >> n;

  list_t list = make_list(n);

  cout << "Lista creata: ";
  print_list(list);

  cout << "Inserisci il valore dei nodi che vuoi eliminare: ";
  value_t value = input_value();

  cout << "Occorrenze trovate: " << count_occurrences(list, value) << endl;

  list = delete_occurrences(list, value);
  cout << "Lista con le occorrenze eliminate: ";
  print_list(list);
  
  return 0;

}