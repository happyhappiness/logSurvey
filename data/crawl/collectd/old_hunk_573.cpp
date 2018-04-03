	float itemp;
	float battv;
	float linefreq;
>>>>>>> .r733
};

#define BIG_BUF 4096

<<<<<<< .mine

#define BIG_BUF 5000

/* Implement snprintf */
int asnprintf(char *str, size_t size, const char *fmt, ...)
{
#ifdef HAVE_VSNPRINTF
   va_list arg_ptr;
   int len;

   va_start(arg_ptr, fmt);
   len = vsnprintf(str, size, fmt, arg_ptr);
   va_end(arg_ptr);

   str[size - 1] = 0;
   return len;

#else

   va_list arg_ptr;
   int len;
   char *buf;

   buf = (char *)malloc(BIG_BUF);

   va_start(arg_ptr, fmt);
   len = vsprintf(buf, fmt, arg_ptr);
   va_end(arg_ptr);

   if (len >= BIG_BUF){
     syslog(LOG_ERR, "apcups: asnprintf(): Buffer overflow");
     return(0);
   }

   memcpy(str, buf, size);
   str[size - 1] = 0;

   free(buf);
   return len;
#endif
}

/* Implement vsnprintf() */
int avsnprintf(char *str, size_t size, const char *format, va_list ap)
{
#ifdef HAVE_VSNPRINTF
   int len;

   len = vsnprintf(str, size, format, ap);
   str[size - 1] = 0;

   return len;

#else

   int len;
   char *buf;

   buf = (char *)malloc(BIG_BUF);

   len = vsprintf(buf, format, ap);
   if (len >= BIG_BUF){
     syslog(LOG_ERR, "apcups: avsnprintf(): Buffer overflow");
     return(0);
   }

  memcpy(str, buf, size);
   str[size - 1] = 0;

   free(buf);
   return len;
#endif
}

=======
>>>>>>> .r733
/*
<<<<<<< .mine
=======
 * Subroutine normally called by macro error_abort() to print
 * FATAL ERROR message and supplied error message
 */
static void generic_error_out(const char *file, int line, const char *fmt, ...)
{
	char buf[256];
	va_list arg_ptr;
	int i;

	snprintf(buf, sizeof(buf), _("FATAL ERROR in %s at line %d\n"), file, line);
	i = strlen(buf);
	va_start(arg_ptr, fmt);
	vsnprintf((char *)&buf[i], sizeof(buf) - i, (char *)fmt, arg_ptr);
	va_end(arg_ptr);
	fprintf(stdout, "%s", buf);

	exit(1);
}

/*
>>>>>>> .r733
 * Read nbytes from the network.
 * It is possible that the total bytes require in several
 * read requests
