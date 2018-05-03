#include <iostream>

using namespace std;
struct Node{

 int value;
 Node* next;

 Node(int value=0,Node* next=nullptr){
    this->value=value;
    this->next=next;

      }

};

struct SList{ //criando lista

   Node* head;

   SList(){
     this->head = nullptr;

  }
   ~SList(){
       deletarTudo(head);
   }

   void deletarTudo(Node * node){
       if(node == nullptr)
           return;
       deletarTudo(node->next);
       delete node;
}
   Node * cortarRabo(Node * node, int value){
      if(node == nullptr)
          return nullptr;
   node->next=cortarRabo(node->next,value);
   if(node->next == nullptr){
       if(node->value != value){
           delete node;
           return nullptr;
       }else{
           return node;
       }
   }
      return node;
}

   void push_front(int value){
       Node *node =new Node(value);//criando novo nó
       node->next=head;//o proximo do no
       this->head=node;//atualiza cabeça
   }
   void pop_front(){
       if(head == nullptr)
           return;
       Node * aux =head; //salva o nó
       head=head->next; //faz a cabeça apontar pro proximo
       delete aux; //deleta o auxiliar
   }
   void push_back(int value){
          if(head == nullptr){
              head = new Node(value);
              return;
          }
          auto node = head;
          while(node->next != nullptr)
              node = node->next;
          node->next = new Node(value);
  }

void  _rpush_back(Node *node,int value){
       if(node->next == nullptr){
          node->next= new Node(value);
           return;

       }else{
          _rpush_back(node->next,value);
       }
   }
   void rpush_back(int value){
       if(head==nullptr)
           head=new Node(value);
      _rpush_back(head,value);
   }

  void pop_back(){
  if(head == nullptr)//se não existe ninguem
      return ;
   if(head->next==nullptr){//só tem um
        delete head;
       head=nullptr;
       return;
       }
    auto node=head;
    while (node->next->next != nullptr)
     node =node->next;
    delete node->next;//avisa pro sistema liberar endereço de memoria
    node->next=nullptr;//avisar que não faz parte

   }
   void show(){
     auto node=head;
     while (node != nullptr) {
     cout<< node->value << " ";
       node=node->next;

     }
     cout << endl;
   }
   void _rshow(Node * node){
     if(node==nullptr)//ponto de parada
      return;
     cout<<node->value << " ";//mudar ordem inverte _rshow cout
       _rshow(node->next);

   }
   void rshow(){
       _rshow(head);
       cout<< endl;
   }

   Node *_rpop_back(Node *node){
       if(node->next == nullptr){//no que vai morrer
           delete node;
           return nullptr;
       }

       node->next =_rpop_back(node->next);

   }
   Node * _remove(Node *node,int value){
       if(node == nullptr){
           return nullptr;
     }
       if(node->value == value){
           auto aux =node->next;
           delete node;
           return aux;
        }
     //chama recursão pro proximo
     node->next =_remove(node->next,value);

   }

   void rremove(int value){
       head = _remove(head,value);
   }

   void iremove(int value){
       Node *atual= head;
       Node *aux;
     if(head == nullptr)//se não existe ninguem
           return ;
     while(atual != nullptr && atual->value == value){
         aux = atual;
         this->head = atual->next;
         atual = this->head;
         delete aux;
     }
     // enquanto o nó próximo ao nó atual for válido
     while(atual->next != nullptr){
         if(atual->next->value == value){ // se o nó próximo ao nó atual for igual ao valor a ser removido
           aux = atual->next;
          atual->next = atual->next->next; // o nó atual vai apontar para o próximo do nó a ser removido
          delete aux;
         }else{
             atual = atual->next; // se não, então o nó próximo ao nó atual vira o nó atual
         }
     }
 }
   void inserir_ordenado(int value){
       auto node = head;
       if(head == nullptr || head->value > value){
           this->head = new Node(value, head);
           return;
       }
       while(node->next != nullptr && node->next->value < value){
           node = node->next;
       }
       node->next = new Node(value, node->next);
   }


   int rmin(Node * node){
       if(node->next == nullptr)
           return node->value;
       return std::min(node->value, rmin(node->next));
}
   int _rmin(){
   return rmin(head);
   }

   int size(){
       int cont=0;
       Node *atual =head;
     if(atual==nullptr){
         return 0;
     }

     while (atual!=nullptr) {
         cont++;
         atual=atual->next;

     }
      return cont;

  }
   int rsomar(){
       int soma=0;
       Node *aux;
       aux=head;
       if(aux == nullptr)
         printf("Lista vazia");
       else{
           while (aux != nullptr) {//Enquanto a cabeça não for vazia
            soma += aux ->value;
            aux =aux ->next;
           }
       }
       return soma;

      }
};

int main()
{
  SList lista;

 lista.push_back(5);
 lista.push_back(6);
 lista.push_back(7);
 lista.push_back(8);
 lista.rpush_back(12);
 lista.rpush_back(18);
 lista.show();
//removendo elementos usando o remove interativo
lista.iremove(7);
printf("Lista ápos a remoçao de elementos \n");
 lista.show();
 printf("A quantidade de nós %d \n",lista.size());
 printf("O resultado da soma dos noś é: %d \n",lista.rsomar());
 printf("Inserindo Ordenado \n");
 lista.inserir_ordenado(78);
 lista.inserir_ordenado(10);
lista.show();




return 0;

}



