#include <iostream>//standard library for cin and cout
#include <vector>// dynamic array that can resize for the number of points
#include <cmath> // for sqrt and pow
#include <utility>// for pair

using namespace std;

// Function that will calculate Euclidean distance between two points
double euclidean_distance(pair<double, double> p1, pair<double, double> p2) {
    return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));// formula for calculating the euclidean distance between two points
}

// Function that will compute total distance for a sequence of points
double total_distance(const vector<pair<double, double>>& points) {
    double total_dist = 0.0; //variable that will serve as storage for total distance
    for (size_t i = 1; i < points.size(); ++i) { // iteration for every number of points
        total_dist += euclidean_distance(points[i - 1], points[i]); //storing the calculated distance between the points
    }
    return total_dist;
}

// Function to calculate that will sum of the first N natural numbers
int sum_of_natural_numbers(int n) {
    return n * (n + 1) / 2; //in reference to the formula for sum of the first N natural numbers
}

int main() {
    int N;
    
    // Input the number of points
    cout << "Enter the number of points (N): ";
    cin >> N;

    // Input the x and y coordinates of the delivery points individually
    vector<pair<double, double>> points(N);
    for (int i = 0; i < N; ++i) {
        cout << "Enter the x-coordinate of point " << (i + 1) << ": ";
        cin >> points[i].first;
        cout << "Enter the y-coordinate of point " << (i + 1) << ": ";
        cin >> points[i].second;
    }

    // Compute the total distance
    double distance = total_distance(points);
    cout << "Total distance between the points: " << distance << endl;


    // Example usage of sum_of_natural_numbers function
    int sum = sum_of_natural_numbers(N);
    cout << "Sum of the first " << N << " natural numbers is: " << sum << endl;
    cout <<"the pairs of coordinates are: " << endl;
    for (const auto& point : points) {
        cout << "(" << point.first << ", " << point.second << ")" << endl;
    }
    cout << endl;
    return 0;
}
