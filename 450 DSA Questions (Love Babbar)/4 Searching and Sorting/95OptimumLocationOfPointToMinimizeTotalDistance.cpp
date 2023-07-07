// https://practice.geeksforgeeks.org/problems/optimum-location-of-point-to-minimize-total-distance/1

// Given a set of coordinates points of the form [p, q] and a line L of the form ax + by + c = 0. The task is to find a point on a given line for which the sum of distances from a given set of coordinates is minimum.

// Input:
// L = {1, -1, -3}
// points[] = {{-3, 2}, {-1, 0},
//             {-1, 2}, {1, 2}, {3, 4}}
// Output: 20.77
// Explanation: In above figure optimum location of
// point of x - y - 3 = 0 line is (2, -1), whose
// total distance with other points is 20.77,
// which is minimum obtainable total distance.

#include <iostream>
using namespace std;
#include <vector>
#include <tuple>
#include <cmath>
#include <climits>

class Solution
{
    // Calculate distance to the point--
    double calDist(double x, double y, pair<int, int> p)
    {
        return sqrt(pow((x - p.first), 2.0) + pow((y - p.second), 2.0));
    }

    // Calculate y from x on the line--
    double dist(tuple<int, int, int> l, vector<pair<int, int>> p, int n, double x)
    {
        // Find y on line from x--
        double y = -(get<2>(l) + get<0>(l) * x) / get<1>(l);

        // Itterate over each point to cal min dist--
        double sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += calDist(x, y, p[i]);
        }

        return sum;
    }

public:
    // From Ternary Search find x on line--
    double findOptimumCost(tuple<int, int, int> l, vector<pair<int, int>> p, int n)
    {
        // End points of line (x)--
        double high = 1e6;
        double low = -1e6;

        // Ternary Search--
        while (high - low > 1e-6)
        {
            // Calculate mid1 and mid2--
            double mid1 = low + (high - low) / 3;
            double mid2 = high - (high - low) / 3;

            // Find Distances from mid1 and mid2 as x--
            double dist1 = dist(l, p, n, mid1);
            double dist2 = dist(l, p, n, mid2);

            // Parabolic Curve of the distance--
            // If dist1 is small then x after dist 2 is always larger
            if (dist1 < dist2)
            {
                high = mid2;
            }
            else
            {
                low = mid1;
            }
        }

        // Last Time Calculating distance for precise ans till 6 digits--
        return dist(l, p, n, (low + high) / 2);
    }
};