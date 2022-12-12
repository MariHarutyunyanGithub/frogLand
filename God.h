#ifndef GOD_H
#define GOD_H

class God {
public:
    void agenda_mode();
    void at_night();
private:
    int day = 7;
    int night = 2;
};
#endif // GOD_H