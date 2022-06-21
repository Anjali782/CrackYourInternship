class Solution {
void changeColor(vector<vector<int>>& image, int i, int j, int n, int m, int currColor, int newColor) {
        
        if((i < 0) || (i >= n) || (j < 0) || (j >= m) || image[i][j] != currColor)
            return;
        
        
        image[i][j] = newColor;
        
        changeColor(image, i + 1, j, n, m, currColor, newColor); // up
        changeColor(image, i - 1, j, n, m, currColor, newColor); // down
        changeColor(image, i, j + 1, n, m, currColor, newColor); // right
        changeColor(image, i, j - 1, n, m, currColor, newColor); // left
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        
        int currColor = image[sr][sc];
        
        if(currColor == newColor)
            return image;
        
        changeColor(image, sr, sc, n, m, currColor, newColor);
        
        return image;
    }
};
