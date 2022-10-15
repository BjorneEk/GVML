/*==========================================================*
 *
 * @author Gustaf Franzén :: https://github.com/BjorneEk;
 *
 * GVML vector functions
 *
 *==========================================================*/

#include "../vector.h"
#include <UL/macro.h>
#include <UL/str.h>
#include <string.h>
#include <stdio.h>
#include <math.h>


ALWAYS_INLINE PURE struct v2f v3fv2f(struct v3f v)
{
        return V2F(v.x, v.y);
}
ALWAYS_INLINE PURE struct v2f v4fv2f(struct v4f v)
{
        return V2F(v.x, v.y);
}
ALWAYS_INLINE PURE struct v3f v2fv3f(struct v2f v)
{
        return V3F(v.x, v.y, 1.0);
}
ALWAYS_INLINE PURE struct v3f v4fv3f(struct v4f v)
{
        return V3F(v.x, v.y, v.z);
}
ALWAYS_INLINE PURE struct v4f v2fv4f(struct v2f v)
{
        return V4F(v.x, v.y, 1.0, 1.0);
}
ALWAYS_INLINE PURE struct v4f v3fv4f(struct v3f v)
{
        return V4F(v.x, v.y, v.z, 1.0);
}

ALWAYS_INLINE PURE f32_t dot2f(struct v2f u, struct v2f v)
{
        return  u.x * v.x + u.y * v.y;
}

ALWAYS_INLINE PURE f32_t dot3f(struct v3f u, struct v3f v)
{
        return  u.x * v.x + u.y * v.y + u.z * v.z;
}

ALWAYS_INLINE PURE f32_t dot4f(struct v4f u, struct v4f v)
{
        return  u.x * v.x + u.y * v.y + u.z * v.z + u.w * v.w;
}

ALWAYS_INLINE PURE struct v3f cross3f(struct v3f u, struct v3f v)
{
        return V3F(
        (u).y * (u).z - (u).z * (u).y,
        (u).z * (u).x - (u).x * (u).z,
        (u).x * (u).y - (u).y * (u).x);
}
ALWAYS_INLINE PURE struct v4f cross4f(struct v4f u, struct v4f v)
{
        return v3fv4f(cross3f(v4fv3f(u), v4fv3f(v)));
}
ALWAYS_INLINE PURE f32_t len2f(struct v2f v)
{
        return sqrtf(fabsf(dot2f(v,v)));
}
ALWAYS_INLINE PURE f32_t len3f(struct v3f v)
{
        return sqrtf(fabsf(dot3f(v,v)));
}
ALWAYS_INLINE PURE f32_t len4f(struct v4f v)
{
        return sqrtf(fabsf(dot4f(v,v)));
}

ALWAYS_INLINE PURE bool equals2f(struct v2f u, struct v2f v)
{
        return (u.x == v.x) && (u.y == v.y);
}
ALWAYS_INLINE PURE bool equals3f(struct v3f u, struct v3f v)
{
        return (u.x == v.x) && (u.y == v.y) && (u .z == v .z);
}
ALWAYS_INLINE PURE bool equals4f(struct v4f u, struct v4f v)
{
        return (u.x == v.x) && (u.y == v.y) && (u .z == v .z) && (u .w == v .w);
}

ALWAYS_INLINE void normalizef2(struct v2f *v)
{
        f32_t l;
        l = len2f(*v);
        v->x /= l, v->y /= l;
}
ALWAYS_INLINE void normalizef3(struct v3f *v)
{
        f32_t l;
        l = len3f(*v);
        v->x /= l, v->y /= l, v->z /= l;
}
ALWAYS_INLINE void normalizef4(struct v4f *v)
{
        f32_t l;
        l = len4f(*v);
        v->x /= l, v->y /= l, v->z /= l, v->w /= l;
}

ALWAYS_INLINE PURE struct v2f normalizedf2(struct v2f v)
{
        f32_t l;
        l = len2f(v);
        return V2F(v.x / l, v.y / l);
}
ALWAYS_INLINE PURE struct v3f normalizedf3(struct v3f v)
{
        f32_t l;
        l = len3f(v);
        return V3F(v.x / l, v.y / l, v.z / l);
}
ALWAYS_INLINE PURE struct v4f normalizedf4(struct v4f v)
{
        f32_t l;
        l = len4f(v);
        return V4F(v.x / l, v.y / l, v.z / l, v.w / l);
}

struct v3f normal3f(struct v3f u, struct v3f v, struct v3f w)
{
        return normalizedf3(cross3f(sub3f(u, v), sub3f(u, w)));
}
struct v4f normal4f(struct v4f u, struct v4f v, struct v4f w)
{
        return v3fv4f(normalizedf3(cross3f(v4fv3f(sub4f(u, v)), v4fv3f(sub4f(u, w)))));
}


void str2f(char *dst, struct v2f v)
{
        f64_t drep[] = {v.x, v.y};
        char * res;

        res = farrtos(drep, 2);

        dst = "v2f(";
        strcpy(dst+4, res);
        strcat(dst, ")");
}
void str3f(char *dst, struct v3f v)
{
        f64_t drep[] = {v.x, v.y, v.z};
        char * res;

        res = farrtos(drep, 3);

        dst = "v3f(";
        strcpy(dst+4, res);
        strcat(dst, ")");
}
void str4f(char *dst, struct v4f v)
{
        f64_t drep[] = {v.x, v.y, v.z, v.w};
        char * res;

        res = farrtos(drep, 4);

        dst = "v4f(";
        strcpy(dst+4, res);
        strcat(dst, ")");
}

void print2f(struct v2f v)
{
        char str[100];
        str2f(str, v);
        printf("%s\n", str);
}
void print3f(struct v3f v)
{
        char str[100];
        str3f(str, v);
        printf("%s\n", str);
}
void print4f(struct v4f v)
{
        char str[100];
        str4f(str, v);
        printf("%s\n", str);
}
