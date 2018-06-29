#include <iostream>
#include <vector>
using namespace std;

void quicksort(vector<int>& vet, int began, int end)
{
    int i, j, pivo, aux;
    i = began;//i recebe ocomeço
    j = end-1; //j=fim
    pivo = vet[(began + end) / 2];
    while(i <= j) //enquanto o comeco for menor ou igual o fim
    {
        while(vet[i] < pivo && i < end)
        {
            i++;
        }
        while(vet[j] > pivo && j > began)
        {
            j--;
        }
        if(i <= j)
        {

            swap(vet[i++],vet[j--]);
        }
    }
    if(j > began)
        quicksort(vet, began, j+1);
    if(i < end)
        quicksort(vet, i, end);
}



void _selectinonSort(vector<int>& vet){

int i,j,minimo;

for(i=0;i< (int)vet.size()-1;i++){
    minimo=i;
for(j=i+1 ;j <(int) vet.size();j++){
    if(vet[j]< vet[minimo])
    minimo=j;
    swap(vet[minimo],vet[i]);
}
}

}
void burblesort(vector<int>& vet){
int i,j;
for(i=0;i< (int)vet.size();i++)
    for(j=0;j< (int)vet.size()-i-1;j++)
       if(vet[j]>vet[j+1])
       swap(vet[j],vet[j+1]);


}

void insertionsort(vector<int>vet){

    for(int i=1;i< (int)vet.size();i++) {
        for(int j=i;j<0;j--){
            if(vet[j]>vet[j-1]){
               swap(vet[j],vet[j-1]);
            }else{
                break;
            }
        }
    }

}

void reverse_minimum_sort(vector<int>& vet){
    int ultimo = vet.size() - 1;
    for(int i = 0; i <= ultimo; ultimo--){
        int imaior = ultimo;
        for(int j = 0; j < ultimo; j++){
            if(vet[j] > vet[imaior]){
                imaior = j;
            }
        }
        std::swap(vet[imaior], vet[ultimo]);
    }
}

void merge(vector<int>& vet, int a, int b, int c){
    int i = a;
    int j = b;
    vector<int> vaux;
    vaux.reserve(c - a);
    while((i < b) && (j < c)){ //comparar particoes
        if(vet[i] < vet[j])
            vaux.push_back(vet[i++]);
        else
            vaux.push_back(vet[j++]);

    }
    while(i < b){
        vaux.push_back(vet[i++]);

    }
    while(j < c){
        vaux.push_back(vet[j++]);

    }
    for(int i = 0; i < (int) vaux.size(); i++){
        vet[a + i] = vaux[i];

    }
}

void mergesort(vector<int>& vet, int a, int c){
    if(c == a + 1)
        return;
    int b = (a + c)/2;
    mergesort(vet, a, b);
    mergesort(vet, b, c);
    merge(vet, a, b, c);
}
int main(int argc, char *argv[])
{
    //int array[10] = {5, 8, 1, 2, 7, 3, 6, 9, 4, 10};
    vector <int> vet ;
    vet.push_back(5);
    vet.push_back(8);
    vet.push_back(1);
    vet.push_back(50);
    vet.push_back(2);
    for(int i = 0; i < (int) vet.size(); i++)
    {
        std::cout << vet[i] << ' ';
    }
    std::cout << std::endl;
    quicksort(vet, 0,(int)vet.size());
  // mergesort(vet,0,(int)vet.size());
   // _selectinonSort(vet);
    //burblesort(vet);

    for(int i = 0; i < (int) vet.size(); i++)
    {
        std::cout << vet[i] << ' ';
    }
    return 0;
}
