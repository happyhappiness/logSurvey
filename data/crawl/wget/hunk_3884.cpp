   # On the NeXT, cc -E runs the code through the compiler's parser,
   # not just through cpp.
   cat > conftest.$ac_ext <<EOF
-#line 1002 "configure"
+#line 1011 "configure"
 #include "confdefs.h"
 #include <assert.h>
 Syntax Error
 EOF
 ac_try="$ac_cpp conftest.$ac_ext >/dev/null 2>conftest.out"
-{ (eval echo configure:1008: \"$ac_try\") 1>&5; (eval $ac_try) 2>&5; }
+{ (eval echo configure:1017: \"$ac_try\") 1>&5; (eval $ac_try) 2>&5; }
 ac_err=`grep -v '^ *+' conftest.out | grep -v "^conftest.${ac_ext}\$"`
 if test -z "$ac_err"; then
   :
