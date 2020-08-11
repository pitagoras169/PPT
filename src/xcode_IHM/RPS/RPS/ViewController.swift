//
//  ViewController.swift
//  RPS
//
//  Created by guillermo pita on 09/08/2020.
//  Copyright © 2020 guillermo pita. All rights reserved.
//

import UIKit

struct Markov_chain {
    var nb_RR: Int
    var nb_RP: Int
    var nb_RS: Int
    var nb_PR: Int
    var nb_PP: Int
    var nb_PS: Int
    var nb_SR: Int
    var nb_SP: Int
    var nb_SS: Int
}

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
    
    var user_choice_2 : String = "r"
    var user_choice_1 : String = "r"
    
    var single_markov = Markov_chain(nb_RR: 1,nb_RP: 1,nb_RS: 1,nb_PR: 1,nb_PP: 1,nb_PS: 1,nb_SR: 1,nb_SP: 1,nb_SS: 1)
    
    
    
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
        print_markov(chain_input : single_markov)

    }
    @IBAction func ExitButtonPressed(_ sender: UIButton) {
        //Action of the exit button
        exit(0)
    }
    
    @IBAction func scissors_user_choice(_ sender: Any) {
        //Add user choice "scissors" to the end of the history of user choices
        user_choices += "s"
        
        //Update Makov Weights
        //print_markov(chain_input : single_markov)
        single_markov = update_markov(chain_input : single_markov,user_choice_2 : user_choice_2, user_choice_1 : user_choice_1)
        //print_markov(chain_input : single_markov)
        
        //Make the Machine's choice
        //machine_choices += random_machine_choice()
        machine_choices += markov_choice(chain_input : single_markov, user_choice_1: user_choice_1)
        
        
        update_HMI_after_play(user_choices: user_choices ,machine_choices: machine_choices)
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
        
        //Reccord history
        user_choice_2 = user_choice_1
        user_choice_1 = "s"
    }
    
    @IBAction func paper_user_choice(_ sender: Any) {
        //Add user choice "paper" to the end of the history of user choices
        user_choices += "p"
        
        //Update Makov Weights
        //print_markov(chain_input : single_markov)
        single_markov = update_markov(chain_input : single_markov,user_choice_2 : user_choice_2, user_choice_1 : user_choice_1)
        //print_markov(chain_input : single_markov)
        
        //Make the Machine's choice
        //machine_choices += random_machine_choice()
        machine_choices += markov_choice(chain_input : single_markov, user_choice_1: user_choice_1)
                
        update_HMI_after_play(user_choices: user_choices ,machine_choices: machine_choices)
        
        human_choice_label.text = "Human : Paper"

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
        
        
        //Reccord history
        user_choice_2 = user_choice_1
        user_choice_1 = "p"
    }
    
    @IBAction func rock_user_choice(_ sender: Any) {
        //Add user choice "rock" to the end of the history of user choices
        user_choices += "r"
        
        //Update Makov Weights
        //print_markov(chain_input : single_markov)
        single_markov = update_markov(chain_input : single_markov,user_choice_2 : user_choice_2, user_choice_1 : user_choice_1)
        //print_markov(chain_input : single_markov)
        
        //Make the Machine's choice
        //machine_choices += random_machine_choice()
        machine_choices += markov_choice(chain_input : single_markov, user_choice_1: user_choice_1)


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
        
        
        //Reccord history
        user_choice_2 = user_choice_1
        user_choice_1 = "r"
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
        single_markov = reset_markov(chain_input: single_markov)
        user_choice_2 = "r"
        user_choice_1 = "r"
    }
    
    func reset_markov(chain_input : Markov_chain) -> (Markov_chain){
        var chain = chain_input
        chain.nb_RR = 1
        chain.nb_RP = 1
        chain.nb_RS = 1
        chain.nb_PR = 1
        chain.nb_PP = 1
        chain.nb_PS = 1
        chain.nb_SR = 1
        chain.nb_SP = 1
        chain.nb_SS = 1
        return chain
    }
    
    func print_markov(chain_input : Markov_chain) -> (Void){
        let chain = chain_input
        print(chain)
    }
    
    func markov_choice(chain_input : Markov_chain, user_choice_1 : String) -> (String){
        let chain = chain_input
        var prob_user_rock = 0.0
        var prob_user_paper = 0.0
        var prob_user_scissors = 0.0
        
        if(user_choice_1 == "r"){
            prob_user_rock = Double(chain.nb_RR) / Double((chain.nb_RR+chain.nb_RP+chain.nb_RS))
            prob_user_paper = Double(chain.nb_RP) / Double((chain.nb_RR+chain.nb_RP+chain.nb_RS))
            prob_user_scissors = Double(chain.nb_RS) / Double((chain.nb_RR+chain.nb_RP+chain.nb_RS))
        }
        
        if(user_choice_1 == "p"){
            prob_user_rock = Double(chain.nb_PR) / Double((chain.nb_PR+chain.nb_PP+chain.nb_PS))
            prob_user_paper = Double(chain.nb_PP) / Double((chain.nb_PR+chain.nb_PP+chain.nb_PS))
            prob_user_scissors = Double(chain.nb_PS) / Double((chain.nb_PR+chain.nb_PP+chain.nb_PS))
        }
        
        if(user_choice_1 == "s"){
            prob_user_rock = Double(chain.nb_SR) / Double((chain.nb_SR+chain.nb_SP+chain.nb_SS))
            prob_user_paper = Double(chain.nb_SP) / Double((chain.nb_SR+chain.nb_SP+chain.nb_SS))
            prob_user_scissors = Double(chain.nb_SS) / Double((chain.nb_SR+chain.nb_SP+chain.nb_SS))
        }
        
        //If the user is most likely to choose rock --> play paper
        if ((prob_user_rock >= prob_user_paper) && (prob_user_rock >= prob_user_scissors)){
            return "p"
        }else {
            //If the user is most likely to choose paper --> play scissors
            if((prob_user_paper >= prob_user_rock) && (prob_user_paper >= prob_user_scissors)){
                return "s"
            } else {
                //If the user is most likely to play scissors --> Play Rock
                return "r"
            }
        }
        
    }
    
    func update_markov(chain_input : Markov_chain,user_choice_2 : String, user_choice_1 : String) -> (Markov_chain){
        var chain = chain_input
        if((user_choice_2 == "r") && (user_choice_1 == "r")){
            chain.nb_RR += 1
        }
        if((user_choice_2 == "r") && (user_choice_1 == "p")){
            chain.nb_RP += 1
        }
        if((user_choice_2 == "r") && (user_choice_1 == "s")){
            chain.nb_RS += 1
        }
        if((user_choice_2 == "p") && (user_choice_1 == "r")){
            chain.nb_PR += 1
        }
        if((user_choice_2 == "p") && (user_choice_1 == "p")){
            chain.nb_PP += 1
        }
        if((user_choice_2 == "p") && (user_choice_1 == "s")){
            chain.nb_PS += 1
        }
        if((user_choice_2 == "s") && (user_choice_1 == "r")){
            chain.nb_SR += 1
        }
        if((user_choice_2 == "s") && (user_choice_1 == "p")){
            chain.nb_SP += 1
        }
        if((user_choice_2 == "s") && (user_choice_1 == "s")){
            chain.nb_SS += 1
        }
        
        return chain
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

