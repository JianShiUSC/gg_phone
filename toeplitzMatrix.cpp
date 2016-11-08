bool toeplitzMatrix(vector<vector<int>>& matrix) {
    int row = (int)matrix.size();
    int col = (int)matrix[0].size();

    for(int i = 0; i < col; i++) {
        int beginRow = 0;
        int beginCol = i;
        while(beginRow < row - 1 && beginCol < col - 1) {
            if(matrix[beginRow][beginCol] != matrix[++beginRow][++beginCol]) return false;
        }
    }

    for(int i = 1; i < row; i++) {
        int beginRow = i;
        int beginCol = 0;
        while(beginRow < row - 1 && beginCol < col - 1) {
            if(matrix[beginRow][beginCol] != matrix[++beginRow][++beginCol]) return false;
        }
    }
    return true;
}


// simplify version
bool toeplitzMatrix(vector<vector<int>>& matrix) {
    for(int i = 0; i < matrix.size() - 1; i++) {
        for(int j = 0; j < matrix[0].size() - 1; j++) {
            if(matrix[i][j] != matrix[i+1][j+1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> matrix = {{6,7,8,9},
                                  {4,6,7,8},
                                  {1,4,6,7},
                                  {0,1,4,6},
                                  {2,0,1,4}};
    cout << toeplitzMatrix(matrix) << endl;
}
