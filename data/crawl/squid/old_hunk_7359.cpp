


echo $ac_n "checking Maximum number of filedescriptors we can open""... $ac_c" 1>&6
echo "configure:2935: checking Maximum number of filedescriptors we can open" >&5
if test "$cross_compiling" = yes; then
  SQUID_MAXFD=256
else
  cat > conftest.$ac_ext <<EOF
#line 2940 "configure"
#include "confdefs.h"

#include <stdio.h>
