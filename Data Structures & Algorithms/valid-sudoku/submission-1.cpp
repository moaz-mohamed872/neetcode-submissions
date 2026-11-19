class intry{
    public:
    int x, y, reg;

    void my_set(int x, int y, int reg){
        this->x = x;
        this->y = y;
        this->reg = reg;
    }
};

class Solution {
public:
    int get_board_reg(int x, int y){
        if(x == 0 || x == 1 || x == 2){
            if(y == 0 || y == 1 || y == 2)
                return 0;

            if(y == 3 || y == 4 || y == 5)
                return 3;

            if(y == 6 || y == 7 || y == 8)
                return 6;
        }

        if(x == 3 || x == 4 || x == 5){
            if(y == 0 || y == 1 || y == 2)
                return 1;

            if(y == 3 || y == 4 || y == 5)
                return 4;

            if(y == 6 || y == 7 || y == 8)
                return 7;
        }

        if(x == 6 || x == 7 || x == 8){
            if(y == 0 || y == 1 || y == 2)
                return 2;

            if(y == 3 || y == 4 || y == 5)
                return 5;

            if(y == 6 || y == 7 || y == 8)
                return 8;
        }

        return -1;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, vector<intry>> positions;

        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                if(board[i][j] != '.') {
                    intry a;
                    a.my_set(i, j, get_board_reg(i,j));
                    positions[board[i][j]].push_back(a);
                }

        for(auto elem: positions){
            unordered_map<int, bool> vis;
            for(auto intr: elem.second){
                if(vis[intr.x])
                    return false;

                vis[intr.x] = true;
            }

            vis.clear();
            for(auto intr: elem.second){
                if(vis[intr.y])
                    return false;

                vis[intr.y] = true;
            }

            vis.clear();
            for(auto intr: elem.second){
                if(vis[intr.reg])
                    return false;

                vis[intr.reg] = true;
            }
        }
        return true;
    }
};

