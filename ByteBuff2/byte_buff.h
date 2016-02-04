#ifndef byte_buff_here
#define byte_buff_here

#include <sys/types.h>


/*!
 * @abstract Pointer to bytebeat function
 */
typedef int8_t (*byte_beat)(int);

/*!
 * @abstract Just enough info to popluate a flick
 */
typedef struct image_format {
    /*! Output format */
    const char * path;
    /*! Core Foundation OS X Image format */
    CFStringRef format;
    /*! Width of the generated image */
    size_t width;
    /*! Height of the generated image */
    size_t height;
} image_format_t;

/*!
 * @abstract Callback and cursor for walking down the PCM
 */
typedef struct sound_format {
    /*! Runtime sample rate of PCM */
    double sampleRate;
    /*! Incrementer `t' in callback program */
    int32_t cursor;
    /*! Function pointer to callback program */
    byte_beat cb;
} sound_format_t;

/*!
 * @abstract Runtime session
 */
typedef struct session {
    /*! Image info */
    image_format_t image;
    /*! Audio info */
    sound_format_t sound;
} session_t;


#endif
