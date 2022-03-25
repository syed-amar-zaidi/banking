using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace ConsoleApplication1
{
    class Program
    {
        static const int size = 50;     // Total Customers Size limit
        static int day = 0;             // Variable to help in displaying date
        static int Employees_count = 0; // Variable to count number of Employees
        // This Count is used to check current customers in the bank.
        static int customers_count = 0; // Variable to count the number of Registered Customers
        static int Account_no = 1111;   // Variable to Generate Account no
        static int captcha_code = 8989; // A Captcha Code
        static string temp_captcha_code;
        static string TodayDate; // Date is in following format day/month/year
        static string username;
        static string password;
        static string admin_username = "admin";
        static string admin_password = "12345";
        static float processing_fee = 100; // processing fee to be charged on every CUstomer at the time of Account Creation
                                           // option variable is declared globally to be passed to adminMenu() and customer_Menu() function
        static int option;
        static string key; // key variable to  stop the execution temporary

        static string customers_address[] = new string[size];
        static string customers_name[] = new string[size];
        static string customers_phone_numbers[] = new string[size];
        static string customers_cnic[] = new string[size];
        static string customers_username[] = new string[size];
        static string customers_password[] = new string[size];
        static float customers_balance[] = new float[size];
        static float customers_balance_copy[] = new float[size]; // This Array will store the copy of customers_balance and will help in sorting
        static int customers_sorted_idx[] = new int[size];       // This array will store the indexes of Maximux Cash owning Customers in a Descending Sequence
        static float customers_asset_price[] = new float[size];
        static bool customers_loan_taken_statu[] s = new bool[size];
        static float customers_total_loan_amount[] = new float[size];
        static float customers_loan_amount_left[] = new float[size];
        static float customers_installment[] = new float[size];
        static char customers_status[] = new char[size];
        static int customers_account_no[] = new int[size];
        static string Employees_Name[] = new string[20];        //{"Kevin","john","Jonathan","Mick","Henrick","Fred"};
        static string Employees_Designation[] = new string[20]; //{"Security_Guard","Sweeper","Cashier","Cashier","Cashier","Manager"};
        static int Employees_Salaries[] = new int[20];
        static char Employees_Attendence_month_jan[,] = new char[10, 31];
        // username and password are globally declared to be passed to void function
        static void Main(string[] args)
        {
            // LoadCommonVariables();
            LoadEmployeesDetails();
            LoadAttendence();
            loadData();
            // Fee will be added to bank cash when registering new user.
            float deposit_cash, withdraw_cash;
            string who = " ";

            while (true)
            {
                header();
                who = loginMenu();
                if (who == "ADMIN")
                {
                    option = 1;
                    while (option != 9)
                    {
                        header();
                        admin_menu();
                        if (option == 1)
                        {
                            //  count = count + 1;
                            header();
                            addCustomer();
                            customers_count = customers_count + 1;
                            storeData(customers_count);
                        }
                        else if (option == 2)
                        {
                            header();
                            cout_tab;
if(DeleteAccount()){
    Console.WriteLine("The Account is Delete Successfully.")
}
else{
    Console.WriteLine("Failed to Delete Account.");
}
                            storeData(customers_count);
                        }
                        else if (option == 3)
                        {
                            header();
                            checkAccounts();
                            tempStop();
                        }
                        else if (option == 4)
                        {
                            header();
                            // makeCopyOfBalance();
                            MakeMaxIdxArray();
                            checkAccountsSorted();
                            tempStop();
                        }
                        else if (option == 5)
                        {
                            header();
                            cout_tab();
                    Console.WriteLine("Total Cash in the bank = {0}",totalCashinTheBank(processing_fee));
                    tempStop();
                        }
                        else if (option == 6)
                        {
                            header();
                            takeAttendence();
                            storeAttendence();
                            // storeCommonVariables();
                            tempStop();
                        }
                        else if (option == 7)
                        {
                            header();
                            checkAttendence();
                            tempStop();
                        }
                        else if (option == 8)
                        {
                            header();
                            AssignGoldStatus();
                            tempStop();
                        }
                    }
                }
                else if (who == "CUSTOMER")
                {
                    for (int i = 0; i < customers_count; i++)
                    {
                        if (username == customers_username[i] && password == customers_password[i])
                        {
                            int current_customer_idx = i;
                            option = 1;
                            while (option != 7)
                            {
                                storeData(customers_count);
                                header();
                                customer_Menu();
                                if (option == 1)
                                {
                                    header();
                                    checkAccountsInfo(current_customer_idx);
                                }
                                else if (option == 2)
                                {
                                    header();
                                    cout_tab();
                            Console.WriteLine("Enter amount to deposit:");
                            deposit_cash=float.Parse(Console.ReadLine());
                            if(depositCash(current_customer_idx, deposit_cash)){
                                Console.WriteLine("Your Amount is Successfully Deposited");
                            }
                            else{
                                Console.WriteLine("An Error Occured while depositing Amount");
                            }
                            tempStop();
                                }
                                else if (option == 3)
                                {
                                    header();
                                    cout_tab();
                            Console.WriteLine("Enter amount to withdraw:");
                            Console.ReadLine(withdraw_cash);
                            if(withdrawCash(current_customer_idx, withdraw_cash)){
                                Console.WriteLine("Cash Successfully Withdrawn");
                            }
                            else{
                                Console.WriteLine("An Error Occured while Withdrawing Cash");
                            }
                            tempStop();
                                }
                                if (option == 4)
                                {
                                    header();
                                    if (customers_loan_taken_status[current_customer_idx])== 0)
                                    {
                                        float temp_loan_amount;
                                        float temp_asset_price;
                                        int temp_installment_plan;
                                        cout_tab();
                                Console.WriteLine("Enter Loan Amount::");
                                temp_loan_amount=Console.ReadLine();
                                cout_tab();
                                Console.WriteLine("Enter your Assets Price::");
                                temp_asset_price=Console.ReadLine();
                                if (isLoanEligible(temp_loan_amount, temp_asset_price))
                                {
                                            cout_tab();
                                    Console.WriteLine("Your Request is Successfully Processed.");
                                    cout_tab();
                                    Console.WriteLine("Enter your Installment Plan");
                                    cout_tab();
                                    Console.WriteLine("1_ 12 Months      2_ 24 Months");
                                    cout_tab();
                                    temp_installment_plan = Console.ReadLine();
                                    while (temp_installment_plan > 2 || temp_installment_plan < 1)
                                    {
                                                cout_tab();
                                        Console.WriteLine("Enter Valid Installment Plan");
                                        cout_tab();
                                        Console.WriteLine("1_ 12 Months      2_ 24 Months");
                                        cout_tab();
                                        temp_installment_plan=Console.ReadLine();
                                    }

                                    customers_installment[current_customer_idx] = installment_calculator(temp_installment_plan, temp_loan_amount);
                                    cout_tab();
                                    Console.WriteLine("The Installment is = {0}",customers_installment[current_customer_idx]);
                                    customers_total_loan_amount[current_customer_idx] = temp_loan_amount;
                                    customers_loan_amount_left[current_customer_idx] = customers_total_loan_amount[current_customer_idx];
                                    customers_asset_price[current_customer_idx] = temp_asset_price;
                                    customers_balance[current_customer_idx] = customers_balance[current_customer_idx] + customers_total_loan_amount[current_customer_idx];
                                    customers_loan_taken_status[current_customer_idx] = 1;
                                }
                                else
                                {
                                            cout_tab();
                                    Console.WriteLine("You are not Eligible for Loan because your requested Amount is Too Big!");
                                }
                                    }
                                    else
                                    {
                                        cout_tab();
                                Console.WriteLine("Sorry Sir Loan is already taken.");
                                    }
                                    tempStop();
                                }
                                if (option == 5)
                                {
                                    header();
                                    if (customers_loan_taken_status[current_customer_idx] == 1 && customers_loan_amount_left[current_customer_idx] > 0)
                                    {
                                        if(pay_loan(current_customer_idx)){
                                            Console.WriteLine("Your Loan Installment is Successfully Payed");
                                        }
                                        else{
                                            Console.WriteLine("Sorry, There was an error while PAying Loan");
                                        }
                                        cout_tab();
                                        Console.WriteLine("Your Lefted Amount of Loan is = {0}", customers_loan_amount_left[current_customer_idx]);
                                    }
                                    else
                                    {
                                        cout_tab();
                                        Console.WriteLine("All Loan Amount is already Payed.");
                                    }
                                    tempStop();
                                }
                                else if (option == 6)
                                {
                                    header();
                                    if (customers_loan_taken_status[current_customer_idx] == 1)
                                    {
                                        ViewLoanInfo(current_customer_idx);
                                        tempStop();
                                    }
                                    else
                                    {
                                        cout_tab();
                                        Console.WriteLine("ALL Loan Amount is Already Payed");
                                        tempStop();
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    header();
                    cout_tab();
                    Console.WriteLine("Invalid Credantials");
                    tempStop();
                }
            }
            return 0;
        }

        static void header() // Header of MANAGEMENT SYSTEM
        {
            Console.WriteLine();
            Console.WriteLine();
            Console.WriteLine();
            cout_tab();
            Console.WritleLine(" _______                #  #           #####       |\\    /|                  #####                          #    ");
            cout_tab();
            Console.WritleLine("|       \\               # #   ( )      #   #       | \\  / |                  #   # ####         ####        #         ");
            cout_tab();
            Console.WritleLine("|_______/   ####  #     ##     #  #    #####       |  \\/  | ####  #    ####  ##### # /# #       # /# #    #####  ");
            cout_tab();
            Console.WritleLine("|       \\   #  #  ####  # #    #  ###      #       |      | #  #  #### #  #      # #/   ######) #/   ####   #      ");
            cout_tab();
            Console.WritleLine("|_______/   ####_ #  #  #  #   #  # #  #####       |      | ####_ #  # ####_ ##### #### #  #  ) #### #  #   ##    ");

            Console.WriteLine();
                              cout_tab(); Console.WriteLine("                     ########   #     # ######## ########## ######  #     #                   "));
            cout_tab();
            Console.WriteLine("                     #           #   #  #             #     #       # # # #                   ");
            cout_tab();
            Console.WriteLine("                     ########     # #   ########      #     ######  #  #  #            ");
            cout_tab();
            Console.WriteLine("                            #      #           #      #     #       #     #           ");
            cout_tab();
            Console.WriteLine("                     ########      #    ########      #     ######  #     #           ");
            cout_tab();
            Console.WriteLine("_________________________________________________________________________________________________________________");
            Console.WriteLine();
        }

        // customer menu to be showed
        static void customer_Menu()
        {
            Console.WriteLine("\t\t\tMenu>>>");
            Console.WriteLine("\t\t\t       1_Check Account Info");
            Console.WriteLine("\t\t\t       2_Deposit Cash");
            Console.WriteLine("\t\t\t       3_Withdraw Cash");
            Console.WriteLine("\t\t\t       4_Take Loan");
            Console.WriteLine("\t\t\t       5_Pay Loan");
            Console.WriteLine("\t\t\t       6_View Loan Info");
            Console.WriteLine("\t\t\t       7_Exit");
            Console.WriteLine("\t\t\tEnter your option:");
            Console.WriteLine("\t\t\t");
            option = int.Parse(Console.ReadLine());
            Console.Clear();
        }
        static void tempStop() // FUNCTION TO STOP THE EXECUTION TEMPORARILY
        {
            cout_tab();
            Console.WriteLine("Enter any Key to Continue......");
            Console.ReadKey();
            Console.Clear();
        }
        // STARTING OF ADMIN FUNCTIONALITY HANDLING
        static void admin_menu() // ADmin Menu
        {
            Console.WriteLine("\t\t\tMENU>>>");
            Console.WriteLine("\t\t\t        1_New Account");
            Console.WriteLine("\t\t\t        2_Delete Account");
            Console.WriteLine("\t\t\t        3_Check Accounts");
            Console.WriteLine("\t\t\t        4_Check Accounts in a Sorting Order");
            Console.WriteLine("\t\t\t        5_Check Total Cash in Bank");
            Console.WriteLine("\t\t\t        6_Take Employees Attendence..");
            Console.WriteLine("\t\t\t        7_Check Employees Attendence.");
            Console.WriteLine("\t\t\t        8_Open Recomended Instruction Box.");
            Console.WriteLine("\t\t\t        9_Exit");
            Console.WriteLine("\t\t\tEnter your option:");
            Console.WriteLine("\t\t\t");
            option = Console.ReadLine();
            Console.Clear();
        }
        static bool addCustomer()
        {
            if (customers_count < size)
            {

                cout_tab();
                Console.WriteLine("Enter Customer Name:");
                customers_name[customers_count] = Console.ReadLine();
                cout_tab();
                Console.WriteLine("Enter Customer Phone Number:");
                customers_phone_numbers[customers_count] = Console.ReadLine();
                while (!isValidPhoneNumber(customers_phone_numbers[customers_count]))
                {
                    cout_tab();
                    Console.WriteLine("Enter Valid Phone number.");
                    customers_phone_numbers[customers_count] = Console.ReadLine();
                }
                cout_tab();
                Console.WriteLine("Enter Customers Address:");
                customers_address[customers_count] = Console.ReadLine();
                while (!isValidAddress(customers_address[customers_count]))
                {
                    cout_tab();
                    Console.WriteLine("Valid Address is Typed with (_) underScore.Eg.Shalimar_road_street_6,etc");
                    customers_address[customers_count] = Console.ReadLine();
                }
                cout_tab();
                Console.WriteLine("Enter Customer Cnic:");
                customers_cnic[customers_count] = Console.ReadLine();
                while (!isValidCnic(customers_cnic[customers_count]))
                {
                    cout_tab();
                    Console.WriteLine("Enter Valid Cnic Number..");
            Console.ReadLine(customers_cnic[customers_count];
                }
                cout_tab();
                Console.WriteLine("Assign Current Customer Status.. (r) for Regular.");
                customers_status[customers_count] = char.Parse(Console.ReadLine());
                while (!isValidStatus(customers_status[customers_count]))
                {
                    cout_tab();
                    Console.WriteLine("Enter Valid Customer Status..");
                    customers_status[customers_count] = char.Parse(Console.ReadLine());
                }

                cout_tab();
                Console.WriteLine("Set Username of Customer:");
                customers_username[customers_count] = Console.ReadLine();
                while (!isUserNameNotTaken(customers_username[customers_count]))
                {
                    cout_tab();
                    Console.WriteLine("Username is already Taken.");
                    customers_username[customers_count] = Console.ReadLine();
                }
                cout_tab();
                Console.WriteLine("Enter password of Customer:");
                customers_password[customers_count] = Console.ReadLine();
                while (!isValidPassword(customers_password[customers_count]))
                {
                    cout_tab();
                    Console.WriteLine("First Letter of Password should be in UpperCase.");
                    customers_password[customers_count] = Console.ReadLine();
                }
                customers_account_no[customers_count] = Account_no++;
                Account_no++;
                Console.Clear();
            }
            return true;
        }
        static void checkAccounts()
        {
            if (customers_count > 0)
            {
                cout_tab();
                Console.WriteLine("Account#\tCustomer Name\t\tCustomer PhoneNumber\t\tCustomer Balance\tCustomers Status");
                for (int i = 0; i < customers_count; i++)
                {
                    cout_tab();
                    Console.WriteLine(customers_account_no[i], "\t\t", customers_name[i], "\t\t\t", customers_phone_numbers[i], "\t\t\t\t" customers_balance[i], "\t\t\t", customers_status[i]);
                }
            }
            else
            {
                cout_tab();
                Console.WriteLine("There are no Customers Registered");
            }
        }
        static int MaxIndex()
        {
            float max = customers_balance_copy[0];
            int max_idx = 0;
            for (int i = 0; i < customers_count; i++)
            {
                if (max < customers_balance_copy[i])
                {
                    max = customers_balance_copy[i];
                    max_idx = i;
                }
            }
            return max_idx;
        }

        static void MakeMaxIdxArray()
        {
            for (int a = 0; a < customers_count; a++)
            {
                customers_sorted_idx[a] = MaxIndex();
                customers_balance_copy[MaxIndex()] = -1;
            }
        }
        static void checkAccountsSorted()
        {
            if (customers_count > 0)
            {
                cout_tab();
                Console.WriteLine("Account#\tCustomer Name\t\tCustomer PhoneNumber\t\tCustomer Balance\tCustomers Status");
                for (int i = 0; i < customers_count; i++)
                {
                    cout_tab();
                    Console.WriteLine(customers_account_no[customers_sorted_idx[i]], "\t\t", customers_name[customers_sorted_idx[i]], "\t\t\t", customers_phone_numbers[customers_sorted_idx[i]], "\t\t\t", customers_balance[customers_sorted_idx[i]], "\t\t\t", customers_status[customers_sorted_idx[i]]);
                }
            }
        }
        static float totalCashinTheBank(float processing_fee)
        {
            float total_cash = 0;
            if (customers_count > 0)
            {
                for (int i = 0; i < customers_count; i++)
                {
                    total_cash = total_cash + customers_balance[i] + (customers_count * processing_fee);
                }
            }
            return total_cash;
        }
        // ENDING OF ADMIN FUNCTIONALITY CUSTOMERS
        // STARTING OF CUSTOMERS FUNCTIONALITY FUNCTIONS
        //  checkAccountsInfo() function is used to Show the Customer,s Account Info to Him
        static void checkAccountsInfo(int idx)
        {
            cout_tab();
    Console.WriteLine("Your Username::       ", customers_name[idx]);
    cout_tab();
    Console.WriteLine("Your Phone number        ", customers_phone_numbers[idx]);
    cout_tab();
    Console.WriteLine("your cnic =              ", customers_cnic[idx]);
    cout_tab();
    Console.WriteLine("your address =           ", customers_address[idx]);
    cout_tab,
        Console.WriteLine("your total balance =     ", customers_balance[idx]);
    tempStop();
        }
        // deposit cash function will deposit the cash and will update the customers balance
        static void depositCash(int idx, float deposit_cash)
        {
            if (isCaptchaSolved())
            {
                customers_balance_copy[idx] = customers_balance[idx] + deposit_cash;
                customers_balance[idx] = customers_balance[idx] + deposit_cash;
                return true;
                captcha_code--;
            }
         return false;
        }
        // withdraw Cash Function will withdraw the cash and will update the customers balance
        static bool withdrawCash(int idx, float withdraw_cash) // should be convered in bool at the end of the finish line
        {
            if (withdraw_cash <= customers_balance[idx])
            {
                if (isCaptchaSolved())
                {
                    customers_balance_copy[idx] = customers_balance[idx] - withdraw_cash;
                    customers_balance[idx] = customers_balance[idx] - withdraw_cash;
                    return true;
                }
                return false;
            }
            // isLoanEligible function will Check wheather a customer is Eligible for Loan or Not
           static bool isLoanEligible(float loan_amount, float asset_price)
            {
                if (asset_price >= loan_amount)
                {
                    return true;
                }
                return false;
            }
            //
            float installment_calculator(int temp_installment_plan, float temp_loan_amount)
            {
                float temp;
                if (temp_installment_plan == 1)
                {
                    temp = temp_loan_amount / 12.0;
                }
                else
                {
                    temp = temp_loan_amount / 24.0;
                }
                return temp;
            }
          static bool pay_loan(int idx)
            {
                if (customers_balance[idx] >= customers_installment[idx])
                {
                    if (customers_loan_amount_left[idx] >= customers_installment[idx])
                    {
                        customers_balance[idx] = customers_balance[idx] - customers_installment[idx];
                        customers_loan_amount_left[idx] = customers_loan_amount_left[idx] - customers_installment[idx];
                        return true;
                    }
                    else
                    {
                        customers_balance[idx] = customers_balance[idx] - customers_loan_amount_left[idx];
                        customers_loan_amount_left[idx] = 0;
                        customers_loan_taken_status[idx] = 0;
                    }
                }
           return false;
            }
           static void ViewLoanInfo(int idx)
            {
                cout_tab();
                Console.WriteLine("Total Loan Amount Taken = {0}", customers_total_loan_amount[idx]);
                cout_tab();
                Console.WriteLine("Installment = {0}", customers_installment[idx]);
                cout_tab();
                Console.WriteLine("Total Loan Amount Left  = {0}", customers_loan_amount_left[idx]);
            }
            // ENDING OF CUSTOMER FUNCTIONALITY HANDLING FUNCTIONS
           static void makeCopyOfBalance()
            {
                for (int i = 0; i < customers_count; i++)
                {
                    customers_balance_copy[i] = customers_balance[i];
                }
            }
           static string loginMenu()
            {
                Console.WriteLine("\t\t\tEnter username:");
                username = Console.ReadLine();
                Console.WriteLine("\t\t\tEnter password:");
                password = Console.ReadLine();
                Console.Clear();
                if (username == admin_username && password == admin_password)
                {
                    return "ADMIN";
                }
                if (customers_count > 0)
                {
                    for (int i = 0; i < customers_count; i++)
                    {
                        if (username == customers_username[i] && password == customers_password[i])
                        {
                            return "CUSTOMER";
                        }
                    }
                }
                return "INVALID";
            }
           static void storeData(int idx)
            {
               string path = "TempPath";
                StreamWriter file = new StreamWriter(path);
    if(File.Exists(path){)
                  for (int iteration = 0; iteration < idx; iteration++)
                    {
                        file.Write(customers_name[iteration],",");
                        file.Write( customers_address[iteration], ",");
                        file.Write( customers_phone_numbers[iteration] , ",");
                        file.Write( customers_cnic[iteration] ,",");
                        file.Write( customers_username[iteration] ,",");
                        file.Write( customers_password[iteration]  ",");
                        file.Write( customers_balance[iteration] ,",");
                        customers_balance_copy[iteration] = customers_balance[iteration];
                        file.Write( customers_balance_copy[iteration] ,",");
                        file.Write( customers_sorted_idx[iteration] ,",");
                        file.Write( customers_asset_price[iteration] ,",");
                        file.Write( customers_loan_taken_status[iteration] ,",");
                        file.Write( customers_total_loan_amount[iteration] ,",");
                        file.Write( customers_loan_amount_left[iteration] ,",");
                        file.Write( customers_installment[iteration] ,",");
                        file.Write( customers_status[iteration] ,",");
                        file.WriteLine( customers_account_no[iteration]);
                    }
                    file.Flush();
                    file.Close();
}
static void loadData()
{
                    string line;
                    customers_count = 0;
                    string path = "C:\\Users\\kali\\Videos\bank\\customerData.txt";  //path sohould be set at the start of execution is file path is changed
                    StreamReader file = new StreamReader(path)
                    if(File.Exists(path)){
                        while((line = file.ReadLine) != null){
customer_name[customers_count] = sperateField(line,1);
 customers_address[customers_count] = seperateField(line,2);
                         customers_phone_numbers[customers_count]=seperateField(line,3);
                         customers_cnic[customers_count]=seperateField(line,4);
                         customers_username[customers_count]=seperateField(line,5);
                         customers_password[customers_count]=seperateField(line,6);
                        customers_name[customers_count] = seperateField(line,7);
                        customers_balance[customers_count] = float.Parse(seperateField(line,8));
                        customers_balance_copy[customers_count] = float.Parse(seperateField(line,9));
                        customers_sorted_idx[customers_count] = float.Parse(seperateField(line,10));
                        customers_asset_price[customers_count] float.Parse(seperateField(line,11));
                        customers_loan_taken_status[customers_count] = float.Parse(seperateField(line,12));
                        customers_total_loan_amount[customers_count] = float.Parse(seperateField(line,13));
                        customers_loan_amount_left[customers_count] = float.Parse(seperateField(line,14));
                        customers_installment[customers_count] = float.Parse(seperateField(line,15));
                        customers_status[customers_count] = bool.Parse(seperateField(line,16));
                        customers_account_no[customers_count] = int.Parse(seperateField(line,17));
                        customers_count++;
                        Account_no++;
                    }
                    file.Flush();
                    file.Close();
}
static string seperateField(string line,int field){
    string temp = "";
    int commaCount = 1;
    for(int i = 0;i < line.Length;i++){
        if(line[i] == ','){
            temp = "";
            commaCount++;
        }
        if(commaCount == field){
            temp = temp+line[i];
        }
    }
    return temp;
}
static bool isValidPhoneNumber(string temp_phone)
{
                    int num_count = 0;
                    while (temp_phone[num_count] != '\0')
                    {
                        num_count++;
                    }
                    if (num_count == 11)
                    {
                        return true;
                    }
                    return false;
}
static bool isValidCnic(string temp_cnic)
{
                    int num_count = 0;
                    while (temp_cnic[num_count] != '\0')
                    {
                        num_count++;
                    }
                    if (num_count == 13)
                    {
                        return true;
                    }
                    return false;
}
static bool isValidPassword(string temp_password)
{
                    int temp_Ascii = int(temp_password[0]);
                    if (temp_Ascii >= 65 && temp_Ascii <= 90)
                    {
                        return true;
                    }
                    return false;
}
static bool isUserNameNotTaken(string temp_username)
{
                    for (int i = 0; i < customers_count; i++)
                    {
                        if (temp_username == customers_username[i])
                        {
                            return false;
                        }
                    }
                    return true;
}
static bool isValidAddress(string temp_address)
{
                    for (int i = 0; i < temp_address.length(); i++)
                    {
                        if (temp_address[i] == '_')
                        {
                            return true;
                        }
                    }
                    return false;
}
static bool isValidStatus(char temp_c)
{
                    if (temp_c == 'r')
                    {
                        return true;
                    }
                    return false;
}
static void show_captcha_code()
{
                    temp_captcha_code = string.Parse(captcha_code);
                    cout_tab();
    Console.WriteLine("*************************************");
    cout_tab();
    Console.WriteLine(temp_captcha_code[0], "****************");
    cout_tab();
    Console.WriteLine(temp_captcha_code[1],"*********************");
    cout_tab();
    Console.WriteLine("************************ {0}{1}",temp_captcha_code[2],temp_captcha_code[3]);
    cout_tab();
    Console.WriteLine("************************************");
    captcha_code--;
}
static bool isCaptchaSolved()
{
                    string temp_user_captcha_code = " ";
                    int temp_captcha_count = 0;
                    show_captcha_code();
                    cout_tab();
    Console.WriteLine("Enter Captcha Code from Above..");
    cout_tab();
    temp_user_captcha_code=int.Parse(Console.ReadLine());
    while (temp_user_captcha_code != temp_captcha_code)
    {
                        cout_tab();
        Console.WriteLine("Enter Valid Captcha Code..");
        temp_user_captcha_code=Console.ReadLine();
        cout_tab();
        Console.WriteLine("Temp Captcha code = {0}",temp_user_captcha_code);
        temp_captcha_count++;
        if (temp_captcha_count == 5)
        {
                            return false;
        }
    }
    return true;
}
static void takeAttendence()
{
                    for (int i = 0; i < Employees_count; i++)
                    {
                        cout_tab();
        Console.WriteLine("Is Present ", Employees_Name[i], "  " , Employees_Designation[i] , " :? (p) for Present (a) for absennt (l) for Leave::");
        Employees_Attendence_month_jan[i,day]=char.Parse(Console.ReadLine());
                    }
                    day++;
                    UpdateDate();
}
static void UpdateDate()
{
                    string month = "-01-2022";
                    string temp_day = string.Parse((day));
                    TodayDate = temp_day + month;
                    cout_tab();
    Console.WriteLine("Today Date = {0}",TodayDate)  ;
}
static void checkAttendence()
{
                    cout_tab();
    Console.WriteLine("Today Date ::{0}",TodayDate)  ;
    Console.Write("\t ";
    if (day < 11)
    {
                        cout_tab();
                        for (int a = 0; a < day; a++)
                        {
                            if (a < 9)
                            {
                Console.Write(0);
                            }
            Console.Write(a + 1 , "  ");
                        }
    }
    else
    {
                        cout_tab();
                        for (int a = day - 10; a < day; a++)
                        {
                            if (a < 9)
                            {
                Console.Write(0);
                            }
            Console.Write(a + 1 , "  ");
                        }
    }
    Console.WriteLine();
    for (int i = 0; i < Employees_count; i++)
    {
                        cout_tab();
        Console.Write(Employees_Name[i];
        Console.Write("\t ";
        if (day < 11)
        {
                            for (int a = 0; a <= day; a++)
                            {
                Console.Write(Employees_Attendence_month_jan[i,a], "   ");
                            }
            Console.WriteLine();
        }
        else
        {
                            for (int a = day - 10; a <= day; a++)
                            {
                Console.WriteLine(Employees_Attendence_month_jan[i,a], "   ");
                            }
            Console.WriteLine();
        }
    }
}
static void storeAttendence()
{                   
     srting path = "C:\\Users\\kali\\Videos\\bank\\EmployeesAttendance.txt";
                    StreamWriter file = new StreamWriter(path);
                    if(File.Exists(path)){
for (int i = 0; i < Employees_count; i++)
                    {
                        for (int a = 0; a < day; a++)
                        {
                            file.Write(Employees_Attendence_month_jan[i,a]);
                        }
                        file.WriteLine();
                    }
                    }
                    file.Flush();
                    file.Close();
}
static void LoadAttendence()
{
                    string line;
                    StreamReader file = new StreamReader(path);
                    if(File.Exists(path)){
                        while((line = file.ReadLine()) != null){
                            for (int i = 0; i < Employees_count; i++)
                        {
                            day = 0;
                            for (int a = 0; a < line.length(); a++)
                            {
                                Employees_Attendence_month_jan[i,a] = line[a];
                                day++;
                            }
                        }
                        }
                    }
                        
}
                    file.Close();
}
/*void LoadEmployeesDetails()
{
                    string temp_s = " ";
                    fstream file;
                    file.open("employees_details.txt", ios::in);
                    int temp_idx = 0;
                    while (!file.eof())
                    {
                         Employees_Name[temp_idx];
                         Employees_Designation[temp_idx];
                         temp_s;
                        Employees_Salaries[temp_idx] = stoi(temp_s);
                        temp_idx++;
                        Employees_count++;
                    }
}
*/
static bool isEligibleGold(int idx)
{
                    if (customers_balance[idx] > 100000)
                    {
                        return true;
                    }
                    return false;
}
static void AssignGoldStatus()
{
                    char temp_choice;
                    int temp_count = 0;
                    for (int i = 0; i < customers_count; i++)
                    {
                        if (isEligibleGold(i) && customers_status[i] == 'r')
                        {
                            cout_tab();
            Console.WriteLine("Customers Name = {0} is Eligible for Gold Status (y) to assign",customers_name[i]);
            temp_choice=char.Parse(Console.ReadLine());
            if (temp_choice == 'G' || temp_choice == 'g')
            {
                                customers_status[i] = 'G';
            }
            temp_count++;
                        }
                    }
                    if (temp_count == 0)
                    {
                        cout_tab();
        Console.WriteLine("There are no Recommended customers For Golden Status.");
        cout_tab();
        Console.WriteLine("Press 1 to Know About Golden Status::");
        temp_count = int.Parse(Console.ReadLine());
        if (temp_count == 1)
        {
                            cout_tab();
            Console.WriteLine("Golden Customers are those whose Bank Balance is greater than 100000 rupees.");
        }
                    }
}
static bool isAccountExist(string name)
{
                    for (int i = 0; i < customers_count; i++)
                    {
                        if (name == customers_username[i])
                        {
                            return true;
                        }
                    }
                    return false;
}
static int SearchIdx(string name)
{
                    int temp_idx = 0;
                    for (int i = 0; i < customers_count; i++)
                    {
                        if (name == customers_username[i])
                        {
                            temp_idx = i;
                        }
                    }
                    return temp_idx;
}
static void DeleteAccount()
{
                    string temp_name;
                    char temp_choice = ' ';
                    Console.WriteLine("\t\t\tEnter username of Customer You Want to Delete ..?");
    temp_name=Console.ReadLine();
    if (isAccountExist(temp_name))
    {
                        Console.WriteLine("\t\t\tAre You sure to Delete ? Press (y) for yes (n) for no.");
        temp_choice= char.Parse(Console.ReadLine());
        if (temp_choice == 'y')
        {
                            int temp_idx = SearchIdx(temp_name);
                            customers_name[temp_idx] = customers_name[customers_count - 1];
                            customers_address[temp_idx] = customers_address[customers_count - 1];
                            customers_phone_numbers[temp_idx] = customers_phone_numbers[customers_count - 1];
                            customers_cnic[temp_idx] = customers_cnic[customers_count - 1];
                            customers_username[temp_idx] = customers_username[customers_count - 1];
                            customers_password[temp_idx] = customers_password[customers_count - 1];
                            customers_balance[temp_idx] = customers_balance[customers_count - 1];
                            customers_balance_copy[temp_idx] = customers_balance_copy[customers_count - 1];
                             // This Array will store the copy of customers_balance and will help in sortingt customers_sorted_idx[size];     // This array will store the indexes of Maximux Cash owning Customers in a Descending Sequence
                            customers_asset_price[temp_idx] = customers_asset_price[customers_count - 1];
                            customers_loan_taken_status[temp_idx] = customers_loan_taken_status[customers_count - 1];
                            customers_total_loan_amount[temp_idx] = customers_total_loan_amount[customers_count - 1];
                            customers_loan_amount_left[temp_idx] = customers_loan_amount_left[customers_count - 1];
                            customers_installment[temp_idx] = customers_installment[customers_count - 1];
                            customers_status[temp_idx] = customers_status[customers_count - 1];
                            customers_account_no[temp_idx] = customers_account_no[customers_count - 1];
                            customers_count--;
                            return true; 
        }
    }
   return false;
}
static void cout_tab()
{
                    Console.WriteLine("\t\t\t");
}
            }
        }
