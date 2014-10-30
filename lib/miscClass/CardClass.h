class Card{
    GameParameters parameters;
    const int number;
public:
    Card();
    Card(const int& num);
    int Point() const;
    std::string SuitName() const;
};

Card::Card():number(0){}

Card::Card(const int& num):number(num){}

//point value of a card
int Card::Point() const{
    int rank = number % parameters.NumberOfCardNames + 1;
    return (rank > parameters.SoftHand) ? parameters.SoftHand : rank;
}

//display card
std::string Card::SuitName() const{
    int rank1 = number % parameters.NumberOfSuitTypes;
    int rank2 = number % parameters.NumberOfCardNames;
    return parameters.CardName[rank2] + parameters.SuitType[rank1];
}