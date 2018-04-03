  # On the NeXT, cc -E runs the code through the compiler's parser,
  # not just through cpp.
  cat > conftest.$ac_ext <<EOF
#line 713 "configure"
#include "confdefs.h"
#include <assert.h>
Syntax Error
EOF
eval "$ac_cpp conftest.$ac_ext >/dev/null 2>conftest.out"
ac_err=`grep -v '^ *+' conftest.out`
if test -z "$ac_err"; then
  :
