#include <iostream>

using namespace std;

// Recursive function to solve the Tower of Hanoi puzzle
void hanoiSolver(int disks, char fromPeg, char toPeg, char auxPeg, int& stepCount) {
    
    // This whole code block will serve as one counter for every shift or transfer of disks
    if (disks == 1) { // Base case: Move one disk - O(1)
        cout << "Shift disk 1 from " << fromPeg << " to " << toPeg << endl; // O(1)
        stepCount++; // O(1)
        return; // O(1)
    }
    // Recursive step: Move (disks - 1) from the source peg to the auxiliary peg
    hanoiSolver(disks - 1, fromPeg, auxPeg, toPeg, stepCount); // O(2^(n-1))

    // Move the nth disk to the destination peg
    cout << "Shift disk " << disks << " from " << fromPeg << " to " << toPeg << endl; // O(1)
    stepCount++; // O(1)

    // Move the remaining disks from the auxiliary peg to the destination peg
    hanoiSolver(disks - 1, auxPeg, toPeg, fromPeg, stepCount); // O(2^(n-1))
}

int main() {
    int numDisks;
    int totalSteps = 0;

    // Ask the user for the number of disks
    cout << "Enter the number of disks to move: ";
    cin >> numDisks;

    // Call the Tower of Hanoi solver
    hanoiSolver(numDisks, 'B', 'C', 'A', totalSteps);

    // Output the total number of moves
    cout << "Number of moves made: " << totalSteps << endl;
    cout << "Time complexity: O(2^n)" << endl;

    return 0;
}
