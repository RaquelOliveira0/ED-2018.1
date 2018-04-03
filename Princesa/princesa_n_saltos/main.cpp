#include <iostream>
#include <list>
using namespace std ;
void salto(std::list<int> &lista,int saltos){
    if(saltos == 2 ){
       lista.push_back(lista.front());
       lista.pop_front();
        lista.pop_front();
        lista.pop_front();

        }

     if(saltos == 3){
       lista.push_back(lista.front());
       lista.pop_front();
        lista.pop_front();
         lista.pop_front();
         lista.pop_front();

}else if(saltos == 5){
        lista.push_back(lista.front());
        lista.pop_front();
         lista.pop_front();
          lista.pop_front();
          lista.pop_front();
          lista.pop_front();
          lista.pop_front();

}
    }



void rodar(std::list<int> &lista){
    lista.push_back(lista.front());
    lista.pop_front();
}
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
int saltos=0;
cout<<"Digite a quntidade e a escolha"<<"\n";
cin >> qtd >> escolha;
cout << "Digite o numero de saltos : 0 ,2, 3 ou 5"<<"\n";
cin >> saltos;
list <int> lista;
for(int i = 1;i <=qtd ; i++){
  lista.push_back(i);
}
 while(lista.front()!= escolha ){
    rodar(lista);
   //lista.push_back(lista.front());
   // lista.pop_front();

 }
    mostrarLista(lista);
  while(lista.size() > 1 ) {
      if(saltos == 0){
      rodar(lista);
      lista.pop_front();
      mostrarLista(lista);
      }else if(saltos > 0){
       salto(lista,saltos);
       mostrarLista(lista);

      }

  }


return 0;

}
