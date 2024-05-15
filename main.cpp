#include <iostream>
#include <vector>
#include <unordered_set>

//MY CODE .Orginial.First try.
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows for validity
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> rowSet; // Store seen characters in a row
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue; // Skip empty cells
                }
                // Check if the current character in the row has been seen before
                if (rowSet.find(board[i][j]) != rowSet.end()) {
                    cout << "Invalid: Duplicate found in row " << i << ", column " << j << endl;
                    return false;
                }
                rowSet.insert(board[i][j]); // Add character to set
            }
        }

        // Check columns for validity
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> colSet; // Store seen characters in a column
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.') {
                    continue; // Skip empty cells
                }
                // Check if the current character in the column has been seen before
                if (colSet.find(board[j][i]) != colSet.end()) {
                    cout << "Invalid: Duplicate found in column " << i << ", row " << j << endl;
                    return false;
                }
                colSet.insert(board[j][i]); // Add character to set
            }
        }
//        SUBGRIDS TESTING.
        cout << "Passed column testing" << endl;
        int k, l, i = 0, j = 0;
        k = i;
        l = j;
        unordered_set<int> Record_Set;
        for (i; i < k + 3; ++i) {
            for (j; j < l + 3; ++j) {
                cout << board[i][j] << " ";
                if (board[i][j] == '.') {
                    continue;
                }
                if (Record_Set.find(board[i][j]) != Record_Set.end()) {
                    cout << "from 3 by 3 testing" << endl;
                    return false;
                }
                Record_Set.insert(board[i][j]);
            }
            j--;
            if ( ((j + 1) != 9) || (k+3-i!=1) ) {
                if (l + 3 - j == 1) {
                    if (k + 3 - i == 1) {
                        cout<<"record set"<<endl;
                        Record_Set.clear();
                        l = j + 1;
                        j = j + 1;
                        if (i < 3) {
                            i = -1;
                        } else if (i < 6) {
                            i = 2;
                        } else if (i < 9) {
                            i = 5;
                        }
                    }
                    else {
                        if ((j + 1) % 3 == 0) {
                            if (j < 3) {
                                j = 0;
                            } else if (j < 6) {
                                j = 3;
                            } else if (j < 9) {
                                j = 6;
                            }
                        }
                    }
                }
            }

            if (j + 1 == 9 && (i + 1 == 3 || i + 1 == 6)) {
                    Record_Set.clear();
                    j = 0;
                    l = 0;
                    k = i+1;
                }
                cout << endl;
            }
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
