#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
    const int COLOR_SIZE = 20;
    char color_one[COLOR_SIZE];
    char color_two[COLOR_SIZE];

    cout << "Choose only from red, yellow, and blue. Input in all lowercase."
         << endl;

    cout << "Pick a first color: " << endl;
    cin >> setw(COLOR_SIZE) >> color_one;

    cout << "Pick a second color: " << endl;
    cin >> setw(COLOR_SIZE) >> color_two;

    // Check whether both inputs are valid primary colors.
    if ((strcmp(color_one, "red") != 0 &&
         strcmp(color_one, "blue") != 0 &&
         strcmp(color_one, "yellow") != 0) ||
        (strcmp(color_two, "red") != 0 &&
         strcmp(color_two, "blue") != 0 &&
         strcmp(color_two, "yellow") != 0))
    {
        cout << "Error: Invalid color entered." << endl;
    }
    // If both colors are the same, display that color.
    else if (strcmp(color_one, color_two) == 0)
    {
        cout << "Result: " << color_one << endl;
    }
    // Mix red and blue to make purple.
    else if ((strcmp(color_one, "red") == 0 &&
              strcmp(color_two, "blue") == 0) ||
             (strcmp(color_one, "blue") == 0 &&
              strcmp(color_two, "red") == 0))
    {
        cout << "Result: purple" << endl;
    }
    // Mix red and yellow to make orange.
    else if ((strcmp(color_one, "red") == 0 &&
              strcmp(color_two, "yellow") == 0) ||
             (strcmp(color_one, "yellow") == 0 &&
              strcmp(color_two, "red") == 0))
    {
        cout << "Result: orange" << endl;
    }
    // Mix blue and yellow to make green.
    else if ((strcmp(color_one, "blue") == 0 &&
              strcmp(color_two, "yellow") == 0) ||
             (strcmp(color_one, "yellow") == 0 &&
              strcmp(color_two, "blue") == 0))
    {
        cout << "Result: green" << endl;
    }

    return 0;
}