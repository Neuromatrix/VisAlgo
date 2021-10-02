#include <bits\stdc++.h>
#include <TXLib.h>

inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
class game_of_life{
    private:
        int n = 50, m = 50;
        std::vector <std::vector <bool>> field_previous;
        std::vector <std::vector <bool>> field_next;
        
        bool alive(){
            return true;
            for(size_t i = 0; i < this->field_previous.size(); i++){
                
            }
            return false;
        }
        int sum_cell(int i, int j){
            int sum = 0;
            int i_p = 0, i_m = 0, j_p = 0, j_m = 0;
            if(i+1>=n) i_p = 0;
            else i_p=i+1;
            if(i-1<0) i_m = n-1;
            else i_m=i-1;
            if(j+1>=m) j_p = 0;
            else j_p=j+1;
            if(j-1<0) j_m = m-1;
            else j_m=j-1;
            sum+=this->field_previous[i_p][j_p];
            sum+=this->field_previous[i][j_p];
            sum+=this->field_previous[i_m][j_p];
            sum+=this->field_previous[i_m][j];
            sum+=this->field_previous[i_m][j_m];
            sum+=this->field_previous[i][j_m];
            sum+=this->field_previous[i_p][j_m];
            sum+=this->field_previous[i_p][j];
            return sum;
        }
        void render(){
            txSetFillColor(TX_BLACK);
            txClear();
            txSetFillColor(TX_WHITE);
            for(std::size_t i = 0; i < this->field_previous.size(); i++){
                for(std::size_t j = 0; j < this->field_previous[i].size(); j++){
                    if(!this->field_previous[i][j]){
                        txRectangle(10*i,10*j,10*(i+1),10*(j+1));
                    }
                }
            }
        }
        void step(){
            this->field_next.resize(n);
            for(int i = 0; i < this->field_previous.size(); i++){
                this->field_next[i].resize(m);
                for(int j = 0; j < this->field_previous[i].size(); j++){
                    if(sum_cell(i,j)==3 || sum_cell(i,j)==2 && this->field_previous[i][j]) this->field_next[i][j] = 1;
                    else if(sum_cell(i,j)==3 && !this->field_previous[i][j]) this->field_next[i][j] = 1;
                    else this->field_next[i][j] = 0;
                }
            }
            this->field_previous = this->field_next;
            this->field_next.clear();
        }
    public:
        void init(std::vector <std::vector <bool>> data){
            return;
        }
        void init(size_t n, size_t m){
            this->n = n;
            this->m = m;
            this->field_previous.resize(n);
            this->field_next.resize(n);
            for(std::size_t i = 0; i < this->field_previous.size(); i++){
                this->field_previous[i].resize(m);
                this->field_next[i].resize(m);
                for(std::size_t j = 0; j < this->field_previous[i].size(); j++){
                    this->field_previous[i][j] = rand()%2;
                }
            }
            return;
        }
        void start(double interval = 1.5){
            txCreateWindow(n*10,m*10);
            while (alive()){
                render();
                step();
                txSleep(100*interval);
            }
            return;      
        }
};

int main(){
    prepare();
    game_of_life a;
    a.init(50,50);
    a.start();
    return 0;
}