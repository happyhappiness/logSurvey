   # On the NeXT, cc -E runs the code through the compiler's parser,
   # not just through cpp.
   cat > conftest.$ac_ext <<EOF
-#line 763 "configure"
+#line 819 "configure"
 #include "confdefs.h"
 #include <assert.h>
 Syntax Error
 EOF
 ac_try="$ac_cpp conftest.$ac_ext >/dev/null 2>conftest.out"
-{ (eval echo configure:769: \"$ac_try\") 1>&5; (eval $ac_try) 2>&5; }
+{ (eval echo configure:825: \"$ac_try\") 1>&5; (eval $ac_try) 2>&5; }
 ac_err=`grep -v '^ *+' conftest.out`
 if test -z "$ac_err"; then
   :
 else
   echo "$ac_err" >&5
+  echo "configure: failed program was:" >&5
+  cat conftest.$ac_ext >&5
   rm -rf conftest*
   CPP="${CC-cc} -E -traditional-cpp"
   cat > conftest.$ac_ext <<EOF
-#line 778 "configure"
+#line 836 "configure"
 #include "confdefs.h"
 #include <assert.h>
 Syntax Error
 EOF
 ac_try="$ac_cpp conftest.$ac_ext >/dev/null 2>conftest.out"
-{ (eval echo configure:784: \"$ac_try\") 1>&5; (eval $ac_try) 2>&5; }
+{ (eval echo configure:842: \"$ac_try\") 1>&5; (eval $ac_try) 2>&5; }
 ac_err=`grep -v '^ *+' conftest.out`
 if test -z "$ac_err"; then
   :
 else
   echo "$ac_err" >&5
+  echo "configure: failed program was:" >&5
+  cat conftest.$ac_ext >&5
   rm -rf conftest*
   CPP=/lib/cpp
 fi
