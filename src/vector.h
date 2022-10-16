/*==========================================================*
 *
 * @author Gustaf Franzén :: https://github.com/BjorneEk;
 *
 * GVML vector header file
 *
 *==========================================================*/

#ifndef _GVML_VECTOR_H_
#define _GVML_VECTOR_H_

#include <UL/types.h>
#include <UL/macro.h>

/**
 * 2, 3 and 4d f32_t vector structs
 **/
struct PACKED v2f { f32_t x, y; }      ;
struct PACKED v3f { f32_t x, y, z; }   ;
struct PACKED v4f { f32_t x, y, z, w; };

/**
 * 2, 3 and 4d i32_t vector structs
 **/
struct PACKED v2i { i32_t x, y; }      ;
struct PACKED v3i { i32_t x, y, z; }   ;
struct PACKED v4i { i32_t x, y, z, w; };

/**
 * vector constructor helper macros
 **/
#define V2(_x, _y)         { .x=(_x), .y=(_y)                   }
#define V3(_x, _y, _z)     { .x=(_x), .y=(_y), .z=(_z)          }
#define V4(_x, _y, _z, _w) { .x=(_x), .y=(_y), .z=(_z), .w=(_w) }
/**
 * constructor macros for the f64_t vector structs
 **/
#define V2F(_x, _y)         ((struct v2f)V2((_x), (_y)))
#define V3F(_x, _y, _z)     ((struct v3f)V3((_x), (_y), (_z)))
#define V4F(_x, _y, _z, _w) ((struct v4f)V4((_x), (_y), (_z), (_w)))
/**
 * constructor macros for the i32_t vector structs
 **/
#define V2I(_x, _y)         ((struct v2i)V2((_x), (_y)))
#define V3I(_x, _y, _z)     ((struct v3i)V3((_x), (_y), (_z)))
#define V4I(_x, _y, _z, _w) ((struct v4i)V4((_x), (_y), (_z), (_w)))

/**
 * converts float vectors to int vectors and vise versa
 **/
#define IV_TO_IV2(v_) V2I((i32_t)((v_).x), (i32_t)((v_).y)))
#define IV_TO_IV3(v_) V3I((i32_t)((v_).x), (i32_t)((v_).y), (i32_t)((v_).z)))
#define IV_TO_IV4(v_) V4I((i32_t)((v_).x), (i32_t)((v_).y), (i32_t)((v_).z), (i32_t)((v_).w)))
#define FV_TO_FV2(v_) V2F((f32_t)((v_).x), (f32_t)((v_).y)))
#define FV_TO_FV3(v_) V3F((f32_t)((v_).x), (f32_t)((v_).y), (f32_t)((v_).z)))
#define FV_TO_FV4(v_) V4F((f32_t)((v_).x), (f32_t)((v_).y), (f32_t)((v_).z), (f32_t)((v_).w)))


/**
 * size conversions
 **/
struct v2f v3fv2f(struct v3f v);
struct v2f v4fv2f(struct v4f v);
struct v3f v2fv3f(struct v2f v);
struct v3f v4fv3f(struct v4f v);
struct v4f v2fv4f(struct v2f v);
struct v4f v3fv4f(struct v3f v);
/*
 * returns the dot product of u and v
 */
f32_t dot2f(struct v2f u, struct v2f v);
f32_t dot3f(struct v3f u, struct v3f v);
f32_t dot4f(struct v4f u, struct v4f v);

/*
 * returns the 3D cross product of u and v
 */
struct v3f cross3f(struct v3f u, struct v3f v);
struct v4f cross4f(struct v4f u, struct v4f v);

f32_t len2f(struct v2f v);
f32_t len3f(struct v3f v);
f32_t len4f(struct v4f v);

bool equals2f(struct v2f u, struct v2f v);
bool equals3f(struct v3f u, struct v3f v);
bool equals4f(struct v4f u, struct v4f v);

void normalizef2(struct v2f *v);
void normalizef3(struct v3f *v);
void normalizef4(struct v4f *v);

struct v2f normalizedf2(struct v2f v);
struct v3f normalizedf3(struct v3f v);
struct v4f normalizedf4(struct v4f v);

struct v3f normal3f(struct v3f u, struct v3f v, struct v3f w);
struct v4f normal4f(struct v4f u, struct v4f v, struct v4f w);

void str2f(char *dst, struct v2f v);
void str3f(char *dst, struct v3f v);
void str4f(char *dst, struct v4f v);

void print2f(struct v2f v);
void print3f(struct v3f v);
void print4f(struct v4f v);


/**
 * int vector functions
 **/

struct v2i v3iv2i(struct v3i v);
struct v2i v4iv2i(struct v4i v);
struct v3i v2iv3i(struct v2i v);
struct v3i v4iv3i(struct v4i v);
struct v4i v2iv4i(struct v2i v);
struct v4i v3iv4i(struct v3i v);

i32_t dot2i(struct v2i u, struct v2i v);
i32_t dot3i(struct v3i u, struct v3i v);
i32_t dot4i(struct v4i u, struct v4i v);

bool equals2i(struct v2i u, struct v2i v);
bool equals3i(struct v3i u, struct v3i v);
bool equals4i(struct v4i u, struct v4i v);

void str2i(char *dst, struct v2i v);
void str3i(char *dst, struct v3i v);
void str4i(char *dst, struct v4i v);

void print2i(struct v2i v);
void print3i(struct v3i v);
void print4i(struct v4i v);
/**
 *  standard vector - vector and vector - scalar operations
 *  for each vector type
 *
 *  naming:  operation size (f|i) ( |_r)
 *
 *  functions ending whith:
 *    _r:
 *      does what the function whitout it would have
 *      done but on the reference
 *    ff or ii:
 *      vector - scalar
 *    i or f:
 *      vector vector
 **/
struct v2f add2f(struct v2f u, struct v2f v);
struct v2f sub2f(struct v2f u, struct v2f v);
struct v2f div2f(struct v2f u, struct v2f v);
struct v2f mul2f(struct v2f u, struct v2f v);

struct v3f add3f(struct v3f u, struct v3f v);
struct v3f sub3f(struct v3f u, struct v3f v);
struct v3f div3f(struct v3f u, struct v3f v);
struct v3f mul3f(struct v3f u, struct v3f v);

struct v4f add4f(struct v4f u, struct v4f v);
struct v4f sub4f(struct v4f u, struct v4f v);
struct v4f div4f(struct v4f u, struct v4f v);
struct v4f mul4f(struct v4f u, struct v4f v);

void add2f_r(struct v2f *u, struct v2f v);
void sub2f_r(struct v2f *u, struct v2f v);
void div2f_r(struct v2f *u, struct v2f v);
void mul2f_r(struct v2f *u, struct v2f v);

void add3f_r(struct v3f *u, struct v3f v);
void sub3f_r(struct v3f *u, struct v3f v);
void div3f_r(struct v3f *u, struct v3f v);
void mul3f_r(struct v3f *u, struct v3f v);

void add4f_r(struct v4f *u, struct v4f v);
void sub4f_r(struct v4f *u, struct v4f v);
void div4f_r(struct v4f *u, struct v4f v);
void mul4f_r(struct v4f *u, struct v4f v);

struct v2f add2ff(struct v2f u, f32_t f);
struct v2f sub2ff(struct v2f u, f32_t f);
struct v2f div2ff(struct v2f u, f32_t f);
struct v2f mul2ff(struct v2f u, f32_t f);

struct v3f add3ff(struct v3f u, f32_t f);
struct v3f sub3ff(struct v3f u, f32_t f);
struct v3f div3ff(struct v3f u, f32_t f);
struct v3f mul3ff(struct v3f u, f32_t f);

struct v4f add4ff(struct v4f u, f32_t f);
struct v4f sub4ff(struct v4f u, f32_t f);
struct v4f div4ff(struct v4f u, f32_t f);
struct v4f mul4ff(struct v4f u, f32_t f);

void add2ff_r(struct v2f *u, f32_t f);
void sub2ff_r(struct v2f *u, f32_t f);
void div2ff_r(struct v2f *u, f32_t f);
void mul2ff_r(struct v2f *u, f32_t f);

void add3ff_r(struct v3f *u, f32_t f);
void sub3ff_r(struct v3f *u, f32_t f);
void div3ff_r(struct v3f *u, f32_t f);
void mul3ff_r(struct v3f *u, f32_t f);

void add4ff_r(struct v4f *u, f32_t f);
void sub4ff_r(struct v4f *u, f32_t f);
void div4ff_r(struct v4f *u, f32_t f);
void mul4ff_r(struct v4f *u, f32_t f);

struct v2i add2i(struct v2i u, struct v2i v);
struct v2i sub2i(struct v2i u, struct v2i v);
struct v2i div2i(struct v2i u, struct v2i v);
struct v2i mul2i(struct v2i u, struct v2i v);

struct v3i add3i(struct v3i u, struct v3i v);
struct v3i sub3i(struct v3i u, struct v3i v);
struct v3i div3i(struct v3i u, struct v3i v);
struct v3i mul3i(struct v3i u, struct v3i v);

struct v4i add4i(struct v4i u, struct v4i v);
struct v4i sub4i(struct v4i u, struct v4i v);
struct v4i div4i(struct v4i u, struct v4i v);
struct v4i mul4i(struct v4i u, struct v4i v);

void add2i_r(struct v2i *u, struct v2i v);
void sub2i_r(struct v2i *u, struct v2i v);
void div2i_r(struct v2i *u, struct v2i v);
void mul2i_r(struct v2i *u, struct v2i v);

void add3i_r(struct v3i *u, struct v3i v);
void sub3i_r(struct v3i *u, struct v3i v);
void div3i_r(struct v3i *u, struct v3i v);
void mul3i_r(struct v3i *u, struct v3i v);

void add4i_r(struct v4i *u, struct v4i v);
void sub4i_r(struct v4i *u, struct v4i v);
void div4i_r(struct v4i *u, struct v4i v);
void mul4i_r(struct v4i *u, struct v4i v);

struct v2i add2ii(struct v2i u, i32_t i);
struct v2i sub2ii(struct v2i u, i32_t i);
struct v2i div2ii(struct v2i u, i32_t i);
struct v2i mul2ii(struct v2i u, i32_t i);

struct v3i add3ii(struct v3i u, i32_t i);
struct v3i sub3ii(struct v3i u, i32_t i);
struct v3i div3ii(struct v3i u, i32_t i);
struct v3i mul3ii(struct v3i u, i32_t i);

struct v4i add4ii(struct v4i u, i32_t i);
struct v4i sub4ii(struct v4i u, i32_t i);
struct v4i div4ii(struct v4i u, i32_t i);
struct v4i mul4ii(struct v4i u, i32_t i);

void add2ii_r(struct v2i *u, i32_t i);
void sub2ii_r(struct v2i *u, i32_t i);
void div2ii_r(struct v2i *u, i32_t i);
void mul2ii_r(struct v2i *u, i32_t i);

void add3ii_r(struct v3i *u, i32_t i);
void sub3ii_r(struct v3i *u, i32_t i);
void div3ii_r(struct v3i *u, i32_t i);
void mul3ii_r(struct v3i *u, i32_t i);

void add4ii_r(struct v4i *u, i32_t i);
void sub4ii_r(struct v4i *u, i32_t i);
void div4ii_r(struct v4i *u, i32_t i);
void mul4ii_r(struct v4i *u, i32_t i);
#endif /* _GVML_VECTOR_H_  */
