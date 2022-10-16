
////////////////////////////////////////////////////////////////////////////
///        @author Gustaf Franzén :: https://github.com/BjorneEk;        ///
////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "../../vector.h"

extern void test_rot3();
extern void test_dot_m3();
extern void test_rot4();
extern void test_dot_m4();
int main(int argc, char const *argv[]) {
        test_rot3();
        test_rot4();
        test_dot_m3();
        test_dot_m4();
        return 0;
}
