#include "waiter.hpp"
using namespace std;
double Order::totalRevenue = 0;
int main()
{

    Waiter w;
    int option;

    while (true)
    {
        cout << "\n--- HOTEL MANAGEMENT ---\n1. New Customer\n2. View Total Sales\n0. Close Hotel\nOption: ";
        cin >> option;

        if (option == 1)
        {
            w.takeOrder();
        }
        else if (option == 2)
            w.getTotalRev();
        else if (option == 0)
            break;
        else
            cout << "Invalid Option!!!" << endl;
    }

    cout << "Hotel Closed. Final Report: " << endl;
    Order::showTotalRevenue();

    return 0;
}
