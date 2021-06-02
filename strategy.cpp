#include <iostream>

enum Risk {
            low,
            medium,
            high
};

class Strategy {
    public:
        int price;
        int time;
        Risk risk;

};


class Rower : public Strategy {
    public:
    Rower() {
            price = 0;
            time = 60;
            risk = high;

            std::cout<<"Rower\n";
        }
};

class Komunikacja_publiczna : public Strategy {
    public:
    Komunikacja_publiczna() {
            price = 3;
            time = 30;
            risk = medium;

            std::cout<<"Zbiorkom\n";
        }
};

class Taksowska : public Strategy {
    public:
    Taksowska(){
        price = 20;
        time = 15;
        Risk risk = low;

        std::cout<<"Taksowska\n";
    }
};

class StrategySelection {

    public:
        int money;
        int time;
        Risk risk;
    
    StrategySelection(int m, int t, Risk r){
            money = m;
            time = t;
            risk = r;
        }

    Strategy getTransport(){

            if (money >= 20) {
                return Taksowska();
            }

            if (money >= 3) {
                return Komunikacja_publiczna();
            }

            return Rower();

    }
};


int main() {

    int money;
    int time;
    int value;
    Risk risk;

    std::cout<<"How much money do you have?\n";
    std::cin>>money;

    std::cout<<"How much time do you have?\n";
    std::cin>>time;

    std::cout<<"What value the package represents?\n";
    std::cin>>value;


    risk = low;
    if (value > 50) {
        risk = medium;
    }

    if (value > 100) {
        risk = high;
    }

    StrategySelection choice = StrategySelection(money, time, risk);
    Strategy transport = choice.getTransport();


}



