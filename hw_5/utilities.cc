#include <fstream>
#include <sstream>
#include "utilities.h"
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function sort_by_magnitude: Takes a reference to a vector of doubles, 
// and sorts it with a comparison function that says that x < y if and only if 
// the absolute value of x is less than the absolute value of y
void sort_by_magnitude(vector<double>& v) {
  sort(v.begin(), v.end(), [](double x, double y) {
    return abs(x) < abs(y);
  });
}

// Function read_matrix_csv: Reads a comma separated value (CSV) file
// of doubles into a matrix and returns it
TypedArray<TypedArray<double>> read_matrix_csv(const string path) {
    ifstream infile(path);
    TypedArray<TypedArray<double>> matrix;
    string line;
    
    //Read the CSV file cell by cell
    while (getline(infile, line)) {
        TypedArray<double> row;
        stringstream ss(line);
        string cell;
        
        while (getline(ss, cell, ',')) {
            if (cell.empty()) { 
                // Throw Error for empty cell
                throw invalid_argument("CSV file has an incomplete matrix.");
            }
            row.set(row.size(), stod(cell));
        }
        if (matrix.size() > 0 && row.size() != matrix.safe_get(0).size()) { 
            // Throw Error if current row and the matrix first row sizes are not equal
            throw invalid_argument("CSV file has a jagged matrix.");
        }
        matrix.set(matrix.size(), row);
    }
    if (matrix.size() == 0) { 
        // Throw Error if matrix is empty
        throw invalid_argument("CSV file represents an empty matrix.");
    }
    return matrix;
}

// Function write_matrix_csv: Writes a comma separated value (CSV) 
// file of doubles from a matrix
void write_matrix_csv(const TypedArray<TypedArray<double>> &matrix, const string path) {
    ofstream outfile(path);
    
    for (int i = 0; i < matrix.size(); i++) {
        TypedArray<double> row = matrix.safe_get(i);
        for (int j = 0; j < row.size(); j++) {
            outfile << row.safe_get(j);
            if (j < row.size() - 1) {
                outfile << ",";
            }
        }
        outfile << endl;
    }
}

// Function occurrence_map: Reads in an ascii text file and returns
// an assocation where each key is a word in the text file, 
// and each value is the number of occurences of that word
map<string, int> occurrence_map(const string path) {
    ifstream infile(path);
    map<string, int> occ_map;
    string line;
    
    while (getline(infile, line)) {
        // Adding whitespace for managing last word in the line
        line += ' '; 
        cout<<line<<endl;
        
        string word = "";
        
        for (int i = 0; i < line.length(); i++) {
            bool is_word = true;
            if(line[i]!=' '){
                // Conversion to Lowercase
                word += tolower(line[i]); 
            }
            else if (word.length() > 0 && line[i] == ' ') {
                // Check and Remove last character of the word if its- '.' or ':'
                if(word[word.length()-1]=='.' || word[word.length()-1]==':'){ 
                    word.erase(word.length()-1,1);
                }
                for (int i = 0; i < word.length(); i++) {
                    // Check if word is invalid
                    if(!(isalnum(word[i]) || word[i] == '\'' || word[i] == '"')){ 
                        is_word = false;
                        break;
                    }
                }
                if(is_word == true){
                    // Check and Remove first character of word if its ''' or '"'
                    if(word[0]=='\'' || word[0] == '"'){ 
                            word.erase(0,1);
                    }
                    // Check if first character of word is ' or "  and remove them
                    if(word[word.length()-1]=='\'' || word[word.length()-1]=='"'){ 
                        word.erase(word.length()-1,1);
                    }
                    // Check and skip empty words
                    if(word==""){ 
                        continue;
                    }
                    // Add word to the map
                    occ_map[word]++;
                }
                // Blank initialization for the next word
                word = "";
            }
        }
    }
    return occ_map;
}