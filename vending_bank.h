#ifndef VENDING_BANK_H
#define VENDING_BANK_H
#include <string>

class VendingBank {

    public:
        VendingBank();
        VendingBank(int id);
        VendingBank(const VendingBank& vb);

        //getters
        int GetPennyCount() const; //returns penny count
        int GetNickelCount() const; //returns nickel count
        int GetDimeCount() const; //gets dime count
        int GetQuarterCount() const; //gets quarter count
        int GetTotalCoinCount() const; //gets count of all coins
        double GetTotalCoinValue() const; //gets total balance/value of all coins

        double GetCurrentBalance() const; //outputs current balance

        int id() const; //returns id

        double GetPennyValue() const; // value .01
        double GetNickelValue() const; //value .05
        double GetDimeValue() const; //value .10
        double GetQuarterValue() const; //value .25
       // FILL IN FURTHER PUBLIC FUNCTIONS HERE

        double ResetBalance(); //sets balance to 0 perhaps for testing

        double InsertCoin(int coin_value); //updates and outputs current balance 
        
        double GiveChange(); // gives change and subracts from current balance and coin counts

        bool BuyItem(int item_price); //subtracts cost from current balance if have enough money else rejects and returns false

        //operator overload
        friend std::ostream& operator<<(std::ostream& stream, const VendingBank& vd); // string output overload

        VendingBank& operator=(VendingBank& vd); // assignment operator overload

        VendingBank operator+(const VendingBank& vd) const; // adding operator overload

    private:
        // id_ is a unique identifier for the VendingBank
        // much like a serial number
        const int id_ ;
        //FILL IN FURTHER DATA MEMBERS HERE

        double current_balance_; //current balance
    
        int penny_coin_count_; // penny count
        int nickel_coin_count_; // nickel count
        int dime_coin_count_; //dime count
        int quarter_coin_count_; // quarter count

        const double penny_value_; // .01
        const double nickel_value_; // .05
        const double dime_value_; //.10
        const double quarter_value_; //.25


};


#endif //VENDING_BANK_H
