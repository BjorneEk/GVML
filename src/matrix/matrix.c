/*==========================================================*
 *
 * @author Gustaf Franzén :: https://github.com/BjorneEk;
 *
 * GVML matrix functions
 *
 *==========================================================*/

#include "../matrix.h"


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

struct m3 add_m3(struct m3 a, struct m3 b);
struct m3 sub_m3(struct m3 a, struct m3 b);
struct m3 mul_m3(struct m3 a, struct m3 b);
struct m3 div_m3(struct m3 a, struct m3 b);

struct m4 add_m4(struct m4 a, struct m4 b);
struct m4 sub_m4(struct m4 a, struct m4 b);
struct m4 mul_m4(struct m4 a, struct m4 b);
struct m4 div_m4(struct m4 a, struct m4 b);

void add_m3_r(struct m3 *a, struct m3 b);
void sub_m3_r(struct m3 *a, struct m3 b);
void mul_m3_r(struct m3 *a, struct m3 b);
void div_m3_r(struct m3 *a, struct m3 b);

void add_m4_r(struct m4 *a, struct m4 b);
void sub_m4_r(struct m4 *a, struct m4 b);
void mul_m4_r(struct m4 *a, struct m4 b);
void div_m4_r(struct m4 *a, struct m4 b);

struct m3 mul_m3s(struct m3 a, f32_t s);
struct m4 mul_m4s(struct m4 a, f32_t s);

void mul_m3s_r(struct m3 *a, f32_t s);
void mul_m4s_r(struct m4 *a, f32_t s);

#define AB(i, j) a.m[i] * b.m[j]
inline PURE struct m3 dot_m3(struct m3 a, struct m3 b)
{
        return M3(
                AB(0,0)+AB(1,3)+AB(2,6), AB(1,0)+AB(1,4)+AB(2,7), AB(0,2)+AB(1,5)+AB(2,8),
                AB(3,0)+AB(4,3)+AB(5,6), AB(3,1)+AB(4,4)+AB(5,7), AB(3,2)+AB(4,5)+AB(5,8),
                AB(6,0)+AB(7,3)+AB(8,6), AB(6,1)+AB(7,4)+AB(8,7), AB(6,2)+AB(7,5)+AB(8,8));
}
inline PURE struct m4 dot_m4(struct m4 a, struct m4 b)
{
        return M4(
                AB(0 ,0)+AB(1 ,4)+AB(2 ,8 )+AB(3 ,12), AB(0 ,1)+AB(1 ,5)+AB(2 ,9 )+AB(3 ,13),
                AB(0 ,2)+AB(1 ,6)+AB(2 ,10)+AB(3 ,14), AB(0 ,3)+AB(1 ,7)+AB(2 ,11)+AB(3 ,15),
                AB(4 ,0)+AB(5 ,4)+AB(6 ,8 )+AB(7 ,12), AB(4 ,1)+AB(5 ,5)+AB(6 ,9 )+AB(7 ,13),
                AB(4 ,2)+AB(5 ,6)+AB(6,10 )+AB(7 ,14), AB(4 ,3)+AB(5 ,7)+AB(6 ,11)+AB(7 ,15),
                AB(8 ,0)+AB(9 ,4)+AB(10,8 )+AB(11,12), AB(8 ,1)+AB(9 ,5)+AB(10,9 )+AB(11,13),
                AB(8 ,2)+AB(8 ,6)+AB(10,10)+AB(11,14), AB(8 ,3)+AB(9 ,7)+AB(10,11)+AB(11,15),
                AB(12,0)+AB(13,4)+AB(14,8 )+AB(15,12), AB(12,1)+AB(13,5)+AB(14,9 )+AB(15,13),
                AB(12,2)+AB(13,6)+AB(14,10)+AB(15,14), AB(12,3)+AB(13,7)+AB(14,11)+AB(15,15));
}
#undef AB
#define AB(i, j) a->m[i] * b.m[j]
inline void dot_m3_r(struct m3 *a, struct m3 b)
{
        a->m[0]=AB(0,0)+AB(1,3)+AB(2,6);
        a->m[1]=AB(1,0)+AB(1,4)+AB(2,7);
        a->m[2]=AB(0,2)+AB(1,5)+AB(2,8);
        a->m[3]=AB(3,0)+AB(4,3)+AB(5,6);
        a->m[4]=AB(3,1)+AB(4,4)+AB(5,7);
        a->m[5]=AB(3,2)+AB(4,5)+AB(5,8);
        a->m[6]=AB(6,0)+AB(7,3)+AB(8,6);
        a->m[7]=AB(6,1)+AB(7,4)+AB(8,7);
        a->m[8]=AB(6,2)+AB(7,5)+AB(8,8);
}
inline void dot_m4_r(struct m4 *a, struct m4 b)
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
        a->m[10]=AB(8 ,2)+AB(8 ,6)+AB(10,10)+AB(11,14);
        a->m[11]=AB(8 ,3)+AB(9 ,7)+AB(10,11)+AB(11,15);
        a->m[12]=AB(12,0)+AB(13,4)+AB(14,8 )+AB(15,12);
        a->m[13]=AB(12,1)+AB(13,5)+AB(14,9 )+AB(15,13);
        a->m[14]=AB(12,2)+AB(13,6)+AB(14,10)+AB(15,14);
        a->m[15]=AB(12,3)+AB(13,7)+AB(14,11)+AB(15,15);
}
#undef AB

struct m3 scale_m3(struct m3 a, struct v3f v);
struct m4 scale_m4(struct m4 a, struct v3f v);

struct m4 translate_m4(struct m4, struct v3f v);

struct m3 rotate_m3(struct m3, struct v3f rv);
struct m4 rotate_m4(struct m4, struct v3f rv);

struct v2f dot_m3f2(struct m3 m, struct v2f v);
struct v3f dot_m3f3(struct m3 m, struct v3f v);
struct v3f dot_m4f3(struct m4 m, struct v3f v);
struct v4f dot_m4f4(struct m4 m, struct v4f v);
