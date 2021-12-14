#include <bits\stdc++.h>
#include <TXLib.h>
using namespace std;
using ll = long long;   
using ull = unsigned long long;
using ld = long double;
constexpr char nl = '\n';
constexpr long double eps = 1e-9;
template <typename T> inline T abs(T &x) {return(x<0 ? -x : x);}
template <typename T> ostream& operator<<(ostream &out, const vector<T> &v) {for (auto &it : v) {out << it << " ";}return out;}
template <typename T1, typename T2> ostream& operator<<(ostream &out, const pair<T1, T2> &v) {out << v.first << " " << v.second;return out;}
template <typename T> inline T pw(T x) {return x*x;}
template <typename T> inline T pw2(T x){return 1LL<<x;}
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
template <int N>
class GAME{
    private:
        class check{
            public:
                bool color;
                int x, y;
                vector <pair <int, int>> moves = {{-1,-1},{-1,1},{1,1},{1,-1}};
        };
        class kinger : public check{
            public:
                int modificate_moves = N;
        };
        int board[N][N];
        check* b1[N][N];
        kinger* b2[N][N];
        int this_move = 0;
        class rules{
            // __NOT_DEFINED__ //
        };
        inline bool is_valid(int x, int y){
            if(x<0 || x >=N || y<0 || y>=N) return false;
            if(board[x][y]!=0) return false;
            return true;
        }
        inline check * getC(int x, int y){return b1[x][y];}
        inline kinger * getK(int x, int y) {return b2[x][y];}
        inline void render(){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    //TODO: Дизайнер рисуй
                    if((i+j)&1){
                        txSetFillColor(TX_BLACK);
                    } else {
                        txSetFillColor(TX_WHITE);
                    }
                    txRectangle(100*j,100*i,100*(j+1),100*(i+1));
                    if (board[i][j]==1) {// шашка
                        check* now = getC(i,j);
                        if(now->color) txSetFillColor(TX_RED);
                        else  txSetFillColor(TX_GREEN);
                        txRectangle(100*j+20,100*i+20,100*(j+1)-20,100*(i+1)-20);
                    }
                    else  if(board[i][j]==2){ // дамка
                        kinger* now = getK(i,j);
                        if(now->color) txSetFillColor(TX_RED);
                        else  txSetFillColor(TX_GREEN);
                        txRectangle(100*j+20,100*i+20,100*(j+1)-20,100*(i+1)-20);
                    }
                    
                }
            }
        }
        void beat(int x, int y, int beatx, int beaty, int x_after_beat, int y_after_beat){
            if(!valid(x_after_beat,y_after_beat)) return;
            if(board[x][y]==1){
                move(x,y,x_after_beat,y_after_beat);
            } else {
                move(x,y,x_after_beat,y_after_beat,2);
            }
            if(board[beatx][beaty]==1) b1[beatx][beaty]= nullptr;
            else b2[beatx][beaty] = nullptr;
        }
        pair<int,int> can_Beat(int x, int y){

        }
        inline void move(int x, int y, int tox, int toy, bool ch_flag = 1){// перемещенеие шашки на место
            if(!valid(tox,toy)) return;
            if(ch_flag){
                swap(b1[x][y],b1[tox][toy]);
            } else {
                swap(b2[x][y],b2[tox][toy]);
            }
        }
        inline void to_kingers(){ // проверка что кто то внезапно преваритлся в дамку
            int whiteSide = 0, blackSide = N-1;
            for(int i = 0; i < N; i++){
                check* ch1 = getC(whiteSide,i);
                check* ch2 = getC(blackSide,i);
                if(ch1->color==0){
                    kinger * appear = new kinger;
                    b1[whiteSide][i] = nullptr;
                    b2[whiteSide][i] = appear;
                }
                if(ch2->color==1){
                     kinger * appear = new kinger;
                    b1[blackSide][i] = nullptr;
                    b2[blackSide][i] = appear;
                }
            }
        }
        void motion(int player){
            // тут мы получаем координаты мышки 
            // если цвет мышки совпадает с 
            int i = 0 , j = 0; // запиши сюда координаты клтеки
            if (board[i][j]==1) {// шашка
                check* now = getC(i,j);
            }
            else  if(board[i][j]==2){ // дамка
                kinger* now = getK(i,j);
            }
            // показываем тут кружочки
            int tox = 0, toy = 0; // считываем куда он хочет пойти

        }
        
        
        inline void starter(){
            txCreateWindow(100*N,100*N);
            prepare();
            int p = 0;
            while (true){
                render();
                motion(p&1);
                txSleep(100);
                
                // спим
                p++;
            }
            txSleep(10000000);
        }
        void prepare(){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    if(i<3 || i>=N-3) {
                        board[i][j] = (((i+j)&1));
                        if(i<3){
                            check * tmp = new check;
                            tmp->color = 0;
                            tmp->x = i, tmp->y = j;
                            b1[i][j] = tmp;
                        } else {
                            check * tmp = new check;
                            tmp->color = 1;
                            tmp->x = i, tmp->y = j;
                            b1[i][j] = tmp;
                        }
                    } else {board[i][j] = 0; b1[i][j] = nullptr;}
                }
            }

        }
        
    public:
        void iwantplay(){
            starter();
        }
};

signed main(){
    GAME <8> x;
    x.iwantplay();
    return 0;
}