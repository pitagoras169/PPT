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
    
    //Text for label that shows the score of the machine
    @IBOutlet weak var machine_score_label: UILabel!
    //Text to display who won
    @IBOutlet weak var current_winner: UILabel!
    //Text for label that shows the score of the human
    @IBOutlet weak var human_score_label: UILabel!
    
    @IBOutlet weak var human_choice_label: UILabel!
    
    @IBOutlet weak var machine_choice_label: UILabel!
    
    
    var user_choices = ""
    var machine_choices = ""
    
    var nb_games = 10
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        //Set The background
        setBackground()
        //Set initial state of wins for the user and the machine
        machine_score_label.text = String(0)
        human_score_label.text = String(0)
        current_winner.text = ""
        human_choice_label.text = ""
        machine_choice_label.text = ""

    }
    @IBAction func ExitButtonPressed(_ sender: UIButton) {
        //Action of the exit button
        exit(0)
    }
    
    @IBAction func scissors_user_choice(_ sender: Any) {
        //Add user choice "scissors" to the end of the history of user choices
        user_choices += "s"
        machine_choices += random_machine_choice()
        update_HMI_after_play(user_choices: user_choices ,machine_choices: machine_choices)
        //print("User choices = " + user_choices)
        print("Machine choices = " + machine_choices)
        human_choice_label.text = "Human : Scissors"
        
        
        let current_machine = String(machine_choices[machine_choices.index(machine_choices.startIndex,offsetBy: machine_choices.count-1)])
        
        if (current_machine == "r") {
            machine_choice_label.text = "Machine : Rock"
        }
        if (current_machine == "s") {
            machine_choice_label.text = "Machine : Scissors"
        }
        if (current_machine == "p") {
            machine_choice_label.text = "Machine : Paper"
        }
        
    }
    
    @IBAction func paper_user_choice(_ sender: Any) {
        //Add user choice "paper" to the end of the history of user choices
        user_choices += "p"
        machine_choices += random_machine_choice()
        update_HMI_after_play(user_choices: user_choices ,machine_choices: machine_choices)
        //print("User choices = " + user_choices)
        human_choice_label.text = "Human : Paper"

        print("Machine choices = " + machine_choices)
        let current_machine = String(machine_choices[machine_choices.index(machine_choices.startIndex,offsetBy: machine_choices.count-1)])
        
        if (current_machine == "r") {
            machine_choice_label.text = "Machine : Rock"
        }
        if (current_machine == "s") {
            machine_choice_label.text = "Machine : Scissors"
        }
        if (current_machine == "p") {
            machine_choice_label.text = "Machine : Paper"
        }
    }
    
    @IBAction func rock_user_choice(_ sender: Any) {
        //Add user choice "rock" to the end of the history of user choices
        user_choices += "r"
        machine_choices += random_machine_choice()
        update_HMI_after_play(user_choices: user_choices ,machine_choices: machine_choices)
        //print("User choices = " + user_choices)
        human_choice_label.text = "Human : Rock"

        print("Machine choices = " + machine_choices)
        let current_machine = String(machine_choices[machine_choices.index(machine_choices.startIndex,offsetBy: machine_choices.count-1)])
        
        if (current_machine == "r") {
            machine_choice_label.text = "Machine : Rock"
        }
        if (current_machine == "s") {
            machine_choice_label.text = "Machine : Scissors"
        }
        if (current_machine == "p") {
            machine_choice_label.text = "Machine : Paper"
        }
    }
    
    @IBAction func new_game_actions(_ sender: Any) {
        //place holder to reccord the game history before erasing it
        
        //reset the user_choices history
        user_choices = ""
        machine_choices = ""
        //Set initial state of wins for the user and the machine
        machine_score_label.text = String(0)
        human_score_label.text = String(0)
        current_winner.text = ""
        human_choice_label.text = ""
        machine_choice_label.text = ""
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
    
    
    func update_HMI_after_play(user_choices : String,machine_choices : String) -> Void {
        //Check the history of each player to determine the text to show
        let stats_game = getStatistics(user_choices: String(user_choices) , machine_choices: String(machine_choices))
        machine_score_label.text = String(stats_game.1)
        human_score_label.text = String(stats_game.0)
        
        let current_game_winner = getWinner(user_choices: String(user_choices) , machine_choices: String(machine_choices))
        if (current_game_winner == 1){
            current_winner.text = "You win !"
        }
        if (current_game_winner == 2){
            current_winner.text = "You loose !"
        }
        if (current_game_winner == 3){
            current_winner.text = "Tie !"
        }
        
    }
    
    func getWinner(user_choices : String, machine_choices : String)-> (Int){
        //User wins -> 1
        //Machine wins -> 2
        //Tie -> 3
        let n = user_choices.count - 1
        //Cases when the user wins
        if(user_choices[user_choices.index(user_choices.startIndex, offsetBy: n)] == "r") && ((machine_choices[machine_choices.index(machine_choices.startIndex, offsetBy: n)] == "s")){
            return 1
        }
        if(user_choices[user_choices.index(user_choices.startIndex, offsetBy: n)] == "p") && ((machine_choices[machine_choices.index(machine_choices.startIndex, offsetBy: n)] == "r")){
            return 1
        }
        if(user_choices[user_choices.index(user_choices.startIndex, offsetBy: n)] == "s") && ((machine_choices[machine_choices.index(machine_choices.startIndex, offsetBy: n)] == "p")){
            return 1
        }
        
        //Cases when the machine wins
        if(user_choices[user_choices.index(user_choices.startIndex, offsetBy: n)] == "r") && ((machine_choices[machine_choices.index(machine_choices.startIndex, offsetBy: n)] == "p")){
            return 2
        }
        if(user_choices[user_choices.index(user_choices.startIndex, offsetBy: n)] == "p") && ((machine_choices[machine_choices.index(machine_choices.startIndex, offsetBy: n)] == "s")){
            return 2
        }
        if(user_choices[user_choices.index(user_choices.startIndex, offsetBy: n)] == "s") && ((machine_choices[machine_choices.index(machine_choices.startIndex, offsetBy: n)] == "r")){
            return 2
        }
        return 3
    }
    
    func getStatistics(user_choices : String, machine_choices : String)-> (Int,Int){
        var nb_wins_user = 0
        var nb_wins_machine = 0
        for n in 0...(user_choices.count-1) {
            
            //Cases when the user wins
            if(user_choices[user_choices.index(user_choices.startIndex, offsetBy: n)] == "r") && ((machine_choices[machine_choices.index(machine_choices.startIndex, offsetBy: n)] == "s")){
                nb_wins_user += 1
            }
            if(user_choices[user_choices.index(user_choices.startIndex, offsetBy: n)] == "p") && ((machine_choices[machine_choices.index(machine_choices.startIndex, offsetBy: n)] == "r")){
                nb_wins_user += 1
            }
            if(user_choices[user_choices.index(user_choices.startIndex, offsetBy: n)] == "s") && ((machine_choices[machine_choices.index(machine_choices.startIndex, offsetBy: n)] == "p")){
                nb_wins_user += 1
            }
            
            //Cases when the machine wins
            if(user_choices[user_choices.index(user_choices.startIndex, offsetBy: n)] == "r") && ((machine_choices[machine_choices.index(machine_choices.startIndex, offsetBy: n)] == "p")){
                nb_wins_machine += 1
            }
            if(user_choices[user_choices.index(user_choices.startIndex, offsetBy: n)] == "p") && ((machine_choices[machine_choices.index(machine_choices.startIndex, offsetBy: n)] == "s")){
                nb_wins_machine += 1
            }
            if(user_choices[user_choices.index(user_choices.startIndex, offsetBy: n)] == "s") && ((machine_choices[machine_choices.index(machine_choices.startIndex, offsetBy: n)] == "r")){
                nb_wins_machine += 1
            }
            
        }
        return (nb_wins_user,nb_wins_machine)
    }
    
    func random_machine_choice()->String {
        let randomInt = Int.random(in: 1..<4)
        if (randomInt == 1){
            return "r"
        }else {
            if (randomInt == 2){
                return "p"
            } else {
                if (randomInt == 3){
                    return "s"
                } else {
                    return "e"
                }
            }
        }
    }
}

