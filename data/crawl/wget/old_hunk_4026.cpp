  rm -rf conftest*
  CPP="${CC-cc} -E -traditional-cpp"
  cat > conftest.$ac_ext <<EOF
#line 960 "configure"
#include "confdefs.h"
#include <assert.h>
Syntax Error
EOF
ac_try="$ac_cpp conftest.$ac_ext >/dev/null 2>conftest.out"
{ (eval echo configure:966: \"$ac_try\") 1>&5; (eval $ac_try) 2>&5; }
ac_err=`grep -v '^ *+' conftest.out`
if test -z "$ac_err"; then
  :
else