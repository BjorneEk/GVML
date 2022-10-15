/*==========================================================*
 *
 * @author Gustaf Franzén :: https://github.com/BjorneEk;
 *
 * GVML float vector operations defenitions in order for
 * vector.c to be less cluttered
 *
 *==========================================================*/

#include "../vector.h"
#include <UL/macro.h>

ALWAYS_INLINE PURE struct v2f add2f(struct v2f u, struct v2f v)
{
        return V2F(u.x+v.x, u.y+v.y);
}
ALWAYS_INLINE PURE struct v2f sub2f(struct v2f u, struct v2f v)
{
        return V2F(u.x-v.x, u.y-v.y);
}
ALWAYS_INLINE PURE struct v2f div2f(struct v2f u, struct v2f v)
{
        return V2F(u.x/v.x, u.y/v.y);
}
ALWAYS_INLINE PURE struct v2f mul2f(struct v2f u, struct v2f v)
{
        return V2F(u.x*v.x, u.y*v.y);
}

ALWAYS_INLINE PURE struct v3f add3f(struct v3f u, struct v3f v)
{
        return V3F(u.x+v.x, u.y+v.y, u.z+v.z);
}
ALWAYS_INLINE PURE struct v3f sub3f(struct v3f u, struct v3f v)
{
        return V3F(u.x-v.x, u.y-v.y, u.z-v.z);
}
ALWAYS_INLINE PURE struct v3f div3f(struct v3f u, struct v3f v)
{
        return V3F(u.x/v.x, u.y/v.y, u.z/v.z);
}
ALWAYS_INLINE PURE struct v3f mul3f(struct v3f u, struct v3f v)
{
        return V3F(u.x*v.x, u.y*v.y, u.z*v.z);
}

ALWAYS_INLINE PURE struct v4f add4f(struct v4f u, struct v4f v)
{
        return V4F(u.x+v.x, u.y+v.y, u.z+v.z, u.w+v.w);
}
ALWAYS_INLINE PURE struct v4f sub4f(struct v4f u, struct v4f v)
{
        return V4F(u.x-v.x, u.y-v.y, u.z-v.z, u.w-v.w);
}
ALWAYS_INLINE PURE struct v4f div4f(struct v4f u, struct v4f v)
{
        return V4F(u.x/v.x, u.y/v.y, u.z/v.z, u.w/v.w);
}
ALWAYS_INLINE PURE struct v4f mul4f(struct v4f u, struct v4f v)
{
        return V4F(u.x*v.x, u.y*v.y, u.z*v.z, u.w*v.w);
}

void add2f_r(struct v2f *u, struct v2f v)
{
        u->x+=v.x, u->y+=v.y;
}
ALWAYS_INLINE void sub2f_r(struct v2f *u, struct v2f v)
{
        u->x-=v.x, u->y-=v.y;
}

ALWAYS_INLINE void div2f_r(struct v2f *u, struct v2f v)
{
        u->x/=v.x, u->y/=v.y;
}
ALWAYS_INLINE void mul2f_r(struct v2f *u, struct v2f v)
{
        u->x*=v.x, u->y*=v.y;
}

ALWAYS_INLINE void add3f_r(struct v3f *u, struct v3f v)
{
        u->x+=v.x, u->y+=v.y, u->z+=v.z;
}
ALWAYS_INLINE void sub3f_r(struct v3f *u, struct v3f v)
{
        u->x-=v.x, u->y-=v.y, u->z-=v.z;
}
ALWAYS_INLINE void div3f_r(struct v3f *u, struct v3f v)
{
        u->x/=v.x, u->y/=v.y, u->z/=v.z;
}
ALWAYS_INLINE void mul3f_r(struct v3f *u, struct v3f v)
{
        u->x*=v.x, u->y*=v.y, u->z*=v.z;
}

ALWAYS_INLINE void add4f_r(struct v4f *u, struct v4f v)
{
        u->x+=v.x, u->y+=v.y, u->z+=v.z, u->w+=v.w;
}
ALWAYS_INLINE void sub4f_r(struct v4f *u, struct v4f v)
{
        u->x-=v.x, u->y-=v.y, u->z-=v.z, u->w-=v.w;
}
ALWAYS_INLINE void div4f_r(struct v4f *u, struct v4f v)
{
        u->x/=v.x, u->y/=v.y, u->z/=v.z, u->w/=v.w;
}
ALWAYS_INLINE void mul4f_r(struct v4f *u, struct v4f v)
{
        u->x*=v.x, u->y*=v.y, u->z*=v.z, u->w*=v.w;
}


ALWAYS_INLINE PURE struct v2f add2ff(struct v2f u, f32_t f)
{
        return V2F(u.x+f, u.y+f);
}
ALWAYS_INLINE PURE struct v2f sub2ff(struct v2f u, f32_t f)
{
        return V2F(u.x-f, u.y-f);
}
ALWAYS_INLINE PURE struct v2f div2ff(struct v2f u, f32_t f)
{
        return V2F(u.x/f, u.y/f);
}
ALWAYS_INLINE PURE struct v2f mul2ff(struct v2f u, f32_t f)
{
        return V2F(u.x*f, u.y*f);
}

ALWAYS_INLINE PURE struct v3f add3ff(struct v3f u, f32_t f)
{
        return V3F(u.x+f, u.y+f, u.z+f);
}
ALWAYS_INLINE PURE struct v3f sub3ff(struct v3f u, f32_t f)
{
        return V3F(u.x-f, u.y-f, u.z-f);
}
ALWAYS_INLINE PURE struct v3f div3ff(struct v3f u, f32_t f)
{
        return V3F(u.x/f, u.y/f, u.z/f);
}
ALWAYS_INLINE PURE struct v3f mul3ff(struct v3f u, f32_t f)
{
        return V3F(u.x*f, u.y*f, u.z*f);
}

ALWAYS_INLINE PURE struct v4f add4ff(struct v4f u, f32_t f)
{
        return V4F(u.x+f, u.y+f, u.z+f, u.w+f);
}
ALWAYS_INLINE PURE struct v4f sub4ff(struct v4f u, f32_t f)
{
        return V4F(u.x-f, u.y-f, u.z-f, u.w-f);
}
ALWAYS_INLINE PURE struct v4f div4ff(struct v4f u, f32_t f)
{
        return V4F(u.x/f, u.y/f, u.z/f, u.w/f);
}
ALWAYS_INLINE PURE struct v4f mul4ff(struct v4f u, f32_t f)
{
        return V4F(u.x*f, u.y*f, u.z*f, u.w*f);
}


ALWAYS_INLINE void add2ff_r(struct v2f *u, f32_t f)
{
        u->x+=f, u->y+=f;
}
ALWAYS_INLINE void sub2ff_r(struct v2f *u, f32_t f)
{
        u->x-=f, u->y-=f;
}
ALWAYS_INLINE void div2ff_r(struct v2f *u, f32_t f)
{
        u->x/=f, u->y/=f;
}
ALWAYS_INLINE void mul2ff_r(struct v2f *u, f32_t f)
{
        u->x*=f, u->y*=f;
}

ALWAYS_INLINE void add3ff_r(struct v3f *u, f32_t f)
{
        u->x+=f, u->y+=f, u->z+=f;
}
ALWAYS_INLINE void sub3ff_r(struct v3f *u, f32_t f)
{
        u->x-=f, u->y-=f, u->z-=f;
}
ALWAYS_INLINE void div3ff_r(struct v3f *u, f32_t f)
{
        u->x/=f, u->y/=f, u->z/=f;
}
ALWAYS_INLINE void mul3ff_r(struct v3f *u, f32_t f)
{
        u->x*=f, u->y*=f, u->z*=f;
}

ALWAYS_INLINE void add4ff_r(struct v4f *u, f32_t f)
{
        u->x+=f, u->y+=f, u->z+=f, u->w+=f;
}
ALWAYS_INLINE void sub4ff_r(struct v4f *u, f32_t f)
{
        u->x-=f, u->y-=f, u->z-=f, u->w-=f;
}
ALWAYS_INLINE void div4ff_r(struct v4f *u, f32_t f)
{
        u->x/=f, u->y/=f, u->z/=f, u->w/=f;
}
ALWAYS_INLINE void mul4ff_r(struct v4f *u, f32_t f)
{
        u->x*=f, u->y*=f, u->z*=f, u->w*=f;
}
