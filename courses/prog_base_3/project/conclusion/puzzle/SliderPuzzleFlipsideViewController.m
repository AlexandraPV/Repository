//
//  SliderPuzzleFlipsideViewController.m
//  Slider Puzzle
//
//  Created by Alexandra on 21.05.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//

#import "SliderPuzzleFlipsideViewController.h"

@implementation SliderPuzzleFlipsideViewController

@synthesize delegate = _delegate;
@synthesize Refresh;
@synthesize PuzzlePicture;
@synthesize CountMoves;
@synthesize Timer;
@synthesize PuzzleLayoutX;
@synthesize PuzzleLayoutY; 

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view
    NSUserDefaults *prefs = [NSUserDefaults standardUserDefaults];
    
    switch ([prefs integerForKey:@"PuzzlePicture"]) {
        case 0:
            PuzzlePicture.selectedSegmentIndex = 0;
            break;
        case 1:
            PuzzlePicture.selectedSegmentIndex = 1;
            break;
        case 2:
            PuzzlePicture.selectedSegmentIndex = 2;
            break;
        case 3:
            PuzzlePicture.selectedSegmentIndex = 3;
            break;
        default:
            break;
    }
    
    if ([prefs boolForKey:@"CountMoves"] == TRUE) {
        CountMoves.on = TRUE;
    } else {
        CountMoves.on = FALSE;
    }
    
    if ([prefs boolForKey:@"Timer"] == TRUE) {
        Timer.on = TRUE;
    } else {
        Timer.on = FALSE;
    }
    
    switch ([prefs integerForKey:@"PuzzleLayoutX"]) {
        case 0:
            PuzzleLayoutX.selectedSegmentIndex = 0;
            break;
        case 1:
            PuzzleLayoutX.selectedSegmentIndex = 1;
            break;
        case 2:
            PuzzleLayoutX.selectedSegmentIndex = 2;
            break;
        case 3:
            PuzzleLayoutX.selectedSegmentIndex = 3;
            break;
        default:
            break;
    }
    
    switch ([prefs integerForKey:@"PuzzleLayoutY"]) {
        case 0:
            PuzzleLayoutY.selectedSegmentIndex = 0;
            break;
        case 1:
            PuzzleLayoutY.selectedSegmentIndex = 1;
            break;
        case 2:
            PuzzleLayoutY.selectedSegmentIndex = 2;
            break;
        case 3:
            PuzzleLayoutY.selectedSegmentIndex = 3;
            break;
        default:
            break;
    }
}

#pragma mark - Actions

- (IBAction)done:(id)sender
{
    [self.delegate flipsideViewControllerDidFinish:self];
}

- (IBAction)Refreshed:(id)sender {
    NSUserDefaults *prefs = [NSUserDefaults standardUserDefaults];
    [prefs setBool:TRUE forKey:@"Refresh"];
}

- (IBAction)PuzzlePictured:(id)sender {
    NSUserDefaults *prefs = [NSUserDefaults standardUserDefaults];
    switch (PuzzlePicture.selectedSegmentIndex) {
        case 0:
            [prefs setInteger:0 forKey:@"PuzzlePicture"];
            break;
        case 1:
            [prefs setInteger:1 forKey:@"PuzzlePicture"];
            break;
        case 2:
            [prefs setInteger:2 forKey:@"PuzzlePicture"];
            break;
        case 3:
            [prefs setInteger:3 forKey:@"PuzzlePicture"];
            break;
        default:
            break;
    }
}

- (IBAction)CountMoved:(id)sender {
    NSUserDefaults *prefs = [NSUserDefaults standardUserDefaults];
    if (CountMoves.on == TRUE) {
        [prefs setBool:TRUE forKey:@"CountMoves"];
    } else {
        [prefs setBool:FALSE forKey:@"CountMoves"];
    }
}

- (IBAction)Timered:(id)sender {
    NSUserDefaults *prefs = [NSUserDefaults standardUserDefaults];
    if (Timer.on == TRUE) {
        [prefs setBool:TRUE forKey:@"Timer"];
    } else {
        [prefs setBool:FALSE forKey:@"Timer"];
    }
}

- (IBAction)PuzzleLayoutedX:(id)sender {
    NSUserDefaults *prefs = [NSUserDefaults standardUserDefaults];
    switch (PuzzleLayoutX.selectedSegmentIndex) {
        case 0:
            [prefs setInteger:0 forKey:@"PuzzleLayoutX"];
            break;
        case 1:
            [prefs setInteger:1 forKey:@"PuzzleLayoutX"];
            break;
        case 2:
            [prefs setInteger:2 forKey:@"PuzzleLayoutX"];
            break;
        case 3:
            [prefs setInteger:3 forKey:@"PuzzleLayoutX"];
            break;
        default:
            break;
    }
}

- (IBAction)PuzzleLayoutedY:(id)sender {
    NSUserDefaults *prefs = [NSUserDefaults standardUserDefaults];
    switch (PuzzleLayoutY.selectedSegmentIndex) {
        case 0:
            [prefs setInteger:0 forKey:@"PuzzleLayoutY"];
            break;
        case 1:
            [prefs setInteger:1 forKey:@"PuzzleLayoutY"];
            break;
        case 2:
            [prefs setInteger:2 forKey:@"PuzzleLayoutY"];
            break;
        case 3:
            [prefs setInteger:3 forKey:@"PuzzleLayoutY"];
            break;
        default:
            break;
    }
    
}

- (void)viewDidUnload
{
    [Refresh release];
    Refresh = nil;
    [self setRefresh:nil];
    [PuzzlePicture release];
    PuzzlePicture = nil;
    [self setPuzzlePicture:nil];
    [CountMoves release];
    CountMoves = nil;
    [self setCountMoves:nil];
    [Timer release];
    Timer = nil;
    [self setTimer:nil];
    [PuzzleLayoutX release];
    PuzzleLayoutX = nil;
    [self setPuzzleLayoutX:nil];
    [PuzzleLayoutY release];
    PuzzleLayoutY = nil;
    [self setPuzzleLayoutY:nil];
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
	[super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated
{
	[super viewDidDisappear:animated];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
}

- (void)dealloc {
    [Refresh release];
    [PuzzlePicture release];
    [CountMoves release];
    [Timer release];
    [PuzzleLayoutX release];
    [PuzzleLayoutY release];
    [super dealloc];
}

@end
