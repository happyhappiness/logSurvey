AC_DEFINE(LIBRESOLV_DNS_TTL_HACK,1,[If libresolv.a has been hacked to export _dns_ttl_])],
AC_MSG_RESULT(no))

if test "$ac_cv_header_sys_statvfs_h" = "yes" ; then
AC_MSG_CHECKING(for working statvfs() interface)
AC_TRY_COMPILE([
