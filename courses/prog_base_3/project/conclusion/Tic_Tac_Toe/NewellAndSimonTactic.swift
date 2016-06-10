//
//  NewellAndSimonTactic.swift
//  TicTacToe
//
//  Created by Alexandra on 10.05.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//


import Foundation

/** Represents a single aspect of Newell and Simon's Tic-tac-toe strategy. */
protocol NewellAndSimonTactic {
    func choosePositionForMark(mark: Mark, onGameBoard gameBoard: GameBoard) -> GameBoard.Position?
}
