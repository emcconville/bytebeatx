//
//  ViewController.m
//  ByteBuff2
//
//  Created by Eric McConville on 2/5/16.
//  Copyright © 2016 Eric McConville. All rights reserved.
//

#import "ViewController.h"
#include "bytebeat.h"

@interface ViewController ()

@end

@implementation ViewController
@synthesize programs, frequencies, toggleButton, imageView;

- (void)viewDidLoad {
    [super viewDidLoad];

    // Populate select values
    session.sound.sampleRate = 8000.0;
    session.sound.cursor = 0;
    catalog = get_catalog();
    size_t i = 0;
    [programs removeAllItems];
    while(catalog[i].label) {
        NSString * text = [NSString stringWithFormat:@"%s by %s", catalog[i].label, catalog[i].author];
        NSComboBoxCell * cell = [[NSComboBoxCell alloc] initTextCell:text];
        [[self programs] addItemWithObjectValue:cell];
        i++;
    }
    // Set default select values
    [programs selectItemAtIndex:0];
    [self selectProgram:nil];
    [frequencies selectItemAtIndex:0];
    [self selectFrequency:nil];
    // Set play button to "off" state
    [toggleButton setTitle:@"Play"];
    [toggleButton setTag:0];
    // Set-up First image preview
}

-(IBAction)selectProgram:(id)sender
{
    session.sound.cursor = 0;
    size_t i = [programs indexOfSelectedItem];
    session.sound.cb = catalog[i].callback;
    [self restartSound];
    [imageView setProgram:session.sound.cb];
    [imageView syncImageToProgram];
}

-(IBAction)selectFrequency:(id)sender
{
    NSInteger i = [frequencies indexOfSelectedItem];
    switch (i) {
        case 1 : session.sound.sampleRate = 11025.0; break;
        case 2 : session.sound.sampleRate = 22050.0; break;
        case 3 : session.sound.sampleRate = 44100.0; break;
        case 4 : session.sound.sampleRate = 48000.0; break;
        case 0 :
        default: session.sound.sampleRate =  8000.0; break;
    }
    [self restartSound];
}

-(IBAction)togglePlay:(id)sender
{
    NSButton * button = sender;
    if ( [button tag] == 0 ) {
        [self startSound];
    } else {
        [self stopSound];
    }
    
}

-(void)startSound
{
    [toggleButton setTag:1];
    audio_startup(&unit, &session);
    [toggleButton setTitle:@"Pause"];
}
-(void)stopSound
{
    [toggleButton setTag:0];
    audio_teardown(&unit);
    [toggleButton setTitle:@"Play"];
}

-(void)restartSound
{
    if ([toggleButton tag] == 1) {
        [self stopSound];
        [self startSound];
    }
}

@end
