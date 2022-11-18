#include <bits/stdc++.h>

using namespace std;

class point
{
public:
    int x, y;
    point(int a, int b) : x(a), y(b) {}
};

class Solution
{
    bool check(point *bl, point *tr, point *c)
    {
        bool x, y;
        x = c->x <= tr->x && c->x >= bl->x;
        y = c->y <= tr->y && c->y >= bl->y;
        return x && y;
    }

    int area(point *a, point *b)
    {
        return abs((a->x - b->x) * (a->y - b->y));
    }

    int seg(point *a, point *b, int z, bool c)
    {
        return c ? abs((a->y - b->y) * z) : abs((a->x - b->x) * z);
    }

public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int ans = 0;
        point *p1 = new point(ax1, ay1), *p2 = new point(ax2, ay2);
        point *p3 = new point(ax2, ay1), *p4 = new point(ax1, ay2);
        point *q1 = new point(bx1, by2), *q2 = new point(bx2, by1);
        point *q3 = new point(bx1, by1), *q4 = new point(bx2, by2);
        int fans = area(p1, p2) + area(q1, q2);

        bool isq1, isq2, isq3, isq4, isp1, isp2;
        isq1 = check(p1, p2, q1);
        isq2 = check(p1, p2, q2);
        isq3 = check(p1, p2, q3);
        isq4 = check(p1, p1, q4);
        isp1 = check(q3, q4, p1) && check(q3, q4, p2);
        isp2 = check(q3, q4, p3) && check(q3, q4, p4);

        cout << check(q1, q2, p1) << check(q1, q2, p2) << check(q1, q2, p3) << check(q1, q2, p4) << endl;
        cout << fans << endl;
        cout << isq1 << isq2 << isq3 << isq4 << isp1 << isp2 << "\n";

        if ((isq1 && isq2) || (isq3 && isq4))
            ans = area(q1, q2);
        else if (isq1 && isq3)
            ans = seg(q1, q3, p3->x - q1->x, true);
        else if (isq2 && isq4)
            ans = seg(q2, q4, p4->x - q4->x, true);
        else if (isq1 && isq4)
            ans = seg(q1, q4, q1->y - p1->y, false);
        else if (isq2 && isq3)
            ans = seg(q2, q3, p2->y - q2->y, false);
        else if (isq1)
            ans = area(q1, p3);
        else if (isq2)
            ans = area(q2, p4);
        else if (isq3)
            ans = area(q3, p2);
        else if (isq4)
            ans = area(q4, p1);
        else if (isp1 || isp2)
            ans = area(p1, p2);
        else
            ans = 0;

        return fans - ans;
    }
};

int main()
{
    cout << "Helllo World";
}