#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows for validity
        for (int row = 0; row < 9; ++row) {
            unordered_set<char> rowSet; // Store seen characters in a row
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.') {
                    continue; // Skip empty cells
                }
                // Check if the current character in the row has been seen before
                if (rowSet.find(board[row][col]) != rowSet.end()) {
                    cout << "Invalid: Duplicate found in row " << row << ", column " << col << endl;
                    return false;
                }
                rowSet.insert(board[row][col]); // Add character to set
            }
        }

        // Check columns for validity
        for (int col = 0; col < 9; ++col) {
            unordered_set<char> colSet; // Store seen characters in a column
            for (int row = 0; row < 9; ++row) {
                if (board[row][col] == '.') {
                    continue; // Skip empty cells
                }
                // Check if the current character in the column has been seen before
                if (colSet.find(board[row][col]) != colSet.end()) {
                    cout << "Invalid: Duplicate found in column " << col << ", row " << row << endl;
                    return false;
                }
                colSet.insert(board[row][col]); // Add character to set
            }
        }

        cout << "Passed column and row checks" << endl;

        // Check 3x3 subgrids for validity
        for (int startRow = 0; startRow < 9; startRow += 3) {
            for (int startCol = 0; startCol < 9; startCol += 3) {
                unordered_set<char> subgridSet; // Store seen characters in a 3x3 subgrid
                for (int row = startRow; row < startRow + 3; ++row) {
                    for (int col = startCol; col < startCol + 3; ++col) {
                        if (board[row][col] == '.') {
                            continue; // Skip empty cells
                        }
                        // Check if the current character in the subgrid has been seen before
                        if (subgridSet.find(board[row][col]) != subgridSet.end()) {
                            cout << "Invalid: Duplicate found in 3x3 subgrid starting at row " << startRow
                                 << ", column " << startCol << endl;
                            return false;
                        }
                        subgridSet.insert(board[row][col]); // Add character to set
                    }
                }
            }
        }

        // If all checks passed, the Sudoku board is valid
        cout << "The sudoku board is valid." << endl;
        return true;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','2','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };

    bool isValid = solution.isValidSudoku(board);
    if (isValid) {
        cout << "The sudoku board is valid." << endl;
    } else {
        cout << "The sudoku board is not valid." << endl;
    }

    return 0;
}
