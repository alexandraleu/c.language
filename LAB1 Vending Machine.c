#include <iostream>
#define N 5
using namespace std;

struct Product {
    char name[20];
    float price;
    int stock;
} *ProductsList;

class SellMachine {
private:
    struct Product *Products;
    float userMoney;
    int selectedProductID;

public:
    SellMachine(struct Product *ProductsList) {
        Products = ProductsList;
        userMoney = 0;
        selectedProductID = -1;
    }

    void receiveMoney(float amount) {
        userMoney += amount;
    }

    int instock(int ProductID) {
        return (Products[ProductID].stock > 0) ? 1 : 0;
    }

    void selectProduct(int ProductID) {
        if (ProductID < 0 || ProductID >= N) {
            cout << "Invalid product ID." << endl;
            return;
        }
        if (!instock(ProductID)) {
            cout << "Product out of stock!" << endl;
            return;
        }
        if (userMoney < Products[ProductID].price) {
            cout << "Not enough money!" << endl;
            return;
        }
        selectedProductID = ProductID;
        cout << "Product " << Products[ProductID].name << " selected." << endl;
    }

    void deselectProduct() {
        selectedProductID = -1;
        cout << "Product deselected." << endl;
    }

    int giveChange() {
        if (selectedProductID == -1) return 0;
        float change = userMoney - Products[selectedProductID].price;
        if (change >= 0) {
            cout << "Giving change: $" << change << endl;
            userMoney = 0;
            return 1;
        }
        return 0;
    }

    void finishTransaction() {
        if (selectedProductID == -1) {
            cout << "No product selected." << endl;
            return;
        }
        if (giveChange()) {
            Products[selectedProductID].stock--;
            cout << "Dispensing product: " << Products[selectedProductID].name << endl;
        }
        selectedProductID = -1;
    }

    void restock(struct Product *ProductsList) {
        Products = ProductsList;
        cout << "SellMachine restocked." << endl;
    }
};

int main() {
    ProductsList = new struct Product[N];
    for (int i = 0; i < N; i++) {
        cout << endl << "Product has code " << i << endl;
        cout << "Name  :";  cin >> ProductsList[i].name;
        cout << "Price :";  cin >> ProductsList[i].price;
        cout << "Stock :";  cin >> ProductsList[i].stock;
    }
    
    SellMachine fmiSellMachine(ProductsList);
    int choice, productID;
    float amount;
    
    do {
        cout << "\n1. Buy Product" << endl;
        cout << "2. Restock Machine" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter money: ";
                cin >> amount;
                fmiSellMachine.receiveMoney(amount);
                
                cout << "Enter product ID: ";
                cin >> productID;
                fmiSellMachine.selectProduct(productID);
                
                fmiSellMachine.finishTransaction();
                break;
            
            case 2:
                fmiSellMachine.restock(ProductsList);
                break;
            
            case 3:
                cout << "Exiting..." << endl;
                break;
            
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 3);
    
    delete[] ProductsList;
    return 0;
}

