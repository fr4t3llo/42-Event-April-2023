<?php
    echo "Choose rock, paper, or scissors : ";
    $choice = array("rock", "paper", "scissors");
    $input = fgets(STDIN);
    $input = trim($input);
    if (!in_array($input, $choice)) { // check if user input is valid
        echo "Invalid choice. Please enter rock, paper, or scissors.\n";
        exit;
    }
    $random_computer_index = rand(0, 2);
    $random_computer_word = $choice[$random_computer_index];
    if ($input == $random_computer_word)
    {
        echo "equal !!\n";
        exit;
    }
    if (($input == "paper" && $random_computer_word == "rock") ||
        ($input == "rock" && $random_computer_word == "scissors") ||
        ($input == "scissors" && $random_computer_word == "paper"))
    {
        echo "Congratulations! You won! The computer chose rock.\n";
    }
    else 
        echo "Sorry, you lost. The computer chose $random_computer_word." 
?>