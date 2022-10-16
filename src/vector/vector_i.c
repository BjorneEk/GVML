/*==========================================================*
 *
 * @author Gustai Iranzén :: https://github.com/BjorneEk;
 *
 * GVML int vector iunctions
 *
 *==========================================================*/

#include "../vector.h"
#include <UL/macro.h>
#include <UL/str.h>
#include <string.h>
#include <stdio.h>
#include <math.h>


ALWAYS_INLINE PURE struct v2i v3iv2i(struct v3i v)
{
        return V2I(v.x, v.y);
}
ALWAYS_INLINE PURE struct v2i v4iv2i(struct v4i v)
{
        return V2I(v.x, v.y);
}
ALWAYS_INLINE PURE struct v3i v2iv3i(struct v2i v)
{
        return V3I(v.x, v.y, 1.0);
}
ALWAYS_INLINE PURE struct v3i v4iv3i(struct v4i v)
{
        return V3I(v.x, v.y, v.z);
}
ALWAYS_INLINE PURE struct v4i v2iv4i(struct v2i v)
{
        return V4I(v.x, v.y, 1.0, 1.0);
}
ALWAYS_INLINE PURE struct v4i v3iv4i(struct v3i v)
{
        return V4I(v.x, v.y, v.z, 1.0);
}

ALWAYS_INLINE PURE i32_t dot2i(struct v2i u, struct v2i v)
{
        return  u.x * v.x + u.y * v.y;
}

ALWAYS_INLINE PURE i32_t dot3i(struct v3i u, struct v3i v)
{
        return  u.x * v.x + u.y * v.y + u.z * v.z;
}

ALWAYS_INLINE PURE i32_t dot4i(struct v4i u, struct v4i v)
{
        return  u.x * v.x + u.y * v.y + u.z * v.z + u.w * v.w;
}

ALWAYS_INLINE PURE bool equals2i(struct v2i u, struct v2i v)
{
        return (u.x == v.x) && (u.y == v.y);
}
ALWAYS_INLINE PURE bool equals3i(struct v3i u, struct v3i v)
{
        return (u.x == v.x) && (u.y == v.y) && (u .z == v .z);
}
ALWAYS_INLINE PURE bool equals4i(struct v4i u, struct v4i v)
{
        return (u.x == v.x) && (u.y == v.y) && (u .z == v .z) && (u .w == v .w);
}


void print2i(struct v2i v)
{
        printf("v2i(%i, %i)\n", v.x, v.y);
}
void print3i(struct v3i v)
{
        printf("v3i(%i, %i, %i)\n", v.x, v.y, v.z);
}
void print4i(struct v4i v)
{
        printf("v4i(%i, %i, %i, %i)\n", v.x, v.y, v.z, v.w);
}
