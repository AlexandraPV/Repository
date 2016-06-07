#import "SliderPuzzleMainViewController.h"

#define TILE_SPACING    4
#define SHUFFLE_NUMBER	100

@implementation SliderPuzzleMainViewController

@synthesize tiles, tileImageView;

int NUM_HORIZONTAL_PIECES = 3;
int NUM_VERTICAL_PIECES = 3;
int countmove = 0;
int thetime = 0;

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{  
    NSUserDefaults *prefs = [NSUserDefaults standardUserDefaults];
    
    self.tiles = [[NSMutableArray alloc] init];
	
	NSString *Pic = [NSString stringWithFormat:@"picture%d.png", [prefs integerForKey:@"PuzzlePicture"]];
    [self initPuzzle:Pic];
    
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

/**
 * take an image path, load the image and break it into tiles to use as our puzzle pieces. 
 **/ 
-(void) initPuzzle:(NSString *) imagePath{
    NSUserDefaults *prefs = [NSUserDefaults standardUserDefaults];
	UIImage *orgImage = [UIImage imageNamed:imagePath];
	
	if( orgImage == nil ){
		return; 
	}
    
    if (tileImageView != nil && [prefs boolForKey:@"Refresh"] == TRUE) {
        for (tileImageView in tiles) {
            [tileImageView removeFromSuperview];
        }
    }
	
	[self.tiles removeAllObjects];
	
	tileWidth = orgImage.size.width/NUM_HORIZONTAL_PIECES;
	tileHeight = orgImage.size.height/NUM_VERTICAL_PIECES;
	
	blankPosition = CGPointMake( NUM_HORIZONTAL_PIECES-1, NUM_VERTICAL_PIECES-1 );
	
	for( int x=0; x<NUM_HORIZONTAL_PIECES; x++ ){
		for( int y=0; y<NUM_VERTICAL_PIECES; y++ ){
			CGPoint orgPosition = CGPointMake(x,y); 
			
			if( blankPosition.x == orgPosition.x && blankPosition.y == orgPosition.y ){
				continue; 
			}
			
			CGRect frame = CGRectMake(tileWidth*x, tileHeight*y, 
									  tileWidth, tileHeight );
			CGImageRef tileImageRef = CGImageCreateWithImageInRect( orgImage.CGImage, frame );
			UIImage *tileImage = [UIImage imageWithCGImage:tileImageRef];
			
			CGRect tileFrame =  CGRectMake((tileWidth+TILE_SPACING)*x, (tileHeight+TILE_SPACING)*y, 
										   tileWidth, tileHeight );
			
			tileImageView = [[Tile alloc] initWithImage:tileImage];
			tileImageView.frame = tileFrame;
			tileImageView.originalPosition = orgPosition;
			tileImageView.currentPosition = orgPosition;
            
			CGImageRelease( tileImageRef );
			
			[tiles addObject:tileImageView];
			
			// now add to view
			[self.view insertSubview:tileImageView atIndex:0];
			[tileImageView release];
		}
	}
	
	[self shuffle];
}

#pragma mark tile handling methods 

-(ShuffleMove) validMove:(Tile *) tile{
	// blank spot above current piece 
	if( tile.currentPosition.x == blankPosition.x && tile.currentPosition.y == blankPosition.y+1 ){
		return UP; 
	}
	
	// bank splot below current piece
	if( tile.currentPosition.x == blankPosition.x && tile.currentPosition.y == blankPosition.y-1 ){
		return DOWN; 
	}
	
	// bank spot left of the current piece
	if( tile.currentPosition.x == blankPosition.x+1 && tile.currentPosition.y == blankPosition.y ){
		return LEFT; 
	}
	
	// bank spot right of the current piece
	if( tile.currentPosition.x == blankPosition.x-1 && tile.currentPosition.y == blankPosition.y ){
		return RIGHT; 
	}
	
	return NONE;
}

-(void) movePiece:(Tile *) tile withAnimation:(BOOL) animate{
	switch ( [self validMove:tile] ) {
		case UP:
			[self movePiece:tile 
			   inDirectionX:0 inDirectionY:-1 withAnimation:animate];
			break;
		case DOWN:
			[self movePiece:tile 
			   inDirectionX:0 inDirectionY:1 withAnimation:animate];
			break;
		case LEFT:
			[self movePiece:tile 
			   inDirectionX:-1 inDirectionY:0 withAnimation:animate];
			break;
		case RIGHT:
			[self movePiece:tile 
			   inDirectionX:1 inDirectionY:0 withAnimation:animate];
			break;
		default:
			break;
	}
}

-(void) movePiece:(Tile *) tile inDirectionX:(NSInteger) dx inDirectionY:(NSInteger) dy withAnimation:(BOOL) animate{
	tile.currentPosition = CGPointMake( tile.currentPosition.x+dx, 
                                       tile.currentPosition.y+dy); 
	blankPosition = CGPointMake( blankPosition.x-dx, blankPosition.y-dy );
	
	int x = tile.currentPosition.x; 
	int y = tile.currentPosition.y;
	
	if( animate ){
		[UIView beginAnimations:@"frame" context:nil];
	}
	tile.frame = CGRectMake((tileWidth+TILE_SPACING)*x, (tileHeight+TILE_SPACING)*y, 
                            tileWidth, tileHeight );
	if( animate ){
		[UIView commitAnimations];
	}
}

-(void) shuffle{
	NSMutableArray *validMoves = [[NSMutableArray alloc] init];
	
	srandom(time(NULL));
	
	for( int i=0; i<SHUFFLE_NUMBER; i++ ){
		[validMoves removeAllObjects];
		
		// get all of the pieces that can move 
		for( Tile *t in tiles ){
			if( [self validMove:t] != NONE ){
				[validMoves addObject:t];
			}
		}
		
		// randomly select a piece to move 
		NSInteger pick = random()%[validMoves count];
		//NSLog(@"shuffleRandom using pick: %d from array of size %d", pick, [validMoves count]);
		[self movePiece:(Tile *)[validMoves objectAtIndex:pick] withAnimation:NO];
	}
	
	[validMoves release];
}


#pragma mark helper methods 
-(Tile *) getPieceAtPoint:(CGPoint) point{
	CGRect touchRect = CGRectMake(point.x, point.y, 1.0, 1.0);
	
	for( Tile *t in tiles ){
		if( CGRectIntersectsRect(t.frame, touchRect) ){
			return t; 
		}		
	}
	return nil;
}

-(BOOL) puzzleCompleted{
	for( Tile *t in tiles ){
		if( t.originalPosition.x != t.currentPosition.x || t.originalPosition.y != t.currentPosition.y ){
			return NO;
		}
	}
	
	return YES;
}

#pragma mark user input hanlding 

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
	NSUserDefaults *prefs = [NSUserDefaults standardUserDefaults];
	UITouch *touch = [touches anyObject];
    CGPoint currentTouch = [touch locationInView:self.view];	
	
	Tile *t = [self getPieceAtPoint:currentTouch];
	if( t != nil ){
        //Start the game timer
        if (timer == nil && [prefs boolForKey:@"Timer"] == TRUE) {
            timer = [NSTimer scheduledTimerWithTimeInterval:1.0 target:self selector:@selector(onTimer) userInfo:nil repeats:YES];
        }
        //Move the pieces
		[self movePiece:t withAnimation:YES];
        //Count the moves
        if ([prefs boolForKey:@"CountMoves"] == TRUE) {
            countmove++;
        }
		if( [self puzzleCompleted] ){
            NSString *Winning;
            if ([prefs boolForKey:@"CountMoves"] == TRUE && [prefs boolForKey:@"Timer"] == TRUE) {
                Winning = [NSString stringWithFormat:@"It took you: %i Moves in %i Seconds!", countmove, thetime];
            } else if ([prefs boolForKey:@"CountMoves"] == TRUE && [prefs boolForKey:@"Timer"] == FALSE) {
                Winning = [NSString stringWithFormat:@"It took you: %i Moves", countmove];
            } else if ([prefs boolForKey:@"CountMoves"] == FALSE && [prefs boolForKey:@"Timer"] == FALSE) {
                Winning = [NSString stringWithFormat:@"Great Job!"];
            } else if ([prefs boolForKey:@"CountMoves"] == FALSE && [prefs boolForKey:@"Timer"] == TRUE) {
                Winning = [NSString stringWithFormat:@"It took you: %i Seconds", thetime];
            }
            
            UIAlertView *message = [[UIAlertView alloc] initWithTitle:@"You Won!"
                                                              message:Winning
                                                             delegate:nil
                                                    cancelButtonTitle:@"OK"
                                                    otherButtonTitles:nil];
            
            [message show];
            [message release];
            countmove = 0;
            thetime = 0;
            if (timer != nil) {
                [timer invalidate];
                timer = nil;
            }
		}
	}
}

- (void)onTimer {
    thetime++;
}

- (void)dealloc {
	[tiles release];
    [tileImageView release];
    [super dealloc];
}

#pragma mark view prperties

- (void)viewDidUnload
{
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

#pragma mark - Flipside View

- (void)flipsideViewControllerDidFinish:(SliderPuzzleFlipsideViewController *)controller
{
    [self dismissModalViewControllerAnimated:YES];
    
    NSUserDefaults *prefs = [NSUserDefaults standardUserDefaults];
    
    //Perform Settings Changes to the Main View
    switch ([prefs integerForKey:@"PuzzleLayoutX"]) {
        case 0:
            NUM_HORIZONTAL_PIECES = 2;
            break;
        case 1:
            NUM_HORIZONTAL_PIECES = 3;
            break;
        case 2:
            NUM_HORIZONTAL_PIECES = 4;
            break;
        case 3:
            NUM_HORIZONTAL_PIECES = 5;
            break;
        default:
            break;
    }
    
    switch ([prefs integerForKey:@"PuzzleLayoutY"]) {
        case 0:
            NUM_VERTICAL_PIECES = 2;
            break;
        case 1:
            NUM_VERTICAL_PIECES = 3;
            break;
        case 2:
            NUM_VERTICAL_PIECES = 4;
            break;
        case 3:
            NUM_VERTICAL_PIECES = 5;
            break;
        default:
            break;
    }
    
    if ([prefs boolForKey:@"Refresh"] == TRUE) {
        countmove = 0;
        thetime = 0;
        if (timer != nil) {
            [timer invalidate];
            timer = nil;
        }
        NSString *Pic = [NSString stringWithFormat:@"picture%d.png", [prefs integerForKey:@"PuzzlePicture"]];
        [self initPuzzle:Pic];
    }
}

- (IBAction)showInfo:(id)sender
{    
    SliderPuzzleFlipsideViewController *controller = [[[SliderPuzzleFlipsideViewController alloc] initWithNibName:@"SliderPuzzleFlipsideViewController" bundle:nil] autorelease];
    controller.delegate = self;
    controller.modalTransitionStyle = UIModalTransitionStyleFlipHorizontal;
    [self presentModalViewController:controller animated:YES];
}

@end