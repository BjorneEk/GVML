
////////////////////////////////////////////////////////////////////////////
///        @author Gustaf Franzén :: https://github.com/BjorneEk;        ///
////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "../../vector.h"
int main(int argc, char const *argv[]) {
        struct v2f v1 = V2F(1.0, 2.0);
        struct v2f v2 = V2F(1.0, 2.0);
        printf("dot: %f\n", dot2f(v2, v2));
        return 0;
}
