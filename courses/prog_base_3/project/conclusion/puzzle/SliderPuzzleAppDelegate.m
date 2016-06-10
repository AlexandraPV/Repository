//
//  SliderPuzzleAppDelegate.m
//  Slider Puzzle
//
//  Created by Alexandra on 21.05.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//

#import "SliderPuzzleAppDelegate.h"

#import "SliderPuzzleMainViewController.h"

@implementation SliderPuzzleAppDelegate

@synthesize window = _window;
@synthesize mainViewController = _mainViewController;

- (void)dealloc
{
    [_window release];
    [_mainViewController release];
    [super dealloc];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    NSUserDefaults *prefs = [NSUserDefaults standardUserDefaults];
    
    if ([prefs objectForKey:@"PuzzlePicture"] == nil) {
        [prefs setBool:FALSE forKey:@"Refresh"];
        [prefs setInteger:0 forKey:@"PuzzlePicture"];
        [prefs setBool:TRUE forKey:@"CountMoves"];
        [prefs setBool:TRUE forKey:@"Timer"];
        [prefs setInteger:1 forKey:@"PuzzleLayoutX"];
        [prefs setInteger:1 forKey:@"PuzzleLayoutY"];
    }
    
    self.window = [[[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]] autorelease];
    // Override point for customization after application launch.
    self.mainViewController = [[[SliderPuzzleMainViewController alloc] initWithNibName:@"SliderPuzzleMainViewController" bundle:nil] autorelease];
    self.window.rootViewController = self.mainViewController;
    [self.window makeKeyAndVisible];
    return YES;
}



@end
