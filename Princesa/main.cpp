#include <iostream>
#include <list>
using namespace std ;

void mostrarLista(list <int> lista){
 int size = lista.size();
    for(int x = 0; x < size; x++){
        std::cout << lista.front() << " ";
        lista.pop_front();
    }
    std::cout << "\n";
 }
int main() {
int qtd= 0;
int escolha = 0;
int salto;
cin >> qtd >> escolha;
cin >>salto;
list <int> lista;
for(int i = 1;i <=qtd ; i++){
  lista.push_back(i);
}

  while(lista.front()!= escolha && salto  ){
    lista.push_back(lista.front());
    lista.pop_front();
  }
  while(lista.size()!= 1){
    mostrarLista(lista);
    lista.push_back(lista.front());
    lista.pop_front();
    lista.pop_front();
  }
   mostrarLista(lista);

return 0;

}
