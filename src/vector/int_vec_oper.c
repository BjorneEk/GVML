/*==========================================================*
 *
 * @author Gustaf Franzén :: https://github.com/BjorneEk;
 *
 * GVML int vector operations defenitions in order for
 * vector.c to be less cluttered
 *
 *==========================================================*/

#include "../vector.h"
#include <UL/macro.h>

ALWAYS_INLINE PURE struct v2i add2i(struct v2i u, struct v2i v)
{
        return V2I(u.x+v.x, u.y+v.y);
}
ALWAYS_INLINE PURE struct v2i sub2i(struct v2i u, struct v2i v)
{
        return V2I(u.x-v.x, u.y-v.y);
}
ALWAYS_INLINE PURE struct v2i div2i(struct v2i u, struct v2i v)
{
        return V2I(u.x/v.x, u.y/v.y);
}
ALWAYS_INLINE PURE struct v2i mul2i(struct v2i u, struct v2i v)
{
        return V2I(u.x*v.x, u.y*v.y);
}

ALWAYS_INLINE PURE struct v3i add3i(struct v3i u, struct v3i v)
{
        return V3I(u.x+v.x, u.y+v.y, u.z+v.z);
}
ALWAYS_INLINE PURE struct v3i sub3i(struct v3i u, struct v3i v)
{
        return V3I(u.x-v.x, u.y-v.y, u.z-v.z);
}
ALWAYS_INLINE PURE struct v3i div3i(struct v3i u, struct v3i v)
{
        return V3I(u.x/v.x, u.y/v.y, u.z/v.z);
}
ALWAYS_INLINE PURE struct v3i mul3i(struct v3i u, struct v3i v)
{
        return V3I(u.x*v.x, u.y*v.y, u.z*v.z);
}

ALWAYS_INLINE PURE struct v4i add4i(struct v4i u, struct v4i v)
{
        return V4I(u.x+v.x, u.y+v.y, u.z+v.z, u.w+v.w);
}
ALWAYS_INLINE PURE struct v4i sub4i(struct v4i u, struct v4i v)
{
        return V4I(u.x-v.x, u.y-v.y, u.z-v.z, u.w-v.w);
}
ALWAYS_INLINE PURE struct v4i div4i(struct v4i u, struct v4i v)
{
        return V4I(u.x/v.x, u.y/v.y, u.z/v.z, u.w/v.w);
}
ALWAYS_INLINE PURE struct v4i mul4i(struct v4i u, struct v4i v)
{
        return V4I(u.x*v.x, u.y*v.y, u.z*v.z, u.w*v.w);
}

void add2i_r(struct v2i *u, struct v2i v)
{
        u->x+=v.x, u->y+=v.y;
}
ALWAYS_INLINE void sub2i_r(struct v2i *u, struct v2i v)
{
        u->x-=v.x, u->y-=v.y;
}

ALWAYS_INLINE void div2i_r(struct v2i *u, struct v2i v)
{
        u->x/=v.x, u->y/=v.y;
}
ALWAYS_INLINE void mul2i_r(struct v2i *u, struct v2i v)
{
        u->x*=v.x, u->y*=v.y;
}

ALWAYS_INLINE void add3i_r(struct v3i *u, struct v3i v)
{
        u->x+=v.x, u->y+=v.y, u->z+=v.z;
}
ALWAYS_INLINE void sub3i_r(struct v3i *u, struct v3i v)
{
        u->x-=v.x, u->y-=v.y, u->z-=v.z;
}
ALWAYS_INLINE void div3i_r(struct v3i *u, struct v3i v)
{
        u->x/=v.x, u->y/=v.y, u->z/=v.z;
}
ALWAYS_INLINE void mul3i_r(struct v3i *u, struct v3i v)
{
        u->x*=v.x, u->y*=v.y, u->z*=v.z;
}

ALWAYS_INLINE void add4i_r(struct v4i *u, struct v4i v)
{
        u->x+=v.x, u->y+=v.y, u->z+=v.z, u->w+=v.w;
}
ALWAYS_INLINE void sub4i_r(struct v4i *u, struct v4i v)
{
        u->x-=v.x, u->y-=v.y, u->z-=v.z, u->w-=v.w;
}
ALWAYS_INLINE void div4i_r(struct v4i *u, struct v4i v)
{
        u->x/=v.x, u->y/=v.y, u->z/=v.z, u->w/=v.w;
}
ALWAYS_INLINE void mul4i_r(struct v4i *u, struct v4i v)
{
        u->x*=v.x, u->y*=v.y, u->z*=v.z, u->w*=v.w;
}


ALWAYS_INLINE PURE struct v2i add2ii(struct v2i u, i32_t i)
{
        return V2I(u.x+i, u.y+i);
}
ALWAYS_INLINE PURE struct v2i sub2ii(struct v2i u, i32_t i)
{
        return V2I(u.x-i, u.y-i);
}
ALWAYS_INLINE PURE struct v2i div2ii(struct v2i u, i32_t i)
{
        return V2I(u.x/i, u.y/i);
}
ALWAYS_INLINE PURE struct v2i mul2ii(struct v2i u, i32_t i)
{
        return V2I(u.x*i, u.y*i);
}

ALWAYS_INLINE PURE struct v3i add3ii(struct v3i u, i32_t i)
{
        return V3I(u.x+i, u.y+i, u.z+i);
}
ALWAYS_INLINE PURE struct v3i sub3ii(struct v3i u, i32_t i)
{
        return V3I(u.x-i, u.y-i, u.z-i);
}
ALWAYS_INLINE PURE struct v3i div3ii(struct v3i u, i32_t i)
{
        return V3I(u.x/i, u.y/i, u.z/i);
}
ALWAYS_INLINE PURE struct v3i mul3ii(struct v3i u, i32_t i)
{
        return V3I(u.x*i, u.y*i, u.z*i);
}

ALWAYS_INLINE PURE struct v4i add4ii(struct v4i u, i32_t i)
{
        return V4I(u.x+i, u.y+i, u.z+i, u.w+i);
}
ALWAYS_INLINE PURE struct v4i sub4ii(struct v4i u, i32_t i)
{
        return V4I(u.x-i, u.y-i, u.z-i, u.w-i);
}
ALWAYS_INLINE PURE struct v4i div4ii(struct v4i u, i32_t i)
{
        return V4I(u.x/i, u.y/i, u.z/i, u.w/i);
}
ALWAYS_INLINE PURE struct v4i mul4ii(struct v4i u, i32_t i)
{
        return V4I(u.x*i, u.y*i, u.z*i, u.w*i);
}


ALWAYS_INLINE void add2ii_r(struct v2i *u, i32_t i)
{
        u->x+=i, u->y+=i;
}
ALWAYS_INLINE void sub2ii_r(struct v2i *u, i32_t i)
{
        u->x-=i, u->y-=i;
}
ALWAYS_INLINE void div2ii_r(struct v2i *u, i32_t i)
{
        u->x/=i, u->y/=i;
}
ALWAYS_INLINE void mul2ii_r(struct v2i *u, i32_t i)
{
        u->x*=i, u->y*=i;
}

ALWAYS_INLINE void add3ii_r(struct v3i *u, i32_t i)
{
        u->x+=i, u->y+=i, u->z+=i;
}
ALWAYS_INLINE void sub3ii_r(struct v3i *u, i32_t i)
{
        u->x-=i, u->y-=i, u->z-=i;
}
ALWAYS_INLINE void div3ii_r(struct v3i *u, i32_t i)
{
        u->x/=i, u->y/=i, u->z/=i;
}
ALWAYS_INLINE void mul3ii_r(struct v3i *u, i32_t i)
{
        u->x*=i, u->y*=i, u->z*=i;
}

ALWAYS_INLINE void add4ii_r(struct v4i *u, i32_t i)
{
        u->x+=i, u->y+=i, u->z+=i, u->w+=i;
}
ALWAYS_INLINE void sub4ii_r(struct v4i *u, i32_t i)
{
        u->x-=i, u->y-=i, u->z-=i, u->w-=i;
}
ALWAYS_INLINE void div4ii_r(struct v4i *u, i32_t i)
{
        u->x/=i, u->y/=i, u->z/=i, u->w/=i;
}
ALWAYS_INLINE void mul4ii_r(struct v4i *u, i32_t i)
{
        u->x*=i, u->y*=i, u->z*=i, u->w*=i;
}
