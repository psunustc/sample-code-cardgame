//#include "UserInterfaceGameClass.h"

class BlackJack{
    UserAccount User;
    UIGamePlay GamePlay;
    Guest NewGuest;
    Dealer NewDealer;
    DealCard DealCards;
    void makeBet();
    void updateBet();
    void DialogueBet();
    void DialogueOptions();
    void DialogueInsurance();
    void resetBet();
    void initHand();
    void GuestHand();
    void DealerHand();
    void judgeHand();
    void endHand();
    void loadUser(UserAccount&);
    void updateUser(UserAccount&);
    void playGuest();
    void updateStatistics();
    void resetStatistics();
    bool checkWager();
public:
    BlackJack();
    void setDeckNumber(const int&);
    void playOneHand(UserAccount&);
};

BlackJack::BlackJack(){}

void BlackJack::setDeckNumber(const int& DeckNum){
    DealCards.setDealCard(DeckNum);
}

void BlackJack::DialogueBet(){
    std::stringstream Question;
    Question<<"\nPlease make a bet as following!\nChoose an integer from 1 up to all your chips of "<<User.NewStatistics.WagerInHand<<" :";
    NLP NLP;
    NLP.extractText(User.NewStatistics.WagerOnTable, Question.str(), 1, User.NewStatistics.WagerInHand);
}

void BlackJack::DialogueOptions(){
    UserCommand Command(User.NewRules);
    Command.setCommands(User, NewDealer, NewGuest);
    std::stringstream Question;
    Question<<Command.OptionsMessage<<"\nPlease enter your choice: ";
    NLP NLP;
    NLP.extractText(NewGuest.CommandCode, Question.str(), Command.OptionsDictionary);
}

bool BlackJack::checkWager(){
    if ((User.NewStatistics.WagerInHand - NewGuest.Bets) > 0 )
        return true;
    else
        return false;
}

void BlackJack::DialogueInsurance(){
    NLP NLP;
    if (NewDealer.insurable && checkWager()) {
        std::stringstream Question;
        Question<<"\nDo you want to get insurance? (y/n): ";
        NLP.extractText(NewGuest.isInsured, Question.str());
    }
    if (NewGuest.isInsured) {
        std::stringstream Question;
        Question<<"\nPlease make a insurance as following!\nChoose an integer from 1 up to half your Bets of "<<NewGuest.Bets<<" :";
        NLP.extractText(NewGuest.Insurances, Question.str(), 1, 0.5*NewGuest.Bets);
    }
}

void BlackJack::updateBet(){
    User.NewStatistics.WagerInHand -= User.NewStatistics.WagerOnTable;
    NewGuest.Bets = User.NewStatistics.WagerOnTable;
}
    
void BlackJack::makeBet(){
    GamePlay.UIMakeBet(User.NewStatistics);
    DialogueBet();
    updateBet();
}

void BlackJack::initHand(){
    User.NewStatistics.Hands++;
    makeBet();
    NewGuest.initialize(DealCards.addCards(), DealCards.addCards());
    NewDealer.initialize(DealCards.addCards(), DealCards.addCards());
    GamePlay.UIRoundBeginning(User.NewStatistics, NewGuest, NewDealer);
}

void BlackJack::playGuest(){
    if (NewGuest.CommandCode > NewGuest.StrategyCodes.Stand) {
        NewGuest.strategy(DealCards.addCards());
    }else
        NewGuest.status = NewGuest.PlayerStatusCodes.Stand;
}

void BlackJack::GuestHand(){
    while (NewGuest.status == NewGuest.PlayerStatusCodes.Play) {
        DialogueInsurance();
        DialogueOptions();
        resetStatistics();
        playGuest();
        GamePlay.UIRoundBeginning(User.NewStatistics, NewGuest, NewDealer);
    }
}

void BlackJack::DealerHand(){
    if(NewGuest.status>NewGuest.PlayerStatusCodes.Bust){
        while (NewDealer.status == NewDealer.PlayerStatusCodes.Play) {
            NewDealer.strategy(DealCards.addCards());
            GamePlay.UIRoundBeginning(User.NewStatistics, NewGuest, NewDealer);
        }
    }
}

void BlackJack::judgeHand(){
    
    std::cout<<NewGuest.status<<' '<<NewDealer.status<<'\n';
    if (NewGuest.status > NewDealer.status) {
        NewGuest.HandStatus = NewGuest.VictoryStatusCodes.Win;
        if (NewGuest.status == NewGuest.PlayerStatusCodes.BlackJack)
            NewGuest.HandStatus = NewGuest.VictoryStatusCodes.BJ;
    }else if(NewGuest.status == NewDealer.status){
        NewGuest.HandStatus = NewGuest.VictoryStatusCodes.Push;
    }else{
        NewGuest.HandStatus = NewGuest.VictoryStatusCodes.Lose;
    }
    if (NewGuest.status == NewDealer.status && NewGuest.status == NewGuest.PlayerStatusCodes.Stand) {
        if (NewGuest.scoreMax > NewDealer.scoreMax){
            NewGuest.HandStatus = NewGuest.VictoryStatusCodes.Win;
        }else if(NewGuest.scoreMax == NewDealer.scoreMax){
            NewGuest.HandStatus = NewGuest.VictoryStatusCodes.Push;
        }else{
            NewGuest.HandStatus = NewGuest.VictoryStatusCodes.Lose;
        }
    }
}

void BlackJack::resetStatistics(){
    if (NewGuest.CommandCode == NewGuest.StrategyCodes.DoubleDown) {
        User.NewStatistics.WagerInHand -= NewGuest.Bets;
    }
    if (NewGuest.isInsured) {
        User.NewStatistics.WagerInHand -= NewGuest.Insurances;
    }
}

void BlackJack::updateStatistics(){
    NewGuest.getWagers();
    User.NewStatistics.WagerInHand += NewGuest.Wins;
    if (NewGuest.HandStatus > NewGuest.VictoryStatusCodes.Push) {
        User.NewStatistics.HandWon++;
    }else if(NewGuest.HandStatus == NewGuest.VictoryStatusCodes.Push){
        User.NewStatistics.HandPush++;
    }else
        User.NewStatistics.HandLost++;
}

void BlackJack::endHand(){
    updateStatistics();
    GamePlay.UIRoundEnd(User.NewStatistics, NewGuest, NewDealer);
    NewGuest.clear();
    NewDealer.clear();
}

void BlackJack::loadUser(UserAccount& NewUser){
    User = NewUser;
}

void BlackJack::updateUser(UserAccount& NewUser){
    NewUser = User;
}

void BlackJack::playOneHand(UserAccount& NewUser){
    loadUser(NewUser);
    initHand();
    GuestHand();
    DealerHand();
    judgeHand();
    endHand();
    updateUser(NewUser);
}

