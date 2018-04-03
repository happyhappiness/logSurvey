   rm -rf conftest*
   CPP="${CC-cc} -E -traditional-cpp"
   cat > conftest.$ac_ext <<EOF
-#line 727 "configure"
+#line 778 "configure"
 #include "confdefs.h"
 #include <assert.h>
 Syntax Error
 EOF
-eval "$ac_cpp conftest.$ac_ext >/dev/null 2>conftest.out"
+ac_try="$ac_cpp conftest.$ac_ext >/dev/null 2>conftest.out"
+{ (eval echo configure:784: \"$ac_try\") 1>&5; (eval $ac_try) 2>&5; }
 ac_err=`grep -v '^ *+' conftest.out`
 if test -z "$ac_err"; then
   :
