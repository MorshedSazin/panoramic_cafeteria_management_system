#include <iostream>
#include <ctime>
#include <iomanip>
#include<vector>
using namespace std;


int currentTime() {
    time_t t = time(NULL);
    struct tm date = *localtime(&t);
    cout<< t << endl;
    cout << "       ---------------------"<<endl;
    cout << "       | time: " << setw(2) << setfill('0') << date.tm_hour << "h-" << setw(2) << setfill('0') << date.tm_min << "m-" << setw(2) << setfill('0')  << date.tm_sec <<"s |"<< endl;
    cout << "       | date: " << setw(2) << setfill('0') << date.tm_mday << "-" << setw(2) << setfill('0') << date.tm_mon+1 << "-" << setw(2) << setfill('0') << date.tm_year+1900 <<"  |" << endl;
    cout << "       ---------------------"<<endl;
    cout << endl;
    // return date.tm_hour;
    return 9;
    
}

void itemsBar(){
    cout << setw(19) <<setfill(' ') << "Items"  <<setw(19) <<"Prices"  <<setw(21) << "Quantity"<<endl;
    cout << setw(20)  <<"---------" <<setw(20) <<"---------" <<setw(20) <<"---------" <<endl;
}

struct MenuItem {
    string name;
    float price;
    int quantity;
};


class BreakFast{
private:

    vector<MenuItem> menuItems = {
        {"Beef Chowmein",      150.00, 10},
        {"Chicken Chowmein",   110.00, 10},
        {"Khichuri",            70.00, 10},
        {"Pasta",               60.00, 10},
        {"Chicken Wings",       40.00, 10},
        {"Cup Cake",            25.00, 10},
        {"Mixed Vegetable",     25.00, 10},
        {"Eggs",                20.00, 10},
        {"Vagfry",              20.00, 10},
        {"Parata",              10.00, 10},
        {"Coffee",              30.00, 10},
        {"Green Tee",           10.00, 10}
    };

    friend void checkBreakFast(BreakFast);
public :
    void items() {
        cout << "It's Breakfast time.." << endl;
        cout << "Note: To select food for order press number 1 to " << size(menuItems) <<" according to the list:" << endl;
        cout << endl;
        itemsBar();
        cout << endl;

        for (int i = 0; i < menuItems.size(); ++i) {
            cout << left << setfill('.') << setw(2) 
            << i + 1 << ". " << setw(25) << menuItems[i].name << ": " << setw(10) << fixed << setprecision(2) << menuItems[i].price << " tk.../" <<right <<setw(8) <<"0"<< menuItems[i].quantity << endl;
        }
        cout << endl;
    }

    float getPrice(int index) {
        return menuItems[index].price;
    }

    float getQuantity(int index) {
        return menuItems[index].quantity;
    }

    void updateQuantity(int index, int qty) {
        menuItems[index].quantity -= qty;
    }

};

void checkBreakFast(BreakFast prObj) {
    
    cout << endl << "....Enter 0 to confirm your order." << endl
    << "....Enter your item number 1 to "<<prObj.menuItems.size() <<" like (1 = Beef Chowmein): ";

    float sum = 0;
    int order, quantity; 
    cin >> order;

    if (order == 0) {
        cout << "You have not ordered yet..." << endl;
    } else {
        while (order != 0) {
            if (order >= 1 && order <= prObj.menuItems.size()) {
                cout << "Enter the quantity: ";
                cin >> quantity;
                if(quantity > prObj.getQuantity(order - 1)){
                  cout << "Apologize sir, we're out of " << prObj.menuItems[order - 1].name <<"." <<endl; 
                }else{
                    cout << "You have ordered: " << prObj.menuItems[order - 1].name  <<", and the quantity is: " << quantity << "." << endl <<endl;;
                    
                    sum += prObj.getPrice(order - 1) * quantity;
                    prObj.updateQuantity(order - 1, quantity);
                }
        
            } else {
                cout << endl <<  "Invalid item number." << endl << "Please enter a valid item number or 0 to confirm the order." << endl <<endl;
            }
            cout << "....Enter your item number to continue purchase: ";
            cin >> order;
        }
    }

    cout << endl;
    cout << "Total check to pay: " << fixed << setprecision(2) << sum << " tk..." << endl;
    cout << "--------------------------------" << endl;
}


class Lunch{
private:
    vector<MenuItem> menuItems = {
        {"Beef Kala Bhuna", 160.00, 10},
        {"Beef Bhuna",      130.00, 10},
        {"Beef Biryani",    160.00, 10},
        {"Chicken Biryani", 120.00, 10},
        {"Khichuri",         90.00, 10},
        {"Chicken Fry",      90.00, 10},
        {"Fish Curry",       80.00, 10},
        {"Fish Curry",       25.00, 10},
        {"Dal",              20.00, 10}
    };

    friend void checkLunch(Lunch);
public :
    void items() {
        cout << "It's Lunch time.." << endl;
        cout << "Note: To select food for order pre.:ss number 1 to " << size(menuItems) <<" according to the list:" << endl;
        cout << endl;
        itemsBar();
        cout << endl;

        for (int i = 0; i < menuItems.size(); ++i) {
            cout << left << setfill('.') << setw(2) 
            << i + 1 << ". " << setw(25) << menuItems[i].name << ": " << setw(10) << fixed << setprecision(2) << menuItems[i].price << " tk.../" <<right <<setw(8) <<"0"<< menuItems[i].quantity << endl;
        }
        cout << endl;
    }
    float getPrice(int index) {
        return menuItems[index].price;
    }

    float getQuantity(int index) {
        return menuItems[index].quantity;
    }

    void updateQuantity(int index, int qty) {
        menuItems[index].quantity -= qty;
    }
};

void checkLunch(Lunch prObj){
   
    cout << endl <<"....Enter 0 to confirm the order."<<endl
    <<"....Enter your items number 0 to " << prObj.menuItems.size() <<" like (1 = Beef Biryani): ";
    
    float sum = 0;
    int order, quantity; 
    cin >> order;
    

    if (order == 0) {
        cout << "You have not ordered yet..." << endl;
    } else {
        while (order != 0) {
            if (order >= 1 && order <= prObj.menuItems.size()) {
                cout << "Enter the quantity: ";
                cin >> quantity;
                if(quantity > prObj.getQuantity(order - 1)){
                  cout << "Apologize sir, we're out of " << prObj.menuItems[order - 1].name <<"." <<endl; 
                }else{
                    cout << "You have ordered: " << prObj.menuItems[order - 1].name  <<", and the quantity is: " << quantity << "." << endl <<endl;;
                    
                    sum += prObj.getPrice(order - 1) * quantity;
                    prObj.updateQuantity(order - 1, quantity);

                }
            } else {
                cout << endl <<  "Invalid item number." << endl << "Please enter a valid item number or 0 to confirm the order." << endl <<endl;
            }
            cout << "....Enter your item number to continue purchase: ";
            cin >> order;
        }
    }
    cout << endl;
    cout << "Total check to pay: " << fixed << setprecision(2) << sum << " tk..." << endl;
    cout << "--------------------------------" << endl;
}


class Snacks{
private:
    vector<MenuItem> menuItems = {
        {"Grill Chicken Full",     300.00, 10},
        {"Grill Chicken Half",     230.00, 10},
        {"Grill Chicken Quater",   160.00, 10},

        {"Beef Kala Bhuna",        160.00, 10},
        {"Beef Bhuna",             130.00, 10},

        {"Seekh Kebab",            100.00, 10},

        {"Falooda",                100.00, 10},
        {"Haleem",                  60.00, 10},
        {"Mughlai",                 60.00, 10},

        {"Fuchka Full",             50.00, 10},
        {"Fuchka Half",             30.00, 10},

        {"Naan Roti",               25.00, 10},

        {"Shingara",                10.00, 10},
        {"Samosa",                  10.00, 10},
        {"Luchi",                   10.00, 10},

        {"kola",                       10, 5}

    };

    friend void checkSnacks(Snacks);
public :
    void items() {
        cout << "It's Snacks time.." << endl;
        cout << "Note: To select food for order press number 1 to " << size(menuItems) <<" according to the list:" << endl;
        cout << endl;
        itemsBar();
        cout << endl;

        for (int i = 0; i < menuItems.size(); ++i) {
            cout << left << setfill('.') << setw(2) 
            << i + 1 << ". " << setw(25) << menuItems[i].name << ": " << setw(10) << fixed << setprecision(0) << menuItems[i].price << " tk.../" << right <<setw(8) <<"0"<< menuItems[i].quantity << endl;
        }
        cout << endl;
    }
    float getPrice(int index) {
        return menuItems[index].price;
    
    }

    int getQuantity(int index) {
        return menuItems[index].quantity;
    }

    void updateQuantity(int index, int qty) {
        menuItems[index].quantity -= qty;
    }
};

void checkSnacks(Snacks prObj){

    cout << endl <<"....Enter 0 to confirm the order."<<endl
    <<"....Enter your items number 1 to " << prObj.menuItems.size() <<" like (1 = Grill Chicken Full): ";
    
    float sum = 0;
    int order, quantity; 
    cin >> order;

    if (order == 0) {
        cout << "You have not ordered yet..." << endl;
    } else {
        while (order != 0) {
            if (order >= 1 && order <= prObj.menuItems.size()) {
                cout << "Enter the quantity: ";
                cin >> quantity;
                if(quantity > prObj.getQuantity(order - 1)){
                  cout << "Apologize sir, we're out of " << prObj.menuItems[order - 1].name <<"." <<endl; 
                }else{
                    cout << "You have ordered: " << prObj.menuItems[order - 1].name  <<", and the quantity is: " << quantity << "." << endl <<endl;;
                    
                    sum += prObj.getPrice(order - 1) * quantity;
                    prObj.updateQuantity(order - 1, quantity);
                }
        
            } else {
                cout << endl <<  "Invalid item number." << endl << "Please enter a valid item number or 0 to confirm the order." << endl <<endl;
            }
            cout << "....Enter your item number to continue purchase: ";
            cin >> order;
        }
    }

    cout << endl;
    cout << "Total check to pay: " << fixed << setprecision(2) << sum << " tk..." << endl;
    cout << "--------------------------------" << endl;
}


class Dinner{
private:
int a = 10, b = 10, c = 10, d = 10, e = 10, f = 10;
    vector<MenuItem> menuItems = {
        {"Beef_Kala_Bhuna",     300.00, a},
        {"Beef_Biryani",        130.00, b},
        {"Beef_Bhuna",          160.00, c},

        {"Chicken_Biryani",     160.00, d},
        {"Khichuri",            130.00, e},

        {"Chicken_Fry",         100.00, f},

        {"Fish_Curry",          100.00, a},
        {"Vegetable_Bhaji",      60.00, a},
        {"Dal",                  60.00, a},

        {"Fuchka_Full",          50.00, a},
        {"Fuchka_Half",          30.00, a},

        {"Naan_Roti",            25.00, a},

        {"Shingara",             10.00, a},
        {"Samosa",               10.00, a},
        {"Luchi",                10.00, a}
    };
   
    friend void checkDinner(Dinner);
public :
    void items() {
       cout << "It's Dinner time.." << endl;
        cout << "Note: To select food for order press number 1 to " << size(menuItems) <<" according to the list:" << endl;
        cout << endl;
        itemsBar();
        cout << endl;

        for (int i = 0; i < menuItems.size(); ++i) {
            cout << left << setfill('.') << setw(2) 
            << i + 1 << ". " << setw(25) << menuItems[i].name << ": " << setw(10) << fixed << setprecision(2) << menuItems[i].price << " tk.../" <<right <<setw(8) <<"0"<< menuItems[i].quantity << endl;
        }
        cout << endl;
    }
    float getPrice(int index) {
        return menuItems[index].price;
    }

    float getQuantity(int index) {
        return menuItems[index].quantity;
    }

    void updateQuantity(int index, int qty) {
        menuItems[index].quantity -= qty;
    }
};

void checkDinner(Dinner prObj){

    cout << endl <<"....Enter 0 to confirm the order."<<endl
    <<"....Enter your items number 0 to " << prObj.menuItems.size() <<" like (1 = Beef Kala Bhuna): ";
    
    float sum = 0;
    int order, quantity; 
    cin >> order;

    if (order == 0) {
        cout << "You have not ordered yet..." << endl;
    } else {
        while (order != 0) {
            if (order >= 1 && order <= prObj.menuItems.size()) {
                cout << "Enter the quantity: ";
                cin >> quantity;
                if(quantity > prObj.getQuantity(order - 1)){
                  cout << "Apologize sir, we're out of " << prObj.menuItems[order - 1].name <<"." <<endl; 
                }else{
                    cout << "You have ordered: " << prObj.menuItems[order - 1].name  <<", and the quantity is: " << quantity << "." << endl <<endl;;
                    
                    sum += prObj.getPrice(order - 1) * quantity;
                    prObj.updateQuantity(order - 1, quantity);
                }
        
            } else {
                cout << endl <<  "Invalid item number." << endl << "Please enter a valid item number or 0 to confirm the order." << endl <<endl;
            }
            cout << "....Enter your item number to continue purchase: ";
            cin >> order;
        }
    }

    cout << endl;
    cout << "Total check to pay: " << fixed << setprecision(2) << sum << " tk..." << endl;
    cout << "--------------------------------" << endl;
}


int main() {

    int time = currentTime();

    if(time < 8 && time > 22) { 
        cout <<setw(33) <<".....SORRY! We're closed....." << endl<<endl;
    } else if(time >= 8 && time < 11){
        BreakFast breakFast;
        breakFast.items();
        checkBreakFast(breakFast);
    }else if(time >= 11 && time < 16) {
        Lunch lunch;
        lunch.items();
        checkLunch(lunch);
    }else if (time >= 16 && time < 20) {
        Snacks snacks; 
        snacks.items();
        checkSnacks(snacks);
    }else {
        Dinner dinner;
        dinner.items();
        checkDinner(dinner);
    }
    return 0;
}
