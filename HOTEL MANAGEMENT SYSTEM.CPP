#include<iostream>
#include<map>
#include<list>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<unistd.h>
using namespace std;
class Room
{
  public:
    int roomNumber;
    string room_type;
    int rent;
    int status;

    Room()
    {
      roomNumber = 0;
      room_type = "None";
      rent = 0;
      status = 0;
    }
    Room addRoom(int);
    void displayRoom();
};
Room Room::addRoom(int rno)
{
  Room room;
  room.roomNumber = rno;
  cout << "Enter room type (AC/Non-AC): ";
  cin >> room.room_type;
  cout << "Enter room rent (per Day)  : ";
  cin >> room.rent;
  room.status = 0;
  cout << "\nRoom Added Successfully!!!" << endl;
  cout << "Press Enter...";
  getch();
  return room;
}
void Room::displayRoom()
{
  string VoO[] = {"Vacant","Occupied"};
  cout << "\n============ [Room Details] ===============" << endl;
  cout << "\nRoom Number    : " << roomNumber << endl;
  cout << "Room Type      : " << room_type << endl;
  cout << "Room Rent      : " << rent << endl;
  cout << "Status         : " << VoO[status] << endl;
  cout << "===========================================" << endl;
}
class Customer
{
	private:
		string name;
		string address;
		string cin_date;
		string cout_date;

    Room room;
    int stay_days;
		float room_rent;
		float restaurant_bill;
		float laundry_bill;
		float game_bill;
		float total_cost;
  public:
    Customer()
    {
      stay_days = 0;
      room_rent = 0.0;
      restaurant_bill = 0.0;
      laundry_bill = 0.0;
      game_bill = 0.0;
      total_cost = 0.0;
    }
    void enter_details();
    void restaurantbill();
    void laundrybill();
    void gamebill();
    void check_info();
    string get_name()
    {
      return name;
    }
    Room& getroom()
    {
      return room;
    }
    void setroom(Room room)
    {
      this->room = room;
    }
    float get_totalcost()
    {
      return this->total_cost;
    }
};
void Customer::enter_details()
{
  fflush(stdin);
  cout << "Enter customer name        : ";
  getline(cin,name);
  fflush(stdin);
  cout << "Enter customer address     : ";
  getline(cin,address);
  fflush(stdin);
  cout << "Enter check - in date      : ";
  getline(cin,cin_date);
  fflush(stdin);
  cout << "Enter check - out date     : ";
  getline(cin,cout_date);
  cout << "Enter Stay Duration (Days) : ";
  cin >> stay_days;
  room_rent = room.rent * stay_days;
  total_cost += room_rent;
}
void Customer::restaurantbill()
{
  system("CLS");
  int choice,n;
  float total_cost = 0.0;
  map<int,string> items = {{1,"Water Bottle"},{2,"Tea"},{3,"BreakFast Combo"},{4,"Lunch"},{5,"Dinner"}};
  map<string,int> item_costs = {{"Water Bottle",20},{"Tea",10},{"BreakFast Combo",90},{"Lunch",110},{"Dinner",150}};
  map<string,int> selected_items = {{"Water Bottle",0},{"Tea",0},{"BreakFast Combo",0},{"Lunch",0},{"Dinner",0}};
  cout << "\n**** RESTAURANT MENU ****" << endl;
  cout << "\n========== ITEMS ========" << endl;
  for(auto i = items.begin();i != items.end();i++)
  {
    cout << i->first << ". " << i->second << "\n\t----> " << item_costs[i->second] << endl;
  }
  cout << "6 > [Calcuate Bill]" << endl;
  cout << "=========================" << endl;
  while(1)
  {
    cout << "\nEnter your choice\n> ";
    cin >> choice;
    if (items.find(choice) != items.end())
    {
    cout << "Selected Item : " << items[choice] << endl;
    cout << "Enter Quantity: ";
    cin >> n;
    selected_items[items[choice]] += n;
    if(n == 1){
      cout << "1 " << items[choice] << " Ordered." << endl;
    }
    else{
      cout << n << " " << items[choice] << "'s Ordered." << endl;
    }
    }
    else if(choice == 6)
    {
    cout << "Calculating Bill";
    for(int i = 0;i < 3;i++){
      sleep(1);
      cout << ".";
    }
    break;
    }
    else
    {
    cout << "INVALID OPTION" << endl;
    }
  }
  system("CLS");
  cout << "RESTAURANT BILL" << endl;
  cout << "==================================================" << endl;
  for(auto it = selected_items.begin();it != selected_items.end();it++)
  {
    if(it->second != 0){
    cout << "Item: " << it->first << "\n\t----> Quantity: " << it->second << "\tPrice: " << item_costs[it->first] * it->second << " Rs." << endl;
    total_cost += item_costs[it->first] * it->second;
    }
  }
  cout << "==================================================" << endl;
  this->restaurant_bill += total_cost;
  this->total_cost += total_cost;
    cout << "Total                                = " << total_cost << " Rs." << endl;
    cout << "==================================================" << endl;
  cout << "Press Enter...";
  getch();
}
void Customer::laundrybill()
{
  system("CLS");
  int choice,n;
  float total_cost = 0.0;
  map<int,string> items = {{1,"Shorts"},{2,"Trousers"},{3,"Shirts"},{4,"Jeans"},{5,"Girls Suit"}};
  map<string,int> item_costs = {{"Shorts",5},{"Trousers",10},{"Shirts",8},{"Jeans",10},{"Girls Suit",20}};
  map<string,int> selected_items = {{"Shorts",0},{"Trousers",0},{"Shirts",0},{"Jeans",0},{"Girls Suit",0}};
  cout << "\n****** LAUNDRY MENU *****" << endl;
  cout << "\n========== ITEMS ========" << endl;
  for(auto i = items.begin();i != items.end();i++)
  {
    cout << i->first << ". " << i->second << "\n\t----> " << item_costs[i->second] << endl;
  }
  cout << "6 > [Calcuate Bill]" << endl;
  cout << "=========================" << endl;
  cout << "     [COST PER PIECE]    " << endl;
  cout << "=========================" << endl;
  
  while(1)
  {
    cout << "\nEnter your choice\n> ";
    cin >> choice;
    if (items.find(choice) != items.end())
    {
    cout << "Selected Item : " << items[choice] << endl;
    cout << "Enter Quantity: ";
    cin >> n;
    selected_items[items[choice]] += n;
    if(n == 1){
      cout << "1 " << items[choice] << " Added." << endl;
    }
    else{
      cout << n << " " << items[choice] << "'s Added." << endl;
    }
    }
    else if(choice == 6)
    {
    cout << "Calculating Bill";
    for(int i = 0;i < 3;i++){
      sleep(1);
      cout << ".";
    }
    break;
    }
    else
    {
    cout << "INVALID OPTION" << endl;
    }
  }
  system("CLS");
  cout << "LAUNDRY BILL" << endl;
  cout << "==================================================" << endl;
  for(auto it = selected_items.begin();it != selected_items.end();it++)
  {
    if(it->second != 0){
    cout << "Item: " << it->first << "\n\t----> Quantity: " << it->second << "\tPrice: " << item_costs[it->first] * it->second << " Rs." << endl;
    total_cost += item_costs[it->first] * it->second;
    }
  }
  cout << "==================================================" << endl;
  this->laundry_bill += total_cost;
  this->total_cost += total_cost;
  cout << "Total                                = " << total_cost << " Rs." << endl;
  cout << "==================================================" << endl;
  cout << "Press Enter...";
  getch();
}
void Customer::gamebill()
{
  system("CLS");
  int choice,n;
  string item;
  float total_cost = 0.0;
  map<int,string> items = {{1,"Table tennis"},{2,"Bowling"},{3,"Snooker"},{4,"Video games"},{5,"Pool"}};
  map<string,int> item_costs = {{"Table tennis",60},{"Bowling",80},{"Snooker",70},{"Video games",90},{"Pool",50}};
  map<string,int> selected_items = {{"Table tennis",0},{"Bowling",0},{"Snooker",0},{"Video games",0},{"Pool",0}};
  cout << "\n****** GAMING MENU ******" << endl;
  cout << "\n========== GAMES ========" << endl;
  for(auto i = items.begin();i != items.end();i++)
  {
    cout << i->first << ". " << i->second << "\n\t----> " << item_costs[i->second] << endl;
  }
  cout << "6 > [Calcuate Bill]" << endl;
  cout << "=========================" << endl;
  cout << "     [COST PER HOUR]    " << endl;
  cout << "==========================" << endl;
  
  cout << item << endl;
  while(1)
  {
    cout << "\nEnter your choice\n> ";
    cin >> choice;
    if (items.find(choice) != items.end())
    {
    cout << "Selected Item : " << items[choice] << endl;
    cout << "Enter number of Hours: ";
    cin >> n;
    selected_items[items[choice]] += n;
    if(n == 1){
      cout << items[choice] << " for next 1 hour." << endl;
    }
    else{
      cout << items[choice] << " for next " << n << " hours." << endl;
    }
    }
    else if(choice == 6)
    {
    cout << "Calculating Bill";
    for(int i = 0;i < 3;i++){
      sleep(1);
      cout << ".";
    }
    break;
    }
    else
    {
    cout << "INVALID OPTION" << endl;
    }
  }
  system("CLS");
  cout << "GAMING BILL" << endl;
  cout << "==================================================" << endl;
  for(auto it = selected_items.begin();it != selected_items.end();it++)
  {
    if(it->second != 0){
    cout << "Item: " << it->first << "\n\t----> Quantity: " << it->second << "\tPrice: " << item_costs[it->first] * it->second << " Rs." << endl;
    total_cost += item_costs[it->first] * it->second;
    }
  }
  cout << "==================================================" << endl;
  cout << "Total                                = " << total_cost << " Rs." << endl;
  this->game_bill += total_cost;
  this->total_cost += total_cost;
  cout << "==================================================" << endl;
  cout << "Press Enter...";
  getch();
}
void Customer::check_info()
{
    cout << "Customer Name     : " << name << endl;
    cout << "Customer Address  : " << address << endl;
    cout << "Check - In date   : " << cin_date << endl;
    cout << "Check - Out date  : " << cout_date << endl;
    if(stay_days == 1)
    {
      cout << "Stay Duration     : " << stay_days << " Day." << endl;
    }
    else
    {
      cout << "Stay Duration     : " << stay_days << " Days." << endl;
    }
    cout << "Room Number       : " << room.roomNumber << endl;
    cout << "Room Type         : " << room.room_type << endl;
    cout << "Room Rent         : " << room_rent << endl;
    cout << "Restuarnt bill    : " << restaurant_bill << endl;
    cout << "Laundry bill      : " << laundry_bill << endl;
    cout << "Gaming bill       : " << game_bill << endl;
    cout << "============================================" << endl;
}
class HotelManagement:protected Room
{
  static int customer_count;
  static float additional_charges;
  list<Room> rooms;
  public:
    list<Customer> customers;
    HotelManagement()
    {
      rooms = {};
      customers = {};
    }
    void manage_Rooms();
    void add_person();
    void calculate_restaurantbill();
    void calculate_laundrybill();
    void calculate_gamebill();
    void show_Totalcost();
    void changeAdditionalcharges();
    void remove_person();
    void show_persons();
};
int HotelManagement::customer_count = 0;
float HotelManagement::additional_charges = 1000.0;
void HotelManagement::manage_Rooms()
{
  int choice;
  while(1)
  {
    system("CLS");
    int i,rno,flag = 0;
    cout << "==========[ Mange Rooms ]==========" << endl;
    cout << "1. Add Room" << endl;
    cout << "2. Search Room" << endl;
    cout << "3. Delete Room" << endl;
    cout << "4. Display Rooms" << endl;
    cout << "5. Back to Main Menu" << endl;
    cout << "==================================" << endl;
    cout << "Enter your choice\n> ";
    cin >> choice;
    if(choice == 1)
    {
      cout << "\nEnter Room Number: ";
      cin >> rno;
      for(auto it = rooms.begin();it != rooms.end();it++)
      {
        if(it->roomNumber == rno)
        {
          flag = 1;
          break;
        }
      }
      if(flag == 1)
      {
        cout << "\nRoom Already Exists,Please Enter a unique Room Number!!!" << endl;
        cout << "Press Enter...";
        getch();
      }
      else
      {
        Room room = addRoom(rno);
        rooms.push_back(room);
      }
    }
    else if(choice == 2)
    {
      cout << "\nEnter Room Number: ";
      cin >> rno;
      for(auto it = rooms.begin();it != rooms.end();it++)
      {
        if(it->roomNumber == rno)
        {
          it->displayRoom();
          getch();
          flag = 1;
          break;
        }
      }
      if(flag == 0)
      {
        cout << "\nRoom Does not exist" << endl;
        getch();
      }
    }
    else if(choice == 3)
    {
      cout << "\nEnter Room Number: ";
      cin >> rno;
      for(auto it = rooms.begin();it != rooms.end();it++)
      {
        if(it->roomNumber == rno)
        {
          rooms.erase(it);
          cout << "Room Deleted Successfully..." << endl;
          flag = 1;
          getch();
          break;
        }
      }
      if(flag == 0)
      {
        cout << "\nRoom Does not exist!!!" << endl;
        getch();
      }
    }
    else if(choice == 4)
    {
      if(rooms.size() != 0)
      {
        cout << "============== [ Rooms Available ] ==================" << endl;
        for(auto it = rooms.begin();it != rooms.end();it++)
        {
          it->displayRoom();
          cout << endl;
        }
        cout << "=====================================================" << endl;
        getch();
      }
      else 
      {
        cout << "No Rooms Added Yet!!!" << endl;
      }
    }
    else if(choice == 5)
    {
      break;
    }
    else 
    {
      cout << ">>> PLEASE ENTER A VALID CHOICE <<<" << endl;
      getch();
    }
  }
}
void HotelManagement::add_person()
{
  int rno;
  int done = 0,found = 0;
  if(rooms.size() != 0)
  {
    for(auto it = rooms.begin(); it != rooms.end();it++){
      if(it->status != 1){found = 1;}
    }
    if(found == 1)
    {
      system("CLS");
      cout << "\n=============== [ Available Rooms] =================" << endl;
      for(auto it = rooms.begin();it != rooms.end();it++)
      {
        if(it->status != 1){it->displayRoom();}
      }
      cout << "\n====================================================" << endl;
      cout << "\nEnter your room choice(Room No): ";
      cin >> rno;
      Customer c;
      for(auto it = rooms.begin();it != rooms.end();it++)
      {
        if(it->status != 1 && it->roomNumber == rno)
        {
          it->status = 1;
          c.setroom(*it);
          c.enter_details();
          customers.push_back(c);
          cout << "\nCustomer Details updated!!!" << endl;
          cout << "Press Enter...";
          getch();
          done = 1;
          break;
        }
      }
      if(done != 1)
      {
        cout << "\nPlease Enter a valid Room!!!" << endl;
        getch();
      }
    }
    else
    {
      cout << "Sorry !!No Vacant Rooms Available..." << endl;
      getch();
    }
  }
  else 
  {
    cout << "Sorry! No rooms available..." << endl;
    getch();
  }
}
void HotelManagement::calculate_restaurantbill()
{
  string name;
  int found = 0;
  fflush(stdin);
  cout << "Enter customer name: ";
  getline(cin,name);
  for(auto i = customers.begin();i != customers.end();i++)
  {
    if(i->get_name() == name)
    {
      i->restaurantbill();
      found = 1;
      break;
    }
  }
  if(found == 0)
  {
    cout << "\nNo customer with name " << name << "." << endl;
    cout << "Press Enter..." << endl;
    getch();
  }
}
void HotelManagement::calculate_laundrybill()
{
  string name;
  int found = 0;
  fflush(stdin);
  cout << "Enter customer name: ";
  getline(cin,name);
  for(auto i = customers.begin();i != customers.end();i++)
  {
    if(i->get_name() == name)
    {
      i->laundrybill();
      found = 1;
      break;
    }
  }
  if(found == 0)
  {
    cout << "\nNo customer with name " << name << "." << endl;
    cout << "Press Enter..." << endl;
    getch();
  }
}
void HotelManagement::calculate_gamebill()
{
  string name;
  int found = 0;
  fflush(stdin);
  cout << "Enter customer name: ";
  getline(cin,name);
  for(auto i = customers.begin();i != customers.end();i++)
  {
    if(i->get_name() == name)
    {
      i->gamebill();
      found = 1;
      break;
    }
  }
  if(found == 0)
  {
    cout << "\nNo customer with name " << name << "." << endl;
    cout << "Press Enter..." << endl;
    getch();
  }
}
void HotelManagement::show_Totalcost()
{
  string name;
  int found = 0;
  fflush(stdin);
  cout << "Enter customer name: ";
  getline(cin,name);
  for(auto i = customers.begin();i != customers.end();i++)
  {
    if(i->get_name() == name)
    {
      cout << "\n=============== CUSTOMER INFO ==============" << endl;
      i->check_info();
      cout << "Total cost         : " << i->get_totalcost() << endl;
      cout << "Additional charges : " << this->additional_charges << endl;
      cout << "============================================" << endl;
      cout << "Grand Total        : " << i->get_totalcost() + this->additional_charges << endl;
      cout << "============================================" << endl;
      cout << "Press Enter..." << endl;
      getch();
      found = 1;
      break;
    }
  }
  if(found == 0)
  {
    cout << "\nNo customer with name " << name << "." << endl;
    cout << "Press Enter..." << endl;
    getch();
  }
}
void HotelManagement::changeAdditionalcharges()
{
  int na;
  cout << "\n====================================" << endl;
  cout << "PREVIOUS ADDITIONAL CHARGE:" << endl;
  cout << "====================================" << endl;
  cout << "\nEnter new additional charge\n> ";
  cin >> na;
  this->additional_charges = na;
  cout << "\n======== [CHANGE SUCCESSFUL] ========" << endl;
  cout << "Press Enter..." << endl;
  getch();
}
void HotelManagement::remove_person()
{
  if(customers.size() != 0)
  {
    string name;
    int found = 0;
    fflush(stdin);
    cout << "Enter customer name: ";
    getline(cin,name);
    for(auto it = customers.begin();it != customers.end();it++)
    {
      if(it->get_name() == name)
      {
        found = 1;
        it->getroom().status = 0;
        for(auto rt = rooms.begin();rt != rooms.end();rt++)
        {
          if(rt->roomNumber == it->getroom().roomNumber)
          {
            rt->status = 0;
          }
          break;
        }
        customers.erase(it);
        cout << "\nCustomer Deleted Successfully!!!" << endl;
        getch();
        break;
      }
    }
    if(found == 0)
    {
      cout << "\nSorry, No Customer with name " << name << " !!!" << endl;
      getch();
    }
  }
  else 
  {
    cout << "\nSorry, No customer yet!!!" << endl;
    getch();
  }
}
void HotelManagement::show_persons()
{
  cout << "There are total " << customers.size() << " customers in Hotel." << endl;
  getch();
}
class MainMenu
{
    private:
        HotelManagement h;
        map<string,string> staff = {{"Sumanth","sumanth_2174"},{"Pradeep","pradeep_2003"},{"A.Jayasree","jayasree_2004"},{"K.Jayasree","jayasree_2003"}};
    public:
        void mainMenu()
        {
            while(1)
            {
                system("CLS");
                int choice;
                cout << "\n\t**************************************************" << endl;
                cout << "\t************ WELCOME TO ANDHRA HOTEL *************" << endl;
                cout << "\t**************************************************" << endl;
                cout << "\n\t=========== [ MAIN MENU ] ===========" << endl;
                cout << "\t 1.STAFF LOGIN" << endl;
                cout << "\t 2.CUSTOMER LOGIN" << endl;
                cout << "\t 3.EXIT" << endl;
                cout << "\t=====================================" << endl;
                cout << "\t Enter your choice\n\t > ";
                cin >> choice;
                if(choice == 1)
                {
                    cout << "\n\tRedirecting to [STAFF PAGE]";
                    for(int i = 0;i < 3;i++){sleep(1);cout << ".";}
                    this->staff_login();
                }
                else if(choice == 2)
                {
                    cout << "\n\tRedirecting to [CUSTOMER PAGE]";
                    for(int i = 0;i < 3;i++){sleep(1);cout << ".";}
                }
                else 
                {
                    cout << "\n\tEXITING APPLICATION";
                    for(int i = 0;i < 3;i++){sleep(1);cout << ".";}
                }
            }
        }
        void staff_login();
        void staffMenu();
        void customer_login();
        void customerMenu(Customer &c);

};
void MainMenu::staff_login()
{
    system("CLS");
    string name,password;
    cout << "\n**************************************************" << endl;
    cout << "**************** STAFF LOGIN PAGE ****************" << endl;
    cout << "**************************************************" << endl;
    fflush(stdin);
    cout << "\nEnter your name     : ";
    getline(cin,name);
    fflush(stdin);
    cout << "Enter your password : ";
    getline(cin,password);
    if(staff.find(name) != staff.end())
    {
        if(staff[name] == password)
        {
            staffMenu();
        }
        else
        {
            cout << "INCORRECT PASSWORD!!!" << endl;
        }
    }
    else
    {
        cout << "INCORRECT STAFF NAME!!!" << endl;
    }
    cout << "Press Enter..." << endl;
    getch();
}
void MainMenu::staffMenu()
{
  while(1)
  {
    system("CLS");
    int choice;
    cout << "\n========== [STAFF MENU] ==========" << endl;
    cout << "1. Manage Rooms" << endl;
    cout << "2. Enter New Customer Data" << endl;
    cout << "3. Calculate restaurant bill" << endl;
    cout << "4. Calculate laundry bill" << endl;
    cout << "5. Calculate gaming bill" << endl;
    cout << "6. Show total cost" << endl;
    cout << "7. Show total persons" << endl;
    cout << "8. Change additional charges" << endl;
    cout << "9. Remove customer Data" << endl;
    cout << "10. Exit" << endl;
    cout << "==================================" << endl;
    cout << "Enter your choice\n> ";
    cin >> choice;
    if(choice == 1)
    {
      h.manage_Rooms();
    }
    if(choice == 2)
    {
      h.add_person();
    }
    else if(choice == 3)
    {
      h.calculate_restaurantbill();
    }
    else if(choice == 4)
    {
      h.calculate_laundrybill();
    }
    else if(choice == 5)
    {
      h.calculate_gamebill();
    }
    else if(choice == 6)
    {
      system("CLS");
      h.show_Totalcost();
    }
    
    else if(choice == 7)
    {
      h.show_persons();
    }
    else if(choice == 8)
    {
      h.changeAdditionalcharges();
    }
    else if(choice == 9)
    {
      h.remove_person();
    }
    else if(choice == 10)
    {
      break;
    }
    else 
    {
      cout << "\n>>> PLEASE ENTER A VALID CHOICE <<<" << endl;
    }
  }
}
void MainMenu::customer_login()
{
    system("CLS");
    string name;
    int found = 0;
    cout << "\n**************************************************" << endl;
    cout << "************** CUSTOMER LOGIN PAGE ***************" << endl;
    cout << "**************************************************" << endl;
    fflush(stdin);
    cout << "\nEnter your name     : ";
    for(auto i = h.customers.begin();i != h.customers.end();i++)
    {
      if(i->get_name() == name)
      {
        this->customerMenu(*i);
        found = 1;
      }
    }
    if(found == 0)
    {
      cout << "No customer with Name: " << name << endl;
    }
    cout << "Press Enter..." << endl;
    getch();
}
void MainMenu::customerMenu(Customer &c)
{
  while(1)
  {
    system("CLS");
    int choice;
    cout << "====== [CUSTOMER MENU] =======" << endl;
    cout << "1. Go to restaurant" << endl;
    cout << "2. Go to laundry" << endl;
    cout << "3. Go to Gaming" << endl;
    cout << "4. Check Details" << endl;
    cout << "5. Go Back to Main Menu" << endl;
    cout << "==============================" << endl;
    cout << "Enter your choice\n> ";
    cin >> choice;
    if(choice == 1)
    {
      c.restaurantbill();
    }
    else if(choice == 2)
    {
      c.laundrybill();
    }
    else if(choice == 3)
    {
      c.gamebill();
    }
    else if(choice == 4)
    {
      system("CLS");
      cout << "==================================================" << endl;
      cout << "\n[" << c.get_name() << "'s INFO]: " << endl;
      c.check_info();
    }
    else if(choice == 5)
    {
      break;
    }
  }
}
int main()
{
    MainMenu m;
    m.mainMenu();
    return 0;
}
