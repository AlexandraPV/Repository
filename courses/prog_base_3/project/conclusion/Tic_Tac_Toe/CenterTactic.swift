//
//  CenterTactic.swift
//  TicTacToe
//
//  Created by Alexandra on 10.05.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//


import Foundation

/**
 Tactic #5 in Newell and Simon's strategy.
 If the center position is empty, returns the center position.
 */
struct CenterTactic: NewellAndSimonTactic {
    
    func choosePositionForMark(mark: Mark, onGameBoard gameBoard: GameBoard) -> GameBoard.Position? {
        assert(gameBoard.dimension == 3)
        
        let center = GameBoard.Position(row: 1, column: 1)
        return gameBoard.isEmptyAtPosition(center) ? center : nil
    }
}
