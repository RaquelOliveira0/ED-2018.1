#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Vetor{
    int * _data;//bloco de dados cria como ponteiro guarda os elementos
    int _capacidade; //tamanho máximo do vetor
    int _size; //quantos elementos estão inseridos no vetor

    Vetor(int capacidade){
        this->_capacidade = capacidade;
        this->_size = 0;
//        this->data = (int*) malloc(capacidade * 4);//retorno lixo
        this->_data = new int[capacidade];//retorno zerado
    }
    void push_back(int value){
        if(this->_size == this->_capacidade)
            return;
        this->reserve(2 * _capacidade);
        this->_data[this->_size] = value;
        this->_size += 1;
    }
    void pop_back(){
        if(this->_size == 0)
            return;
        this->_data[_size] = 0;
        this->_size -= 1;
    }

    //retornar a refencia à variavel dessa posicao
    int& at(int indice){
        return this->_data[indice];
    }
    int& front(){
        return this->_data[0];
    }
    int& back(){
        return this->_data[this->_size - 1];
    }
    int * begin(){ //retorna endereço
        return &this->_data[0];
    }
    int * end(){
        return &this->_data[this->_size];
    }
    int& size(){
        return this->_size;
    }

    int capacity(){
        return this->_capacidade;
    }

    void reserve(int capacity){
         if(capacity >= _capacidade){
              _capacidade=capacity;
               _data=new int[_capacidade];
               }

      else if(capacity < _capacidade){
          _size/_size;

        }
    }


};

int main()
{
    //vector<int> v {1,2,2,2};

   // cout <<"Imprimindo c++"<<"\n";
  //  v.push_back(0);
   // v.push_back(1);
   // v.push_back(2);
   // cout<<v.size();
   // cout<< v.capacity();
   //  v.reserve(10);
   // cout<< v.capacity();


  //  for(int x : v)
    // cout << x <<"\n ";

   // //adiciona os elementos vetor

  //  v.push_back(1);//1 elemento, 1 de capacidade
    //v.push_back(3);//2 elementos,2 de cap
    //v.push_back(5);//3 elementos,4 cap

    //v.reserve(100);
   //expande capacidade parva 100 elementos
    // v.size();// 3 imprime
    // v.capacity() ;//100 imprime

    //lvalue
   // v.front();//1
    //v.back();//5
    //v.front() = 6;

    //posicoes - iteradores
    //não são ponteiro, mas se comportam como se fosse
   // v.begin();//iterador pro primeiro endereço
   // v.end();//iterador pro abismo

   // vector<string> frutas(5, "bananas");
   // vector<string> f2(frutas); //cria f2 a partir de frutas copia
    //list<float> lista(10, 0.1f);

   //list<int> list = {3, 2, 5, 4, 3, 6, 8, 6};
   //for(int x : list)    //imprime a lista
     //  cout << x << " ";
   //for(auto it = list.begin(); it != list.end(); it++)
    //  cout << *it << " ";

  //Vetor pivet(3);
 //  pivet.push_back(4); //cap 1
 // pivet.push_back(2); //cap 2
  //  pivet.push_back(7);  //cap 4
  //  cout <<"size:"<< pivet.size();
  // for(int x : pivet)
    //  cout << x <<"\n ";




   Vetor teste(0);//o vetor usado
   cout<<"Imprimindo o meu vetor"<<"\n";
   cout<<"Capacidade antes do reserve:"<< teste.capacity()<<"\n";
   cout<< "Size:"<<teste.size()<<"\n";
    teste.reserve(10);
   cout<<"Capacidade depois do reserve:" << teste.capacity()<<"\n";


    //int x = 3;
   // int y = 2;
   // x = y;
   //int z = x;
    //lvalue & significa referencia
   // int& a = x;

    return 0;
}
