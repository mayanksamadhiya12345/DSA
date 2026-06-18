class Solution {
public:
    double angleClock(int hour, int minutes) {
        // base 12
        double total_min_angle = minutes * 6; // 6° per minute
        double total_hour_angle = hour * 30 + minutes * 0.5; // 30° per hour + 0.5° per minute

        double ans = abs(total_hour_angle - total_min_angle);
        return min(ans, 360 - ans);
    }
};