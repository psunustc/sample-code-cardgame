class Dealer : public Player{
public:
    void setSoftHand(const int& softhit);
    void strategy(int newCard);
    std::string showCard0();
    std::string showPoint0();
    std::string showCards();
    std::string showPoints();
    void clear();
};

void Dealer::setSoftHand(const int& softhit){
    softhand=softhit;
}
void Dealer::strategy(int newCard){
    if (softhand==GameParameters.HardHitOn) {
        if(scoreMax<GameParameters.HardHit){
            addCard(newCard);
        }else{//stand
            status=PlayerStatusCodes.Stand;
        }
    }else{
        if((score)<GameParameters.HardHit){//hit
            addCard(newCard);
        }else{//stand
            status=PlayerStatusCodes.Stand;
        }
    }
}

std::string Dealer::showCard0(){
    std::stringstream output;
    output<<Cards[0].SuitName()<<"  ??";
    return output.str();
}

std::string Dealer::showPoint0(){
    std::stringstream OutPut;
    OutPut<<std::setw(3)<<Cards[0].Point()<<"+";
    if (Cards[0].Point() == 1) OutPut<<"("<<GameParameters.SoftHand<<"+)";
    return OutPut.str();
}
std::string Dealer::showCards(){
    std::stringstream output;
    for (int i=0; i<Cards.size(); i++)
        output<<Cards[i].SuitName()<<" ";
    return output.str();
}

std::string Dealer::showPoints(){
    std::stringstream OutPut;
    OutPut<<std::setw(3)<<scoreMin;
    if (scoreMax>scoreMin) OutPut<<'('<<scoreMax<<')';
    return OutPut.str();
}

void Dealer::clear(){
    score = 0;
    scoreMax = 0;
    scoreMin = 0;
    ace = 0;
    status = 0;
    softhand = 0;
    resetCard();
}