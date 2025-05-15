int rows = grid.size();           
        int cols = grid[0].size();
        int a; 
        vector<int>ans;
        for(int i = 0;i<rows;i++){
            bool found = false;
            for(int j = 0;j<cols;j++){

                for(int k = 0;k<rows;k++){
                    for(int l = 0;l<cols;l++){
                        if ((i != k || j != l) && grid[i][j] == grid[k][l]){
                            found = true;
                            ans.push_back(grid[k][l]);
                            break;
                           }

                    }
                    if(found)
                      break;
                }
                if(found)
                break;
            }
            if(found)
            break;
        }
       for (int k = 0; k <= rows * cols; k++) {
        bool found = false;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == k+1) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (!found) {
            ans.push_back(k+1);
            break;
        }
    }
    return ans; 
    }