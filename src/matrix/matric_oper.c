/*==========================================================*
 *
 * @author Gustaf Franzén :: https://github.com/BjorneEk;
 *
 * GVML matrix operations functions
 *
 *==========================================================*/
#include "../matrix.h"

inline PURE struct m3 add_m3(struct m3 a, struct m3 b)
{
        return M3(
                a.m[0]+b.m[0], a.m[1]+b.m[1], a.m[2]+b.m[2],
                a.m[3]+b.m[3], a.m[4]+b.m[4], a.m[5]+b.m[5],
                a.m[6]+b.m[6], a.m[7]+b.m[7], a.m[8]+b.m[8]);
}
inline PURE struct m3 sub_m3(struct m3 a, struct m3 b)
{
        return M3(
                a.m[0]-b.m[0], a.m[1]-b.m[1], a.m[2]-b.m[2],
                a.m[3]-b.m[3], a.m[4]-b.m[4], a.m[5]-b.m[5],
                a.m[6]-b.m[6], a.m[7]-b.m[7], a.m[8]-b.m[8]);
}
inline PURE struct m3 mul_m3(struct m3 a, struct m3 b)
{
        return M3(
                a.m[0]*b.m[0], a.m[1]*b.m[1], a.m[2]*b.m[2],
                a.m[3]*b.m[3], a.m[4]*b.m[4], a.m[5]*b.m[5],
                a.m[6]*b.m[6], a.m[7]*b.m[7], a.m[8]*b.m[8]);
}
inline PURE struct m3 div_m3(struct m3 a, struct m3 b)
{
        return M3(
                a.m[0]/b.m[0], a.m[1]/b.m[1], a.m[2]/b.m[2],
                a.m[3]/b.m[3], a.m[4]/b.m[4], a.m[5]/b.m[5],
                a.m[6]/b.m[6], a.m[7]/b.m[7], a.m[8]/b.m[8]);
}

inline PURE struct m4 add_m4(struct m4 a, struct m4 b)
{
        return M4(
                a.m[0 ]+b.m[0 ], a.m[1 ]+b.m[1 ], a.m[2 ]+b.m[2 ], a.m[3 ]+b.m[3 ],
                a.m[4 ]+b.m[4 ], a.m[5 ]+b.m[5 ], a.m[6 ]+b.m[6 ], a.m[7 ]+b.m[7 ],
                a.m[8 ]+b.m[8 ], a.m[9 ]+b.m[9 ], a.m[10]+b.m[10], a.m[11]+b.m[11],
                a.m[12]+b.m[12], a.m[13]+b.m[13], a.m[14]+b.m[14], a.m[15]+b.m[15]);
}
inline PURE struct m4 sub_m4(struct m4 a, struct m4 b)
{
        return M4(
                a.m[0 ]-b.m[0 ], a.m[1 ]-b.m[1 ], a.m[2 ]-b.m[2 ], a.m[3 ]-b.m[3 ],
                a.m[4 ]-b.m[4 ], a.m[5 ]-b.m[5 ], a.m[6 ]-b.m[6 ], a.m[7 ]-b.m[7 ],
                a.m[8 ]-b.m[8 ], a.m[9 ]-b.m[9 ], a.m[10]-b.m[10], a.m[11]-b.m[11],
                a.m[12]-b.m[12], a.m[13]-b.m[13], a.m[14]-b.m[14], a.m[15]-b.m[15]);
}
inline PURE struct m4 mul_m4(struct m4 a, struct m4 b)
{
        return M4(
                a.m[0 ]*b.m[0 ], a.m[1 ]*b.m[1 ], a.m[2 ]*b.m[2 ], a.m[3 ]*b.m[3 ],
                a.m[4 ]*b.m[4 ], a.m[5 ]*b.m[5 ], a.m[6 ]*b.m[6 ], a.m[7 ]*b.m[7 ],
                a.m[8 ]*b.m[8 ], a.m[9 ]*b.m[9 ], a.m[10]*b.m[10], a.m[11]*b.m[11],
                a.m[12]*b.m[12], a.m[13]*b.m[13], a.m[14]*b.m[14], a.m[15]*b.m[15]);
}
inline PURE struct m4 div_m4(struct m4 a, struct m4 b)
{
        return M4(
                a.m[0 ]/b.m[0 ], a.m[1 ]/b.m[1 ], a.m[2 ]/b.m[2 ], a.m[3 ]/b.m[3 ],
                a.m[4 ]/b.m[4 ], a.m[5 ]/b.m[5 ], a.m[6 ]/b.m[6 ], a.m[7 ]/b.m[7 ],
                a.m[8 ]/b.m[8 ], a.m[9 ]/b.m[9 ], a.m[10]/b.m[10], a.m[11]/b.m[11],
                a.m[12]/b.m[12], a.m[13]/b.m[13], a.m[14]/b.m[14], a.m[15]/b.m[15]);
}

ALWAYS_INLINE void add_m3_r(struct m3 *a, struct m3 b)
{
        *a = add_m3(*a, b);
}
ALWAYS_INLINE void sub_m3_r(struct m3 *a, struct m3 b)
{
        *a = sub_m3(*a, b);
}
ALWAYS_INLINE void mul_m3_r(struct m3 *a, struct m3 b)
{
        *a = mul_m3(*a, b);
}
ALWAYS_INLINE void div_m3_r(struct m3 *a, struct m3 b)
{
        *a = div_m3(*a, b);
}

ALWAYS_INLINE void add_m4_r(struct m4 *a, struct m4 b)
{
        *a = add_m4(*a, b);
}
ALWAYS_INLINE void sub_m4_r(struct m4 *a, struct m4 b)
{
        *a = sub_m4(*a, b);
}
ALWAYS_INLINE void mul_m4_r(struct m4 *a, struct m4 b)
{
        *a = mul_m4(*a, b);
}
ALWAYS_INLINE void div_m4_r(struct m4 *a, struct m4 b)
{
        *a = div_m4(*a, b);
}
inline PURE struct m3 add_m3s(struct m3 a, f32_t s)
{
        return M3(
                a.m[0]+s, a.m[1]+s, a.m[2]+s,
                a.m[3]+s, a.m[4]+s, a.m[5]+s,
                a.m[6]+s, a.m[7]+s, a.m[8]+s);
}
inline PURE struct m3 sub_m3s(struct m3 a, f32_t s)
{
        return M3(
                a.m[0]-s, a.m[1]-s, a.m[2]-s,
                a.m[3]-s, a.m[4]-s, a.m[5]-s,
                a.m[6]-s, a.m[7]-s, a.m[8]-s);
}
inline PURE struct m3 mul_m3s(struct m3 a, f32_t s)
{
        return M3(
                a.m[0]*s, a.m[1]*s, a.m[2]*s,
                a.m[3]*s, a.m[4]*s, a.m[5]*s,
                a.m[6]*s, a.m[7]*s, a.m[8]*s);
}
inline PURE struct m3 div_m3s(struct m3 a, f32_t s)
{
        return M3(
                a.m[0]/s, a.m[1]/s, a.m[2]/s,
                a.m[3]/s, a.m[4]/s, a.m[5]/s,
                a.m[6]/s, a.m[7]/s, a.m[8]/s);
}

inline PURE struct m4 add_m4s(struct m4 a, f32_t s)
{
        return M4(
                a.m[0 ]+s, a.m[1 ]+s, a.m[2 ]+s, a.m[3 ]+s,
                a.m[4 ]+s, a.m[5 ]+s, a.m[6 ]+s, a.m[7 ]+s,
                a.m[8 ]+s, a.m[9 ]+s, a.m[10]+s, a.m[11]+s,
                a.m[12]+s, a.m[13]+s, a.m[14]+s, a.m[15]+s);
}
inline PURE struct m4 sub_m4s(struct m4 a, f32_t s)
{
        return M4(
                a.m[0 ]-s, a.m[1 ]-s, a.m[2 ]-s, a.m[3 ]-s,
                a.m[4 ]-s, a.m[5 ]-s, a.m[6 ]-s, a.m[7 ]-s,
                a.m[8 ]-s, a.m[9 ]-s, a.m[10]-s, a.m[11]-s,
                a.m[12]-s, a.m[13]-s, a.m[14]-s, a.m[15]-s);
}
inline PURE struct m4 mul_m4s(struct m4 a, f32_t s)
{
        return M4(
                a.m[0 ]*s, a.m[1 ]*s, a.m[2 ]*s, a.m[3 ]*s,
                a.m[4 ]*s, a.m[5 ]*s, a.m[6 ]*s, a.m[7 ]*s,
                a.m[8 ]*s, a.m[9 ]*s, a.m[10]*s, a.m[11]*s,
                a.m[12]*s, a.m[13]*s, a.m[14]*s, a.m[15]*s);
}
inline PURE struct m4 div_m4s(struct m4 a, f32_t s)
{
        return M4(
                a.m[0 ]/s, a.m[1 ]/s, a.m[2 ]/s, a.m[3 ]/s,
                a.m[4 ]/s, a.m[5 ]/s, a.m[6 ]/s, a.m[7 ]/s,
                a.m[8 ]/s, a.m[9 ]/s, a.m[10]/s, a.m[11]/s,
                a.m[12]/s, a.m[13]/s, a.m[14]/s, a.m[15]/s);
}

ALWAYS_INLINE void add_m3s_r(struct m3 *a, f32_t s)
{
        *a = add_m3s(*a, s);
}
ALWAYS_INLINE void sub_m3s_r(struct m3 *a, f32_t s)
{
        *a = sub_m3s(*a, s);
}
ALWAYS_INLINE void mul_m3s_r(struct m3 *a, f32_t s)
{
        *a = mul_m3s(*a, s);
}
ALWAYS_INLINE void div_m3s_r(struct m3 *a, f32_t s)
{
        *a = div_m3s(*a, s);
}

ALWAYS_INLINE void add_m4s_r(struct m4 *a, f32_t s)
{
        *a = add_m4s(*a, s);
}
ALWAYS_INLINE void sub_m4s_r(struct m4 *a, f32_t s)
{
        *a = sub_m4s(*a, s);
}
ALWAYS_INLINE void mul_m4s_r(struct m4 *a, f32_t s)
{
        *a = mul_m4s(*a, s);
}
ALWAYS_INLINE void div_m4s_r(struct m4 *a, f32_t s)
{
        *a = div_m4s(*a, s);
}
