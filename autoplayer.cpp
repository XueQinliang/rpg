#include "autoplayer.h"
#include "maps.h"
#include <iostream>
/*autoplayer::autoplayer(){
    blood=fullblood;
    this->eatable=false;
    this->coverable=false;
}
autoplayer::autoplayer(int x,int y,int state,int action):x(x),y(y),state(state),action(action){
    this->eatable=false;
    this->coverable=false;
    blood=fullblood;

}
void autoplayer::set(int x,int y,int state,int action){
    this->x=x;
    this->y=y;
    this->state=state;
    this->action=action;
    blood=fullblood;

}*/
void autoplayer::move(int i, maps &m,int v){
        action++;
        if(action>=16){
            action=1;
        }
        if(cover(i,m)){
        if(wound==0){
        if(i==1) {y-=v;
            state=4;}
        else if(i==2) {y+=v;
            state=1;}
        else if(i==3) {x-=v;
            state=2;}
        else if(i==4) {x+=v;
            state=3;}
        else {}}}
};
void autoplayer::show(QPainter &paint,maps &m){
        string route="C://Users//XQLRUC//Desktop//rpg_game//";
        route=route+name;
        route=route+".png";
        const char *p=route.data();
        all.load(p);
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                play[i][j]=all.copy(QRect(i*qsize,j*2*qsize,qsize,qsize*2));
            }
        }
        if(wound==0){
            if(fight()==true) action = 7;
            paint.drawImage(x, y, play[action/4][state-1]);
        }
        else {
            QImage part;
            string r="C:\\Users\\XQLRUC\\Desktop\\rpg_game\\dun.png";
            const char *p=r.data();
            part.load(p);
            if(blood>0){
                paint.drawImage(x, y, play[action/4][state-1]);
                paint.drawImage(x,y,part);
                srand((unsigned)time(NULL));
                int i=rand()%4+1;
            if(cover(i,m)){
                if(i==1)set(x,y+wound/10);
                if(i==2)set(x-wound/10,y);
                if(i==3)set(x+wound/10,y);
                if(i==4)set(x,y-wound/10);
            }//else set(x+wound/10,y);
            if(wound>0)wound+=2;
            if(wound<0)wound-=2;
            if(abs(wound)==29){
            wound=0;
            }}else{
                if(abs(wound)<=29)
                paint.drawImage(x,y,part);
                else
                paint.drawImage(x,y+qsize,part);
                srand((unsigned)time(NULL));
                int i=rand()%4+1;
                if(cover(i,m)){
                    if(i==1)set(x,y+wound/10);
                    if(i==2)set(x-wound/10,y);
                    if(i==3)set(x+wound/10,y);
                    if(i==4)set(x,y-wound/10);
                }//else set(x+wound/10,y);
                if(abs(wound)<=50){
                    if(wound>0)wound+=2;
                    if(wound<0)wound-=2;
                }
        }}
        if(blood>0){
            paint.setPen(QPen(Qt::black,1));
            paint.drawRect(x,y-6,fullpower,6);
            paint.setBrush(Qt::red);
            paint.drawRect(x,y-6,blood,6);
            paint.setBrush(Qt::NoBrush);
            for(int i=0;i<4;i++){
                fe[i].show(paint);
            if(fe[i].used==true){
                kuwu f;
                fe[i]=f;
            }}
            //bo.show(paint);
        }
    }
void autoplayer::attack(){
    for(int i=0;i<4;i++){
    if(fe[i].get_s()==0){
    kuwu f(x,y,i+1);
    fe[i]=f;
    fe[i].dire(i+1);
    fe[i].setv(5);
    fe[i].start();
    }
}
}
bool autoplayer::check(feibiao f){
    if(f.getx()+12>=this->getx()&&f.getx()+12<=this->getx()+qsize
            &&f.gety()+12>=this->gety()&&f.gety()+12<=this->gety()+qsize&&wound==0){
        while(wound==0){
            wound=rand()%3-1;
        }
        blood-=3;
        return true;
    }else return false;
}
bool autoplayer::check(bigskill b){
    if(b.getx()+12>=this->getx()&&b.getx()+12<=this->getx()+qsize
            &&b.gety()+12>=this->gety()&&b.gety()+12<=this->gety()+qsize&&wound==0){
        while(wound==0){
            wound=rand()%3-1;
        }
        blood-=15;
        return true;
    }else return false;
}
void autoplayer::bigattack(){
    static int num=0;
    num++;
    shenbiao shen(getx(),gety());
    shen.start();
    shen.used=true;
    this->shens.push_back(shen);
    std::cout<<num<<endl;
}
