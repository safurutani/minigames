#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

void guess_game();
void rock_paper_scissors();
void high_low();

int main()
{
    bool ingame = false;
    int option;
    while (option != 4 && ingame == false)
    {
        std::cout << "\nChoose a game:\n1. Guess the Number \n2. Rock, Paper, Scissors\n3. High/Low\n4. Quit" << std::endl;
        std::cin >> option; 

        switch(option)
        {
            case 1:
                ingame = true;
                guess_game();
                ingame = false;
                break;
            case 2:
                ingame = true;
                rock_paper_scissors();
                ingame = false;
                break;
            case 3:
                ingame = true;
                high_low();
                ingame = false;
                break;
            case 4:
                std::cout << "The fun will end now.";
                break;
            default:
                std::cout << "Please choose a valid number.";
        }     
    }
    
}

void guess_game() 
{
    bool playing = true;
    while (playing)
    {
        int max;
        int guess;
        int num_guesses = 0;
        std::cout << "\nWhat would you like the maximum number to be? ";
        std::cin >> max;
        srand(time(NULL));
        int answer = rand() % max;
        std::cout << "Okay, I randomly picked a number from 1 to " << max << std::endl;
        while (guess != answer)
        {
            std::cout << "Guess a number: ";
            std::cin >> guess;
            if (guess < answer)
            {
                std::cout << "Your guess is too low. ";
            }
            else if (guess > answer)
            {
                std::cout << "Your guess is too high. ";
            }
            num_guesses += 1;
        }
        if (guess == answer)
        {
            std::cout << "That's correct! You won in " << num_guesses << " guesses!" << std::endl;
            std::cout << "Play again? (y/n)";
            std::string replay; 
            std::cin >> replay;
            if (replay != "y") 
            {
                playing = false;
                std::cout << "Thanks for playing\n\n";
            } 
        }
    }
}
void rock_paper_scissors() 
{
    bool playing = true;
    bool game_over = false;
    int cpu = 0;
    int player = 0;
    std::vector <std::string> choices = {"ROCK", "PAPER", "SCISSORS"};     
    while (playing)
    {
        
        std::cout << "What will you choose?\n\nROCK    PAPER    SCISSORS\n";
        std::string selection = "";
        std::cin >> selection;
        std::transform(selection.begin(), selection.end(),selection.begin(), ::toupper);
        
        srand(time(NULL));
        std::string cpu_selection = choices[rand() % 3];
        std::cout << selection << " (Player) vs. " << cpu_selection << " (CPU)\n";
        if (selection == cpu_selection)
        {
            std::cout << "It's a tie! Nobody won.\n";
            std::cout << "CPU: " << cpu << "    Player: " << player;

        }
        else if (selection == "ROCK")
        {
            if (cpu_selection == "PAPER")
            {
                cpu += 1;
                std::cout << "Sorry, you lost.\n";
                std::cout << "CPU: " << cpu << "    Player: " << player;
            }
            else
            {
                player += 1;
                std::cout << "Congratulations! You won!\n";
                std::cout << "CPU: " << cpu << "    Player: " << player;
            }
        }
        else if (selection == "PAPER")
        {
            if (cpu_selection == "ROCK")
            {
                player += 1;
                std::cout << "Congratulations! You won!\n";
                std::cout << "CPU: " << cpu << "    Player: " << player;
            }
            else
            {
                cpu += 1;
                std::cout << "Sorry, you lost.\n";
                std::cout << "CPU: " << cpu << "    Player: " << player;
            }
        }
        else if (selection == "SCISSORS")
        {
            if (cpu_selection == "PAPER")
            {
                player += 1;
                std::cout << "Congratulations! You won!\n";
                std::cout << "CPU: " << cpu << "    Player: " << player;
            }
            else
            {
                cpu += 1;
                std::cout << "Sorry, you lost.\n";
                std::cout << "CPU: " << cpu << "    Player: " << player;
            }
        }
        else
        {
            std::cout << "Invalid choice. Please choose again.\n";
            std::cin >> selection;
        }
        std::cout << "\nPlay Again? (y/n)";
        std::string replay;
        std::cin >> replay;
        if (replay != "y") 
        {
            playing = false;
            std::cout << "Thanks for playing\n\n";
        }
    }
}
void high_low()
{
    bool playing = true;
    int score = 0;
    int games = 0;
    while (playing)
    {
        srand(time(NULL));
        int card1 = (rand() % 9) + 1;
        int card2 = (rand() % 10) + 1;
        while (card1 == card2)
        {
            card2 = (rand() % 10) + 1;
        }
        std::cout << "There are 10 cards ranging from 1 to 10. I am picking a random card.\nThe first card is " << card1 << ".";
        std::cout << "\nDo you think the next card will be lower or higher than " << card1 << "?";
        std::cout << "\n1. Lower\n2. Higher\n";
        int guess;
        std::cin >> guess;
        std::cout << "\nThe second card is " << card2 << "\n";
        games += 1;
        if (card2 > card1)
        {
            if (guess == 1)
            {
                std::cout << card2 << " is higher than " << card1;
                std::cout << "\nYou lost\nScore: " << score << "    Games played: " << games;
            }
            else if (guess == 2)
            {
                score += 1;
                std::cout << card2 << " is higher than " << card1;
                std::cout << "\nYou won!\nScore: " << score << "    Games played: " << games;
            }
        }
        else
        {
            if (guess == 1)
            {
                score += 1;
                std::cout << card2 << " is lower than " << card1;
                std::cout << "\nYou won!\n Score: " << score << "    Games played: " << games;
            }
            else if (guess == 2)
            { 
                std::cout << card2 << " is lower than " << card1;
                std::cout << "\nYou lost\nScore: " << score << "    Games played: " << games;
            }
        }
        std::cout << "\nPlay Again? (y/n)";
        std::string replay;
        std::cin >> replay;
        if (replay != "y") 
        {
            playing = false;
            std::cout << "Thanks for playing\n\n";
        }
    }
}

