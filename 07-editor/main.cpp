#include <iostream>
#include <list>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "sftext.h"

using namespace std;

struct Ambiente{
    list<char> texto; //lista de caracters
    list <char> aux;
    list <char> aux2;
    list<char>::iterator cursor;//cursor que aponta
     list<char>::iterator cursor2;

    Ambiente(){
        cursor = texto.end();//nó válido

    }

    string toString(){
        stringstream ss;
        for(auto it = texto.begin(); it != texto.end(); it++){
            if(it == cursor) //se o interador for igual cursor
                ss << "#";
            ss << (*it);
        }
        if(cursor == texto.end())
            ss << "#";
        return ss.str();
    }
};

int main()
{
    Ambiente amb;




    amb.texto.push_back('a');
    amb.texto.push_back('m');
    amb.texto.push_back('o');
    amb.texto.push_back('r');

    sf::RenderWindow janela(sf::VideoMode(800, 600), "Janela");//criando janela

    while(janela.isOpen()){ //laço da janela

        sf::Event event;
        while(janela.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                janela.close();
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Z){
                    if(event.key.control)
                   cout << "control z" << endl;
                     amb.aux=amb.texto;
                  if(!amb.aux.empty()){
                      amb.aux.back();

                    amb.texto.pop_back();

                    }

                }
                else if(event.key.code == sf::Keyboard::R){
                    if(event.key.control){
                        cout << "control r" << endl;

                    if(!amb.aux.empty()){
                      amb.aux.back();
                      amb.texto=amb.aux;
                      amb.cursor=amb.texto.end();

                          }
                    }
                }




                else if((event.key.code >= sf::Keyboard::A) &&
                   (event.key.code <= sf::Keyboard::Z)){
                    char tecla = (event.key.code - sf::Keyboard::A) + 'a';
                    cout << tecla << endl;
                    amb.texto.insert(amb.cursor,tecla);
                }
                else if((event.key.code == sf::Keyboard::Space)){
                    cout << "espaco" << endl;
                    amb.texto.insert(amb.cursor,' ');
                }
                else if(event.key.code == sf::Keyboard::BackSpace){
                    cout << "backspace" << endl;
                   for(auto it = amb.texto.begin(); it != amb.texto.end(); it--){
                  amb.texto.erase(amb.cursor++,amb.cursor--);
                      }
                    }

                else if(event.key.code == sf::Keyboard::Delete){
                    cout << "delete" << endl;
                   if(amb.cursor != amb.texto.end()){
                  amb.texto.erase(amb.cursor++);
                      }
                }

                else if(event.key.code == sf::Keyboard::Left){
                    amb.cursor--;
                }
                else if(event.key.code == sf::Keyboard::Right){
                    amb.cursor++;
                }
            }
        }

        auto pos = sf::Vector2f(30, 50);
        janela.clear();
        janela.draw(sfText(pos, amb.toString(), sf::Color::White, 30));
        janela.display();
    }
    return 0;
}




