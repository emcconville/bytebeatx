
#include "beats.h"

int8_t aaa(int t)
{
    return (t*5&t>>7)|(t*3&t>>10);
}


int8_t aab(int t)
{
    return (int)(t/1e7*t*t+t)%127|t>>4|t>>5|t%127+(t>>16)|t;
}

int8_t aac(int t)
{
    return ((t/2*(15&(0x2345678a0>>(t>>8&28))))|t/2>>(t>>11)^t>>12)+(t/16&t&24);
}

int8_t aad(int t)
{
    return (t&t%255)-(t*3&t>>13&t>>6);
}

int8_t aae(int t)
{
    return ((t*("36364689"[t>>12&7]&15))/12&128)+
           (((((t>>12)^(t>>12)-2)%11*t)/4|t>>13)&127);
}

int8_t aaf(int t)
{
    return ((t*9&t>>4)|(t*5&t>>7)|(t*3&t/1024))-1;
}

int8_t aag(int t)
{
    return ((t*(t>>12)&(201*t/100)&(199*t/100))
           &(t*(t>>14)&(t*301/100)&(t*339/100)))
           +((t*(t>>17)&(t*202/100)&(t*198/100))
           -(t*(t>>17)&(t*302/100)&(t*298/100)));
}

//https://www.youtube.com/watch?v=GtQdIYUtAHg
int8_t bba(int t)
{
    return t * ((t>>12|t>>8)&63&t>>4);
}

int8_t bbb(int t)
{
    return (t*(t>>5|t>>8))>>(t>>16); // tejeez
}

int8_t bbc(int t)
{
    return t*((t>>9|t>>13)&25&t>>6); // visy
}

int8_t bbd(int t)
{
    return t*(t>>11&t>>8&123&t>>3); // tejeez
}

int8_t bbe(int t)
{
    return (t*(t>>8*(t>>15|t>>8)&
           (20|(t>>19)*5>>t|t>>3))); // visy
}

int8_t bbf(int t)
{
    return ((t&4095)*(255&t*(t&t>>13))>>12)+
           (127&t*(234&t>>8&t>>3)>>(3&t>>14)); // tejeez
}

int8_t bbg(int t)
{
    return t*(t>>((t>>9|t>>8))&63&t>>4); // visy
}

int8_t cca(int t)
{
    return (t>>6|t|t>>(t>>16))*10+((t>>11)&7); // viznut
}

int8_t ccb(int t)
{
    return (t|(t>>9|t>>7))*t&(t>>11|t>>9); // red-
}

int8_t ccc(int t)
{
    return (t*5&(t>>7))|(t*3&(t*4>>10));
}

int8_t ccd(int t)
{
    return (t>>7|t|t>>6)*10+4*((t&t>>13)|t>>6);
}

int8_t cce(int t)
{
    return ((t&4096)?((t*(t^t%255)|(t>>4))>>1):(t>>3)|((t&8192)?t<<2:t)); // skurk
}











