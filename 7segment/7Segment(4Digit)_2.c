//15. Foursegment

#include <wiringPi.h>
#include <stdio.h>
#define a 29
#define b 27
#define c 22
#define d 24
#define e 25
#define f 28
#define g 21
#define one 5
#define two 4
#define three 1
#define four 7

void display0()
{
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,LOW);  
}

void display1()
{
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
}


void display2()
{
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,LOW);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);
}

void display3()
{
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);
}

int main(void)
{
    wiringPiSetup();
    pinMode(a,OUTPUT);
    pinMode(b,OUTPUT);
    pinMode(c,OUTPUT);
    pinMode(d,OUTPUT);
    pinMode(e,OUTPUT);
    pinMode(f,OUTPUT);
    pinMode(g,OUTPUT);
    pinMode(one,OUTPUT);
    pinMode(two,OUTPUT);
    pinMode(three,OUTPUT);
    pinMode(four,OUTPUT);

    while(1)
    {
        digitalWrite(one,LOW);
        display0();
        delay(5);
        digitalWrite(one,HIGH);
        digitalWrite(two,LOW);
        display1();
        delay(5);
        digitalWrite(two,HIGH);
        digitalWrite(three,LOW);
        display2();
        delay(5);
        digitalWrite(three,HIGH);
        digitalWrite(four,LOW);
        display3();
        delay(5);
        digitalWrite(four,HIGH);
    }

    return 0;
}
