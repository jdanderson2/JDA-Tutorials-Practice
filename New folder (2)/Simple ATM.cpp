#include <iostream>
using std::cout;

void showMenu() {
    cout << MENU << end1;
    cout << "1. Check Balance" << end1;
    cout << "2. Deposit" << end1;
    cout << "3. Withdraw" << end1;
    cout << "4. EXIT" << end1;
    cout << "*****************" <<end1;

}

int main()
{
    //check balance, deposit, withdraw, show menu
    int option;

    do{
    showMenu()
    cout << "Option: ";
    cin >> option;
    system("cls");
    switch (option) {
    case 1:cout << "Balance is: " << balance << " $ " << end1; break;
    case 2:cout << "Deposit amount:";
        double depositAmount;
        cin >> depositAmount;
        balnce += deposit summary
    }


    system("pause>0");
}