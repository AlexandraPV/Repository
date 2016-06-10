//
//  SliderPuzzleMainViewController.h
//  Slider Puzzle
//
//  Created by Alexandra on 21.05.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//

#import "SliderPuzzleFlipsideViewController.h"
#import "Tile.h"

typedef enum {
	NONE			= 0,
	UP				= 1,
	DOWN			= 2, 
	LEFT			= 3,
	RIGHT			= 4
} ShuffleMove;

@interface SliderPuzzleMainViewController : UIViewController <SliderPuzzleFlipsideViewControllerDelegate> {
    CGFloat tileWidth; 
	CGFloat tileHeight;
	
	NSMutableArray *tiles; 
	CGPoint blankPosition; 
    
    NSTimer *timer;
    
    Tile *tileImageView;
}

- (IBAction)showInfo:(id)sender;

@property (nonatomic,retain) NSMutableArray *tiles; 
@property (nonatomic,retain) Tile *tileImageView;

-(void) initPuzzle:(NSString *) imagePath;

-(ShuffleMove) validMove:(Tile *) tile;
-(void) movePiece:(Tile *) tile withAnimation:(BOOL) animate;
-(void) movePiece:(Tile *) tile inDirectionX:(NSInteger) dx inDirectionY:(NSInteger) dy withAnimation:(BOOL) animate;
-(void) shuffle;

-(Tile *) getPieceAtPoint:(CGPoint) point;
-(BOOL) puzzleCompleted;

@end
