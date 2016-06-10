//
//  BlockTactic.swift
//  TicTacToe
//
//  Created by Alexandra on 10.05.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//

import Foundation

/**
 Tactic #2 in Newell and Simon's strategy.
 If the opponent can play one mark to win, returns the position to block/occupy.
 */
struct BlockTactic: NewellAndSimonTactic {
    
    func choosePositionForMark(mark: Mark, onGameBoard gameBoard: GameBoard) -> GameBoard.Position? {
        return WinTactic().choosePositionForMark(mark.opponentMark(), onGameBoard: gameBoard)
    }
}
