#include <bits\stdc++.h>
#include <TXLib.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr char nl = '\n';
constexpr long double eps = 1e-9;
template <typename T> inline T abs(T& x) { return(x < 0 ? -x : x); }
template <typename T> ostream& operator<<(ostream& out, const vector<T>& v) { for (auto& it : v) { out << it << " "; }return out; }
template <typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& v) { out << v.first << " " << v.second; return out; }
template <typename T> inline T pw(T x) { return x * x; }
template <typename T> inline T pw2(T x) { return 1LL << x; }
inline void pprepare() {
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
template <int N>
class GAME {
private:
    class check {
    public:
        bool color;
        int x, y;
        int modificate_moves = 1;
    };
    class kinger{
    public:
        bool color;
        int x, y;
        int modificate_moves = N;
        
    };
    int board[N][N];
    check* b1[N][N];
    kinger* b2[N][N];
    int this_move = 0;
    class rules {
        // __NOT_DEFINED__ //
    };
    inline bool is_valid(int x, int y) {//!DONE
        if (x < 0 || x >= N || y < 0 || y >= N) return false;
        if (board[y][x] != 0) return false;
        return true;
    }
    inline check* getC(int x, int y) { return b1[y][x]; } //!DONE
    inline kinger* getK(int x, int y) { return b2[y][x]; } // !DONE
    inline void render() {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                //TODO: Дизайнер рисуй
                if (((x + y) & 1)) {
                    txSetFillColor(TX_BLACK);
                }
                else {
                    txSetFillColor(TX_WHITE);
                }
                txRectangle(100 * x, 100 * y, 100 * (x + 1), 100 * (y + 1));
                if (board[y][x] == 1) {// шашка
                    check* now = getC(x, y);
                    if (now->color) txSetFillColor(TX_RED);
                    else  txSetFillColor(TX_GREEN);
                    txCircle((100 * x + 100 * (x + 1)) / 2, (100 * y + 100 * (y + 1)) / 2, 35);
                    //txRectangle(100 * j + 20, 100 * i + 20, 100 * (j + 1) - 20, 100 * (i + 1) - 20);
                }
                else  if (board[y][x] == 2) { // дамка
                    kinger* now = getK(x, y);
                    if (now->color) txSetFillColor(TX_RED);
                    else  txSetFillColor(TX_GREEN);
                    txRectangle(100 * x + 20, 100 * y + 20, 100 * (x + 1) - 20, 100 * (y + 1) - 20);
                }

            }
        }
    }
    //? POSSIBLY DONE
    inline bool move(int x, int y, int tox, int toy, bool ch_flag = 1) {// перемещенеие шашки на место
        if (!is_valid(tox, toy)) return false;
        if (ch_flag) {
            board[toy][tox] = 1;
            swap(b1[y][x], b1[toy][tox]);
        }
        else {
            board[toy][tox] = 2;
            swap(b2[y][x], b2[toy][tox]);
        }
        board[y][x] = 0;
        return true;
    }
    bool beat(int x, int y, int beatx, int beaty, int x_after_beat, int y_after_beat) {
        if (!is_valid(x_after_beat, y_after_beat)) return false;
        if (board[y][x] == 1) {
            move(x, y, x_after_beat, y_after_beat);
        }
        else if(board[y][x] == 2) {
            move(x, y, x_after_beat, y_after_beat, 2);
        }
        if (board[beaty][beatx] == 1) b1[beaty][beatx] = nullptr;
        else b2[beaty][beatx] = nullptr;
        board[beaty][beatx] = 0;
        return true;
    }
    bool can_Beat(int x, int y, int p_color, int killer_x, int killer_y) {//TODO: must be done
        if (x < 0 || x >= N || y < 0 || y >= N) return false;
        if (board[y][x] == 0 || board[killer_y][killer_x]==0) return false;
        check * maybeBeat =  getC(x,y);
        if (board[y][x] == 2) kinger * maybeBeat = getK(x,y);
        if(maybeBeat->color!=p_color) return false;
        if(board[killer_y][killer_x]==1) {
            for(int i = 2; i < 3; i++)
                if(is_valid(i*(x-killer_x),i*(y-killer_y))) return true;
            return false;
        } else if (board[killer_y][killer_x] == 2){
            for(int i = 2; i < N+2; i++)
                if(is_valid(i*(x-killer_x),i*(y-killer_y))) return true;
            return false;
        }
        
    }
    //!DONE
    
    //! DONE
    inline void to_kingers() { // проверка что кто то внезапно преваритлся в дамку
        int whiteSide = 0, blackSide = N - 1;
        for (int i = 0; i < N; i++) {
            if (board[whiteSide][i] == 1) {
                check* ch1 = getC(i , whiteSide);
                if (ch1->color == 1) {
                    kinger* appear = new kinger;
                    appear->color = ch1->color;
                    b1[whiteSide][i] = nullptr;
                    b2[whiteSide][i] = appear;
                    board[whiteSide][i] = 2;
                }
                
            }
            if (board[blackSide][i] == 1) {
                check* ch2 = getC( i,blackSide);
                if (ch2->color == 0) {
                    kinger* appear = new kinger;
                    appear->color = ch2->color;
                    b1[blackSide][i] = nullptr;
                    b2[blackSide][i] = appear;
                    board[blackSide][i] = 2;
                }
                
            }

        }
    }
    void motion(int player) {
    tryAgain:
        int sx = txMouseX();
        int sy = txMouseY();
        while (!(txMouseButtons() & 1)) {
            sx = txMouseX();
            sy = txMouseY();
        }

        // тут мы получаем координаты мышки 
        // если цвет мышки совпадает с 
        int x = sx / 100, y = sy / 100; // запиши сюда координаты клтеки
        if((x+y)&1==0) goto tryAgain;
        if(board[y][x]==1){
            if(player==getC(x, y)->color) goto tryAgain;
        } else if (board[y][x]==2){
            if(player==getK(x,y)->color) goto tryAgain;
        }
        if(board[y][x]==0) goto tryAgain;
        check* now = getC(x, y);
        int md = 2;
        if (board[y][x] == 2) { // дамка
            kinger* now = getK(x, y);
            int md = now->modificate_moves+1;
        }
        vector <pair <int, int>> moves = {{-1,-1},{-1,1},{1,1},{1,-1} };
        // показываем тут кружочки
        for(int i = 1; i < md; i++){
            for(const auto &it : moves){
                int a = it.first*i;
                int b = it.second*i;
                txSetFillColor(TX_GRAY);
                if (is_valid(x + b, y + a) && !can_Beat(x+b,y+a,player,x , y)) 
                    txCircle((100 * (x + b) + 100 * (x + b + 1)) / 2, 
                    (100 * (y + a) + 100 * (y + a + 1)) / 2, 20);
                else if(can_Beat(x+b,y+a,player,x, y)){
                    if(board[y][x]==0) continue;
                    if(board[y][x] == 1){
                        for(int i = 2; i < 3; i++)
                            if(is_valid(x+i*(b),y+i*(a))) 
                            txCircle((100 * (x + i*b) + 100 * (x + i*b + 1)) / 2, 
                            (100 * (y + i*a) + 100 * (y + i*a + 1)) / 2, 20);
                    }
                    if (board[y][x] == 2){
                        for(int i = 2; i < N+2; i++)
                            if(is_valid(x+i*(b),y+i*(a))) 
                            txCircle((100 * (x + i*b) + 100 * (x + i*b + 1)) / 2, 
                            (100 * (y + i*a) + 100 * (y + i*a + 1)) / 2, 20);
                    }
                    
                    
                }
            }
        }
    
        
        int ex = txMouseX(), ey = txMouseY();

        while (!(txMouseButtons() & 2)) {
            ex = txMouseX();
            ey = txMouseY();
        }
        
        txSleep(500);
        int tox = ex / 100, toy = ey / 100; // считываем куда он хочет пойти
        if((tox+toy)&1==0) goto tryAgain;
        if (!is_valid(tox, toy)) {
            render();
            goto tryAgain;
        }
        else {
            if(abs(tox-x)==2 and abs(toy-y)==2){
                
                int mbBex = (tox-x)/2;
                int mbBey = (toy-y)/2;
                beat(x,y,x+mbBex,y+mbBey,tox,toy);
            } 
            
            if (board[y][x] == 1) {// шашка
                move(x, y, tox, toy);
            }
            else  if (board[y][x] == 2) { // дамка
                move(x, y, tox, toy, 0);
            }
            
        }
        to_kingers();
        
    }


    inline void starter() {
        txCreateWindow(100 * N, 100 * N);
        prepare();
        int p = 0;
        while (true) {
            render();
            motion(p & 1);
            txSleep(100);

            // спим
            p++;
        }
        txSleep(10000000);
    }
    void prepare() {//!DONE
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i < 3 || i >= N - 3) {
                    if((i+j)&1){
                        board[i][j] = (((i + j) & 1));
                        if (i < 3) {
                            check* tmp = new check;
                            tmp->color = 0;
                            tmp->x = i, tmp->y = j;
                            b1[i][j] = tmp;
                        }
                        else {
                            check* tmp = new check;
                            tmp->color = 1;
                            tmp->x = i, tmp->y = j;
                            b1[i][j] = tmp;
                        }
                    }
                    else { board[i][j] = 0; b1[i][j] = nullptr; b2[i][j]==nullptr;} 
                }
                else { board[i][j] = 0; b1[i][j] = nullptr; b2[i][j]==nullptr;}
                b2[i][j]=nullptr;
            }
           
        }

    }

public:
    void iwantplay() {
        starter();
    }
};

signed main() {
    pprepare();
    GAME <8> x;
    x.iwantplay();
    return 0;
}