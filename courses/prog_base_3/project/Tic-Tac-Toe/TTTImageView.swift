//
//  TTTImageView.swift
//  rdtyuh
//
//  Created by Alexandra on 15.05.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//

import Cocoa

class TTTImageView: UIImageView {

    var player: String?
    var activated: Bool! = false
    
    func setPlayer(_payer:String)  {
        self.player = _payer
        
        if activated == false{
            if _player = "X"{
                self.image = UIImage( named: "X")
            }else {
                self.image = UIImage( named: "O")
            }
            activated = true 
    }
}
