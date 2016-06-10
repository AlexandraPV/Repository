//
//  TicTacToeStrategy.swift
//  TicTacToe
//
//  Created by Alexandra on 10.05.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//


import Foundation

/** Describes an object capable of deciding where to put the next mark on a GameBoard. */
public protocol TicTacToeStrategy {
    func choosePositionForMark(mark: Mark, onGameBoard gameBoard: GameBoard, completionHandler: GameBoard.Position -> Void)
}

public func createArtificialIntelligenceStrategy() -> TicTacToeStrategy {
    return NewellAndSimonStrategy()
}
