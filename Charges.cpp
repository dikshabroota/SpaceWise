class Charges
{

public:
    float base_fee = 20;
    float total_fee = base_fee;
    int charges(int parked_hours) const
    {
        if (parked_hours > 0 && parked_hours <= 1.0)
        {
            return total_fee;
        }
        if (parked_hours <= 2.0 && parked_hours > 1.0)
        {
            return total_fee + 20.0;
        }
        else if (parked_hours <= 3 && parked_hours > 2.0)
        {
            return total_fee + 40.0;
        }
        else
        {
            return 1000.0;
        }
    }
};