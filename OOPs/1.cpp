#include <iostream>
using namespace std;
class Hero{
    // properties
    public:
    int health;
    int level;
    Hero(int health, int level){
        this->health = health;
        this->level = level;
    }
};
int main()
{
    Hero sup(5,40);
    cout << sup.level;
    return 0;
}