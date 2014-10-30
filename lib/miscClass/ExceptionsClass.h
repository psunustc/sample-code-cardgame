class Exceptions{
    void getHelpMenu();
    void exitGame();
public:
    std::string ExceptDict;
    
    Exceptions();

    void handleExceptions(const char&);
};

Exceptions::Exceptions():ExceptDict("HhEe"){
    
}

void Exceptions::getHelpMenu(){
    std::string line;
    std::fstream file("Doc/BlackJack.txt");
    if (file.is_open()){
        while ( getline (file,line) ){
            std::cout << line << '\n';
        }
        file.close();
    }
}

void Exceptions::exitGame(){
    std::cout<<"\nThanks for playing!";
    std::cout<<"\nPlease send your comments to pengsun00@gmail.com\n";
    std::exit(0);
}

void Exceptions::handleExceptions(const char& code){
    if (code=='e'||code=='E') {
        exitGame();
    }else
        getHelpMenu();
}