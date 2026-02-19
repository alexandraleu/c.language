#include<iostream>
#include<vector>

class wallet{
    public:
        int balance = 0;

        void addMoney(int amount){
            balance += amount;
        }

        void removeMoney(int amount){
            balance -= amount;
        }
};

class coffeeMachine{
    std::vector<std::string> products = {"Espresso", "Latte", "Cappuccino"};
    std::vector<int> prices = {5, 10, 15};

    public:
        void buyCoffee(wallet &w){
            std::cout << "Select a product: " << std::endl;
            for(int i = 0; i<products.size(); i++){
                std::cout << i+1 << ". " << products[i] << " - $" << prices[i] << std::endl;
            }
            int choice;

            std::cin >> choice;

            switch(choice){
                case 1:
                    if(w.balance >= prices[choice-1]){
                        w.removeMoney(prices[choice-1]);
                        std::cout << "You bought an Espresso!" << std::endl;
                    }
                    else std::cout << "Not enough balance!" << std::endl;
                    break;

                case 2:
                    if(w.balance >= prices[choice-1]){
                        w.removeMoney(prices[choice-1]);
                        std::cout << "You bought a Latte!" << std::endl;
                    }
                    else std::cout << "Not enough balance!" << std::endl;
                    break;

                case 3:
                    if(w.balance >= prices[choice-1]){
                        w.removeMoney(prices[choice-1]);
                        std::cout << "You bought a Cappuccino!" << std::endl;
                    }
                    else std::cout << "Not enough balance!" << std::endl;
                    break;

                default:
                    std::cout << "Invalid choice!" << std::endl;
            }
        }
};


int main(){
    wallet myWallet;
    myWallet.addMoney(7);
    
    coffeeMachine CoffeeMachine;
    CoffeeMachine.buyCoffee(myWallet);
    CoffeeMachine.buyCoffee(myWallet);

    return 0;
}