
/* Standard */
#include "string.h"
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
    {"ccc",       "", ccc},
    {"ccd",       "", ccd},
    {"cce",  "skurk", cce},
    {"ccf","xpensive",ccf},
    {"eea",  "Jeff Burdges", eea},
    {"eeb",  "JiminP", eeb},
    {"eec",  "JiminP", eec},
    {"eed",  "JiminP", eed},
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
    printf("Availabel Labels:\n");
    size_t index = 0;
    while(catalog[index].label != NULL) {
        printf("    -%s  by %s\n", catalog[index].label, catalog[index].author);
        index++;
    };
    
}


