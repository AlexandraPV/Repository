//
//  Player.swift
//  TicTacToe
//
//  Created by Alexandra on 10.05.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//


import Foundation

/** Represents a Tic-tac-toe contestant, either human or computer. */
internal final class Player {
    
    init(mark: Mark, gameBoard: GameBoard, strategy: TicTacToeStrategy) {
        self.mark = mark
        self.gameBoard = gameBoard
        self.strategy = strategy
    }
    
    let mark: Mark
    
    func choosePositionWithCompletionHandler(completionHandler: GameBoard.Position -> Void) {
        strategy.choosePositionForMark(mark, onGameBoard: gameBoard, completionHandler: completionHandler)
    }

    private let gameBoard: GameBoard
    private let strategy: TicTacToeStrategy
}
