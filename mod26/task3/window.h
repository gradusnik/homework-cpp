#pragma once

class Window {
    int x_start = 0;
    int y_start = 0;
    int width = 1;
    int height = 1;
public:
    void setXStart(int x);
    void setYStart(int y);
    void setWidth(int w);
    void setHeight(int h);
    int getXStart();
    int getYStart();
    int getWidth();
    int getHeight();
    void move();
    void resize();
};