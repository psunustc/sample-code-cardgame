//#include "NLPClass.h"
//#include "dictionary.h"

class UserGameRules{
public:
    int MinDeck;
    int MaxDeck;
    bool SplitOn;
    bool DoubleOn;
    bool SurrenderOn;
    bool SoftHiton;
    bool InsuranceOn;
    int DeckNumber;

private:
    NLP NLP;
    
    void setDeckNumber();
    void setSplit();
    void setDouble();
    void setSurrender();
    void setSoftHit();
    void setInsurance();
    
public:
    void setGameRules();
    void showOptions();
    
    
    UserGameRules(): DeckNumber(3), SplitOn(true), DoubleOn(true),SurrenderOn(true), SoftHiton(true), InsuranceOn(true){
        const GameParameters NewParameters;
        MinDeck = NewParameters.MinDeck;
        MaxDeck = NewParameters.MaxDeck;
    }
};

void UserGameRules::setGameRules(){
    std::cout<<"Please choose the game rules first!";
    setDeckNumber();
    setSplit();
    setDouble();
    setSurrender();
    setInsurance();
    showOptions();
}

void UserGameRules::setDeckNumber(){
    std::stringstream tmp;
    tmp<<"\nPlease choose the number of decks of cards!(from "<<MinDeck<<" to "<<MaxDeck<<"):";
    NLP.extractText(DeckNumber, tmp.str(), MinDeck, MaxDeck);
}

void UserGameRules::setSplit(){
    std::string Question("Do you want to add SPLIT?(y/n):");
    NLP.extractText(SplitOn, Question);
}

void UserGameRules::setDouble(){
    std::string Question("Do you want to add DOUBLE?(y/n):");
    NLP.extractText(DoubleOn, Question);
}

void UserGameRules::setSurrender(){
    std::string Question("Do you want to add SURRENDER?(y/n):");
    NLP.extractText(SurrenderOn, Question);
}

void UserGameRules::setInsurance(){
    std::string Question("Do you want to add INSURANCE?(y/n):");
    NLP.extractText(InsuranceOn, Question);
}

void UserGameRules::showOptions(){
    std::cout<<"\nYour choices are: ";
    std::cout<<DeckNumber<<" decks of cards with ";
    std::cout<<"SPLIT "<<(SplitOn?"ON":"OFF")<<", \n";
    std::cout<<"DOUBLE "<<(DoubleOn?"ON":"OFF")<<", ";
    std::cout<<"SURRENDER "<<(SurrenderOn?"ON":"OFF")<<" and, ";;
    std::cout<<"INSURANCE "<<(InsuranceOn?"ON":"OFF")<<". ";;
    std::cout<<"\n";
}