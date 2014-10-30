struct UserGameStatistics{
    int WagerOnTable;
    double WagerInHand, WagerWon, WagerInsured;
    int HandWon, HandLost, HandPush, Hands;
    
    UserGameStatistics():WagerOnTable(0), WagerWon(0), WagerInsured(0), HandLost(0), HandPush(0), HandWon(0), Hands(0){
        const GameParameters NewParameters;
        WagerInHand = NewParameters.NewChips;
    }
    
    bool isAlive();
};

bool UserGameStatistics::isAlive(){
    return (WagerInHand> 0.1);
}
