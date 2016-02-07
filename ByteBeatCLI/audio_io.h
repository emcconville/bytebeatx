#ifndef audio_bleep_bleep
#define audio_bleep_bleep

#include <AudioToolbox/AudioToolbox.h>
#include "byte_buff.h"

void audio_startup(AudioUnit * unit, session_t * session);
void audio_teardown(AudioUnit * unit);

byte_beat find_callback_by_label(const char * token);

#endif
