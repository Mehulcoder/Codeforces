class Solution {
private:

	int rowSize, colSize;
	vector<int> offset = {0, 1, 0, -1, 0};

	bool outOfBounds(int row, int col) {
		return row < 0 || col < 0 || row >= rowSize || col >= colSize;
	}

	void flowToPacificOrAtlantic(vector<vector<int>>& matrix, int row, int col, vector<vector<bool>>& visited) {
		visited[row][col] = true;

		int currWaterLevel = matrix[row][col];
		for (int i = 1; i < offset.size(); i++) { // Go to left right up down using the offset --> (+1, +0) (+0, +1), (-1, +0), (+0, -1)
			int r = row + offset[i], c = col + offset[i - 1];
			if (!outOfBounds(r , c) &&
			        currWaterLevel <= matrix[r][c] && // !!! current water level is lower than the surrounding water !!!
			        !visited[r][c]) {

				flowToPacificOrAtlantic(matrix, r, c, visited);
			}
		}
	}

public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<vector<int>> result;
		rowSize = matrix.size();
		if (rowSize == 0)
			return result;
		colSize = matrix[0].size();

		// initialize the maps to 0
		vector<vector<bool>> pacific(rowSize, vector<bool> (colSize, 0));
		vector<vector<bool>> atlantic(rowSize, vector<bool> (colSize, 0));

		for (int row = 0; row < rowSize; row++) {
			flowToPacificOrAtlantic(matrix, row, 0, pacific); // column 0 (pacific)
			flowToPacificOrAtlantic(matrix, row, colSize - 1, atlantic); // column end (atlantic)
		}
		for (int col = 0; col < colSize; col++) {
			flowToPacificOrAtlantic(matrix, 0, col, pacific); // row 0 (pacific)
			flowToPacificOrAtlantic(matrix, rowSize - 1, col, atlantic); // row end (atlantic)
		}

		// Compare the two 'maps' and find where they have a common 1
		for (int row = 0; row < rowSize; row++) {
			for (int col = 0; col < colSize; col++) {
				if (pacific[row][col] == 1 && atlantic[row][col] == 1) {
					result.push_back({row, col});
				}
			}
		}

		return result;
	}
};