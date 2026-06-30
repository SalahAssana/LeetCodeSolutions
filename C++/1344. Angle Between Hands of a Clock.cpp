class Solution {
public:
    double angleClock(int hour, int minutes)
    {
        double minute_angle = minutes * 6.0;
        double hour_angle = ((hour * 30) % 360) + ((double)minutes / 60.0) * 30.0;

        double diff = abs(hour_angle - minute_angle);
        return min(diff, 360 - diff);
    }
};
