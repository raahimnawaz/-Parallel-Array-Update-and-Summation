#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

void   printParallel(const double[], const string[], const int);
double updateAndSum(double[], const string[], const int);

/*******************************************************************************
 * Description:
 * Starting point of the program. Creates two arrays. Uses loops to let the user
 * populate the arrays. Calls functions to print out and update the arrays in
 * parallel.
 *
 * Input(s):
 * N/A
 *
 * Output:
 * An integer that signals the exit code to the operating system (OS)
*******************************************************************************/

int main() {
    // declare first array
    const int SIZE = 5;
    double firstArray[SIZE];

    // range-based `for` loop to get user input for `firstArray`
    for (double& elem : firstArray) {
        cout << "Enter a floating-point number: ";
        cin  >> elem;
    }

    // declare second array
    string secondArray[SIZE];

    // normal `for` loop to get user input for `secondArray`
    cin.ignore();
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter a name: ";
        getline(cin, secondArray[i]);
    }

    // function calls
    printParallel(firstArray, secondArray, SIZE);
    cout << "Sum: " << updateAndSum(firstArray, secondArray, SIZE) << endl;
    printParallel(firstArray, secondArray, SIZE);

    // terminate
    return 0;
}

/*******************************************************************************
 * Description:
 * Uses a `while` loop to print the two arrays in parallel.
 *
 * Input(s):
 * DARR       - a constant array of `double` elements
 * SARR       - a constant array of `string` elements
 * ARRAY_SIZE - a constant integer that represents how many elements exist in
 *              the arrays
 *
 * Output:
 * N/A
*******************************************************************************/

void printParallel(const double DARR[], const string SARR[], const int ARRAY_SIZE) {
    cout << endl;
    int i = 0;
    while (i < ARRAY_SIZE) {
        cout << DARR[i] << ' ' << SARR[i] << endl;
        i++;
    }
    cout << endl;
}

/*******************************************************************************
 * Description:
 * Uses a normal `for` loop to update `darr` by adding the length of its
 * parallel element in `SARR`. Also calculates the sum of the new values.
 *
 * Input(s):
 * darr       - an array of `double` elements
 * SARR       - a constant array of `string` elements
 * ARRAY_SIZE - a constant integer that represents how many elements exist in
 *              the arrays
 *
 * Output:
 * The sum of the newly updated elements in `darr`.
*******************************************************************************/

double updateAndSum(double darr[], const string SARR[], const int ARRAY_SIZE) {
    double sum = 0.0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        darr[i] += SARR[i].length();
        sum += darr[i];
    }
    return sum;
}
