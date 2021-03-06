//
//  ViewController.swift
//  Tic Tac Toe
//
//  Created by Alexandra on 30.05.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet var ticTacImg1: UIImageView!
    @IBOutlet var ticTacImg2: UIImageView!
    @IBOutlet var ticTacImg3: UIImageView!
    @IBOutlet var ticTacImg4: UIImageView!
    @IBOutlet var ticTacImg5: UIImageView!
    @IBOutlet var ticTacImg6: UIImageView!
    @IBOutlet var ticTacImg7: UIImageView!
    @IBOutlet var ticTacImg8: UIImageView!
    @IBOutlet var ticTacImg9: UIImageView!
    
    @IBOutlet var ticTacBtn1: UIButton!
    @IBOutlet var ticTacBtn2: UIButton!
    @IBOutlet var ticTacBtn3: UIButton!
    @IBOutlet var ticTacBtn4: UIButton!
    @IBOutlet var ticTacBtn5: UIButton!
    @IBOutlet var ticTacBtn6: UIButton!
    @IBOutlet var ticTacBtn7: UIButton!
    @IBOutlet var ticTacBtn8: UIButton!
    @IBOutlet var ticTacBtn9: UIButton!
   
    @IBOutlet var resetBtn: UIButton!
    @IBOutlet var userMessage: UILabel!
    
    var plays = Dictionary<Int, Int>()
    var done = false
    var aiDeciding = false
    
    
    
    @IBAction func UIButtonClicked (sender: UIButton){
        userMessage.hidden = true
        //if !plays[sender.tag] && !aiDeciding && !done{
            setImageForSpot(sender.tag, player:1)
       // }
        checkForWin()
        aiTurn()
    }
    
    func setImageForSpot(spot:Int,player:Int){
        var playerMark = player == 1 ? "x" : "o"
        plays[spot] = player
        switch spot {
        case 1:
            ticTacImg1.image = UIImage(named: playerMark)
        case 1:
            ticTacImg2.image = UIImage(named: playerMark)
        case 1:
            ticTacImg3.image = UIImage(named: playerMark)
        case 1:
            ticTacImg4.image = UIImage(named: playerMark)
        case 1:
            ticTacImg5.image = UIImage(named: playerMark)
        case 1:
            ticTacImg6.image = UIImage(named: playerMark)
        case 1:
            ticTacImg7.image = UIImage(named: playerMark)
        case 1:
            ticTacImg8.image = UIImage(named: playerMark)
        case 1:
            ticTacImg9.image = UIImage(named: playerMark)
        default:
            ticTacImg5.image = UIImage(named: playerMark)
        }
    }
    
    
    @IBAction func resetBtnClicked(sender:UIButton){
        done = false
        resetBtn.hidden = true
        userMessage.hidden = true
        reset()
    }
    
    func reset(){
        plays = [:]
        ticTacImg1.image = nil
        ticTacImg2.image = nil
        ticTacImg3.image = nil
        ticTacImg4.image = nil
        ticTacImg5.image = nil
        ticTacImg6.image = nil
        ticTacImg7.image = nil
        ticTacImg8.image = nil
        ticTacImg9.image = nil
    }
    
    func checkForWin(){
        var whoWon = ["I" :0 , "you" : 1]
        for(key,value) in whoWon{
            if (plays[7] == value && plays[8] == value && plays[9] == value) ||
            (plays[4] == value && plays[5] == value && plays[6] == value) ||
            (plays[1] == value && plays[2] == value && plays[3] == value) ||
            (plays[1] == value && plays[4] == value && plays[7] == value) ||
            (plays[1] == value && plays[5] == value && plays[8] == value) ||
            (plays[1] == value && plays[5] == value && plays[9] == value) ||
            (plays[3] == value && plays[6] == value && plays[9] == value) ||
            (plays[3] == value && plays[5] == value && plays[7] == value){
                self.userMessage.hidden = false
                self.userMessage.text = "Looks like \(key) won!"
                self.resetBtn.hidden = false
                self.done = true
            }
        }
    }
    
    func checkFor(value:Int, inList:Int[]) -> String {
        var conclusion = ""
        for cell in inList {
            if plays[cell] == value {
                conclusion += "1"
            }else{
                conclusion += "0"
                
            }
        }
        return conclusion
    }
    
    func checkButtom(#value :Int)-> (location :String, pattern: String){
        return ("bottom",checkFor(value, inList:[7, 8, 9]))
    }
    
    func checkRight(#value :Int)-> (location :String, pattern: String){
        return ("bottom",checkFor(value, inList:[3, 6, 9]))
    }
    
    func checkMiddleAcross(#value :Int)-> (location :String, pattern: String){
        return ("bottom",checkFor(value, inList:[4, 5, 6]))
    }
    func checkMiddleDown(#value :Int)-> (location :String, pattern: String){
        return ("bottom",checkFor(value, inList:[2, 5, 8]))
    }
    func checkDiagLeftRight(#value :Int)-> (location :String, pattern: String){
        return ("bottom",checkFor(value, inList:[3, 5, 7]))
    }
    func checkTop(#value :Int)-> (location :String, pattern: String){
        return ("bottom",checkFor(value, inList:[1, 2, 3]))
    }
    func checkLeft(#value :Int)-> (location :String, pattern: String){
        return ("bottom",checkFor(value, inList:[1, 4, 7]))
    }
    func checkDiagRightLeft(#value :Int)-> (location :String, pattern: String){
        return ("bottom",checkFor(value, inList:[1, 5, 9]))
    }
    
    
    
    func rowCheck(#value:Int) -> (location :String, pattern :String)?{
    var acceptableFinds = ["011","110","101"]
    var findFuncs = [checkTop, checkButtom, checkRight, checkMiddleAcross, checkMiddleDown, checkDiagLeftRight, checkDiagRightLeft]
    for  algorthm in findFuncs{
    var algorthmResults = algorthm(value:value)
        if find(acceptableFinds, algorthmResults.pattern){
        return algorthmResults
        }
    }
    }
    
    func aiTurn(){
        if done(){
            return
        }
        aiDeciding = true     //computer two in a row
        if let result = rowCheck(value:0){
            var whereToPlayResult = whereToPlay(result.location, pattern)
        }
        
        
        aiDeciding = false
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

