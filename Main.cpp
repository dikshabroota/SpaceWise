#include <iostream>
#include <string>
#include <queue>

using namespace std;

#include "ParkingLot.cpp"
#include "Charges.cpp"

#define GREEN_TEXT "\033[32m"
#define RESET_COLOR "\033[0m"
#define RED_TEXT "\033[31m"
#define YELLOW_TEXT "\033[33m"

int main()
{

    ParkingLot parking_lot;
    Vehicle vehicle;
    Charges fee_calculator;
    queue<Vehicle> four_wheeler_queue;

    int choice;

    while (true)
    {
        cout << endl;
        cout << YELLOW_TEXT << "Parking Lot Management System" << RESET_COLOR << endl;
        cout << "1. Enter Vehicle" << endl;
        cout << "2. Exit Vehicle" << endl;
        cout << "3. Display Charges" << endl;
        cout << "4. Check Availability and Status" << endl;
        cout << "5. Exit Program" << endl;
        cout << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
        {
            string license_plate;
            string owner_name;
            cout << "Enter license plate number : ";
            cin >> license_plate;
            cout << "Enter owner's name : ";
            cin >> owner_name;
            cout << endl;

            vehicle.setDetails(license_plate, owner_name);

            if (parking_lot.is_space_available())
            {

                int spot_number = parking_lot.allocate_parking_spot(vehicle);

                if (spot_number != -1)
                {
                    cout << endl;
                    cout << "PARKING SPOT ALLOTTED!" << endl
                         << endl;
                    cout << "Your spot number is " << GREEN_TEXT << spot_number << "." << RESET_COLOR << endl;
                    cout << endl;
                }
                else
                {
                    cout << "No parking spot available" << endl;
                }
            }
            else
            {
                four_wheeler_queue.push(vehicle);
                cout << endl;
                cout << "No space vacant, please wait for your turn." << endl;
                cout << "You are number " << four_wheeler_queue.size() << " in the waiting list" << endl;
                cout << "Thank you for your cooperation!" << endl;
                cout << endl;
            }

            break;
        }

        case 2:
        {

            int spot_number;
            int parked_hours;
            cout << "Enter your spot number : ";
            cin >> spot_number;

            bool exit_temp = parking_lot.deallocate_parking_spot(spot_number);

            if (exit_temp)
            {
                cout << endl;
                cout << "Enter number of hours : ";
                cin >> parked_hours;
                cout << endl;
                cout << endl;
                if (parked_hours <= 0)
                {
                    cout << "Enter valid hours" << endl;
                }

                cout << "**************** FEE RECEIPT **************" << endl
                     << endl;

                Vehicle vehicle_temp = parking_lot.getVehicleAtSpot(spot_number);

                if (!vehicle_temp.getLicensePlate().empty())
                {
                    cout << "License Plate: " << vehicle_temp.getLicensePlate() << endl;

                    cout << "Owner: " << vehicle_temp.getOwnerName() << endl;
                }

                float total_fee = fee_calculator.charges(parked_hours);

                if (total_fee == 1000)
                {
                    cout << "Total fee: "
                         << "Rs." << total_fee << RED_TEXT << "(penalty)" << RESET_COLOR << endl
                         << endl;
                }
                else
                {
                    cout << "Total fee: "
                         << "Rs." << total_fee << endl
                         << endl;
                }

                cout << "*******************************************" << endl;

                if (!four_wheeler_queue.empty())
                {

                    spot_number = parking_lot.allocate_parking_spot(four_wheeler_queue.front());

                    cout << endl;
                    cout << "Spot allocated to vehicle waiting" << endl;
                    cout << "license plate : " << four_wheeler_queue.front().getLicensePlate() << endl;
                    cout << "Owner's name : " << four_wheeler_queue.front().getOwnerName() << endl;
                    cout << "spot number is " << GREEN_TEXT << spot_number << RESET_COLOR << endl
                         << endl;

                    four_wheeler_queue.pop();
                }
            }
            else
            {
                cout << endl;
                cout << "Invalid spot number or already vacant" << endl;
            }

            break;
        }

        case 3:
        {
            int parked_hours;
            cout << "----------------------------------------" << endl;
            cout << "              CHARGES             " << endl;
            cout << "----------------------------------------" << endl;
            cout << "Welcome to our parking services" << endl;
            cout << endl;
            cout << "Base charge = Rs.20/-" << endl;
            cout << "Less than 1 hour : Base charge + Rs.0/-" << endl;
            cout << "Between 1-2 hours : Base charge + Rs.20/-" << endl;
            cout << "Between 2-3 hours : Base charge + Rs.40/-" << endl;
            cout << "More than 3 hours : Penalty" << endl;
            cout << endl;

            //   double total_fee = fee_calculator.calculate_fee(parked_hours);
            //  cout << "Total fee: " << total_fee << " rp" <<endl;

            break;
        }

        case 4:
        {

            cout << "Vacant spots: " << parking_lot.getNumVacantSpots() << endl;
            cout << "Occupied spots: " << parking_lot.getNumOccupiedSpots() << endl;

            bool available_temp = parking_lot.is_space_available();
            if (available_temp)
            {
                cout << "Space is vacant, you can park the vehicle " << endl;
            }
            else
            {
                cout << "No space vacant, please enter the parking lot and wait for your turn." << endl;
            }
            cout << endl;
            parking_lot.print_spot_status();

            break;
        }

        case 5:
        {
            cout << "Exiting program....." << endl;
            cout << endl;
            return 0;
        }

        default:
        {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
        }
    }

    return 0;
}
