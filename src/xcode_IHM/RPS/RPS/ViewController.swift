//
//  ViewController.swift
//  RPS
//
//  Created by guillermo pita on 09/08/2020.
//  Copyright © 2020 guillermo pita. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    //Adding the background image object
    
    let backgroundImageView = UIImageView()
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        //Set The background
        setBackground()
    }
    func setBackground(){
        view.addSubview(backgroundImageView)
        backgroundImageView.translatesAutoresizingMaskIntoConstraints = false
        backgroundImageView.topAnchor.constraint(equalTo: view.topAnchor).isActive = true
        backgroundImageView.bottomAnchor.constraint(equalTo: view.bottomAnchor).isActive = true
        backgroundImageView.leadingAnchor.constraint(equalTo: view.leadingAnchor).isActive = true
        backgroundImageView.trailingAnchor.constraint(equalTo: view.trailingAnchor).isActive = true
        backgroundImageView.image = UIImage(named: "ocean4")
        view.sendSubviewToBack(backgroundImageView)
    }
}

