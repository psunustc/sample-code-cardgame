//#include <vector>

struct Player{
    const PlayerStatusCodes PlayerStatusCodes;
    const GameParameters GameParameters;
    const StrategyCodes StrategyCodes;
    const VictoryStatusCodes VictoryStatusCodes;
    std::vector<Card> Cards;
    int score;
    int scoreMin;
    int scoreMax;
    int ace;
    int status;
    int softhand;
    bool beginning;
    bool splitable;
    bool insurable;
    bool BJAtBeginning;

    Player();
    void getCard(const int& NewCard);
    void getScoreAce(const int& newCard);
    void getScoreMaxMin();
    void getPoint(const int& newCard);
    void addCard(const int& newCard);
    void setBeginning();
    void resetCard();
    void isBJAtBeginning();
    void isSplitable();
    void isInsurable();
    void initialize(const int& newCard1, const int& newCard2);
    void getStatus();
    
    
};

Player::Player():score(0),scoreMax(0),scoreMin(0),ace(0),status(0),softhand(0),beginning(true){}

void Player::getCard(const int& NewCard){
    Card tmp(NewCard);
    Cards.push_back(tmp);
    setBeginning();
}

void Player::getScoreAce(const int& newCard){
    int tmp = Cards.back().Point();
    if (tmp==1) {
        ace++;
    }else{
        score += tmp;
    }
}

void Player::getScoreMaxMin(){
    scoreMin = score + ace;
    if (ace>0 && (scoreMin+GameParameters.SoftHand)<=GameParameters.Target) {
        scoreMax = scoreMin + GameParameters.SoftHand;
    }else{
        scoreMax = scoreMin;
    }
}

void Player::getPoint(const int& newCard){
    getScoreAce(newCard);
    getScoreMaxMin();
}

void Player::addCard(const int& newCard){
    getCard(newCard);
    getPoint(newCard);
    getStatus();
}

void Player::setBeginning(){
    beginning= (Cards.size()<3) ? true : false;
}

void Player::resetCard(){
    while(!Cards.empty())Cards.pop_back();
}

void Player::isBJAtBeginning(){
    BJAtBeginning = (status == PlayerStatusCodes.BlackJack);
}
void Player::isSplitable(){
    splitable = (Cards.size()==2 && Cards[0].Point() == Cards[1].Point());
}
void Player::isInsurable(){
    insurable = (Cards[0].Point() == 1);
}

void Player::initialize(const int& newCard1, const int& newCard2){
    addCard(newCard1);
    addCard(newCard2);
    isBJAtBeginning();
    isSplitable();
    isInsurable();
}

void Player::getStatus(){
    if (scoreMin > GameParameters.Target) {
        status = PlayerStatusCodes.Bust;
    }else if(scoreMax == GameParameters.Target){
        status = PlayerStatusCodes.Twentyone;
        if (beginning) {
            status = PlayerStatusCodes.BlackJack;
        }
    }
}