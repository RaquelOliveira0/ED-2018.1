#include <lib/pen.h>

void arvore(Pen  &p, int lado){
    if(lado< 10)
    return;
    p.setColor(rand() % 255, rand() % 255, rand() % 255);
    p.walk(lado);
    p.right(20);
    arvore(p, lado- 12);
    p.left(40);
    arvore(p, lado -12);
    p.right(20);
    arvore(p, lado -12);
    p.walk(-lado);

  }

void gelo(Pen  &p, int lado){
    float ang =72;
    if(lado< 2)
        return;
     p.setColor(Color::White);
     for(int i=0;i<5;i++){
         p.walk(lado);
         gelo(p,lado*0.34);
         p.walk(-lado);
         p.right(ang);
     }
     }

void filtro_sonhos(Pen& p, int lado){
    float ang = 400;
    if(lado < 10)
        return;
    p.setColor(Color::Green);
     p.walk(lado);
     p.circle(90);
     p.walk(lado);
     p.rotate(90);
      p.circle(90);
     p.walk(lado);
     p.right(ang);
      filtro_sonhos(p,lado);


}
void trigo(Pen& p,int lado){
    if(lado<=0)
        return;
    float ang=45;
    float dec=3;
    for(int i=0;i<4;i++){
        p.walk(lado);
        p.right(ang);
        trigo(p,lado/dec);
        p.left(ang*2);
        trigo(p,lado/dec);
        p.right(ang);
    }

    p.walk(-lado*4);



}

void fractal(){
    Pen p(800, 600);
    p.setThickness(1);
    p.setXY(300, 500);
    p.setHeading(90);
    p.setSpeed(70);
   // trigo(p,100);
   arvore(p, 100);
   // gelo(p,100);
   // filtro_sonhos(p,100);
    p.wait();
}

int main(){
    fractal();
    return 0;
}

