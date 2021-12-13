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
        bool this_move = 0;
        class rules{
            // __NOT_DEFINED__ //
        };
        check * getC(int x, int y){return check[x][y];}
        kinger * getK(int x, int y) {return kinger[x][y];}
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
                        // txSetFillColor(TX_GREEN);
                        // txRectangle(100*j+20,100*i+20,100*(j+1)-20,100*(i+1)-20);
                    }
                    else  if(board[i][j]==2){ // дамка
                        kinger* now = getK(i,j);
                        // txSetFillColor(TX_RED);
                        // txRectangle(100*j+20,100*i+20,100*(j+1)-20,100*(i+1)-20);
                    }
                    
                }
            }
        }
        void motion(int player){
            // тут мы получаем координаты мышки 
            // если цвет мышки совпадает с 
            int i = 0 , j = 0; // запиши сюда координаты клтеки
            if (board[i][j]==1) {// шашка
                check* now = getC(i,j);
                cout << now->color;
            }
            else  if(board[i][j]==2){ // дамка
                kinger* now = getK(i,j);
            }
        }
        
        void move(int x, int y, int tox, int toy, bool ch_flag = 1);
        inline void starter(){
            txCreateWindow(100*N,100*N);
            prepare();
            int p = 0;
            while (true){
                render();
                motion(p&1);
                render();
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
                    } else board[i][j] = 0;
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