#include <sys/ipc.h>
#include <sys/msg.h>])

# check for compiler support of %zu printf macro
AH_TEMPLATE(PRIuSIZE,[Compiler supports %zu printf macro])
AC_MSG_CHECKING([for compiler %zu support])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <stdio.h>
  ]],[[size_t n=1;printf("%zu",n);]])],[
    AC_DEFINE(PRIuSIZE,"zu")
    AC_MSG_RESULT(yes)
  ],[AC_MSG_RESULT(no)],[AC_MSG_RESULT(no)])


dnl Check for special functions
AC_FUNC_ALLOCA

