

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define up 72
#define down 80
#define left 75
#define right 77
#define esc 27
#define enter 13

int ballpos=100;

void arrow(int x,int y)
{
int poly[8];
poly[0]=x+30;
poly[1]=y;
poly[2]=x+25;
poly[3]=y-5;
poly[4]=x+25;
poly[5]=y+5;
poly[6]=poly[0];
poly[7]=poly[1];
setfillstyle(SOLID_FILL,WHITE);
fillpoly(3,poly);
line(x,y,x+30,y);
line(x,y,x-5,y+5);
line(x,y,x-5,y-5);

}


void bow(int y)
{

line(10,30+y,10,90+y);
arc(10,60+y,-90,90,25);
}


void bowarrow(int y)
{arrow(10,60+y);
line(10,30+y,10,90+y);
arc(10,60+y,-90,90,25);

}


void obj()
{
circle(570,240,20);
}

int main(void)
{
   /* request auto detection */
   int gd=DETECT,gm;
   int x,y,ch,i;
   initgraph(&gd,&gm,"..//bgi");
    y=240;
    obj() ;
   while(1)
   {

   bowarrow(y);
   obj();
   ch= getch();
   switch(ch)
   {
   case up: y--;
   cleardevice();
   bow(y);
   obj();
   break;
   case down:y++;
   cleardevice();
   bow(y);
   obj();
   break;
   case enter:  bow(y);
   y=y+60;
   for(i=0;i<520;i++)
  {bow(y-60);
  arrow(i,y);
  obj();
  delay(10);
   cleardevice();
   }
   if(y>220&&y<260)
   {
   settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
   outtextxy(200,300,"HIT!  :) ");
   }
   else
   {
   settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
   outtextxy(200,300,"MISS!  :( ");
   }
   delay(2000);
   exit(0);
   break;
   case esc:exit(0);
   }
   }


   getch();
   closegraph();
   return 0;
}