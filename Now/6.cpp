#include <bits/stdc++.h>
using namespace std;

bool sln(long long E, long long H, long long N)
{
    long long x, y, z;
    x = 2 * E + H - 3 * N;
    y = E + H - 2 * N;
    z = 6 * N - 3 * E - 2 * H;
    if (x < 0 || y < 0 || z < 0)
        return false;
    else
        return true;
}

int main()
{

    int t;
    cin >> t;
    long long ans[t + 1];
    for (int k = 0; k < t; ++k)
    {
        long long N, E, H, A, B, C, p, q, r, e, h, x, y, z;
        cin >> N >> E >> H >> A >> B >> C;
        x = 2 * E + H - 3 * N;
        y = E + H - 2 * N;
        z = 6 * N - 3 * E - 2 * H;
        p = -3 * A - 2 * B + 6 * C;
        q = 2 * A + B - 3 * C;
        r = A + B - 2 * C;

        if (x < 0 || y < 0)
        {
            ans[k] = -1;
            continue;
        }

        long long w, pe1x, pe1y, pe2x, pe3x, pe3y, pe2y, ph1x, ph1y, ph2x, ph2y, ph3x, ph3y;
        long long e1, e2, e3, h1, h2, h3, w1, w2, w3, w4, w5, w6, w7, w8;
        cout << "pqr :" << p << " " << q << " " << r << "\n";

        ////////////////////////////////////////
        if (E <= N)
        {
            pe1x = E;
            pe1y = min(H, 3 * N - 2 * E);

            pe2x = E;
            if (E % 2 == 1)
                pe2x = pe2x - 1;
            pe2y = min(H, (6 * N - 3 * pe2x) / 2);

            pe3x = E;
            pe3y = min(H, (6 * N - 3 * pe2x) / 2);
        }
        else if (E > N && E < 2 * N)
        {
            pe1x = E;
            pe1y = min(H, 2 * N - E);

            pe2x = E;
            if (E % 2 == 1)
                pe2x = pe2x - 1;
            pe2y = min(H, (6 * N - 3 * pe2x) / 2);

            pe3x = E;
            pe3y = min(H, (6 * N - 3 * pe2x) / 2);
        }
        else
        {
            pe1x = 2 * N;
            pe1y = 0;
            pe2x = 2 * N;
            pe2y = 0;
            pe3x = 2 * N;
            pe3y = 0;
        }
        if (sln(pe3x, pe3y, N))
            w6 = q * pe3x + r * pe3y;
        else
            w6 = INT_MAX;

        if (H <= N)
        {
            ph1y = H;
            ph1x = min(E, 2 * N - H);

            ph2y = H;
            if (H % 3 == 1)
                ph2y = ph2y - 1;
            else if (H % 3 == 2)
                ph2y = ph2y - 2;
            ph2x = min(E, (6 * N - 2 * ph2y) / 3);

            ph3y = H;
            ph3x = min(E, (6 * N - 2 * ph2y) / 3);
            if (sln(ph3x, ph3y, N))
                w7 = q * pe3x + r * pe3y;
            else
                w7 = INT_MAX;
        }
        else if (H > N && H < 3 * N)
        {
            ph1y = H;
            if ((N % 2 == 1 && ph1y % 2 == 0) || (N % 2 == 0 && ph1y % 2 == 1))
                ph1y = ph1y - 1;
            ph1x = min(E, (3 * N - ph1y) / 2);

            ph2y = H;
            if (H % 3 == 1)
                ph2y = ph2y - 1;
            else if (H % 3 == 2)
                ph2y = ph2y - 2;
            ph2x = min(E, (6 * N - 2 * ph2y) / 3);

            ph3y = H;
            ph3x = min(E, (6 * N - 2 * ph2y) / 3);
            if (sln(ph3x, ph3y, N))
                w7 = q * pe3x + r * pe3y;
            else
                w7 = INT_MAX;

            long long ph4y, ph4x;
            ph4y = H;
            ph4x = min(E, (3 * N - ph1y) / 2);
            if (sln(ph3x, ph3y, N))
                w8 = q * pe3x + r * pe3y;
            else
                w8 = INT_MAX;
            w7 = min(w7, w8);
        }
        else
        {
            ph1y = 3 * N;
            ph1x = 0;
            ph2y = 3 * N;
            ph2x = 0;
            ph3x = 2 * N;
            ph3y = 0;
            w7 = q * ph3x + r * ph3y;
        }
        w6 = min(w6, w7);
        //////////////////////////////////////////////

        //////////////////
        bool b1, b2, b3, b4;
        b1 = sln(pe1x, pe1y, N);
        b2 = sln(pe2x, pe2y, N);
        b3 = sln(ph1x, ph1y, N);
        b4 = sln(ph2x, ph2y, N);
        /////////////////

        cout << pe1x << " " << pe1y << "\n";
        cout << pe2x << " " << pe2y << "\n";
        cout << ph1x << " " << ph1y << "\n";
        cout << ph2x << " " << ph2y << "\n";

        if ((E <= N && H >= N) || (E >= N && H <= N))
        {
            long double p1, p2;
            if (E <= N)
            {
                p1 = 3 * N - 2 * E;
                p2 = (6 * N - 3 * E) * 0.5;
            }
            else
            {
                p1 = 2 * N - E;
                p2 = (6 * N - 3 * E) * 0.5;
            }
            if (H <= max(p1, p2) && H >= min(p1, p2))
            {
                w1 = q * E + r * H;
                e2 = E;
                h2 = min(pe1y, pe2y);
                w2 = q * e2 + r * h2;
                h3 = H;
                e3 = min(ph1x, ph2x);
                w3 = q * e3 + r * h3;
                w = min(min(w1, w2), w3);
            }
            else
            {
                if (!b1)
                    w1 = INT_MAX;
                else
                    w1 = q * pe1x + r * pe1y;
                if (!b2)
                    w2 = INT_MAX;
                else
                    w2 = q * pe2x + r * pe2y;
                if (!b3)
                    w3 = INT_MAX;
                else
                    w3 = q * ph1x + r * ph1y;
                if (!b4)
                    w4 = INT_MAX;
                else
                    w4 = q * ph2x + r * ph2y;
                //w5 = q * N + r * N;
                w = min(min(w1, w2), min(w3, w4));
                //w = min(w, w5);
            }
        }
        else
        {
            if (b1 = 0)
                w1 = INT_MAX;
            else
                w1 = q * pe1x + r * pe1y;
            if (b2 = 0)
                w2 = INT_MAX;
            else
                w2 = q * pe2x + r * pe2y;
            if (b3 = 0)
                w3 = INT_MAX;
            else
                w3 = q * ph1x + r * ph1y;
            if (b4 = 0)
                w4 = INT_MAX;
            else
                w4 = q * ph2x + r * ph2y;
            w5 = q * N + r * N;
            w = min(min(w1, w2), min(w3, w4));
            w = min(w, w5);
        }
        w = min(w, w6);
        cout << w1 + N * p << " " << w2 + N * p << " " << w3 + N * p << " " << w4 + N * p << " " << w5 + N * p << " " << w6 << "\n";
        ans[k] = w + N * p;
    }

    for (int k = 0; k < t; ++k)
    {
        cout << ans[k] << "\n";
    }
    return 0;
}