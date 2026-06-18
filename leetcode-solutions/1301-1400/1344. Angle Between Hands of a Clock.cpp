/*
Problem: Angle Between Hands of a Clock
Approach: Maths
Time: O(1)
*/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = 360 / 12;
        double minuteAngle = 360 / 60;

        double angleBetween = abs(((hour % 12) * hourAngle + ((double)minutes / 60 * 30)) - (minutes % 60) * minuteAngle);

        return angleBetween < (360 - angleBetween) ? angleBetween : 360 - angleBetween;
    }
};