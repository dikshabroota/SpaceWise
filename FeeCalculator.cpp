class FeeCalculator
{

public:
    int base_fee = 20;
    int total_fee = base_fee;
    int calculate_fee(int parked_hours) const
    {
        if (parked_hours == 1)
        {
            return total_fee;
        }
        if (parked_hours == 2)
        {
            return total_fee + 10;
        }
        else if (parked_hours == 3)
        {
            return total_fee + 50;
        }
        else
        {
            return 5000;
        }
    }
};