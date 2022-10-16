/*==========================================================*
 *
 * @author Gustaf Franzén :: https://github.com/BjorneEk;
 *
 * GVML matrix header file
 *
 *==========================================================*/

#ifndef _GVML_MATRIX_H_
#define _GVML_MATRIX_H_


#include "vector.h"
#include <UL/types.h>
#include <UL/macro.h>
#include <UL/math.h>

/**
 * row major order matricies
 **/
struct PACKED m3 { f32_t m[9 ]; };
struct PACKED m4 { f32_t m[16]; };


#define M3(_a,_b,_c,_d,_e,_f,_g,_h,_i) (struct m3) {.m={                        \
        (_a), (_b), (_c),                                                       \
        (_d), (_e), (_f),                                                       \
        (_g), (_h), (_i),}}
#define M4(_a,_b,_c,_d,_e,_f,_g,_h,_i,_j,_k,_l,_m,_n,_o,_p) (struct m4) {.m={   \
        (_a), (_b), (_c), (_d),                                                 \
        (_e), (_f), (_g), (_h),                                                 \
        (_i), (_j), (_k), (_l),                                                 \
        (_m), (_n), (_o), (_p)}}
/**
 * Identity matricies
 **/
#define EYE_M3 M3(                                                              \
                1.0, 0.0, 0.0,                                                  \
                0.0, 1.0, 0.0,                                                  \
                0.0, 0.0, 1.0)

#define EYE_M4 M4(                                                              \
                1.0, 0.0, 0.0, 0.0,                                             \
                0.0, 1.0, 0.0, 0.0,                                             \
                0.0, 0.0, 1.0, 0.0,                                             \
                0.0, 0.0, 0.0, 1.0)
/**
 * rotation matrix macros
 **/
#define RX_M3(_a) M3(                                                           \
                1.0, 0.0,      0.0,                                             \
                0.0, COSF(_a), -SINF(_a),                                         \
                0.0, SINF(_a),  COSF(_a))
#define RY_M3(_a) M3(                                                           \
                cos(_a),  0.0,  sin(_a),                                        \
                0.0,      1.0,  0.0,                                            \
                -sin(_a), 0.0,  cos(_a))
#define RZ_M3(_a) M3(                                                           \
                cos(_a), -sin(_a), 0.0,                                         \
                sin(_a),  cos(_a), 0.0,                                         \
                0.0,      0.0,     1.0)

#define RX_M4(_a) M4(                                                           \
                1.0,  0.0,      0.0,     0.0,                                   \
                0.0,  cos(_a),  sin(_a), 0.0,                                   \
                0.0, -sin(_a),  cos(_a), 0.0,                                   \
                0.0,  0.0,      0.0,     1.0)
#define RY_M4(_a) M4(                                                           \
                cos(_a), 0.0, -sin(_a), 0.0,                                    \
                0.0,     1.0,  0.0,     0.0,                                    \
                sin(_a), 0.0,  cos(_a), 0.0,                                    \
                0.0,     0.0,  0.0,     1.0)
#define RZ_M4(_a) M4(                                                           \
                cos(_a), -sin(_a), 0.0, 0.0,                                    \
                sin(_a),  cos(_a), 0.0, 0.0,                                    \
                0.0,      0.0,     1.0, 0.0,                                    \
                0.0,      0.0,     0.0, 1.0)

/**
 * scaling matricies
 **/
#define SCALE_MAT3(x_, y_, z_) M3(                                              \
                (x_), 0.0, 0.0,                                                 \
                0.0, (y_), 0.0,                                                 \
                0.0, 0.0, (z_))
#define SCALE_MAT4(x_, y_, z_) M4(                                              \
                (x_), 0.0, 0.0, 0.0,                                            \
                0.0, (y_), 0.0, 0.0,                                            \
                0.0, 0.0, (z_), 0.0,                                            \
                0.0, 0.0, 0.0,  1.0)
/**
 * translation matricies
 **/
#define TRANSLATE_MAT4(x_, y_, z_) M4(                                          \
                1.0, 0.0, 0.0, (x_),                                            \
                0.0, 1.0, 0.0, (y_),                                            \
                0.0, 0.0, 1.0, (z_),                                            \
                0.0, 0.0, 0.0, 1.0)

struct m4 m3m4(struct m3 m);
struct m3 m4m3(struct m4 m);

struct m3 transpose_m3(struct m3 m);
struct m4 transpose_m4(struct m4 m);

void transpose_m3_r(struct m3 *m);
void transpose_m4_r(struct m4 *m);

struct m4 perspective(f32_t fov, f32_t ar, f32_t n, f32_t f);

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


struct m3 add_m3s(struct m3 a, f32_t s);
struct m3 sub_m3s(struct m3 a, f32_t s);
struct m3 mul_m3s(struct m3 a, f32_t s);
struct m3 div_m3s(struct m3 a, f32_t s);

struct m4 add_m4s(struct m4 a, f32_t s);
struct m4 sub_m4s(struct m4 a, f32_t s);
struct m4 mul_m4s(struct m4 a, f32_t s);
struct m4 div_m4s(struct m4 a, f32_t s);

void add_m3s_r(struct m3 *a, f32_t s);
void sub_m3s_r(struct m3 *a, f32_t s);
void mul_m3s_r(struct m3 *a, f32_t s);
void div_m3s_r(struct m3 *a, f32_t s);

void add_m4s_r(struct m4 *a, f32_t s);
void sub_m4s_r(struct m4 *a, f32_t s);
void mul_m4s_r(struct m4 *a, f32_t s);
void div_m4s_r(struct m4 *a, f32_t s);

struct m3 dot_m3(struct m3 a, struct m3 b);
struct m4 dot_m4(struct m4 a, struct m4 b);

void dot_m3_r(struct m3 *a, struct m3 b);
void dot_m4_r(struct m4 *a, struct m4 b);

struct m3 scale_m3(struct m3 a, struct v3f v);
struct m4 scale_m4(struct m4 a, struct v3f v);

struct m4 translate_m4(struct m4, struct v3f v);

struct m3 rotate_m3(struct m3, f32_t a, struct v3f rv);
struct m4 rotate_m4(struct m4, f32_t a, struct v3f rv);

struct v3f dot_m3f(struct m3 m, struct v3f v);
struct v4f dot_m4f(struct m4 m, struct v4f v);

void printm3(struct m3 m);
void printm4(struct m4 m);

#endif /* _GVML_MATRIX_H_ */
