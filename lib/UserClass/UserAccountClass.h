//#include "UserGameRulesClass.h"
//#include "UserGameStatisticsClass.h"

struct UserAccount{
    std::string UserName;
    UserGameStatistics NewStatistics;
    UserGameRules NewRules;
    
    void loadAccount();
    void setAccount();
    void saveAccount();
    void setUserName();
    bool isNewUser(std::string);
    bool isAlive();
    
    UserAccount():UserName(""){}

};

bool UserAccount::isAlive(){
    return NewStatistics.isAlive();
}

void UserAccount::saveAccount(){
    
}

void UserAccount::loadAccount(){
    
}

void UserAccount::setUserName(){
    std::cout<<"Please enter your username:";
    std::getline(std::cin, UserName);
}

bool UserAccount::isNewUser(std::string name){
    return true;
}

void UserAccount::setAccount(){
    //setUserName();
    if (isNewUser(UserName)) {
        NewRules.setGameRules();
    }else{
        loadAccount();
    }
}