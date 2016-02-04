/* Standard */
#include <stdlib.h>
/* Apple */
#import <CoreServices/CoreServices.h>
#import <CoreGraphics/CoreGraphics.h>
#import <ImageIO/ImageIO.h>
/* Me */
#include "image_io.h"


void image_startup(session_t * session)
{
    size_t
    w = session->image.width,
    h = session->image.height,
    limit = w * h;
    uint8_t * pixels = calloc(limit, sizeof(uint8_t));
    int cursor;
    for(cursor = 0;cursor<limit;cursor++) {
        pixels[cursor] = session->sound.cb(cursor);
    }
    CFDataRef blob = CFDataCreate(NULL, pixels, limit * sizeof(uint8_t));
    CGDataProviderRef provider = CGDataProviderCreateWithCFData(blob);
    CGColorSpaceRef gray = CGColorSpaceCreateDeviceGray();
    CGImageRef image = CGImageCreate(
                                     w, h,
                                     4, 4, w,
                                     gray, kCGBitmapByteOrderDefault|kCGImageAlphaNone,
                                     provider, NULL,
                                     false, kCGRenderingIntentDefault);
    CFStringRef path = CFStringCreateWithCString(NULL, session->image.path, kCFStringEncodingUTF8);
    CFURLRef url = CFURLCreateWithFileSystemPathRelativeToBase(NULL, path, kCFURLPOSIXPathStyle, false, NULL);
    CGImageDestinationRef destination =  CGImageDestinationCreateWithURL(url, session->image.format, 1, NULL);
    CGImageDestinationAddImage(destination, image, NULL);
    CGImageDestinationFinalize(destination);
    CFRelease(url);
    CFRelease(path);
    CFRelease(destination);
    CGImageRelease(image);
    CGColorSpaceRelease(gray);
    CGDataProviderRelease(provider);
    CFRelease(blob);
    free(pixels);

}
void image_teardown(){}