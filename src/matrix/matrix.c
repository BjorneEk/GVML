/*==========================================================*
 *
 * @author Gustaf Franzén :: https://github.com/BjorneEk;
 *
 * GVML matrix functions
 *
 *==========================================================*/

#include "../matrix.h"
#include <UL/math.h>
#include <string.h>
#include <UL/str.h>
#include <stdio.h>




PURE struct m4 m3m4(struct m3 m)
{
        return M4(
                m.m[0], m.m[1], m.m[2], 0.0,
                m.m[3], m.m[4], m.m[5], 0.0,
                m.m[6], m.m[7], m.m[8], 0.0,
                0.0,    0.0,    0.0,    1.0);
}
PURE struct m3 m4m3(struct m4 m)
{
                return M3(
                        m.m[0], m.m[1], m.m[2],
                        m.m[4], m.m[5], m.m[6],
                        m.m[8], m.m[9], m.m[10]);
}

struct m4 perspective(f32_t fov, f32_t ar, f32_t n, f32_t f)
{
        f32_t scale;
        f32_t r, l, t, b;
        struct m4 res;
        scale = tan(fov * 0.5 * M_PI / 180) * n;
        r = ar * scale, l = -r;
        t = scale, b = -t;


        res = M4(
                2 * n / (r - l),   0,                  0,                  0,
                0,                 2 * n / (t - b),    0,                  0,
                (r + l) / (r - l), (t + b) / (t - b), -(f + n) / (f - n), -1,
                0,       0,       -2 * f * n / (f - n),                    0);

        return res;
}


ALWAYS_INLINE PURE struct m3 transpose_m3(struct m3 m)
{
        return M3(
                m.m[0], m.m[3], m.m[6],
                m.m[1], m.m[4], m.m[7],
                m.m[2], m.m[5], m.m[8]);
}
ALWAYS_INLINE PURE struct m4 transpose_m4(struct m4 m)
{
        return M4(
                m.m[0 ], m.m[4 ], m.m[8 ], m.m[12],
                m.m[1 ], m.m[5 ], m.m[9 ], m.m[13],
                m.m[2 ], m.m[6 ], m.m[10], m.m[14],
                m.m[3 ], m.m[7 ], m.m[11], m.m[15]);
}

ALWAYS_INLINE void transpose_m3_r(struct m3 *m)
{
        *m = transpose_m3(*m);
}
ALWAYS_INLINE void transpose_m4_r(struct m4 *m)
{
        *m = transpose_m4(*m);
}


#define AB(i, j) a.m[i] * b.m[j]
PURE struct m3 dot_m3(struct m3 a, struct m3 b)
{
        return M3(
                AB(0,0)+AB(1,3)+AB(2,6), AB(0,1)+AB(1,4)+AB(2,7), AB(0,2)+AB(1,5)+AB(2,8),
                AB(3,0)+AB(4,3)+AB(5,6), AB(3,1)+AB(4,4)+AB(5,7), AB(3,2)+AB(4,5)+AB(5,8),
                AB(6,0)+AB(7,3)+AB(8,6), AB(6,1)+AB(7,4)+AB(8,7), AB(6,2)+AB(7,5)+AB(8,8));
}
PURE struct m4 dot_m4(struct m4 a, struct m4 b)
{
        return M4(
                AB(0 ,0)+AB(1 ,4)+AB(2 ,8 )+AB(3 ,12), AB(0 ,1)+AB(1 ,5)+AB(2 ,9 )+AB(3 ,13),
                AB(0 ,2)+AB(1 ,6)+AB(2 ,10)+AB(3 ,14), AB(0 ,3)+AB(1 ,7)+AB(2 ,11)+AB(3 ,15),
                AB(4 ,0)+AB(5 ,4)+AB(6 ,8 )+AB(7 ,12), AB(4 ,1)+AB(5 ,5)+AB(6 ,9 )+AB(7 ,13),
                AB(4 ,2)+AB(5 ,6)+AB(6,10 )+AB(7 ,14), AB(4 ,3)+AB(5 ,7)+AB(6 ,11)+AB(7 ,15),
                AB(8 ,0)+AB(9 ,4)+AB(10,8 )+AB(11,12), AB(8 ,1)+AB(9 ,5)+AB(10,9 )+AB(11,13),
                AB(8 ,2)+AB(9 ,6)+AB(10,10)+AB(11,14), AB(8 ,3)+AB(9 ,7)+AB(10,11)+AB(11,15),
                AB(12,0)+AB(13,4)+AB(14,8 )+AB(15,12), AB(12,1)+AB(13,5)+AB(14,9 )+AB(15,13),
                AB(12,2)+AB(13,6)+AB(14,10)+AB(15,14), AB(12,3)+AB(13,7)+AB(14,11)+AB(15,15));
}
#undef AB
#define AB(i, j) a->m[i] * b.m[j]
void dot_m3_r(struct m3 *a, struct m3 b)
{
        a->m[0]=AB(0,0)+AB(1,3)+AB(2,6);
        a->m[1]=AB(0,1)+AB(1,4)+AB(2,7);
        a->m[2]=AB(0,2)+AB(1,5)+AB(2,8);
        a->m[3]=AB(3,0)+AB(4,3)+AB(5,6);
        a->m[4]=AB(3,1)+AB(4,4)+AB(5,7);
        a->m[5]=AB(3,2)+AB(4,5)+AB(5,8);
        a->m[6]=AB(6,0)+AB(7,3)+AB(8,6);
        a->m[7]=AB(6,1)+AB(7,4)+AB(8,7);
        a->m[8]=AB(6,2)+AB(7,5)+AB(8,8);
}
void dot_m4_r(struct m4 *a, struct m4 b)
{
        a->m[0 ]=AB(0 ,0)+AB(1 ,4)+AB(2 ,8 )+AB(3 ,12);
        a->m[1 ]=AB(0 ,1)+AB(1 ,5)+AB(2 ,9 )+AB(3 ,13);
        a->m[2 ]=AB(0 ,2)+AB(1 ,6)+AB(2 ,10)+AB(3 ,14);
        a->m[3 ]=AB(0 ,3)+AB(1 ,7)+AB(2 ,11)+AB(3 ,15);
        a->m[4 ]=AB(4 ,0)+AB(5 ,4)+AB(6 ,8 )+AB(7 ,12);
        a->m[5 ]=AB(4 ,1)+AB(5 ,5)+AB(6 ,9 )+AB(7 ,13);
        a->m[6 ]=AB(4 ,2)+AB(5 ,6)+AB(6 ,10)+AB(7 ,14);
        a->m[7 ]=AB(4 ,3)+AB(5 ,7)+AB(6 ,11)+AB(7 ,15);
        a->m[8 ]=AB(8 ,0)+AB(9 ,4)+AB(10,8 )+AB(11,12);
        a->m[9 ]=AB(8 ,1)+AB(9 ,5)+AB(10,9 )+AB(11,13);
        a->m[10]=AB(8 ,2)+AB(9 ,6)+AB(10,10)+AB(11,14);
        a->m[11]=AB(8 ,3)+AB(9 ,7)+AB(10,11)+AB(11,15);
        a->m[12]=AB(12,0)+AB(13,4)+AB(14,8 )+AB(15,12);
        a->m[13]=AB(12,1)+AB(13,5)+AB(14,9 )+AB(15,13);
        a->m[14]=AB(12,2)+AB(13,6)+AB(14,10)+AB(15,14);
        a->m[15]=AB(12,3)+AB(13,7)+AB(14,11)+AB(15,15);
}
#undef AB

struct m3 scale_m3(struct m3 m, struct v3f v)
{
        return dot_m3(m, SCALE_MAT3(v.x, v.y, v.z));
}
struct m4 scale_m4(struct m4 m, struct v3f v)
{
        return dot_m4(m, SCALE_MAT4(v.x, v.y, v.z));
}

struct m4 translate_m4(struct m4 m, struct v3f v)
{
        return dot_m4(m, TRANSLATE_MAT4(v.x, v.y, v.z));
}

/**
 * calculates the rotation matrix for a rotation around V by a radians using
 * 'Rodrigues rotation formula'
 **/
PURE struct m3 rotation_mat3(f32_t a, struct v3f v)
{
        struct m3 W,W2, W_sina;

        normalizef3(&v);
        /*
         0 0 0
         0 0-1
         0 1 0
          */
        W = M3(
                0.0, -v.z,  v.y,
                v.z,  0.0, -v.x,
               -v.y,  v.x,  0.0);

        W_sina = mul_m3s(W, SINF(a));

        W2 = dot_m3(W,W);

        mul_m3s_r(&W2, 2.0*SIN2F(a/2.0));
        /*MR = I + W_sina + W2*/
        return add_m3(add_m3(EYE_M3, W_sina), W2);
}


PURE struct m4 rotation_mat4(f32_t a, struct v3f v)
{
        return m3m4(rotation_mat3(a,v));
}

ALWAYS_INLINE PURE struct m3 rotate_m3(struct m3 m, f32_t a, struct v3f v)
{
        return dot_m3(m, rotation_mat3(a, v));
}
struct m4 rotate_m4(struct m4 m, f32_t a, struct v3f v)
{
        return dot_m4(m, rotation_mat4(a, v));
}

struct v3f dot_m3f(struct m3 m, struct v3f v)
{
        return V3F(
                m.m[0] * v.x + m.m[1] * v.y + m.m[2] * v.z,
                m.m[3] * v.x + m.m[4] * v.y + m.m[5] * v.z,
                m.m[6] * v.x + m.m[7] * v.y + m.m[8] * v.z);
}
struct v4f dot_m4f(struct m4 m, struct v4f v)
{
        return V4F(
                v.x * m.m[0 ] + v.y * m.m[1 ] + v.z * m.m[2 ] + v.w * m.m[3 ],
                v.x * m.m[4 ] + v.y * m.m[5 ] + v.z * m.m[6 ] + v.w * m.m[7 ],
                v.x * m.m[8 ] + v.y * m.m[9 ] + v.z * m.m[10] + v.w * m.m[11],
                v.x * m.m[12] + v.y * m.m[13] + v.z * m.m[14] + v.w * m.m[15]);
}

void printm3(struct m3 m)
{
        i32_t i, j;
        f32_t * ptr;

        ptr = m.m;
        printf("│");
        for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++)
                        printf("%5.2f ", *(ptr++));
                printf("│\n");
                if(i<2) printf("│");
        }
}
void printm4(struct m4 m)
{
        i32_t i, j;
        f32_t * ptr;

        ptr = m.m;
        printf("│");
        for (i = 0; i < 4; i++) {
                for (j = 0; j < 4; j++)
                        printf("%5.2f ", *(ptr++));
                printf("│\n");
                if(i<5) printf("│");
        }
}
