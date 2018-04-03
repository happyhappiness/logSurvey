	va_list args;

	va_start(args, format);
	fprintf(stderr, "ntlm-auth[%ld]: ", (long)getpid());
	vfprintf(stderr, format, args);
	va_end(args);
#if FAIL_DEBUG