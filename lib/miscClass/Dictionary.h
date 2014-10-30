struct GameParameters{
    int MinDeck;
    int MaxDeck;
    int CardsPerDeck;
    int NewChips;
    int SoftHand;
    int HardHitOn;
    int HardHit;
    int Target;
    double InsuranceRate, BJRate;
    enum{NumberOfCardNames=13};
    enum{NumberOfSuitTypes=4};
    const char* SuitType[NumberOfSuitTypes];
    std::string CardName[NumberOfCardNames];
    
    GameParameters():MinDeck(1), MaxDeck(8), CardsPerDeck(52), NewChips(100), HardHit(17), HardHitOn(1), SoftHand(10), Target(21), InsuranceRate(2), BJRate(1.5){
        SuitType[0]="\u2660";
        SuitType[1]="\u2663";
        SuitType[2]="\u2665";
        SuitType[3]="\u2666";
        CardName[0]=" A";
        CardName[1]=" 2";
        CardName[2]=" 3";
        CardName[3]=" 4";
        CardName[4]=" 5";
        CardName[5]=" 6";
        CardName[6]=" 7";
        CardName[7]=" 8";
        CardName[8]=" 9";
        CardName[9]="10";
        CardName[10]=" J";
        CardName[11]=" Q";
        CardName[12]=" K";
    }
};

struct AnswerCodes{
    int Yes;
    int No;
    int Help;
    int Exit;
    int Nonsense;
    AnswerCodes():Yes(1), No(-1), Help(2), Exit(-2), Nonsense(0){}
};

struct StrategyCodes{
    int Surrender;
    int DoubleDown;
    int Hit;
    int Stand;
    int Split;
    int Insurance;
    int Assist;
    int Help;
    int Exit;
    int Nonsense;
    StrategyCodes():Nonsense(-1), Exit(0), Help(1), Assist(2), Surrender(3), Stand(4), DoubleDown(5), Hit(6), Insurance(7), Split(8) {}
};

struct PlayerStatusCodes{
    int Surrender;
    int Bust;
    int Stand;
    int Play;
    int Twentyone;
    int BlackJack;
    PlayerStatusCodes():Surrender(-3), Bust(-2), Stand(-1), Play(0), Twentyone(1), BlackJack(2){}
};

struct VictoryStatusCodes{
    int Lose;
    int Push;
    int Win;
    int BJ;
    VictoryStatusCodes():Lose(-1), Push(0), Win(1), BJ(2){}
};

struct CommandMap{
    std::map<std::string, int> CommandCodes;
    CommandMap(){
        StrategyCodes SC;
        CommandCodes["exit"] = SC.Exit;
        CommandCodes["e"] = SC.Exit;
        CommandCodes["help"] = SC.Help;
        CommandCodes["h"] = SC.Help;
        CommandCodes["assist"] = SC.Assist;
        CommandCodes["a"] = SC.Assist;
        CommandCodes["hit"] = SC.Hit;
        CommandCodes["t"] = SC.Hit;
        CommandCodes["stand"] = SC.Stand;
        CommandCodes["s"] = SC.Stand;
        CommandCodes["double"] = SC.DoubleDown;
        CommandCodes["d"] = SC.DoubleDown;
        CommandCodes["surrender"] = SC.Surrender;
        CommandCodes["r"] = SC.Surrender;
        CommandCodes["split"] = SC.Split;
        CommandCodes["p"] = SC.Split;
        CommandCodes["Insurance"] = SC.Insurance;
        CommandCodes["i"] = SC.Insurance;
    }
};
