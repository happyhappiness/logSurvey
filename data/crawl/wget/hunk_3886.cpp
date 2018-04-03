   rm -rf conftest*
   CPP="${CC-cc} -nologo -E"
   cat > conftest.$ac_ext <<EOF
-#line 1036 "configure"
+#line 1045 "configure"
 #include "confdefs.h"
 #include <assert.h>
 Syntax Error
 EOF
 ac_try="$ac_cpp conftest.$ac_ext >/dev/null 2>conftest.out"
-{ (eval echo configure:1042: \"$ac_try\") 1>&5; (eval $ac_try) 2>&5; }
+{ (eval echo configure:1051: \"$ac_try\") 1>&5; (eval $ac_try) 2>&5; }
 ac_err=`grep -v '^ *+' conftest.out | grep -v "^conftest.${ac_ext}\$"`
 if test -z "$ac_err"; then
   :
