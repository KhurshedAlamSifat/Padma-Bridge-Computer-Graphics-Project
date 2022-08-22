#include <Windows.h>
#include <GL/glut.h>
#include<math.h>
#include<stdio.h>
using namespace std;

int planStatus = 1;
float planX = 0;
float planY = 0;
float planSpeed = 1.4;

int trainStatus = 1;
float trainX = 0;
float trainY = 0;
float trainSpeed = 0.8;

int busStatus1 = 1;
float busX = 0;
float busY = 0;
float busSpeed1 = 1.7;

int trackStatus1 = 1;
float trackX = 0;
float trackY = 0;
float trackSpeed1 = 1.5;

int carStatus1 = 1;
float car1X = 0;
float car1Y = 0;
float carSpeed1 = 2;

int carStatus2 = 1;
float car2X = 0;
float car2Y = 0;
float carSpeed2 = 2.2;

int cloud1Status = 1;
float cloud1X = 0;
float cloud1Y = 0;
float cloud1Speed = 0.071;

int cloud2Status = 1;
float cloud2X = 0;
float cloud2Y = 0;
float cloud2Speed = 0.075;

int cloud3Status = 1;
float cloud3X = 0;
float cloud3Y = 0;
float cloud3Speed = 0.073;

int ship1Status = 1;
float ship1X = 0;
float ship1Y = 0;
float ship1Speed =2.7;

int ship2Status = 1;
float ship2X = 0;
float ship2Y = 0;
float ship2Speed = 1;

int noukaStatus = 1;
float noukaX = 0;
float noukaY = 0;
float noukaSpeed =0.6;

int noukaStatus2 = 1;
float nouka2X = 0;
float nouka2Y = 0;
float noukaSpeed2 =0.5;

void DrawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++)
        {
            float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle
            float x = r * cosf(theta);//calculate the x component
            float y = 1.3*r * sinf(theta);//calculate the y component
            glVertex2f(x + cx, y + cy);//output vertex
        }
        glEnd();
}

void sky()
{
    glBegin(GL_QUADS);
    glColor3ub(176,224,230);
    glVertex2f(0,500 );
    glVertex2f(700,500);
    glVertex2f(700,250);
    glVertex2f(0,250);
    glEnd();
}

void sun()
{
    glColor3ub(249,215,28);
    DrawCircle(80,440, 20, 100);
}

void cloud1()
{
    glColor3ub(255,255,255);
    DrawCircle(100,440-10, 15, 10000);

    glColor3ub(255,255,255);
    DrawCircle(115,450-10, 15, 10000);

    glColor3ub(255,255,255);
    DrawCircle(120,440-10, 15, 10000);

    glColor3ub(255,255,255);
    DrawCircle(133,465-10, 18, 10000);

    glColor3ub(255,255,255);
    DrawCircle(140,447-10, 15, 10000);

    glColor3ub(255,255,255);
    DrawCircle(153,455-10, 15, 10000);
}

void updatecloud1()
	{
		if (cloud1Status == 1)
		{
			cloud1X +=cloud1Speed;
		}
        if (cloud1X>600)
		{
			cloud1X =-150 ;
		}
		glPushMatrix();
		glTranslatef(cloud1X, cloud1Y, 0);
		cloud1();
		glPopMatrix();
	}

void cloud2()
{
    glColor3ub(255,255,255);
    DrawCircle(100+200,440+10, 15, 10000);

    glColor3ub(255,255,255);
    DrawCircle(115+200,450+10, 15, 10000);

    glColor3ub(255,255,255);
    DrawCircle(120+200,440+10, 15, 10000);

    glColor3ub(255,255,255);
    DrawCircle(133+200,465+10, 18, 10000);

    glColor3ub(255,255,255);
    DrawCircle(140+200,447+10, 15, 10000);

    glColor3ub(255,255,255);
    DrawCircle(153+200,455+10, 15, 10000);
}

void updatecloud2()
	{
		if (cloud2Status == 1)
		{
			cloud2X +=cloud2Speed;
		}
        if (cloud2X>400)
		{
			cloud2X =-340 ;
		}
		glPushMatrix();
		glTranslatef(cloud2X, cloud2Y, 0);
		cloud2();
		glPopMatrix();
	}

void cloud3()
{
    glColor3ub(255,255,255);
    DrawCircle(100+410,440, 15, 10000);

    glColor3ub(255,255,255);
    DrawCircle(115+410,450, 15, 10000);

    glColor3ub(255,255,255);
    DrawCircle(120+410,440, 15, 10000);

    glColor3ub(255,255,255);
    DrawCircle(133+410,465, 18, 10000);

    glColor3ub(255,255,255);
    DrawCircle(140+410,447, 15, 10000);

    glColor3ub(255,255,255);
    DrawCircle(153+410,455, 15, 10000);
}

void updatecloud3()
	{
		if (cloud3Status == 1)
		{
			cloud3X +=cloud3Speed;
		}
        if (cloud3X>200)
		{
			cloud3X =-550 ;
		}
		glPushMatrix();
		glTranslatef(cloud3X, cloud3Y, 0);
		cloud3();
		glPopMatrix();
	}

void plan()
{
    glBegin(GL_QUADS); //plane
    glColor3ub(234,234,234);
    glVertex2f(100,455 ); // x, y
    glVertex2f(140,455);
    glVertex2f(140,470); // x, y
    glVertex2f(100,470);
    glEnd();

    glBegin(GL_QUADS); //body
    glColor3ub(234,234,234);
    glVertex2f(50,460 ); // x, y
    glVertex2f(100,455);
    glVertex2f(100,470); // x, y
    glVertex2f(50,470);
    glEnd();

    glBegin(GL_POLYGON);//outline of upper triangle plane
    glColor3ub(234,234,234);
    glVertex2f(140.0,470.0);
    glVertex2f(155.0,465.0);
    glVertex2f(160.0,465.0);
    glVertex2f(165.0,457.0);
    glVertex2f(140.0,455.0);
    glEnd();

    glBegin(GL_POLYGON);//left side wing
    glColor3ub(112,146,190);
    glVertex2f(99.0,470.0);
    glVertex2f(84.0,480.0);
    glVertex2f(105.0,480.0);
    glVertex2f(120.0,470.0);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINE_LOOP);
    glColor3ub(110 ,110, 110);
    glVertex2f(70,462 ); // x, y
    glVertex2f(75,462);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINE_LOOP);
    glColor3ub(110 ,110, 110);
    glVertex2f(77,462 ); // x, y
    glVertex2f(82,462);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINE_LOOP);
    glColor3ub(110 ,110, 110);
    glVertex2f(84,462 ); // x, y
    glVertex2f(89,462);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINE_LOOP);
    glColor3ub(110 ,110, 110);
    glVertex2f(91,462 ); // x, y
    glVertex2f(96,462);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINE_LOOP);
    glColor3ub(110 ,110, 110);
    glVertex2f(98,462 ); // x, y
    glVertex2f(103,462);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINE_LOOP);
    glColor3ub(110 ,110, 110);
    glVertex2f(105,462 ); // x, y
    glVertex2f(110,462);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINE_LOOP);
    glColor3ub(110 ,110, 110);
    glVertex2f(112,462 ); // x, y
    glVertex2f(117,462);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINE_LOOP);
    glColor3ub(110 ,110, 110);
    glVertex2f(119,462 ); // x, y
    glVertex2f(124,462);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINE_LOOP);
    glColor3ub(110 ,110, 110);
    glVertex2f(126,462 ); // x, y
    glVertex2f(131,462);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINE_LOOP);
    glColor3ub(110 ,110, 110);
    glVertex2f(133,462 ); // x, y
    glVertex2f(138,462);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINE_LOOP);
    glColor3ub(110 ,110, 110);
    glVertex2f(140,462 ); // x, y
    glVertex2f(143,462);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINE_LOOP);
    glColor3ub(110 ,110, 110);
    glVertex2f(144,462 ); // x, y
    glVertex2f(150,462);
    glEnd();

    glBegin(GL_POLYGON);//rightside wing
    glColor3ub(112,146,190);
    glVertex2f(99.0,462.0);
    glVertex2f(120.0,462);
    glVertex2f(100.0,445.0);
    glVertex2f(79.0,445.0);
    glEnd();

    glBegin(GL_POLYGON);//back wing
    glColor3ub(112,146,190);
    glVertex2f(50,470.0);
    glVertex2f(50,485.0);
    glVertex2f(55.0,485.0);
    glVertex2f(70.0,470.0);
    glEnd();
}

void updateplan()
	{
		if (planStatus == 1)
		{
			planX +=planSpeed;
		}
        if (planX>700)
		{
			planX =-150 ;
		}
		glPushMatrix();
		glTranslatef(planX, planY, 0);
		plan();
		glPopMatrix();
	}

void rightlamp()
{
    glBegin(GL_QUADS);
    glColor3ub(100,100,100);

    //right
    glVertex2f(360-60-60-60-60-60-60,325 );// lamp stand
    glVertex2f(362-60-60-60-60-60-60,325);
    glVertex2f(362-60-60-60-60-60-60,365);
    glVertex2f(360-60-60-60-60-60-60,365);

    glVertex2f(356-60-60-60-60-60-60,362 );// lamp ligth
    glVertex2f(360-60-60-60-60-60-60,360);
    glVertex2f(360-60-60-60-60-60-60,363);
    glVertex2f(356-60-60-60-60-60-60,365);

    glVertex2f(360-60-60-60-60-60,325 );// lamp stand
    glVertex2f(362-60-60-60-60-60,325);
    glVertex2f(362-60-60-60-60-60,365);
    glVertex2f(360-60-60-60-60-60,365);

    glVertex2f(356-60-60-60-60-60,362 );// lamp ligth
    glVertex2f(360-60-60-60-60-60,360);
    glVertex2f(360-60-60-60-60-60,363);
    glVertex2f(356-60-60-60-60-60,365);

    glVertex2f(360-60-60-60-60,325 );// lamp stand
    glVertex2f(362-60-60-60-60,325);
    glVertex2f(362-60-60-60-60,365);
    glVertex2f(360-60-60-60-60,365);

    glVertex2f(356-60-60-60-60,362 );// lamp ligth
    glVertex2f(360-60-60-60-60,360);
    glVertex2f(360-60-60-60-60,363);
    glVertex2f(356-60-60-60-60,365);

    glVertex2f(360-60-60-60,325 );// lamp stand
    glVertex2f(362-60-60-60,325);
    glVertex2f(362-60-60-60,365);
    glVertex2f(360-60-60-60,365);

    glVertex2f(356-60-60-60,362 );// lamp ligth
    glVertex2f(360-60-60-60,360);
    glVertex2f(360-60-60-60,363);
    glVertex2f(356-60-60-60,365);

    glVertex2f(360-60-60,325 );// lamp stand
    glVertex2f(362-60-60,325);
    glVertex2f(362-60-60,365);
    glVertex2f(360-60-60,365);

    glVertex2f(356-60-60,362 );// lamp ligth
    glVertex2f(360-60-60,360);
    glVertex2f(360-60-60,363);
    glVertex2f(356-60-60,365);

    glVertex2f(360-60,325 );// lamp stand
    glVertex2f(362-60,325);
    glVertex2f(362-60,365);
    glVertex2f(360-60,365);

    glVertex2f(356-60,362 );// lamp ligth
    glVertex2f(360-60,360);
    glVertex2f(360-60,363);
    glVertex2f(356-60,365);

    //left
    glVertex2f(360,325 );// lamp stand
    glVertex2f(362,325);
    glVertex2f(362,365);
    glVertex2f(360,365);

    glVertex2f(362,360 );// lamp ligth
    glVertex2f(366,362);
    glVertex2f(366,365);
    glVertex2f(362,363);

    glVertex2f(360+60,325 );// lamp stand
    glVertex2f(362+60,325);
    glVertex2f(362+60,365);
    glVertex2f(360+60,365);

    glVertex2f(362+60,360 );// lamp ligth
    glVertex2f(366+60,362);
    glVertex2f(366+60,365);
    glVertex2f(362+60,363);

    glVertex2f(360+60+60,325 );// lamp stand
    glVertex2f(362+60+60,325);
    glVertex2f(362+60+60,365);
    glVertex2f(360+60+60,365);

    glVertex2f(362+60+60,360 );// lamp ligth
    glVertex2f(366+60+60,362);
    glVertex2f(366+60+60,365);
    glVertex2f(362+60+60,363);

    glVertex2f(360+60+60+60,325 );// lamp stand
    glVertex2f(362+60+60+60,325);
    glVertex2f(362+60+60+60,365);
    glVertex2f(360+60+60+60,365);

    glVertex2f(362+60+60+60,360 );// lamp ligth
    glVertex2f(366+60+60+60,362);
    glVertex2f(366+60+60+60,365);
    glVertex2f(362+60+60+60,363);

    glVertex2f(360+60+60+60+60,325 );// lamp stand
    glVertex2f(362+60+60+60+60,325);
    glVertex2f(362+60+60+60+60,365);
    glVertex2f(360+60+60+60+60,365);

    glVertex2f(362+60+60+60+60,360 );// lamp ligth
    glVertex2f(366+60+60+60+60,362);
    glVertex2f(366+60+60+60+60,365);
    glVertex2f(362+60+60+60+60,363);

    glVertex2f(360+60+60+60+60+60,325 );// lamp stand
    glVertex2f(362+60+60+60+60+60,325);
    glVertex2f(362+60+60+60+60+60,365);
    glVertex2f(360+60+60+60+60+60,365);

    glVertex2f(362+60+60+60+60+60,360 );// lamp ligth
    glVertex2f(366+60+60+60+60+60,362);
    glVertex2f(366+60+60+60+60+60,365);
    glVertex2f(362+60+60+60+60+60,363);


    glEnd();
}

void leftlamp()
{
    glBegin(GL_QUADS);
    glColor3ub(100,100,100);

    //right
    glVertex2f(390-60-60-60-60-60-60,325 );// lamp stand
    glVertex2f(392-60-60-60-60-60-60,325);
    glVertex2f(392-60-60-60-60-60-60,360);
    glVertex2f(390-60-60-60-60-60-60,360);

    glVertex2f(386-60-60-60-60-60-60,357 );// lamp ligth
    glVertex2f(390-60-60-60-60-60-60,355);
    glVertex2f(390-60-60-60-60-60-60,358);
    glVertex2f(386-60-60-60-60-60-60,360);

    glVertex2f(390-60-60-60-60-60,325 );// lamp stand
    glVertex2f(392-60-60-60-60-60,325);
    glVertex2f(392-60-60-60-60-60,360);
    glVertex2f(390-60-60-60-60-60,360);

    glVertex2f(386-60-60-60-60-60,357 );// lamp ligth
    glVertex2f(390-60-60-60-60-60,355);
    glVertex2f(390-60-60-60-60-60,358);
    glVertex2f(386-60-60-60-60-60,360);

    glVertex2f(390-60-60-60-60,325 );// lamp stand
    glVertex2f(392-60-60-60-60,325);
    glVertex2f(392-60-60-60-60,360);
    glVertex2f(390-60-60-60-60,360);

    glVertex2f(386-60-60-60-60,357 );// lamp ligth
    glVertex2f(390-60-60-60-60,355);
    glVertex2f(390-60-60-60-60,358);
    glVertex2f(386-60-60-60-60,360);

    glVertex2f(390-60-60-60,325 );// lamp stand
    glVertex2f(392-60-60-60,325);
    glVertex2f(392-60-60-60,360);
    glVertex2f(390-60-60-60,360);

    glVertex2f(386-60-60-60,357 );// lamp ligth
    glVertex2f(390-60-60-60,355);
    glVertex2f(390-60-60-60,358);
    glVertex2f(386-60-60-60,360);

    glVertex2f(390-60-60,325 );// lamp stand
    glVertex2f(392-60-60,325);
    glVertex2f(392-60-60,360);
    glVertex2f(390-60-60,360);

    glVertex2f(386-60-60,357 );// lamp ligth
    glVertex2f(390-60-60,355);
    glVertex2f(390-60-60,358);
    glVertex2f(386-60-60,360);

    glVertex2f(390-60,325 );// lamp stand
    glVertex2f(392-60,325);
    glVertex2f(392-60,360);
    glVertex2f(390-60,360);

    glVertex2f(386-60,357 );// lamp ligth
    glVertex2f(390-60,355);
    glVertex2f(390-60,358);
    glVertex2f(386-60,360);

    //left
    glVertex2f(390,325 );// lamp stand
    glVertex2f(392,325);
    glVertex2f(392,360);
    glVertex2f(390,360);

    glVertex2f(392,355 );// lamp ligth
    glVertex2f(396,357);
    glVertex2f(396,360);
    glVertex2f(392,358);


    glVertex2f(390+60,325 );// lamp stand
    glVertex2f(392+60,325);
    glVertex2f(392+60,360);
    glVertex2f(390+60,360);

    glVertex2f(392+60,355 );// lamp ligth
    glVertex2f(396+60,357);
    glVertex2f(396+60,360);
    glVertex2f(392+60,358);

    glVertex2f(390+60+60,325 );// lamp stand
    glVertex2f(392+60+60,325);
    glVertex2f(392+60+60,360);
    glVertex2f(390+60+60,360);

    glVertex2f(392+60+60,355 );// lamp ligth
    glVertex2f(396+60+60,357);
    glVertex2f(396+60+60,360);
    glVertex2f(392+60+60,358);

    glVertex2f(390+60+60+60,325 );// lamp stand
    glVertex2f(392+60+60+60,325);
    glVertex2f(392+60+60+60,360);
    glVertex2f(390+60+60+60,360);

    glVertex2f(392+60+60+60,355 );// lamp ligth
    glVertex2f(396+60+60+60,357);
    glVertex2f(396+60+60+60,360);
    glVertex2f(392+60+60+60,358);

     glVertex2f(390+60+60+60+60,325 );// lamp stand
    glVertex2f(392+60+60+60+60,325);
    glVertex2f(392+60+60+60+60,360);
    glVertex2f(390+60+60+60+60,360);

    glVertex2f(392+60+60+60+60,355 );// lamp ligth
    glVertex2f(396+60+60+60+60,357);
    glVertex2f(396+60+60+60+60,360);
    glVertex2f(392+60+60+60+60,358);

    glVertex2f(390+60+60+60+60+60,325 );// lamp stand
    glVertex2f(392+60+60+60+60+60,325);
    glVertex2f(392+60+60+60+60+60,360);
    glVertex2f(390+60+60+60+60+60,360);

    glVertex2f(392+60+60+60+60+60,355 );// lamp ligth
    glVertex2f(396+60+60+60+60+60,357);
    glVertex2f(396+60+60+60+60+60,360);
    glVertex2f(392+60+60+60+60+60,358);

    glEnd();
}

void bridge()
{

    glBegin(GL_QUADS);

    glColor3ub(162,148,145);

    glVertex2f(332-100,182 );// 1st pillar up
    glVertex2f(353-100,182);
    glVertex2f(353-100,245);
    glVertex2f(332-100,245);

    glVertex2f(315-100,165 );// 1st pillar down
    glVertex2f(370-100,165);
    glVertex2f(367-100,182);
    glVertex2f(318-100,182);

    glVertex2f(332+100,182 );// 2nd pillar up
    glVertex2f(353+100,182);
    glVertex2f(353+100,245);
    glVertex2f(332+100,245);

    glVertex2f(315+100,165 );// 2nd pillar down
    glVertex2f(370+100,165);
    glVertex2f(367+100,182);
    glVertex2f(318+100,182);

    glVertex2f(332-300,182 );// 3rd pillar up
    glVertex2f(353-300,182);
    glVertex2f(353-300,245);
    glVertex2f(332-300,245);

    glVertex2f(315-300,165 );// 3rd pillar down
    glVertex2f(370-300,165);
    glVertex2f(367-300,182);
    glVertex2f(318-300,182);

    glVertex2f(332+300,182 );// 4th pillar up
    glVertex2f(353+300,182);
    glVertex2f(353+300,245);
    glVertex2f(332+300,245);

    glVertex2f(315+300,165 );// 4th pillar down
    glVertex2f(370+300,165);
    glVertex2f(367+300,182);
    glVertex2f(318+300,182);

    glColor3ub(162,148,145);
    glVertex2f(0,250+55 );// span upper part
    glVertex2f(700,250+55);
    glVertex2f(700,270+55);
    glVertex2f(0,270+55);

    glColor3ub(126,118,116);
    glVertex2f(0,245+55 );
    glVertex2f(700,245+55);
    glVertex2f(700,250+55);
    glVertex2f(0,250+55);

    glColor3ub(207,207,209);
    glVertex2f(0,245+50 );
    glVertex2f(700,245+50);
    glVertex2f(700,250+50);
    glVertex2f(0,250+50);

    glColor3ub(95,95,95);
    glVertex2f(0,250 );// rail line
    glVertex2f(700,250);
    glVertex2f(700,252);
    glVertex2f(0,252);

    glColor3ub(207,207,209);
    glVertex2f(0,240 );// span lower part
    glVertex2f(700,240);
    glVertex2f(700,250);
    glVertex2f(0,250);

    glColor3ub(207,207,209);
    glVertex2f(25,250 );// span inside design
    glVertex2f(33,250);
    glVertex2f(8,295);
    glVertex2f(0,295);
    glVertex2f(25,250 );
    glVertex2f(33,250);
    glVertex2f(58,295);
    glVertex2f(50,295);

    glVertex2f(25+50,250 );
    glVertex2f(33+50,250);
    glVertex2f(8+50,295);
    glVertex2f(0+50,295);
    glVertex2f(25+50,250 );
    glVertex2f(33+50,250);
    glVertex2f(58+50,295);
    glVertex2f(50+50,295);

    glVertex2f(25+100,250 );
    glVertex2f(33+100,250);
    glVertex2f(8+100,295);
    glVertex2f(0+100,295);
    glVertex2f(25+100,250 );
    glVertex2f(33+100,250);
    glVertex2f(58+100,295);
    glVertex2f(50+100,295);

    glVertex2f(25+150,250 );
    glVertex2f(33+150,250);
    glVertex2f(8+150,295);
    glVertex2f(0+150,295);
    glVertex2f(25+150,250 );
    glVertex2f(33+150,250);
    glVertex2f(58+150,295);
    glVertex2f(50+150,295);

    glVertex2f(25+200,250 );
    glVertex2f(33+200,250);
    glVertex2f(8+200,295);
    glVertex2f(0+200,295);
    glVertex2f(25+200,250 );
    glVertex2f(33+200,250);
    glVertex2f(58+200,295);
    glVertex2f(50+200,295);

    glVertex2f(25+250,250 );
    glVertex2f(33+250,250);
    glVertex2f(8+250,295);
    glVertex2f(0+250,295);
    glVertex2f(25+250,250 );
    glVertex2f(33+250,250);
    glVertex2f(58+250,295);
    glVertex2f(50+250,295);

    glVertex2f(25+300,250 );
    glVertex2f(33+300,250);
    glVertex2f(8+300,295);
    glVertex2f(0+300,295);
    glVertex2f(25+300,250 );
    glVertex2f(33+300,250);
    glVertex2f(58+300,295);
    glVertex2f(50+300,295);

    glVertex2f(25+350,250 );
    glVertex2f(33+350,250);
    glVertex2f(8+350,295);
    glVertex2f(0+350,295);
    glVertex2f(25+350,250 );
    glVertex2f(33+350,250);
    glVertex2f(58+350,295);
    glVertex2f(50+350,295);

    glVertex2f(25+400,250 );
    glVertex2f(33+400,250);
    glVertex2f(8+400,295);
    glVertex2f(0+400,295);
    glVertex2f(25+400,250 );
    glVertex2f(33+400,250);
    glVertex2f(58+400,295);
    glVertex2f(50+400,295);

    glVertex2f(25+450,250 );
    glVertex2f(33+450,250);
    glVertex2f(8+450,295);
    glVertex2f(0+450,295);
    glVertex2f(25+450,250 );
    glVertex2f(33+450,250);
    glVertex2f(58+450,295);
    glVertex2f(50+450,295);

    glVertex2f(25+500,250 );
    glVertex2f(33+500,250);
    glVertex2f(8+500,295);
    glVertex2f(0+500,295);
    glVertex2f(25+500,250 );
    glVertex2f(33+500,250);
    glVertex2f(58+500,295);
    glVertex2f(50+500,295);

    glVertex2f(25+550,250 );
    glVertex2f(33+550,250);
    glVertex2f(8+550,295);
    glVertex2f(0+550,295);
    glVertex2f(25+550,250 );
    glVertex2f(33+550,250);
    glVertex2f(58+550,295);
    glVertex2f(50+550,295);

    glVertex2f(25+600,250 );
    glVertex2f(33+600,250);
    glVertex2f(8+600,295);
    glVertex2f(0+600,295);
    glVertex2f(25+600,250 );
    glVertex2f(33+600,250);
    glVertex2f(58+600,295);
    glVertex2f(50+600,295);

    glVertex2f(25+650,250 );
    glVertex2f(33+650,250);
    glVertex2f(8+650,295);
    glVertex2f(0+650,295);
    glVertex2f(25+650,250 );
    glVertex2f(33+650,250);
    glVertex2f(58+650,295);
    glVertex2f(50+650,295);

    glVertex2f(25+700,250 );
    glVertex2f(33+700,250);
    glVertex2f(8+700,295);
    glVertex2f(0+700,295);
    glVertex2f(25+700,250 );
    glVertex2f(33+700,250);
    glVertex2f(58+700,295);
    glVertex2f(50+700,295);

    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(60,60,60);
    glVertex2f(0,250+55 );
    glVertex2f(35,250+55);
    glVertex2f(35,270+55);
    glVertex2f(0,270+55);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(60,60,60);
    glVertex2f(0+35,250+55 );
    glVertex2f(35+35,250+55);
    glVertex2f(35+35,270+55);
    glVertex2f(0+35,270+55);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(60,60,60);
    glVertex2f(0+35+35,250+55 );
    glVertex2f(35+35+35,250+55);
    glVertex2f(35+35+35,270+55);
    glVertex2f(0+35+35,270+55);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(60,60,60);
    glVertex2f(0+35+35+35,250+55 );
    glVertex2f(35+35+35+35,250+55);
    glVertex2f(35+35+35+35,270+55);
    glVertex2f(0+35+35+35,270+55);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(60,60,60);
    glVertex2f(0+35+35+35+35,250+55 );
    glVertex2f(35+35+35+35+35,250+55);
    glVertex2f(35+35+35+35+35,270+55);
    glVertex2f(0+35+35+35+35,270+55);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(60,60,60);
    glVertex2f(0+35+35+35+35+35,250+55 );
    glVertex2f(35+35+35+35+35+35,250+55);
    glVertex2f(35+35+35+35+35+35,270+55);
    glVertex2f(0+35+35+35+35+35,270+55);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(60,60,60);
    glVertex2f(0+35+35+35+35+35+35,250+55 );
    glVertex2f(35+35+35+35+35+35+35,250+55);
    glVertex2f(35+35+35+35+35+35+35,270+55);
    glVertex2f(0+35+35+35+35+35+35,270+55);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(60,60,60);
    glVertex2f(0+35+35+35+35+35+35+35,250+55 );
    glVertex2f(35+35+35+35+35+35+35+35,250+55);
    glVertex2f(35+35+35+35+35+35+35+35,270+55);
    glVertex2f(0+35+35+35+35+35+35+35,270+55);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(60,60,60);
    glVertex2f(0+35+35+35+35+35+35+35+35,250+55 );
    glVertex2f(35+35+35+35+35+35+35+35+35,250+55);
    glVertex2f(35+35+35+35+35+35+35+35+35,270+55);
    glVertex2f(0+35+35+35+35+35+35+35+35,270+55);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(60,60,60);
    glVertex2f(0+35+35+35+35+35+35+35+70,250+55 );
    glVertex2f(35+35+35+35+35+35+35+35+70,250+55);
    glVertex2f(35+35+35+35+35+35+35+35+70,270+55);
    glVertex2f(0+35+35+35+35+35+35+35+70,270+55);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(60,60,60);
    glVertex2f(0+35+35+35+35+35+35+35+70+35,250+55 );
    glVertex2f(35+35+35+35+35+35+35+35+70+35,250+55);
    glVertex2f(35+35+35+35+35+35+35+35+70+35,270+55);
    glVertex2f(0+35+35+35+35+35+35+35+70+35,270+55);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(60,60,60);
    glVertex2f(0+35+35+35+35+35+35+35+70+70,250+55 );
    glVertex2f(35+35+35+35+35+35+35+35+70+70,250+55);
    glVertex2f(35+35+35+35+35+35+35+35+70+70,270+55);
    glVertex2f(0+35+35+35+35+35+35+35+70+70,270+55);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(60,60,60);
    glVertex2f(0+35+35+35+35+35+35+35+70+70+35,250+55 );
    glVertex2f(35+35+35+35+35+35+35+35+70+70+35,250+55);
    glVertex2f(35+35+35+35+35+35+35+35+70+70+35,270+55);
    glVertex2f(0+35+35+35+35+35+35+35+70+70+35,270+55);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(60,60,60);
    glVertex2f(0+35+35+35+35+35+35+35+70+70+70,250+55 );
    glVertex2f(35+35+35+35+35+35+35+35+70+70+70,250+55);
    glVertex2f(35+35+35+35+35+35+35+35+70+70+70,270+55);
    glVertex2f(0+35+35+35+35+35+35+35+70+70+70,270+55);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(60,60,60);
    glVertex2f(0+35+35+35+35+35+35+35+70+70+70+35,250+55 );
    glVertex2f(35+35+35+35+35+35+35+35+70+70+70+35,250+55);
    glVertex2f(35+35+35+35+35+35+35+35+70+70+70+35,270+55);
    glVertex2f(0+35+35+35+35+35+35+35+70+70+70+35,270+55);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(60,60,60);
    glVertex2f(0+35+35+35+35+35+35+35+70+70+70+70,250+55 );
    glVertex2f(35+35+35+35+35+35+35+35+70+70+70+70,250+55);
    glVertex2f(35+35+35+35+35+35+35+35+70+70+70+70,270+55);
    glVertex2f(0+35+35+35+35+35+35+35+70+70+70+70,270+55);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(60,60,60);
    glVertex2f(0+35+35+35+35+35+35+35+70+70+70+70+35,250+55 );
    glVertex2f(35+35+35+35+35+35+35+35+70+70+70+70+35,250+55);
    glVertex2f(35+35+35+35+35+35+35+35+70+70+70+70+35,270+55);
    glVertex2f(0+35+35+35+35+35+35+35+70+70+70+70+35,270+55);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(60,60,60);
    glVertex2f(0+35+35+35+35+35+35+35+70+70+70+70+70,250+55 );
    glVertex2f(35+35+35+35+35+35+35+35+70+70+70+70+70,250+55);
    glVertex2f(35+35+35+35+35+35+35+35+70+70+70+70+70,270+55);
    glVertex2f(0+35+35+35+35+35+35+35+70+70+70+70+70,270+55);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(60,60,60);
    glVertex2f(0+35+35+35+35+35+35+35+70+70+70+70+70+35,250+55 );
    glVertex2f(35+35+35+35+35+35+35+35+70+70+70+70+70+35,250+55);
    glVertex2f(35+35+35+35+35+35+35+35+70+70+70+70+70+35,270+55);
    glVertex2f(0+35+35+35+35+35+35+35+70+70+70+70+70+35,270+55);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(60,60,60);
    glVertex2f(0+35+35+35+35+35+35+35+70+70+70+70+70+70,250+55 );
    glVertex2f(35+35+35+35+35+35+35+35+70+70+70+70+70+70,250+55);
    glVertex2f(35+35+35+35+35+35+35+35+70+70+70+70+70+70,270+55);
    glVertex2f(0+35+35+35+35+35+35+35+70+70+70+70+70+70,270+55);
    glEnd();
}

void bus()
{
	    glBegin(GL_QUADS);
	    glColor3ub(153,0,0);
	    glVertex2f(455,325 );
	    glVertex2f(500,325);
	    glVertex2f(500,335);
	    glVertex2f(455,335);
	    glEnd();

	    glBegin(GL_QUADS);
	    glColor3ub(153,0,0);
	    glVertex2f(462,335 );
	    glVertex2f(500,335);
	    glVertex2f(500,347);
	    glVertex2f(462,347);
	    glEnd();

	    glBegin(GL_POLYGON);   // font glass
        glColor3ub(192,192,192);
        glVertex2f(462,347);
        glVertex2f(455,334);
        glVertex2f(462,334);
	    glEnd();

	    glLineWidth(1);
	    glBegin(GL_LINE_LOOP);
        glColor3ub(0,0,0);
        glVertex2f(462,347);
        glVertex2f(455,334);
        glVertex2f(462,334);
	    glEnd();

	    glBegin(GL_QUADS);
	    glColor3ub(200,200,200);
	    glVertex2f(464,326 );
	    glVertex2f(468,326);
	    glVertex2f(468,340);
	    glVertex2f(464,340);
	    glEnd();

	    glLineWidth(1);
	    glBegin(GL_LINE_LOOP);
        glColor3ub(0,0,0);
        glVertex2f(464,326 );
	    glVertex2f(468,326);
	    glVertex2f(468,340);
	    glVertex2f(464,340);
	    glEnd();

	    glBegin(GL_QUADS);
	    glColor3ub(200,200,200);
	    glVertex2f(470,335 );
	    glVertex2f(497,335);
	    glVertex2f(497,342);
	    glVertex2f(470,342);
	    glEnd();


        glLineWidth(1);
	    glBegin(GL_LINE_LOOP);
        glColor3ub(0,0,0);
        glVertex2f(470,335 );
	    glVertex2f(479,335);
	    glVertex2f(479,342);
	    glVertex2f(470,342);
	    glEnd();

	    glLineWidth(1);
	    glBegin(GL_LINE_LOOP);
        glColor3ub(0,0,0);
        glVertex2f(470,335 );
	    glVertex2f(479+9,335);
	    glVertex2f(479+9,342);
	    glVertex2f(470,342);
	    glEnd();

	    glLineWidth(1);
	    glBegin(GL_LINE_LOOP);
        glColor3ub(0,0,0);
        glVertex2f(470,335 );
	    glVertex2f(479+9+9,335);
	    glVertex2f(479+9+9,342);
	    glVertex2f(470,342);
	    glEnd();

}

void updatebus()
	{
		if (busStatus1 == 1)
		{
			busX -=busSpeed1;
		}
        if (busX<-620)
		{
			busX =320 ;
		}
		glPushMatrix();
		glTranslatef(busX, busY, 0);
		bus();
		glPopMatrix();
	}

void track()
{
    glBegin(GL_QUADS); // back part
    glColor3ub(139,69,19);
    glVertex2f(110,325);
    glVertex2f(140,325);
    glVertex2f(140,347);
    glVertex2f(110,347);
    glEnd();

    glBegin(GL_QUADS);  // front part
    glColor3ub(186,85,211);
    glVertex2f(102,325);
    glVertex2f(110,325);
    glVertex2f(110,344);
    glVertex2f(102,344);
    glEnd();

    glBegin(GL_QUADS);  // front part
    glColor3ub(186,85,211);
    glVertex2f(95,325);
    glVertex2f(102,325);
    glVertex2f(102,344);
    glVertex2f(95,333);
    glEnd();

    glBegin(GL_QUADS);  // front part
    glColor3ub(220,220,220);
    glVertex2f(98,333);
    glVertex2f(108,333);
    glVertex2f(108,342);
    glVertex2f(104,342);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2f(98,333);
    glVertex2f(108,333);
    glVertex2f(108,342);
    glVertex2f(104,342);
    glEnd();
}

void updatetrack()
	{
		if (trackStatus1 == 1)
		{
			trackX -=trackSpeed1;
		}
        if (trackX<-150)
		{
			trackX =700 ;
		}
		glPushMatrix();
		glTranslatef(trackX, trackY, 0);
		track();
		glPopMatrix();
	}

void car1()
{
    glBegin(GL_QUADS);
    glColor3ub(237,28,36);
    glVertex2f(200,325);
    glVertex2f(203,325 );
    glVertex2f(203,332);
    glVertex2f(200,330);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(237,28,36);
    glVertex2f(203,325);
    glVertex2f(225,325 );
    glVertex2f(225,332);
    glVertex2f(203,332);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(237,28,36);
    glVertex2f(203,332);
    glVertex2f(225,332 );
    glVertex2f(221,337);
    glVertex2f(207,337);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(237,28,36);
    glVertex2f(225,325);
    glVertex2f(228,325 );
    glVertex2f(228,330);
    glVertex2f(225,332);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230,230,230);
    glVertex2f(205,331);
    glVertex2f(213,331 );
    glVertex2f(213,335);
    glVertex2f(209,335);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2f(205,331);
    glVertex2f(213,331 );
    glVertex2f(213,335);
    glVertex2f(209,335);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230,230,230);
    glVertex2f(215,331);
    glVertex2f(223,331 );
    glVertex2f(219,335);
    glVertex2f(215,335);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2f(215,331);
    glVertex2f(223,331 );
    glVertex2f(219,335);
    glVertex2f(215,335);
    glEnd();

}

void updatecar1()
	{
		if (carStatus1 == 1)
		{
			car1X +=carSpeed1;
		}
        if (car1X>510)
		{
			car1X =-205 ;
		}
		glPushMatrix();
		glTranslatef(car1X, car1Y, 0);
		car1();
		glPopMatrix();
	}

void car2()
{
    glBegin(GL_QUADS);
    glColor3ub(105,114,216);
    glVertex2f(200+270,325);
    glVertex2f(203+270,325 );
    glVertex2f(203+270,332);
    glVertex2f(200+270,330);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,114,216);
    glVertex2f(203+270,325);
    glVertex2f(225+270,325 );
    glVertex2f(225+270,332);
    glVertex2f(203+270,332);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,114,216);
    glVertex2f(203+270,332);
    glVertex2f(225+270,332 );
    glVertex2f(221+270,337);
    glVertex2f(207+270,337);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,114,216);
    glVertex2f(225+270,325);
    glVertex2f(228+270,325 );
    glVertex2f(228+270,330);
    glVertex2f(225+270,332);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230,230,230);
    glVertex2f(205+270,331);
    glVertex2f(213+270,331 );
    glVertex2f(213+270,335);
    glVertex2f(209+270,335);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2f(205+270,331);
    glVertex2f(213+270,331 );
    glVertex2f(213+270,335);
    glVertex2f(209+270,335);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230,230,230);
    glVertex2f(215+270,331);
    glVertex2f(223+270,331 );
    glVertex2f(219+270,335);
    glVertex2f(215+270,335);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2f(215+270,331);
    glVertex2f(223+270,331 );
    glVertex2f(219+270,335);
    glVertex2f(215+270,335);
    glEnd();

}

void updatecar2()
	{
		if (carStatus2 == 1)
		{
			car2X +=carSpeed2;
		}
        if (car2X>240)
		{
			car2X =-475 ;
		}
		glPushMatrix();
		glTranslatef(car2X, car2Y, 0);
		car2();
		glPopMatrix();
	}

void train()
{
    glBegin(GL_QUADS);
    glColor3ub(100,100,100);
    glVertex2f(230-73+300,285);// train
    glVertex2f(271-73+300,285);
    glVertex2f(271-73+300,287);
    glVertex2f(230-73+300,287);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,85,105);
    glVertex2f(240-74+300,286);// train
    glVertex2f(245-74+300,286);
    glVertex2f(245-74+300,289.5);
    glVertex2f(240-74+300,289.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,85,105);
    glVertex2f(240-73+11+300,286);// train
    glVertex2f(245-73+11+300,286);
    glVertex2f(245-73+11+300,289.5);
    glVertex2f(240-73+11+300,289.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,85,105);
    glVertex2f(220-73+300,258);// train
    glVertex2f(230-73+300,258);
    glVertex2f(230-73+300,287);
    glVertex2f(220-73+300,283);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(237,28,36);
    glVertex2f(217-73+300,252);// train
    glVertex2f(230-73+300,252);
    glVertex2f(230-73+300,258);
    glVertex2f(220-73+300,258);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,85,105);
    glVertex2f(230-73+300,255);// train
    glVertex2f(271-73+300,255);
    glVertex2f(271-73+300,285);
    glVertex2f(230-73+300,285);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(214,184,156);
    glVertex2f(222-73+300,266);// train
    glVertex2f(271-73+300,266);
    glVertex2f(271-73+300,277);
    glVertex2f(222-73+300,277);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(230-73+300,252);// train down
    glVertex2f(270-73+300,252);
    glVertex2f(270-73+300,258);
    glVertex2f(230-73+300,258);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+17-73+300,265);// train WINDOW
    glVertex2f(222+22-73+300,265);
    glVertex2f(222+22-73+300,279);
    glVertex2f(212+17-73+300,279);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(262-73+300,260);// train door
    glVertex2f(267-73+300,260);
    glVertex2f(267-73+300,281);
    glVertex2f(262-73+300,281);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(218-73+300,260);// train channel
    glVertex2f(220-73+300,260);
    glVertex2f(220-73+300,264);
    glVertex2f(218-73+300,264);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(100,100,100);
    glVertex2f(200+300,285);// train
    glVertex2f(271+300,285);
    glVertex2f(271+300,287);
    glVertex2f(200+300,287);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,85,105);
    glVertex2f(200+300,258);// train
    glVertex2f(271+300,258);
    glVertex2f(271+300,285);
    glVertex2f(200+300,285);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(214,184,156);
    glVertex2f(200+300,266);// train
    glVertex2f(271+300,266);
    glVertex2f(271+300,277);
    glVertex2f(200+300,277);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(204+300,260);// train door
    glVertex2f(209+300,260);
    glVertex2f(209+300,281);
    glVertex2f(204+300,281);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(262+300,260);// train door
    glVertex2f(267+300,260);
    glVertex2f(267+300,281);
    glVertex2f(262+300,281);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+300,268);// train WINDOW
    glVertex2f(216+300,268);
    glVertex2f(216+300,276);
    glVertex2f(212+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+6+300,268);// train WINDOW
    glVertex2f(216+6+300,268);
    glVertex2f(216+6+300,276);
    glVertex2f(212+6+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+12+300,268);// train WINDOW
    glVertex2f(216+12+300,268);
    glVertex2f(216+12+300,276);
    glVertex2f(212+12+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+18+300,268);// train WINDOW
    glVertex2f(216+18+300,268);
    glVertex2f(216+18+300,276);
    glVertex2f(212+18+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+24+300,268);// train WINDOW
    glVertex2f(216+24+300,268);
    glVertex2f(216+24+300,276);
    glVertex2f(212+24+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+30+300,268);// train WINDOW
    glVertex2f(216+30+300,268);
    glVertex2f(216+30+300,276);
    glVertex2f(212+30+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+36+300,268);// train WINDOW
    glVertex2f(216+36+300,268);
    glVertex2f(216+36+300,276);
    glVertex2f(212+36+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+42+300,268);// train WINDOW
    glVertex2f(216+42+300,268);
    glVertex2f(216+42+300,276);
    glVertex2f(212+42+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(201+300,252);// train down
    glVertex2f(270+300,252);
    glVertex2f(270+300,258);
    glVertex2f(201+300,258);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(198+300,260);// train channel
    glVertex2f(200+300,260);
    glVertex2f(200+300,261);
    glVertex2f(198+300,261);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(100,100,100);
    glVertex2f(200+73+300,285);// train
    glVertex2f(271+73+300,285);
    glVertex2f(271+73+300,287);
    glVertex2f(200+73+300,287);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,85,105);
    glVertex2f(200+73+300,258);// train
    glVertex2f(271+73+300,258);
    glVertex2f(271+73+300,285);
    glVertex2f(200+73+300,285);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(214,184,156);
    glVertex2f(200+73+300,266);// train
    glVertex2f(271+73+300,266);
    glVertex2f(271+73+300,277);
    glVertex2f(200+73+300,277);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(204+73+300,260);// train door
    glVertex2f(209+73+300,260);
    glVertex2f(209+73+300,281);
    glVertex2f(204+73+300,281);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(262+73+300,260);// train door
    glVertex2f(267+73+300,260);
    glVertex2f(267+73+300,281);
    glVertex2f(262+73+300,281);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+73+300,268);// train WINDOW
    glVertex2f(216+73+300,268);
    glVertex2f(216+73+300,276);
    glVertex2f(212+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+6+73+300,268);// train WINDOW
    glVertex2f(216+6+73+300,268);
    glVertex2f(216+6+73+300,276);
    glVertex2f(212+6+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+12+73+300,268);// train WINDOW
    glVertex2f(216+12+73+300,268);
    glVertex2f(216+12+73+300,276);
    glVertex2f(212+12+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+18+73+300,268);// train WINDOW
    glVertex2f(216+18+73+300,268);
    glVertex2f(216+18+73+300,276);
    glVertex2f(212+18+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+24+73+300,268);// train WINDOW
    glVertex2f(216+24+73+300,268);
    glVertex2f(216+24+73+300,276);
    glVertex2f(212+24+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+30+73+300,268);// train WINDOW
    glVertex2f(216+30+73+300,268);
    glVertex2f(216+30+73+300,276);
    glVertex2f(212+30+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+36+73+300,268);// train WINDOW
    glVertex2f(216+36+73+300,268);
    glVertex2f(216+36+73+300,276);
    glVertex2f(212+36+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+42+73+300,268);// train WINDOW
    glVertex2f(216+42+73+300,268);
    glVertex2f(216+42+73+300,276);
    glVertex2f(212+42+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(201+73+300,252);// train down
    glVertex2f(270+73+300,252);
    glVertex2f(270+73+300,258);
    glVertex2f(201+73+300,258);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(198+73+300,260);// train channel
    glVertex2f(200+73+300,260);
    glVertex2f(200+73+300,261);
    glVertex2f(198+73+300,261);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(100,100,100);
    glVertex2f(200+73+73+300,285);// train
    glVertex2f(271+73+73+300,285);
    glVertex2f(271+73+73+300,287);
    glVertex2f(200+73+73+300,287);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,85,105);
    glVertex2f(200+73+73+300,258);// train
    glVertex2f(271+73+73+300,258);
    glVertex2f(271+73+73+300,285);
    glVertex2f(200+73+73+300,285);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(214,184,156);
    glVertex2f(200+73+73+300,266);// train
    glVertex2f(271+73+73+300,266);
    glVertex2f(271+73+73+300,277);
    glVertex2f(200+73+73+300,277);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(204+73+73+300,260);// train door
    glVertex2f(209+73+73+300,260);
    glVertex2f(209+73+73+300,281);
    glVertex2f(204+73+73+300,281);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(262+73+73+300,260);// train door
    glVertex2f(267+73+73+300,260);
    glVertex2f(267+73+73+300,281);
    glVertex2f(262+73+73+300,281);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+73+73+300,268);// train WINDOW
    glVertex2f(216+73+73+300,268);
    glVertex2f(216+73+73+300,276);
    glVertex2f(212+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+6+73+73+300,268);// train WINDOW
    glVertex2f(216+6+73+73+300,268);
    glVertex2f(216+6+73+73+300,276);
    glVertex2f(212+6+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+12+73+73+300,268);// train WINDOW
    glVertex2f(216+12+73+73+300,268);
    glVertex2f(216+12+73+73+300,276);
    glVertex2f(212+12+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+18+73+73+300,268);// train WINDOW
    glVertex2f(216+18+73+73+300,268);
    glVertex2f(216+18+73+73+300,276);
    glVertex2f(212+18+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+24+73+73+300,268);// train WINDOW
    glVertex2f(216+24+73+73+300,268);
    glVertex2f(216+24+73+73+300,276);
    glVertex2f(212+24+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+30+73+73+300,268);// train WINDOW
    glVertex2f(216+30+73+73+300,268);
    glVertex2f(216+30+73+73+300,276);
    glVertex2f(212+30+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+36+73+73+300,268);// train WINDOW
    glVertex2f(216+36+73+73+300,268);
    glVertex2f(216+36+73+73+300,276);
    glVertex2f(212+36+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+42+73+73+300,268);// train WINDOW
    glVertex2f(216+42+73+73+300,268);
    glVertex2f(216+42+73+73+300,276);
    glVertex2f(212+42+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(201+73+73+300,252);// train down
    glVertex2f(270+73+73+300,252);
    glVertex2f(270+73+73+300,258);
    glVertex2f(201+73+73+300,258);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(198+73+73+300,260);// train channel
    glVertex2f(200+73+73+300,260);
    glVertex2f(200+73+73+300,261);
    glVertex2f(198+73+73+300,261);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(100,100,100);
    glVertex2f(200+73+73+73+300,285);// train
    glVertex2f(271+73+73+73+300,285);
    glVertex2f(271+73+73+73+300,287);
    glVertex2f(200+73+73+73+300,287);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,85,105);
    glVertex2f(200+73+73+73+300,258);// train
    glVertex2f(271+73+73+73+300,258);
    glVertex2f(271+73+73+73+300,285);
    glVertex2f(200+73+73+73+300,285);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(214,184,156);
    glVertex2f(200+73+73+73+300,266);// train
    glVertex2f(271+73+73+73+300,266);
    glVertex2f(271+73+73+73+300,277);
    glVertex2f(200+73+73+73+300,277);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(204+73+73+73+300,260);// train door
    glVertex2f(209+73+73+73+300,260);
    glVertex2f(209+73+73+73+300,281);
    glVertex2f(204+73+73+73+300,281);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(262+73+73+73+300,260);// train door
    glVertex2f(267+73+73+73+300,260);
    glVertex2f(267+73+73+73+300,281);
    glVertex2f(262+73+73+73+300,281);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+73+73+73+300,268);// train WINDOW
    glVertex2f(216+73+73+73+300,268);
    glVertex2f(216+73+73+73+300,276);
    glVertex2f(212+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+6+73+73+73+300,268);// train WINDOW
    glVertex2f(216+6+73+73+73+300,268);
    glVertex2f(216+6+73+73+73+300,276);
    glVertex2f(212+6+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+12+73+73+73+300,268);// train WINDOW
    glVertex2f(216+12+73+73+73+300,268);
    glVertex2f(216+12+73+73+73+300,276);
    glVertex2f(212+12+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+18+73+73+73+300,268);// train WINDOW
    glVertex2f(216+18+73+73+73+300,268);
    glVertex2f(216+18+73+73+73+300,276);
    glVertex2f(212+18+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+24+73+73+73+300,268);// train WINDOW
    glVertex2f(216+24+73+73+73+300,268);
    glVertex2f(216+24+73+73+73+300,276);
    glVertex2f(212+24+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+30+73+73+73+300,268);// train WINDOW
    glVertex2f(216+30+73+73+73+300,268);
    glVertex2f(216+30+73+73+73+300,276);
    glVertex2f(212+30+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+36+73+73+73+300,268);// train WINDOW
    glVertex2f(216+36+73+73+73+300,268);
    glVertex2f(216+36+73+73+73+300,276);
    glVertex2f(212+36+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+42+73+73+73+300,268);// train WINDOW
    glVertex2f(216+42+73+73+73+300,268);
    glVertex2f(216+42+73+73+73+300,276);
    glVertex2f(212+42+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(201+73+73+73+300,252);// train down
    glVertex2f(270+73+73+73+300,252);
    glVertex2f(270+73+73+73+300,258);
    glVertex2f(201+73+73+73+300,258);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(198+73+73+73+300,260);// train channel
    glVertex2f(200+73+73+73+300,260);
    glVertex2f(200+73+73+73+300,261);
    glVertex2f(198+73+73+73+300,261);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(100,100,100);
    glVertex2f(200+73+73+73+73+300,285);// train
    glVertex2f(271+73+73+73+73+300,285);
    glVertex2f(271+73+73+73+73+300,287);
    glVertex2f(200+73+73+73+73+300,287);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,85,105);
    glVertex2f(200+73+73+73+73+300,258);// train
    glVertex2f(271+73+73+73+73+300,258);
    glVertex2f(271+73+73+73+73+300,285);
    glVertex2f(200+73+73+73+73+300,285);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(214,184,156);
    glVertex2f(200+73+73+73+73+300,266);// train
    glVertex2f(271+73+73+73+73+300,266);
    glVertex2f(271+73+73+73+73+300,277);
    glVertex2f(200+73+73+73+73+300,277);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(204+73+73+73+73+300,260);// train door
    glVertex2f(209+73+73+73+73+300,260);
    glVertex2f(209+73+73+73+73+300,281);
    glVertex2f(204+73+73+73+73+300,281);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(262+73+73+73+73+300,260);// train door
    glVertex2f(267+73+73+73+73+300,260);
    glVertex2f(267+73+73+73+73+300,281);
    glVertex2f(262+73+73+73+73+300,281);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+73+73+73+73+300,268);
    glVertex2f(216+73+73+73+73+300,276);
    glVertex2f(212+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+6+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+6+73+73+73+73+300,268);
    glVertex2f(216+6+73+73+73+73+300,276);
    glVertex2f(212+6+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+12+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+12+73+73+73+73+300,268);
    glVertex2f(216+12+73+73+73+73+300,276);
    glVertex2f(212+12+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+18+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+18+73+73+73+73+300,268);
    glVertex2f(216+18+73+73+73+73+300,276);
    glVertex2f(212+18+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+24+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+24+73+73+73+73+300,268);
    glVertex2f(216+24+73+73+73+73+300,276);
    glVertex2f(212+24+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+30+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+30+73+73+73+73+300,268);
    glVertex2f(216+30+73+73+73+73+300,276);
    glVertex2f(212+30+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+36+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+36+73+73+73+73+300,268);
    glVertex2f(216+36+73+73+73+73+300,276);
    glVertex2f(212+36+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+42+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+42+73+73+73+73+300,268);
    glVertex2f(216+42+73+73+73+73+300,276);
    glVertex2f(212+42+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(201+73+73+73+73+300,252);// train down
    glVertex2f(270+73+73+73+73+300,252);
    glVertex2f(270+73+73+73+73+300,258);
    glVertex2f(201+73+73+73+73+300,258);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(198+73+73+73+73+300,260);// train channel
    glVertex2f(200+73+73+73+73+300,260);
    glVertex2f(200+73+73+73+73+300,261);
    glVertex2f(198+73+73+73+73+300,261);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(100,100,100);
    glVertex2f(200+73+73+73+73+73+300,285);// train
    glVertex2f(271+73+73+73+73+73+300,285);
    glVertex2f(271+73+73+73+73+73+300,287);
    glVertex2f(200+73+73+73+73+73+300,287);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,85,105);
    glVertex2f(200+73+73+73+73+73+300,258);// train
    glVertex2f(271+73+73+73+73+73+300,258);
    glVertex2f(271+73+73+73+73+73+300,285);
    glVertex2f(200+73+73+73+73+73+300,285);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(214,184,156);
    glVertex2f(200+73+73+73+73+73+300,266);// train
    glVertex2f(271+73+73+73+73+73+300,266);
    glVertex2f(271+73+73+73+73+73+300,277);
    glVertex2f(200+73+73+73+73+73+300,277);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(204+73+73+73+73+73+300,260);// train door
    glVertex2f(209+73+73+73+73+73+300,260);
    glVertex2f(209+73+73+73+73+73+300,281);
    glVertex2f(204+73+73+73+73+73+300,281);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(262+73+73+73+73+73+300,260);// train door
    glVertex2f(267+73+73+73+73+73+300,260);
    glVertex2f(267+73+73+73+73+73+300,281);
    glVertex2f(262+73+73+73+73+73+300,281);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+73+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+73+73+73+73+73+300,268);
    glVertex2f(216+73+73+73+73+73+300,276);
    glVertex2f(212+73+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+6+73+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+6+73+73+73+73+73+300,268);
    glVertex2f(216+6+73+73+73+73+73+300,276);
    glVertex2f(212+6+73+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+12+73+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+12+73+73+73+73+73+300,268);
    glVertex2f(216+12+73+73+73+73+73+300,276);
    glVertex2f(212+12+73+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+18+73+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+18+73+73+73+73+73+300,268);
    glVertex2f(216+18+73+73+73+73+73+300,276);
    glVertex2f(212+18+73+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+24+73+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+24+73+73+73+73+73+300,268);
    glVertex2f(216+24+73+73+73+73+73+300,276);
    glVertex2f(212+24+73+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+30+73+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+30+73+73+73+73+73+300,268);
    glVertex2f(216+30+73+73+73+73+73+300,276);
    glVertex2f(212+30+73+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+36+73+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+36+73+73+73+73+73+300,268);
    glVertex2f(216+36+73+73+73+73+73+300,276);
    glVertex2f(212+36+73+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+42+73+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+42+73+73+73+73+73+300,268);
    glVertex2f(216+42+73+73+73+73+73+300,276);
    glVertex2f(212+42+73+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(201+73+73+73+73+73+300,252);// train down
    glVertex2f(270+73+73+73+73+73+300,252);
    glVertex2f(270+73+73+73+73+73+300,258);
    glVertex2f(201+73+73+73+73+73+300,258);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(198+73+73+73+73+73+300,260);// train channel
    glVertex2f(200+73+73+73+73+73+300,260);
    glVertex2f(200+73+73+73+73+73+300,261);
    glVertex2f(198+73+73+73+73+73+300,261);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(100,100,100);
    glVertex2f(200+73+73+73+73+73+73+300,285);// train
    glVertex2f(271+73+73+73+73+73+73+300,285);
    glVertex2f(271+73+73+73+73+73+73+300,287);
    glVertex2f(200+73+73+73+73+73+73+300,287);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,85,105);
    glVertex2f(200+73+73+73+73+73+73+300,258);// train
    glVertex2f(271+73+73+73+73+73+73+300,258);
    glVertex2f(271+73+73+73+73+73+73+300,285);
    glVertex2f(200+73+73+73+73+73+73+300,285);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(214,184,156);
    glVertex2f(200+73+73+73+73+73+73+300,266);// train
    glVertex2f(271+73+73+73+73+73+73+300,266);
    glVertex2f(271+73+73+73+73+73+73+300,277);
    glVertex2f(200+73+73+73+73+73+73+300,277);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(204+73+73+73+73+73+73+300,260);// train door
    glVertex2f(209+73+73+73+73+73+73+300,260);
    glVertex2f(209+73+73+73+73+73+73+300,281);
    glVertex2f(204+73+73+73+73+73+73+300,281);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(262+73+73+73+73+73+73+300,260);// train door
    glVertex2f(267+73+73+73+73+73+73+300,260);
    glVertex2f(267+73+73+73+73+73+73+300,281);
    glVertex2f(262+73+73+73+73+73+73+300,281);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+73+73+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+73+73+73+73+73+73+300,268);
    glVertex2f(216+73+73+73+73+73+73+300,276);
    glVertex2f(212+73+73+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+6+73+73+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+6+73+73+73+73+73+73+300,268);
    glVertex2f(216+6+73+73+73+73+73+73+300,276);
    glVertex2f(212+6+73+73+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+12+73+73+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+12+73+73+73+73+73+73+300,268);
    glVertex2f(216+12+73+73+73+73+73+73+300,276);
    glVertex2f(212+12+73+73+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+18+73+73+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+18+73+73+73+73+73+73+300,268);
    glVertex2f(216+18+73+73+73+73+73+73+300,276);
    glVertex2f(212+18+73+73+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+24+73+73+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+24+73+73+73+73+73+73+300,268);
    glVertex2f(216+24+73+73+73+73+73+73+300,276);
    glVertex2f(212+24+73+73+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+30+73+73+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+30+73+73+73+73+73+73+300,268);
    glVertex2f(216+30+73+73+73+73+73+73+300,276);
    glVertex2f(212+30+73+73+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+36+73+73+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+36+73+73+73+73+73+73+300,268);
    glVertex2f(216+36+73+73+73+73+73+73+300,276);
    glVertex2f(212+36+73+73+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex2f(212+42+73+73+73+73+73+73+300,268);// train WINDOW
    glVertex2f(216+42+73+73+73+73+73+73+300,268);
    glVertex2f(216+42+73+73+73+73+73+73+300,276);
    glVertex2f(212+42+73+73+73+73+73+73+300,276);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(201+73+73+73+73+73+73+300,252);// train down
    glVertex2f(270+73+73+73+73+73+73+300,252);
    glVertex2f(270+73+73+73+73+73+73+300,258);
    glVertex2f(201+73+73+73+73+73+73+300,258);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(198+73+73+73+73+73+73+300,260);// train channel
    glVertex2f(200+73+73+73+73+73+73+300,260);
    glVertex2f(200+73+73+73+73+73+73+300,261);
    glVertex2f(198+73+73+73+73+73+73+300,261);
    glEnd();
}

void updatetrain()
	{
		if (trainStatus == 1)
		{
			trainX -=trainSpeed;
		}
        if (trainX<-1020)
		{
			trainX =300 ;
		}
		glPushMatrix();
		glTranslatef(trainX, trainY, 0);
		train();
		glPopMatrix();
	}

void river()
{
glBegin(GL_QUADS);

glColor3ub(30,144,255);
glVertex2f(0,0);
glColor3ub(135,206,250);
glVertex2f(0,270 ); // x, y
glColor3ub(135,206,250);
glVertex2f(700,270);
glColor3ub(30,169,255);
glVertex2f(700,0);// x, y
glEnd();
}

void nouka()
{
glBegin(GL_QUADS);
glColor3ub(185,122,87);
glVertex2f(48,140);
glVertex2f(75,140);
glVertex2f(82,150);
glVertex2f(41,150);
glEnd();

glLineWidth(1);
glBegin(GL_LINE_LOOP);
glColor3ub(0,0,0);
glVertex2f(48,140);
glVertex2f(75,140);
glVertex2f(82,150);
glVertex2f(41,150);
glEnd();


glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f(65,150);
glVertex2f(67,150);
glVertex2f(67,181);
glVertex2f(65,181);
glEnd();

glBegin(GL_QUADS);
glColor3ub(220,20,60);
glVertex2f(53,158);
glVertex2f(65,158);
glVertex2f(65,180);
glVertex2f(53,158);
glEnd();
}

void updatenouka()
	{
		if (noukaStatus == 1)
		{
			noukaX +=noukaSpeed;
		}
        if (noukaX>700)
		{
			noukaX =-80 ;
		}
		glPushMatrix();
		glTranslatef(noukaX, noukaY, 0);
		nouka();
		glPopMatrix();
	}

void nouka2()
{
glBegin(GL_QUADS);
glColor3ub(142,88,60);
glVertex2f(449,210);
glVertex2f(473,210);
glVertex2f(480,218);
glVertex2f(442,218);
glEnd();

glLineWidth(1);
glBegin(GL_LINE_LOOP);
glColor3ub(0,0,0);
glVertex2f(449,210);
glVertex2f(473,210);
glVertex2f(480,218);
glVertex2f(442,218);
glEnd();

glBegin(GL_QUADS);
glColor3ub(52,33,22);
glVertex2f(450,218);
glVertex2f(472,218);
glVertex2f(470,224);
glVertex2f(452,224);
glEnd();
}

void updatenouka2()
	{
		if (noukaStatus2 == 1)
		{
			nouka2X -=noukaSpeed2;
		}
        if (nouka2X<-500)
		{
			nouka2X =250 ;
		}
		glPushMatrix();
		glTranslatef(nouka2X, nouka2Y, 0);
		nouka2();
		glPopMatrix();
	}

void ship1()
{

glBegin(GL_QUADS);
glColor3ub(100,100,100);
glVertex2f(150,60);
glVertex2f(190,60);
glVertex2f(188,80);
glVertex2f(152,80);
glEnd();

glBegin(GL_QUADS);
glColor3ub(136,0,21);
glVertex2f(150,76);
glVertex2f(190,76);
glVertex2f(188,80);
glVertex2f(152,80);
glEnd();

glBegin(GL_QUADS);
glColor3ub(255,201,14);
glVertex2f(150,74);
glVertex2f(190,74);
glVertex2f(188,76);
glVertex2f(152,76);
glEnd();

glBegin(GL_QUADS);
glColor3ub(250,247,231);
glVertex2f(154,64);
glVertex2f(159,64);
glVertex2f(159,72);
glVertex2f(154,72);
glEnd();

glBegin(GL_QUADS);
glColor3ub(250,247,231);
glVertex2f(154+7,64);
glVertex2f(159+7,64);
glVertex2f(159+7,72);
glVertex2f(154+7,72);
glEnd();

glBegin(GL_QUADS);
glColor3ub(250,247,231);
glVertex2f(154+7+7,64);
glVertex2f(159+7+7,64);
glVertex2f(159+7+7,72);
glVertex2f(154+7+7,72);
glEnd();

glBegin(GL_QUADS);
glColor3ub(100,100,100);
glVertex2f(150,30);
glVertex2f(210+30,30);
glVertex2f(230+30,60);
glVertex2f(130,60);
glEnd();

glBegin(GL_QUADS);
glColor3ub(136,0,21);
glVertex2f(137,50);
glVertex2f(223+30,50);
glVertex2f(230+30,60);
glVertex2f(130,60);
glEnd();

glBegin(GL_QUADS);
glColor3ub(255,201,14);
glVertex2f(140,46);
glVertex2f(220+30,46);
glVertex2f(223+30,50);
glVertex2f(137,50);
glEnd();

}

void updateship1()
	{
		if (ship1Status == 1)
		{
			ship1X +=ship1Speed;
		}
        if (ship1X>600)
		{
			ship1X =-280 ;
		}
		glPushMatrix();
		glTranslatef(ship1X, ship1Y, 0);
		ship1();
		glPopMatrix();
	}

void ship2()
{
glBegin(GL_QUADS);
glColor3ub(25,25,112);
glVertex2f(350,40+70);
glVertex2f(380,40+70);
glVertex2f(380,55+70);
glVertex2f(330,55+70);
glEnd();

glLineWidth(1);
glBegin(GL_LINE_LOOP);
glColor3ub(0,0,0);
glVertex2f(350,40+70);
glVertex2f(380,40+70);
glVertex2f(380,55+70);
glVertex2f(330,55+70);
glEnd();

glBegin(GL_QUADS);
glColor3ub(128,129,236);
glVertex2f(340,55+70);
glVertex2f(373,55+70);
glVertex2f(373,65+70);
glVertex2f(350,65+70);
glEnd();

glLineWidth(1);
glBegin(GL_LINE_LOOP);
glColor3ub(0,0,0);
glVertex2f(340,55+70);
glVertex2f(373,55+70);
glVertex2f(373,65+70);
glVertex2f(350,65+70);
glEnd();

glBegin(GL_QUADS);
glColor3ub(220,20,60);
glVertex2f(350,65+70);
glVertex2f(370,65+70);
glVertex2f(355,70+70);
glVertex2f(355,70+70);
glEnd();
}

void updateship2()
	{
		if (ship2Status == 1)
		{
			ship2X -=ship2Speed;
		}
        if (ship2X<-400)
		{
			ship2X =400 ;
		}
		glPushMatrix();
		glTranslatef(ship2X, ship2Y, 0);
		ship2();
		glPopMatrix();
	}

void display()
{
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer with current clearing color
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

sky();
sun();
updatecloud1();
updatecloud2();
updatecloud3();
updateplan();
river();

updatetrain();
leftlamp();
updatecar1();
updatecar2();
updatebus();
updatetrack();
rightlamp();
updatenouka2();
bridge();
updatenouka();
updateship2();
updateship1();

glFlush();
glutPostRedisplay();
glutSwapBuffers();
}

void position(void)
{
glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,700,0,500);
}

int main(int argc, char** argv) {

glutInit(&argc, argv);
glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
glutInitWindowSize(1320,660);
glutCreateWindow("PADMA BRIDGE");
glutDisplayFunc(display);
position();
//glutKeyboardFunc(handleKeypress);

glutMainLoop();
}
