class UserCommand{
    UserGameRules GameRules;
    
    void addSurrender(){
        if (GameRules.SurrenderOn) {
            KeysDictionary += "Rr";
            OptionsMessage += "(R/r)suRrender ";
            OptionsDictionary.push_back("surrender");
            OptionsDictionary.push_back("r");
        }
    }
    
    void addSplit(){
        if (GameRules.SplitOn) {
            KeysDictionary += "Pp";
            OptionsMessage += "(P/p)sPlit ";
            OptionsDictionary.push_back("split");
            OptionsDictionary.push_back("p");
        }
    }
    
    void addInsurance(){
        if (GameRules.InsuranceOn) {
            KeysDictionary += "Ii";
            OptionsMessage += "(I/i)Insurance ";
            OptionsDictionary.push_back("insurance");
            OptionsDictionary.push_back("i");
        }
    }
    
    void addDouble(){
        if (GameRules.DoubleOn) {
            KeysDictionary += "Dd";
            OptionsMessage += "(D/d)Double ";
            OptionsDictionary.push_back("double");
            OptionsDictionary.push_back("d");
        }
    }
public:
    std::string KeysDictionary;
    std::string OptionsMessage;
    std::vector<std::string> OptionsDictionary;
    
    UserCommand(const UserGameRules& Rules):GameRules(Rules), KeysDictionary("TtSs"), OptionsMessage("Strategies:\n(T/t)hiT (S/s)Stand "){
        OptionsDictionary.push_back("hit");
        OptionsDictionary.push_back("t");
        OptionsDictionary.push_back("stand");
        OptionsDictionary.push_back("s");
    }
    
    void setCommands(const UserAccount& User, const Dealer& NewDealer, const Guest& NewGuest){
        if (NewGuest.beginning) {
            bool WagerFlag = User.NewStatistics.WagerInHand >= NewGuest.Bets;
            if(WagerFlag)addDouble();
            addSurrender();
            //if(WagerFlag && NewGuest.splitable) addSplit();
            //if(NewDealer.insurable) addInsurance();
        }
    }
};