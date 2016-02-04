#ifndef _BOO_HIST_
#define _BOO_HIST_

#include <sys/types.h>
#include "byte_buff.h"

// For callback directory
typedef struct audio_beat {
    const char * label;
    const char * author;
    byte_beat callback;
} audio_beat_t;

byte_beat find_callback_by_label(const char * token);
void print_all_labels();

#endif