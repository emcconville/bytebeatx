//
//  ViewController.h
//  ByteBuff2
//
//  Created by Eric McConville on 2/5/16.
//  Copyright © 2016 Eric McConville. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <AudioToolbox/AudioToolbox.h>
#import "ImageView.h"
#include "byte_buff.h"
#include "beats.h"

@interface ViewController : NSViewController {
    session_t session;
    AudioUnit unit;
    audio_beat_t * catalog;
}
@property (weak, nonatomic) IBOutlet NSPopUpButton * programs;
@property (weak, nonatomic) IBOutlet NSPopUpButton * frequencies;
@property (weak, nonatomic) IBOutlet NSButton * toggleButton;
@property (weak, nonatomic) IBOutlet ImageView * imageView;
-(IBAction)selectProgram:(id)sender;
-(IBAction)selectFrequency:(id)sender;
-(IBAction)togglePlay:(id)sender;
@end
