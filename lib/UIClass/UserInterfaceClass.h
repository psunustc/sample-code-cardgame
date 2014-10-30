class UserInterface{
    bool continueGame;
    void UIWhiteHead();
    void UIWelcome();
    void UIDialogue();
public:
    UserInterface();
    void initInterface();
    bool continueInterface(const UserAccount&);
    void endInterface();
    
};

UserInterface::UserInterface():continueGame(true){}

void UserInterface::UIWhiteHead(){
    for (int i=0; i<100; i++) {
        std::cout<<std::endl;
    }
    for (int i=0; i<60; i++) {
        std::cout<<"*";
    }
    std::cout<<"\n";
}

void UserInterface::UIWelcome(){
    std::cout<<"\t\tWelcome to the BlackJack!"<<std::endl;
    std::cout<<"Please type H/h for HELP or E/e to EXIT any time!\n";
    std::cout<<"\n";
}

void UserInterface::UIDialogue(){
    std::string Question("\nDo you want to continue?(y/n):");
    NLP NLP;
    NLP.extractText(continueGame, Question);
}

void UserInterface::initInterface(){
    UIWhiteHead();
    UIWelcome();
}

bool UserInterface::continueInterface(const UserAccount& NewUser){
    //if (NewUser.NewStatistics.Hands==0)return true;
    UIDialogue();
    return continueGame;
}
void UserInterface::endInterface(){
}