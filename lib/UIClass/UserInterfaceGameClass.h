//#include "CardClass.h"
//#include "PlayerBaseClass.h"
//#include "PlayerGuestClass.h"
//#include "PlayerDealerClass.h"
class UIGamePlay{
    UserGameStatistics NewStatistics;
    
    void UIWelcome();
    void UIGameStat(UserGameStatistics&);
    void UIRules();
    void UIDealerCardAtBeginning(Dealer&);
    void UIDealerCardAtTheEnd(Dealer&);
    void UIGuest(Guest&);
    void UIResult(Guest&);
    void UIReport(UserGameStatistics&);
    
public:
    void UIMakeBet(UserGameStatistics&);
    void UIRoundBeginning(UserGameStatistics&, Guest&, Dealer&);
    void UIRoundEnd(UserGameStatistics&, Guest&, Dealer&);
};

void UIGamePlay::UIWelcome(){
    for (int i=0; i<100; i++) {
        std::cout<<std::endl;
    }
    for (int i=0; i<60; i++) {
        std::cout<<"*";
    }
    std::cout<<"\n(H/h)Help";
    std::cout<<"\t\tBLACKJACK";
    std::cout<<"\t\t(E/e)Exit\n";
}

void UIGamePlay::UIGameStat(UserGameStatistics& NewStatistics){
    std::cout<<"\nGame #"<<NewStatistics.Hands;
    std::cout<<", game won: "<<NewStatistics.HandWon;
    std::cout<<", game push: "<<NewStatistics.HandPush;
    std::cout<<", game lost: "<<NewStatistics.HandLost<<std::endl;
}

void UIGamePlay::UIDealerCardAtBeginning(Dealer& NewDealer){
    std::cout<<"\nDearer's points: "<<NewDealer.showPoint0();
    std::cout<<"\nDealer's   card: "<<NewDealer.showCard0();
    std::cout<<std::endl;
}

void UIGamePlay::UIDealerCardAtTheEnd(Dealer& NewDealer){
    std::cout<<"\nDearer's points: "<<NewDealer.showPoints();
    std::cout<<"\nDealer's   card: "<<NewDealer.showCards();
    
}

void UIGamePlay::UIRules(){
    std::cout<<"\nBlackJack pays 3:2\t";
    std::cout<<"Insurance pays 2:1\t\n";
}

void UIGamePlay::UIGuest(Guest& NewGuest){
    std::cout<<"\nYour       card: "<<NewGuest.showCards();
    std::cout<<"\nYour     points: "<<NewGuest.showPoints();
    std::cout<<"\tYour bet: "<<NewGuest.Bets;
    if (NewGuest.Insurances) {
        std::cout<<"\t Your insurance: "<<NewGuest.Insurances;
    }
}

void UIGamePlay::UIReport(UserGameStatistics& Statistics){
    std::cout<<"\n\nYour current chips in hand: "<<Statistics.WagerInHand;
    std::cout<<"\n"<<std::endl;
}

void UIGamePlay::UIMakeBet(UserGameStatistics& Statistics){
    UIWelcome();
    UIGameStat(Statistics);
    UIRules();
}

void UIGamePlay::UIResult(Guest& NewGuest){
    if (NewGuest.HandStatus == NewGuest.VictoryStatusCodes.BJ) {
        std::cout<<"\nYou win a BlackJack!";
    }else if(NewGuest.HandStatus == NewGuest.VictoryStatusCodes.Win){
        std::cout<<"\nYou win!";
    }else if(NewGuest.HandStatus == NewGuest.VictoryStatusCodes.Push){
        std::cout<<"\nYou push!";
    }else{
        std::cout<<"\nYou lose!";
    }
}

void UIGamePlay::UIRoundBeginning(UserGameStatistics& Statistics, Guest& NewGuest, Dealer& NewDealer){
    UIWelcome();
    UIGameStat(Statistics);
    UIRules();
    UIDealerCardAtBeginning(NewDealer);
    UIGuest(NewGuest);
    UIReport(Statistics);
}

void UIGamePlay::UIRoundEnd(UserGameStatistics& Statistics, Guest& NewGuest, Dealer& NewDealer){
    UIWelcome();
    UIGameStat(Statistics);
    UIRules();
    UIDealerCardAtTheEnd(NewDealer);
    UIGuest(NewGuest);
    UIResult(NewGuest);
    UIReport(Statistics);
}