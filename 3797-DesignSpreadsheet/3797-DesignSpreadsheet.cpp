// Last updated: 08/03/2026, 13:22:59
class Spreadsheet {
    vector<vector<int>> sheet;
public:
    Spreadsheet(int rows) {
        sheet=vector<vector<int>>(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        sheet[stoi(cell.substr(1)) - 1][cell[0]-'A'] = value;
    }
    
    void resetCell(string cell) {
        sheet[stoi(cell.substr(1))-1][cell[0] - 'A'] = 0;
    }
    
    int getValue(string formula) {
        int ans=0;
        for(int i=1;i<formula.size();i++){


            if(formula[i] >= 'A' && formula[i] <= 'Z'){
                int col=formula[i++] - 'A';
                int row=0;
                while(i<formula.size()&&formula[i]!='+'){
                    
                    row = row * 10 + (formula[i++] - 48);
                }
                    
                ans += sheet[row - 1][col];  
            }
            else {
                int val = 0;
                while(i < formula.size() && formula[i] != '+'){
                    val = val * 10 + (formula[i++] - 48) % 10;
                }
                ans += val;
            }
        }
        
        return ans;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */


/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */