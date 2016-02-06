//
//  ImageView.h
//  ByteBuff2
//
//  Created by Eric McConville on 2/5/16.
//  Copyright © 2016 Eric McConville. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#include "byte_buff.h"
@interface ImageView : NSImageView {
    byte_beat callback;
}
- (void)setProgram:(byte_beat)cb;
- (void)syncImageToProgram;
@end
