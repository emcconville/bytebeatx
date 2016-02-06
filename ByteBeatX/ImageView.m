//
//  ImageView.m
//  ByteBuff2
//
//  Created by Eric McConville on 2/5/16.
//  Copyright © 2016 Eric McConville. All rights reserved.
//

#import "ImageView.h"

@implementation ImageView

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    if ([self inLiveResize]) {
        [self syncImageToProgram];
    } else {
        //[self syncImageToProgram];
    }
}

- (void)setProgram:(byte_beat)cb
{
    callback = cb;
}
- (void)syncImageToProgram
{
    if (callback == NULL) {
        return; // Safety first
    }
    NSRect extent = [self bounds];
    size_t
        w = extent.size.width,
        h = extent.size.height,
    limit = w * h;
    uint8_t * pixels = calloc(limit, sizeof(uint8_t));
    int cursor;
    for(cursor = 0;cursor<limit;cursor++) {
        pixels[cursor] = callback(cursor);
    }
    CFDataRef blob = CFDataCreate(NULL, pixels, limit * sizeof(uint8_t));
    CGDataProviderRef provider = CGDataProviderCreateWithCFData(blob);
    CGColorSpaceRef gray = CGColorSpaceCreateDeviceGray();
    CGImageRef image = CGImageCreate(
                                     w, h,
                                     8, 8, w,
                                     gray, kCGBitmapByteOrderDefault|kCGImageAlphaNone,
                                     provider, NULL,
                                     false, kCGRenderingIntentDefault);

    NSImage * yai = [[NSImage alloc] initWithCGImage:image size:extent.size];
    [self setImage:yai];
    CGImageRelease(image);
    CGColorSpaceRelease(gray);
    CGDataProviderRelease(provider);
    CFRelease(blob);
    free(pixels);
}

@end
