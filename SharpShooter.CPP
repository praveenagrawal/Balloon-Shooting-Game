#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<fstream.h>
#include<string.h>
void intro();
void fp();
void new_game();
void outlook();
void countdown();
void name();
void highscore();
void time();
void point();
void post_comment();
void view_comment();
int index=0,arn=1,*ar,points=0,p1=10,i,speed=30,cursor=2,cursorx,cursory,colorl=14,colorr=14,num=0;
int time_min=0,time_msec=0,time_sec=0,sec=0;
int buck[]={3,3,3,3,3,3};
char move,case_val,namech='\0';
char ch[80];
void post_comment()
{
  fstream ob("comment.txt",ios::in|ios::out|ios::ate);
  settextstyle(4,0,7);
  setcolor(RED);
  clearviewport();
  setbkcolor(WHITE);
  outtextxy(30,30,"Enter your comments");
  settextstyle(3,0,3);
  outtextxy(20,100,"Please do write your name and class at the end.");
  outtextxy(10,getmaxy()-50,"NOTE - PRESS ENTER ONLY AT THE END.");
  char ch[80];
  cout<<"\n\n\n\n\n\n\n\n\n";
  gets(ch);
  ob.write((char*)&ch,sizeof(ch));
  ob.close();
}
void view_comment()
{
  fstream ob("comment.txt",ios::in|ios::out|ios::ate);
  char ch[80];
  clrscr();
  ob.seekg(0);
  ob.read((char*)&ch,sizeof(ch));
  int i=1;
  while(!ob.eof())
  {
   cout<<i<<"......\n";
   i++;
   puts(ch);
   getch();
   cout<<endl;
   ob.read((char*)&ch,sizeof(ch));
  }
  ob.close();
  getch();
}
void outlook()
{
  clearviewport();
  setcolor(WHITE);
  settextstyle(4,0,7);
  setfillstyle(INTERLEAVE_FILL,6);
  floodfill(200,350,6);
  outtextxy(100,150,"Sharp Shooter");
  line(100,230,500,230);
  line(100,235,500,235);
  rectangle(30,10,590,450);
  rectangle(33,13,587,447);
  rectangle(36,16,584,444);
  getch();
}
void fp()
{
  cursorx=25;
  cursory=170;
  while(cursor==2)
  {
    cleardevice();
    setbkcolor(YELLOW);
    setcolor(GREEN);
    settextstyle(4,0,4);
    outtextxy(180,20,"Are You A");
    setcolor(RED);
    settextstyle(4,0,6);
    outtextxy(150,50,"Sharp Shooter");
    setcolor(8);
    settextstyle(0,0,0);
    outtextxy(50,180,"*");
    outtextxy(50,210,"*");
    outtextxy(50,240,"*");
    outtextxy(50,270,"*");
    outtextxy(50,300,"*");
    setcolor(1);
    settextstyle(3,0,3);
    outtextxy(50,170,"  NEW GAME");
    outtextxy(50,200,"  INSTRUCTIONS");
    outtextxy(50,230,"  POST COMMENTS");
    outtextxy(50,260,"  VIEW COMMENTS");
    outtextxy(50,290,"  EXIT");
    setcolor(8);
    settextstyle(4,0,1);
    outtextxy(cursorx,cursory,"->");
    move=getch();
    if(move==72)
    {
      if(cursory!=170)
      cursory-=30;
      else
      cursory=290;
    }
    if(move==80)
    {
      if(cursory!=290)
	cursory+=30;
      else
	cursory=170;
    }
    if(move==13)
      break;
  }
}
void intro()
{
  int intrlp=1;
  int intro_end=1;
  while(intro_end==1)
  {
  switch(intrlp)
  {
  case 1:
  {
  cleardevice();
  setbkcolor(BLACK);
  setcolor(RED);
  settextstyle(4,0,7);
  outtextxy(100,20,"INSTRUCTIONS");
  setcolor(WHITE);
  settextstyle(3,0,3);
  setbkcolor(BLACK);
  outtextxy(45,130,"* THIS IS A SIMPLE GAME IN WHICH YOU ARE ");
  outtextxy(45,170,"  GOING TO FIND A GROUP OF BALOONS.  YOU");
  outtextxy(45,210,"  ARE PROVIDED WITH A BOW AND A NUMBER");
  outtextxy(45,250,"  OF ARROWS.YOU HAVE TO MAKE USE OF YOUR");
  outtextxy(45,290,"  EFFICIENCY AND ACCURACY TO SHOOT THE");
  outtextxy(45,330,"  BALLOONS USING MINIMUM NUMBER OF ARROWS.");
  settextstyle(1,0,5);
  setcolor(GREEN);
  outtextxy(100,400,"PRESS RIGHT KEY");
  }break;
  case 2:
  {
  cleardevice();
  setbkcolor(BLACK);
  setcolor(RED);
  settextstyle(4,0,7);
  outtextxy(100,20,"INSTRUCTIONS");
  setcolor(WHITE);
  settextstyle(3,0,3);
  setbkcolor(BLACK);
  outtextxy(45,130,"* THE BALLOONS WOULD CONTINUOUSLY MOVE UP.");
  outtextxy(45,170,"  YOU HAVE TO PRESS THE ENTER KEY ONCE TO");
  outtextxy(45,210,"  SHOOT THE ARROW. DO NOT PRESS THE ENTER ");
  outtextxy(45,250,"  MORE THAN ONCE. AS THE ARROW STRIKES");
  outtextxy(45,290,"  ANY BALLOON IT WOULD BURST.");
  settextstyle(1,0,5);
  setcolor(GREEN);
  outtextxy(40,400,"PRESS LEFT OR RIGHT KEY");
  }break;
  case 3:
  {
  cleardevice();
  setbkcolor(BLACK);
  setcolor(RED);
  settextstyle(4,0,7);
  outtextxy(100,20,"INSTRUCTIONS");
  setcolor(WHITE);
  settextstyle(3,0,3);
  outtextxy(45,130," I HOPE THAT THE INSTRUCTIONS ARE CLEAR");
  outtextxy(45,170," TO THE PLAYER. TO MOVE BACK TO THE MAIN");
  outtextxy(45,210," SCREEN PRESS THE 'Esc' KEY. TO REVIEW");
  outtextxy(45,250," THE INSTRUCTIONS PRESS THE LEFT CURSOR");
  outtextxy(45,290," CONTROL KEY.");
  settextstyle(1,0,5);
  setcolor(GREEN);
  outtextxy(40,400,"PRESS LEFT KEY OR Esc KEY");
  }
  }
  case_val=getch();
  if(case_val==75)
  {
    if(intrlp!=1)
     intrlp--;
    colorl=15;
  }
  if(case_val==77)
  {
   if(intrlp!=3)
    intrlp++;
   colorr=15;
  }
  if(case_val==27)
    intro_end=0;
  }
}
void name()
{
  int i=0;
  clearviewport();
  setbkcolor(LIGHTBLUE);
  settextstyle(4,0,5);
  setcolor(WHITE);
  outtextxy(100,100,"Enter your name");

  while(ch[i]!=13)
  {
    ch[i]=getch();
    ch[i+1]='\0';
    if((ch[i]!=8)&&(ch[i]!=13))
    {
     clearviewport();
     setbkcolor(LIGHTBLUE);
     settextstyle(4,0,5);
     setcolor(WHITE);
     outtextxy(100,100,"Enter your name");
     outtextxy(100,150,ch);
     i++;
    }
    if(ch[i]==8)
    {
     clearviewport();
     setbkcolor(LIGHTBLUE);
     settextstyle(4,0,5);
     setcolor(WHITE);
     outtextxy(100,100,"Enter your name");
     ch[i-1]=' ';
     outtextxy(100,150,ch);
     i--;
    }
    if(ch[i]==13)
     break;

  }
}
void new_game()
{
  clearviewport();
  setbkcolor(LIGHTBLUE);
  setcolor(WHITE);
  settextstyle(1,0,8);
  outtextxy(40,50,"WELCOME..");
  outtextxy(40,150,"Lets Begin...");
  setcolor(RED);
  settextstyle(1,0,3);
  outtextxy(100,300,"PROCESSING...");
  setcolor(BROWN);
  rectangle(100,330,400,350);
  setcolor(RED);
  for(i=102;i<=398;i+=2)
  {
    line(i,332,i,348);
    delay(speed);
    if(i==250)
    speed-=10;
  }
}
void countdown()
{
  clearviewport();
  setfillstyle(10,RED);
  floodfill(1,1,RED);
  settextstyle(10,0,75);
  setcolor(WHITE);
  outtextxy(250,75,"3");
  delay(1000);
  clearviewport();
  setfillstyle(10,RED);
  floodfill(1,1,RED);
  settextstyle(10,0,75);
  setcolor(WHITE);
  outtextxy(250,75,"2");
  delay(1000);
  clearviewport();
  setfillstyle(10,RED);
  floodfill(1,1,RED);
  settextstyle(10,0,75);
  setcolor(WHITE);
  outtextxy(250,75,"1");
  delay(1000);
  clearviewport();
  setfillstyle(10,RED);
  floodfill(1,1,RED);
  settextstyle(10,0,80);
  setcolor(WHITE);
  outtextxy(100,75,"Go...");
  delay(500);
}
void end()
{
  clearviewport();
  setbkcolor(GREEN);
  setcolor(RED);
  settextstyle(4,0,7);
  outtextxy(150,10,"Thank You");
  line(130,100,450,100);
  line(130,103,450,103);
  settextstyle(1,0,5);
  outtextxy(50,150,"By Praveen Agrawal, XII 'B'");
  setcolor(WHITE);
  settextstyle(1,0,4);
  outtextxy(100,250,"PLAYER NAME: ");
  outtextxy(350,250,ch);
  char *num_arrows;
  int temp;i=0;
  num++;
  while(num!=0)
  {
    temp=num%10;
    num_arrows[i]=temp+48;
    num/=10;
    i++;
  }
  outtextxy(100,300,"NO. OF ARROWS USED :");
  outtextxy(500,300,num_arrows);

  getch();

}


void main()
{
  int driver = DETECT,mode;
  initgraph(&driver,&mode,"c:\\tc\\bgi");
  int mno=0,h1=46,k1=getmaxy()-35,r2=13,up=0,r1=10,b1=5,bx1=30,bx2=60;
  int by1=300,by2=getmaxy()-20,lx=80,ly=80,exr=20,eyr=50,e_x=80,e_y=80;
  int loop,qwe=0,x1,l1,l2,X,H,shoot=0,y=80,h=350,k=450,i,j,r=20,lmn=1;
  int burst[]={9,9,9,9,9,9};
  float c,x=80,cx=80,cy=80,cx1=80;
  unsigned long dist1;
  clrscr();
  outlook();
  label:
  fp();
  if(cursory==230)
  {
    post_comment();
    goto label;
  }
  if(cursory==260)
  {
    view_comment();
    goto label;
  }
  if(cursory==170)
  {
    name();
    new_game();
    countdown();
  }
  if(cursory==200)
  {
    intro();
    goto label;
  }

  if(cursory==290)
   lmn=2;
while(lmn==1)
{
cleardevice();
settextstyle(0,0,0);
h=350;
setcolor(BROWN);
if((shoot==0)||(x!=80))
{
line(x,y,x+80,y);
line(x,y+1,x+80,y+1);
outtextxy(x-5,y-3,">");
outtextxy(x-2,y-3,">");
outtextxy(x+75,y-3,">");
}
for(i=0;i<=2;i++)
ellipse(e_x+i,e_y,270,90,exr,eyr);

X=x+80;
shoot=kbhit();
if((shoot==0)||((shoot!=0)&&(x!=80)))
 line(lx,lx-50,ly,ly+50);
else if((shoot!=0) && (x==80))
  {
      line(cx,cy,cx+80,cy);
      line(cx,cy+1,cx+80,cy+1);
      outtextxy(cx-5,cy-3,">");
      outtextxy(cx-2,cy-3,">");
      outtextxy(cx+75,cy-3,">");
      line(cx1,cy-50,cx,cy);
      line(cx1,cy+50,cx,cy);
      if(cx>=60)
      cx-=1;
  }
line(bx1,by1,bx1,by2);
line(bx1+2,by1,bx1+2,by2);
line(bx2,by1,bx2,by2);
line(bx2+2,by1,bx2+2,by2+2);
line(bx1,by2+2,bx2+2,by2+2);
line(bx1+2,by2,bx2,by2);

if(shoot!=0)
{
 if((x<=700)&&(cx<=62))
 x+=4;
}
if(x>=600)
{
 getch();
 shoot=0;
x=80;
num++;
cx=80;
arn++;
}

for(i=1;i<=6;i++)
{

  if(burst[i-1]==9)
  {
  setcolor(DARKGRAY);
  circle(h,k,r);
  setfillstyle(1,WHITE);
  fillellipse(h,k,r,r);
  floodfill(h,k,WHITE);
  h+=2*r+2;

  }
  else
  {
    h+=2*r+2;
  }
}
h1=46;
k1=getmaxy()-35;
for(i=1;i<=6;i++)
{
  if(buck[i-1]==8)
  {
  setcolor(DARKGRAY);
  circle(h1,k1,r2);
  setfillstyle(1,WHITE);
  fillellipse(h1,k1,r2,r2);
  floodfill(h1,k1,WHITE);
  k1-=2*r2+2;
  }
}
h=350;
delay(20);
k-=2;
if(k<=15)
k=450;
X=x+80;
for(i=0;i<=5;i++)
{
  H=350+(i*42);
  if(X<=H)
  {
    if((H-X)<=40)
    {
      dist1=((H-X)*(H-X))+((k-y)*(k-y));
      if((dist1<=450)&&(dist1>=280))
      {
	if(burst[i]==9)
	{
	  buck[mno]=8;
	  mno++;
	}
	ar[index]=arn;
	index++;
	burst[i]=4;
      }
    }
  }
}
qwe=0;
for(i=0;i<=5;i++)
{
 if(burst[i]==4)
  qwe++;
}
if(qwe==6)
{
  lmn=6;
  delay(500);
  end();
  getch();
  goto label;
}



}

getch();
}





