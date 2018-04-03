	strerror \
)

AC_MSG_CHECKING(Maximum number of filedescriptors we can open)
AC_TRY_RUN([
#include <stdio.h>
