#include <stdio.h>

struct ty {
        double r, s, p;
        ty() : r(-1), s(0), p(0) {}
        ty(double r, double s, double p) : r(r), s(s), p(p) {}
        void mult(double d) { r *= d; s *= d; p *= d; }
};

int R, S, P;
ty DP[105][105][105];

ty solve(int r, int s, int p)
{
        if (r == 0) return ty(0, 1, 0);
        if (s == 0) return ty(0, 0, 1);
        if (p == 0) return ty(1, 0, 0);

        ty& ret = DP[r][s][p];
        if (ret.r != -1)
                return ret;

        ty m1 = solve(r-1, s, p);
        ty m2 = solve(r, s-1, p);
        ty m3 = solve(r, s, p-1);
        double pt = r*p+s*r+p*s;
        m1.mult(r*p/pt);
        m2.mult(s*r/pt);
        m3.mult(p*s/pt);
        return ret = ty(m1.r+m2.r+m3.r, m1.s+m2.s+m3.s, m1.p+m2.p+m3.p);
}

int main()
{
        scanf("%d%d%d", &R, &S, &P);
        ty ans = solve(R, S, P);
        printf("%.15f %.15f %.15f\n", ans.r, ans.s, ans.p);
        return 0;
}
