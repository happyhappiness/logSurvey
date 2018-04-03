  rm -rf conftest*
  CPP="${CC-cc} -E -traditional-cpp"
  cat > conftest.$ac_ext <<EOF
#line 727 "configure"
#include "confdefs.h"
#include <assert.h>
Syntax Error
EOF
eval "$ac_cpp conftest.$ac_ext >/dev/null 2>conftest.out"
ac_err=`grep -v '^ *+' conftest.out`
if test -z "$ac_err"; then
  :
