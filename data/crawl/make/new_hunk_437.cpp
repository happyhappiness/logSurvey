#include <string.h>
#include <stdio.h>

#include "gnumake.h"

int
testload_gmk_setup ()
{
    gmk_eval ("TESTLOAD = implicit", 0);
    return 1;
}

int
explicit_setup ()
{
    gmk_eval ("TESTLOAD = explicit", 0);
    return 1;
}
EOF
close($F) or die "close: testload.c: $!\n";

# Make sure we can compile
run_make_test('testload.so: testload.c ; @'.$sobuild, '', '');

# TEST 1
run_make_test(q!
PRE := $(.LOADED)
load testload.so
POST := $(.LOADED)
all: ; @echo pre=$(PRE) post=$(POST) $(TESTLOAD)
!,
              '', "pre= post=testload.so implicit\n");

# TEST 2
# Load using an explicit function
run_make_test(q!
PRE := $(.LOADED)
load ./testload.so(explicit_setup)
POST := $(.LOADED)
all: ; @echo pre=$(PRE) post=$(POST) $(TESTLOAD)
!,
              '', "pre= post=testload.so explicit\n");

# TEST 4
# Check multiple loads
run_make_test(q!
PRE := $(.LOADED)
load ./testload.so
load testload.so(explicit_setup)
POST := $(.LOADED)
all: ; @echo pre=$(PRE) post=$(POST) $(TESTLOAD)
!,
              '', "pre= post=testload.so implicit\n");

# TEST 5
# Check auto-rebuild of loaded file that's out of date
