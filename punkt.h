#ifndef PUNKT_H
#define PUNKT_H

class punkt
{
public:
    punkt();
    int x;
    int y;
    int W = 1;
    punkt &operator =(const punkt &p){
        this->x = p.x;
        this->y = p.y;
        return *this;
    }
};

#endif // PUNKT_H
