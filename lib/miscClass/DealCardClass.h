class DealCard{
    const GameParameters Parameters;
    int Decks;
    int NumberOfCards;
    int ThresholdForShuffle;
    std::vector<int> DealedCards;
    
    void resetCards();
    bool isOldCard(const int&);
    int getCards();
    
public:
    DealCard();
    void setDealCard(const int&);
    void shuffleCards();
    int addCards();
};

DealCard::DealCard(){}

void DealCard::setDealCard(const int& num){
    Decks = num;
    NumberOfCards = Decks * Parameters.CardsPerDeck;
    ThresholdForShuffle = 0.3 * NumberOfCards;
}

void DealCard::resetCards(){
    while (!DealedCards.empty()) DealedCards.pop_back();
}

void DealCard::shuffleCards(){
    if (DealedCards.size() >= ThresholdForShuffle) {
        resetCards();
    }
}

bool DealCard::isOldCard(const int& NewCard){
    for (int i=0; i<DealedCards.size(); i++)
        if (DealedCards[i] == NewCard) return true;
    return false;
}

int DealCard::getCards(){
    int NewCard;
    do {
        srand(clock());
        NewCard = rand() % NumberOfCards;
    } while (isOldCard(NewCard));
    return NewCard;
}

int DealCard::addCards(){
    int NewCard = getCards();
    DealedCards.push_back(NewCard);
    shuffleCards();
    return NewCard;
}