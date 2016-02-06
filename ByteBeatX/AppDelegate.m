//
//  AppDelegate.m
//  ByteBeatX
//
//  Created by Eric McConville on 2/5/16.
//  Copyright © 2016 Eric McConville. All rights reserved.
//

#import "AppDelegate.h"

@interface AppDelegate ()

@property (weak) IBOutlet NSWindow *window;
@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Insert code here to initialize your application
}

- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}

- (BOOL) applicationShouldTerminateAfterLastWindowClosed: (NSApplication *) theApplication
{
    return YES; // Do it now!
}

@end
