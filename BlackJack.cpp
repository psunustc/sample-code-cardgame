#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include <cstdlib>
#include <locale>

#include "lib/miscClass/Dictionary.h"
#include "lib/miscClass/ExceptionsClass.h"
#include "lib/miscClass/NLPClass.h"
#include "lib/miscClass/CardClass.h"
#include "lib/miscClass/DealCardClass.h"

#include "lib/BJClass/PlayerBaseClass.h"
#include "lib/BJClass/PlayerDealerClass.h"
#include "lib/BJClass/PlayerGuestClass.h"

#include "lib/UserClass/UserGameRulesClass.h"
#include "lib/UserClass/UserGameStatisticsClass.h"
#include "lib/UserClass/UserAccountClass.h"
#include "lib/UserClass/UserCommandClass.h"

#include "lib/UIClass/UserInterfaceClass.h"
#include "lib/UIClass/UserInterfaceGameClass.h"

#include "lib/BJClass/GameBlackJackClass.h"
#include "lib/GameClass.h"


int main(){
    Game NewGame;
    NewGame.playGame();
    return 0;
}
