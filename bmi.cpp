#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double weight;
    double height;

    cout << "Enter your weight (in pounds): " << endl;
    cin >> weight;

    cout << "Enter your height (in inches): " << endl;
    cin >> height;

    // Validate before calculating so we never divide by zero or
    // classify a meaningless negative BMI.
    if (weight <= 0 || height <= 0)
    {
        cout << "Error: weight and height must be positive." << endl;
        return 1;
    }

    double bmi = weight * 703.0 / (height * height);

    // Display the BMI rounded to two decimals; the stored value is unchanged.
    cout << fixed << setprecision(2);
    cout << "Your BMI is " << bmi << endl;

    // Classify using the unrounded BMI. Checking "< 18.5" first and
    // "<= 25.0" second means 18.5 and 25.0 both land in the optimal range.
    if (bmi < 18.5)
    {
        cout << "Category: Underweight" << endl;
    }
    else if (bmi <= 25.0)
    {
        cout << "Category: Optimal weight" << endl;
    }
    else
    {
        cout << "Category: Overweight" << endl;
    }

    return 0;
}
