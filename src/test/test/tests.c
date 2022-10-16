/*==========================================================*
 *
 * @author Gustaf Franzén :: https://github.com/BjorneEk;
 *
 * GVML matrix test functions
 *
 *==========================================================*/


#include "../../matrix.h"
#include <stdio.h>
#include <UL/math.h>

void test_rot3()
{
        struct v3f v, res;
        struct m3 m;
        v = V3F(0.0, 0.0, 1.0);

        m = EYE_M3;
        m = rotate_m3(m, deg_to_rad(180.0), V3F(1.0,0.0,1.0));
        res = dot_m3f(m, v);

        printf("test_rot3:\nresult:   ");
        print3f(res);
        printf("expected: ");
        print3f(V3F(1.0,0.0,0.0));
}

void test_rot4()
{
        struct v4f v, res;
        struct m4 m;
        v = V4F(0.0, 0.0, 1.0, 1.0);

        m = EYE_M4;
        m = rotate_m4(m, deg_to_rad(180.0), V3F(1.0,0.0,1.0));
        res = dot_m4f(m, v);

        printf("test_rot4:\nresult:   ");
        print4f(res);
        printf("expected: ");
        print4f(V4F(1.0,0.0,0.0, 1.0));
}
void test_dot_m3()
{
        struct m3 a, b, r, ex;

        a = M3(
                1.0, 2.0, 3.0,
                4.0, 5.0, 6.0,
                7.0, 8.0, 9.0);
        b = M3(
                8.0, 9.0, 8.0,
                9.0, 8.0, 9.0,
                8.0, 9.0, 8.0);
        ex = M3(
                50.0, 52.0, 50.0,
                125.0,130.0,125.0,
                200.0,208.0,200.0);
        r = dot_m3(a, b);
        printf("test_dot_m3:\nresult:\n");
        printm3(r);
        printf("expected:\n");
        printm3(ex);
}
void test_dot_m4()
{
        struct m4 a, b, r, ex;

        a = M4(
                1.0,  2.0,  3.0,  4.0,
                5.0,  6.0,  7.0,  8.0,
                9.0,  10.0, 11.0, 12.0,
                13.0, 14.0, 15.0, 16.0);
        b = M4(
                8.0, 9.0, 8.0, 9.0,
                9.0, 8.0, 9.0, 8.0,
                8.0, 9.0, 8.0, 9.0,
                9.0, 8.0, 9.0, 8.0);
        ex = M4(
                86.0, 84.0, 86.0, 84.0,
                222.0, 220.0, 222.0, 220.0,
                358.0, 356.0, 358.0, 356.0,
                494.0, 492.0, 494.0, 492.0);
        r = dot_m4(a, b);
        printf("test_dot_m4:\nresult:\n");
        printm4(r);
        printf("expected:\n");
        printm4(ex);
}
