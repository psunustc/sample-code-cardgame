//#include "UserAccountClass.h"
//#include "GameBlackJackClass.h"
//#include "UserInterfaceClass.h"

class Game{
private:
    UserAccount NewUser;
    BlackJack NewHand;
    UserInterface NewInterface;

    void initGame();
    void continueGame();
    void DialogueExit();
    void endGame();
    
public:
    Game(){}
    void playGame();
};

void Game::initGame(){
    NewInterface.initInterface();
    NewUser.setAccount();
    NewHand.setDeckNumber(NewUser.NewRules.DeckNumber);
}

void Game::continueGame(){
    while (NewInterface.continueInterface(NewUser) ) {
        NewHand.playOneHand(NewUser);
        if(!NewUser.isAlive()){
            std::cout<<"\nYou are out of wagers!";
            break;
        }
    }
}
void Game::DialogueExit(){
    std::cout<<"\nThanks for playing!";
    std::cout<<"\nPlease send your comments to pengsun00@gmail.com\n";
}

void Game::endGame(){
    NewInterface.endInterface();
    NewUser.saveAccount();
    DialogueExit();
}

void Game::playGame(){
    initGame();
    continueGame();
    endGame();
}