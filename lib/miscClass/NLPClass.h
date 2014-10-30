class NLP{
private:
    Exceptions Xcpts;
    void Cap2Small(std::string&);
    bool isSubString(const char& , const std::string&);
    bool isSubString(const std::string& , const std::vector<std::string>&);
    bool isInteger(const std::string&);
    int StringToInt(const std::string&);
    bool isTextExtracted(const std::string&, const std::string&);
    bool isTextExtracted(const std::string&, const std::vector<std::string>&);
    bool isNumberExtracted(const std::string&, const int&, const int&);
    
public:
    NLP(){}
    void extractText(bool&, const std::string&);
    void extractText(int&, const std::string&, const std::vector<std::string>&);
    void extractText(int&, const std::string&, const int&, const int&);
    void extractText(double&, const std::string&, const std::vector<std::string>&);
    void extractText(double&, const std::string&, const int&, const int&);};

void NLP::Cap2Small(std::string& tmp){
    std::locale loc;
    for (int i=0; i<tmp.size(); i++) {
        tmp[i] = std::tolower(tmp[i], loc);
    }
}

bool NLP::isSubString(const char& Word, const std::string& Dict){
    for (int i=0; i<Dict.size(); i++) {
        if (Word==Dict[i]) {
            return true;
            break;
        }
    }
    return false;
}

bool NLP::isSubString(const std::string& Word, const std::vector<std::string>& Dict){
    for (int i=0; i<Dict.size(); i++) {
        if (Word==Dict[i]) {
            return true;
            break;
        }
    }
    return false;
}

bool NLP::isTextExtracted(const std::string& Word, const std::string& Dict){
    if (isSubString(Word[0], Dict)) {
        return true;
    }else if(isSubString(Word[0], Xcpts.ExceptDict)){
        Xcpts.handleExceptions(Word[0]);
        return false;
    }else{
        std::cout<<"Input not recognizable!\n";
        return false;
    }
}

bool NLP::isTextExtracted(const std::string& Word, const std::vector<std::string>& Dict){
    if (isSubString(Word, Dict)) {
        return true;
    }else if(isSubString(Word[0], Xcpts.ExceptDict)){
        Xcpts.handleExceptions(Word[0]);
        return false;
    }else{
        std::cout<<"Input not recognizable!\n";
        return false;
    }
}

bool NLP::isInteger(const std::string& Input){
    if(isSubString(Input[0], Xcpts.ExceptDict)){
        Xcpts.handleExceptions(Input[0]);
        return false;
    }
    int len=Input.size();
    
    if (len==0) {
        return false;
    }
    int i=0;
    while((Input[i]-'0')>=0 && (Input[i]-'9')<=0) {
        i++;
    }
    if(i==len)return true;
    else return false;
}

bool NLP::isNumberExtracted(const std::string& Answer, const int& Min, const int& Max){
    bool isNumber = isInteger(Answer);
    bool isInRange = StringToInt(Answer)>=Min && StringToInt(Answer)<=Max;
    if (isNumber && isInRange) {
        return true;
    }else if(!isNumber){
        std::cout<<"Not recognizable!\n";
    }else{
        std::cout<<"Out of range!\n";
    }
        return false;
}

int NLP::StringToInt(const std::string& Input){
    int Output;
    std::stringstream(Input)>>Output;
    return Output;
}

void NLP::extractText(bool& Output, const std::string& Question){
    std::string Option("yYnN");
    std::string Answer;
    do{
        std::cout<<Question;
        std::getline(std::cin, Answer);
    }while (!isTextExtracted(Answer, Option));
    
    if (Answer[0]=='y' or Answer[0]=='Y') {
        Output=true;
    }else
        Output=false;
}

void NLP::extractText(int& Output, const std::string& Question, const std::vector<std::string>& Options){
    
    std::string Answer;
    do{
        std::cout<<Question;
        std::getline(std::cin, Answer);
        Cap2Small(Answer);
    }while (!isTextExtracted(Answer, Options));
    CommandMap ComdMap;
    Output = ComdMap.CommandCodes[Answer];
}

void NLP::extractText(int& Output, const std::string& Question, const int& Min, const int& Max){
    std::string Answer;
    do{
        std::cout<<Question;
        std::getline(std::cin, Answer);
    }while (!isNumberExtracted(Answer, Min, Max));
    
    Output=StringToInt(Answer);
}

void NLP::extractText(double& Output, const std::string& Question, const std::vector<std::string>& Options){
   
    std::string Answer;
    do{
        std::cout<<Question;
        std::getline(std::cin, Answer);
        Cap2Small(Answer);
    }while (!isTextExtracted(Answer, Options));
    CommandMap ComdMap;
    Output = ComdMap.CommandCodes[Answer];
}

void NLP::extractText(double& Output, const std::string& Question, const int& Min, const int& Max){
    std::string Answer;
    do{
        std::cout<<Question;
        std::getline(std::cin, Answer);
    }while (!isNumberExtracted(Answer, Min, Max));
    
    Output=StringToInt(Answer);
}