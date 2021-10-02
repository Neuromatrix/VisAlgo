#ifndef game_of_live 
#define game_of_live
#include <vector>
class game_of_life{
    private:
        size_t n = 50, m = 50;
        std::vector <std::vector <bool>> field_previous;
        std::vector <std::vector <bool>> field_next;
        bool alive();
        int sum_cell(ssize_t i, ssize_t j);
        void render();
        void step();
    public:
        void init(std::vector <std::vector <bool>> data);
        void init(size_t n, size_t m);
        void start(double interval = 1.5);
};
#endif