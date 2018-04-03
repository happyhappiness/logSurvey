
	* configure.in (AC_FUNC_VPRINTF): Check for vprintf()/_doprnt().

	* misc.c(message, error, fatal): Add preprocessor stuff to enable
	creation of variable-argument functions with appropriate
	prototypes, that works with ANSI, pre-ANSI, varargs.h, stdarg.h,
	v*printf(), _doprnt(), or none of the above.  Culled from GNU
