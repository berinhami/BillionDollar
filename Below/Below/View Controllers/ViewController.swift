//
//  ViewController.swift
//  Below
//
//  Created by Selena Montoya on 5/10/22.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
    
    }
    @IBAction func navButtons(){
        
        let vc = storyboard?.instantiateViewController(withIdentifier: "high_bac") as! BacViewController
        present( vc, animated: true)
    }

}



