

import UIKit

class FollowDevView: UIViewController
{
    @IBAction func followButtonDidPress(sender: AnyObject) {
        UIApplication.sharedApplication().openURL(NSURL(string:"")!)
            self.dismissViewControllerAnimated(true, completion: nil)
    } 
}