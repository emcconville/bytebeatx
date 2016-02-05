/* Standard */
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
/* Apple */
#import <AudioToolbox/AudioToolbox.h>
#import <CoreServices/CoreServices.h>
/* Me */
#import "byte_buff.h"
#import "beats.h"
#import "audio_io.h"
#import "image_io.h"

static volatile int loop;

void stop_loop(int g) { loop = 0; }

void generate_sound(session_t * session)
{
    AudioUnit outputUnit;
    audio_startup(&outputUnit, session);
    for (loop=1;loop==1;);
    printf("Snap!\n");
    audio_teardown(&outputUnit);
}

void generate_image(session_t * session)
{
    image_startup(session);
    image_teardown(); // Does nothing
}


int main(int argc, const char * argv[]) {

    session_t session = {
        .image = {
            .path = NULL,
            .format = kUTTypePNG,
            .width = 255,
            .height = 255,
        },
        .sound = {
            .sampleRate = 8000.0 /*  48000.0 44100.0 22050.0 11025.0 8000.0 */,
            .cursor = 0,
            .cb = find_callback_by_label("aaa")
        }
    };
    int i;
    for (i=0; i<argc; i++) {
        if (argv[i][0] == '+') {
            session.sound.sampleRate = atof(&(argv[i][1]));
        } else if (argv[i][0] == '-') {
            if (strncmp(&(argv[i][1]), "width", 5) == 0) {
                session.image.width = atoi(argv[++i]);
            } else if (strncmp(&(argv[i][1]), "height", 6) == 0) {
                session.image.height = atoi(argv[++i]);
            } else if (strncmp(&(argv[i][1]), "image", 5) == 0) {
                session.image.path = argv[++i];
            }  else {
                if (argv[i][1] == 'h' || argv[i][1] == '?') {
                 const char * help_message = ""
                    "ByteBeatX - v0.0.0 (_@emcconville.com)\n"
                    "\n"
                    "Generate audio:\n"
                    "    bytebeat +<frequency> -<label>\n"
                    "\n"
                    "Generate image:\n"
                    "    bytebeat -width <int> -height <int> -image <path>\n"
                    "\n";
                    printf("%s", help_message);
                    print_all_labels();
                    printf("\nAvailable Frequencies:\n"
                           "    +48000 (DVD)\n"
                           "    +41000 (CD)\n"
                           "    +22050 (mp3)\n"
                           "    +11025 (tape)\n"
                           "    +8000  (8-bit) default\n");
                    return 0;
                } else {
                    session.sound.cb = find_callback_by_label(&(argv[i][1]));
                    if (session.sound.cb == NULL) {
                        fprintf(stderr, "Don't know what %s is.\n", argv[i]);
                        return 1;
                    }
                }
            }
        }
    }

    signal(SIGINT, stop_loop);
    signal(SIGTERM, stop_loop);
    
    if (session.image.path != NULL) {
        generate_image(&session);
    } else {
        generate_sound(&session);
    }

    return 0;
}
