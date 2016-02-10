
/* Standard */
#include "string.h"
#include "math.h"
/* Me */
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

int8_t aada(int t)
{
    return t>>4|(t&(t>>5)/((t>>(7-(t>>15))&-t>>(7-(t>>15)))|t)); // droid
}

int8_t aae(int t)
{
    return ((t*("36364689"[t>>12&7]&15))/12&128)+
           (((((t>>12)^(t>>12)-2)%11*t)/4|t>>13)&127); // ryg
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

int8_t aah(int t)
{
    return t*(t^t+(t>>15|1)^(t-1280^t)>>10);
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
    return (t*5&(t>>7))|(t*3&(t*4>>10)); // mirro
}

int8_t ccd(int t)
{
    return (t>>7|t|t>>6)*10+4*((t&t>>13)|t>>6); // viznut
}

int8_t cce(int t)
{
    return ((t&4096)?((t*(t^t%255)|(t>>4))>>1):(t>>3)|((t&8192)?t<<2:t)); // skurk
}

int8_t ccf(int t)
{
    return ((t*(t>>8|t>>9)&46&t>>8))^((t&(t>>13))|t>>6); // xpensive
}


int8_t eea(int t)
{
    // http://codegolf.stackexchange.com/q/4746
    return ((t<<1)^((t<<1)+(t>>7)&t>>12))|t>>(4-(1^7&(t>>19)))|t>>7;
}

int8_t eeb(int t)
{
    return ((7&(((t>>17)+1)>>2)+((t>>10)&1+2*(t>>18&1))*(("23468643"[7&t>>12]-48)+(3&t>>11))+((3&t>>17)>0)*(3&t>>9)*!(1&t>>10)*((((2+t)>>10&3)^((2+t)>>11&3))))*t*"@06+"[3&t>>15]/32);
}

int8_t eec(int t)
{
    return ((t>>10)&1)*(t*("23468643"[7&t>>12]-48)+t*(3&t>>11))*"@06+"[3&t>>15]/32;
}

int8_t eed(int t)
{
    return t*(3&t>>11)+(t&t>>11)*4*!((t>>11)%3);
}

int8_t oxa(int t)
{
    return ((t>>1%128)+20)*3*t>>14*t>>18; // harism
}

int8_t oxb(int t)
{
    return t*(((t>>9)&10)|((t>>11)&24)^((t>>10)&15&(t>>15))); // tangent128
}

int8_t oxc(int t)
{
    return (t*t/256)&(t>>((t/1024)%16))^t%64*(0xC0D3DE4D69>>(t>>9&30)&t%32)*t>>18; // ultrageranium
}

int8_t shs1(int t)
{
    return (t|t>>8)>>(t>>7)|(t<<6|t<<8)>>(t>>11)|(t<<7|t<<11)>>(t>>11); // hadez
}
int8_t shs2(int t)
{
    return (t|t>>17)>>(t>>7)|(t<<2|t<<8)>>(t>>11)|(t<<2|t<<11)>>(t>>17); // h0uz3
}
int8_t shs3(int t)
{
    return (int8_t)sin(t>>16)|(t|t>>8); // hadez
}
int8_t shs4(int t)
{
    return (t>>9&t>>8)*(t>>3); // h0uz3
}
int8_t shs5(int t)
{
    return (t>>8|t-2)&(2-t|8<<t); // h0uz3
}
int8_t shs6(int t)
{
    return ((t>>8|t-2)&(2-t|8<<t))<<((t>>8|t-2)&(2-t|8<<t))>>((t>>8|t-2)&(2-t|8<<t)); // h0uz3
}
int8_t shs7(int t)
{
    return ((t>>3|t<<7)|t>>11)|t>>16; // h0uz3
}
int8_t shs8(int t)
{
    return ((((t>>3|t<<7)|t>>11)|t>>16)&23); // h0uz3
}
int8_t shs9(int t)
{
// FIXME!
//    return ((sin((t%17)*3.1415*0.5)*100)<<t/90)|(sin(t*t*3.1415*0.5)*50); // samuirai
    return 0;
}
int8_t shs10(int t)
{
    return ((t>>4)|((t<<4)&0x11111+t/1000)); // tv
}
int8_t shs11(int t)
{
    return t<700000?((t/2000%2?t<<3:t<<2)>>(t/10000%3)<<t/100000):t<800000?-t*t*t>>(t/1000)|t/(800000-t):t<805000?t<<(t/500):/*"fin"*/1/(t-t); // tv
}
int8_t shs12(int t)
{
    return ((t>>7)* 0xff) * (t & 0xff)/32 & ~(t / 127); // bdwheele
}
int8_t shs13(int t)
{
    int l[4] = {8,9,10,11};
    return ((t>>10)<<((t>>4)%(l[(t>>11)%4]-(t>>15)%4))); // tito
}

static audio_beat_t catalog[50] = {
    {"aaa", "viznut", aaa},
    {"aab",    "bst", aab},
    {"aac",     "kb", aac},
    {"aad", "viznut", aad},
    {"aae",    "ryg", aae},
    {"aaf","stephth", aaf},
    {"aag", "viznut", aag},
    {"aah",    "216", aah},
    {"bba", "viznut", bba},
    {"bbb", "tejeez", bbb},
    {"bbc",   "visy", bbc},
    {"bbd", "tejeez", bbd},
    {"bbe",   "visy", bbe},
    {"bbf", "tejeez", bbf},
    {"bbg", "viznut", bbg},
    {"cca", "viznut", cca},
    {"ccb",   "red-", ccb},
    {"ccc",  "miiro", ccc},
    {"ccd", "viznut", ccd},
    {"cce",  "skurk", cce},
    {"ccf","xpensive",ccf},
    {"eea","Jeff Burdges", eea},
    {"eeb",  "JiminP", eeb},
    {"eec",  "JiminP", eec},
    {"eed",  "JiminP", eed},
    {"oxa",  "herism", oxa},
    {"oxb","tangent128", oxb},
    {"oxc","ultrageranium", oxc},
    {"shs1",  "hadez",shs1},
    {"shs2",  "h0uz3",shs2},
    {"shs3",  "hadez",shs3},
    {"shs4",  "h0uz3",shs4},
    {"shs5",  "h0uz3",shs5},
    {"shs6",  "h0uz3",shs6},
    {"shs7",  "h0uz3",shs7},
    {"shs8",  "h0uz3",shs8},
    {"shs9","samuirai",shs9},
    {"shs10",    "tv",shs10},
    {"shs11",    "tv",shs11},
    {"shs12","bdwheele",shs12},
    {"shs13",  "tito",shs13},
    { NULL,     NULL, NULL}
};


byte_beat find_callback_by_label(const char * token)
{
    size_t index = 0;
    byte_beat BB = NULL;
    while(catalog[index].label != NULL) {
        if(strcasecmp(catalog[index].label, token) == 0) {
            BB = catalog[index].callback;
            break;
        }
        index++;
    };
    
    return BB;
}

void print_all_labels()
{
    printf("Available Labels:\n");
    size_t index = 0;
    while(catalog[index].label != NULL) {
        printf("    -%s   by %s\n", catalog[index].label, catalog[index].author);
        index++;
    };
    
}

audio_beat_t * get_catalog()
{
    return catalog;
}

