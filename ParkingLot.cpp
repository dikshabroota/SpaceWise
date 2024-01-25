#include <unordered_map>
#include <iostream>
#include <queue>
using namespace std;

#include "Vehicle.cpp"

#define GREEN_TEXT "\033[32m"
#define RESET_COLOR "\033[0m"
#define RED_TEXT "\033[31m"

class ParkingLot
{
private:
    unordered_map<int, pair<bool, Vehicle>> parking_spots;
    int num_vacant_spots;
    int num_occupied_spots;

public:
    ParkingLot()
    {
        initialize_spots();
        num_vacant_spots = 6; // Assuming all spots are initially vacant
        num_occupied_spots = 0;
    }
    void initialize_spots()
    {
        for (int i = 1001; i <= 1006; ++i)
        {
            parking_spots[i] = make_pair(false, Vehicle());
        }
    }

    // for availablity
    bool is_space_available() const
    {
        for (const auto &spot : parking_spots)
        {
            if (!spot.second.first)
            {
                return true;
            }
        }
        return false;
    }
    // for allocation
    int allocate_parking_spot(Vehicle &vehicle)
    {
        for (auto &spot : parking_spots)
        {
            if (!spot.second.first)
            {
                spot.second.first = true;
                spot.second.second = vehicle; // Store the vehicle in the parking spot
                num_vacant_spots--;
                num_occupied_spots++;
                return spot.first;
            }
        }
        return -1; // No available spot
    }

    // for deallocation
    bool deallocate_parking_spot(int spot_number)
    {
        auto it = parking_spots.find(spot_number);
        if (it != parking_spots.end() && it->second.first)
        {
            it->second.first = false;
            // it->second.second = Vehicle();
            num_occupied_spots--;
            num_vacant_spots++;
            return true; // Space deallocated successfully
        }
        return false; // Invalid spot number or already vacant
    }

    int getNumVacantSpots() const
    {
        return num_vacant_spots;
    }
    int getNumOccupiedSpots() const
    {
        return num_occupied_spots;
    }

    void print_spot_status() const
    {
        int iterationCount = 0;

        for (const auto &spot : parking_spots)
        {
            if (spot.second.first)
            {
                cout << RED_TEXT << spot.first << RESET_COLOR << " "
                     << "[X]"
                     << "   ";
            }
            else
            {
                cout << GREEN_TEXT << spot.first << RESET_COLOR << " "
                     << "[ ]"
                     << "   ";
            }

            iterationCount++;

            if (iterationCount == 2)
            {
                cout << endl;
                iterationCount = 0; // Reset the iteration count
            }
        }
        if (iterationCount != 0)
        {
            cout << endl;
        }
    }

    Vehicle getVehicleAtSpot(int spot_number) const
    {
        auto it = parking_spots.find(spot_number);
        if (it != parking_spots.end())
        {
            return it->second.second;
        }
        return Vehicle();
    }
};
