])

AS_IF([test x"$with_ssl" = xopenssl], [
  dnl As of this writing (OpenSSL 0.9.6), the libcrypto shared library
  dnl doesn't record its dependency on libdl, so we need to make sure
  dnl -ldl ends up in LIBS on systems that have it.  Most OSes use
  dnl dlopen(), but HP-UX uses shl_load().
  AC_CHECK_LIB(dl, dlopen, [], [
    AC_CHECK_LIB(dl, shl_load)
  ])

  ssl_found=no
  case $host_os in
    *mingw32* )
      dnl prefer link to openssl dlls if possible. if not then fallback on static libs. if not then error

      AC_CHECK_LIB(eay32, EVP_MD_CTX_init)
      if test x"$ac_cv_lib_eay32_EVP_MD_CTX_init" != xno
      then
        AC_CHECK_LIB(ssl32, SSL_connect, [
          ssl_found=yes
          AC_MSG_NOTICE([Enabling support for SSL via OpenSSL (shared)])
          AC_LIBOBJ([openssl])
          LIBS="${LIBS} -lssl32"
          AC_DEFINE([HAVE_LIBSSL32], [1], [Define to 1 if you have the `ssl32' library (-lssl32).])
        ],
        AC_MSG_ERROR([openssl not found: shared lib eay32 found but ssl32 not found]))

      else
        LIBS+=' -lgdi32'
        dnl fallback and test static libs
      fi
      dnl add zdll lib as dep for above tests?
    ;;
  esac

  AS_IF([test x$ssl_found != xyes], [
    dnl Now actually check for -lssl if it wasn't already found
    AC_LIB_HAVE_LINKFLAGS([ssl], [crypto], [
#include <openssl/ssl.h>
#include <openssl/x509.h>
#include <openssl/err.h>
