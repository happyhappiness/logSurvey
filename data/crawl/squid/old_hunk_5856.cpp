
fi

echo $ac_n "checking size of int""... $ac_c" 1>&6
echo "configure:3283: checking size of int" >&5
if eval "test \"`echo '$''{'ac_cv_sizeof_int'+set}'`\" = set"; then
  echo $ac_n "(cached) $ac_c" 1>&6
else
  if test "$cross_compiling" = yes; then
    { echo "configure: error: can not run test program while cross compiling" 1>&2; exit 1; }
else
  cat > conftest.$ac_ext <<EOF
#line 3291 "configure"
#include "confdefs.h"
#include <stdio.h>
main()
