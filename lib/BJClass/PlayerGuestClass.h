class Guest : public Player{
public:
    int Bets;
    double Insurances, Wins;
    int HandStatus, CommandCode;
    bool isInsured;
    void strategy(int newCard);
    void getWinsLoss();
    void getWagers();
    void clear();
    std::string showCards();
    std::string showPoints();
};

void Guest::strategy(int newCard){
    if (CommandCode==StrategyCodes.Hit){
        addCard(newCard);
    }else if(CommandCode==StrategyCodes.DoubleDown){
        addCard(newCard);
        Bets *= 2;
        if (status==PlayerStatusCodes.Play)
            status=PlayerStatusCodes.Stand;
    }else if(CommandCode==StrategyCodes.Surrender){
        status=PlayerStatusCodes.Surrender;
    }else if(CommandCode==StrategyCodes.Insurance){
        status=PlayerStatusCodes.Play;
        insurable=false;
    }
}

void Guest::getWinsLoss(){
    if (HandStatus == VictoryStatusCodes.BJ) Wins =  Bets * (1 + GameParameters.BJRate);
    else if (HandStatus == VictoryStatusCodes.Win) Wins = 2 * Bets;
    else if (HandStatus == VictoryStatusCodes.Push) Wins = Bets;
    else{
        if(CommandCode == StrategyCodes.Surrender)Wins = 0.5 * Bets;
    }
    
}

void Guest::getWagers(){
    getWinsLoss();
    Wins += Insurances * (1 + GameParameters.InsuranceRate);
}

void Guest::clear(){
    score = 0;
    scoreMax = 0;
    scoreMin = 0;
    ace = 0;
    status = 0;
    softhand = 0;
    resetCard();
    Bets=0;
    Wins=0;
    Insurances=0;
    isInsured=false;
}

std::string Guest::showCards(){
    std::stringstream output;
    for (int i=0; i<Cards.size(); i++)
        output<<Cards[i].SuitName()<<" ";
    return output.str();
}

std::string Guest::showPoints(){
    std::stringstream OutPut;
    OutPut<<std::setw(3)<<scoreMin;
    if (scoreMax>scoreMin) OutPut<<'('<<scoreMax<<')';
    return OutPut.str();
}
