    fflush (f))
#endif

#if @GNULIB_FPURGE@
# if @REPLACE_FPURGE@
#  define fpurge rpl_fpurge
# endif
# if @REPLACE_FPURGE@ || !@HAVE_DECL_FPURGE@
  /* Discard all pending buffered I/O data on STREAM.
     STREAM must not be wide-character oriented.
     Return 0 if successful.  Upon error, return -1 and set errno.  */
  extern int fpurge (FILE *gl_stream);
# endif
#elif defined GNULIB_POSIXCHECK
# undef fpurge
# define fpurge(f) \
   (GL_LINK_WARNING ("fpurge is not always present - " \
                     "use gnulib module fpurge for portability"), \
    fpurge (f))
#endif

#if @GNULIB_FCLOSE@
# if @REPLACE_FCLOSE@
#  define fclose rpl_fclose
  /* Close STREAM and its underlying file descriptor.  */
extern int fclose (FILE *stream);
# endif
#elif defined GNULIB_POSIXCHECK
# undef fclose
# define fclose(f) \
   (GL_LINK_WARNING ("fclose is not always POSIX compliant - " \
                     "use gnulib module fclose for portable " \
                     "POSIX compliance"), \
    fclose (f))
#endif

#if @GNULIB_FPUTC@ && @REPLACE_STDIO_WRITE_FUNCS@ && @GNULIB_STDIO_H_SIGPIPE@
# undef fputc
# define fputc rpl_fputc
extern int fputc (int c, FILE *stream);
#endif

#if @GNULIB_PUTC@ && @REPLACE_STDIO_WRITE_FUNCS@ && @GNULIB_STDIO_H_SIGPIPE@
# undef putc
# define putc rpl_fputc
extern int putc (int c, FILE *stream);
#endif

#if @GNULIB_PUTCHAR@ && @REPLACE_STDIO_WRITE_FUNCS@ && @GNULIB_STDIO_H_SIGPIPE@
# undef putchar
# define putchar rpl_putchar
extern int putchar (int c);
#endif

#if @GNULIB_FPUTS@ && @REPLACE_STDIO_WRITE_FUNCS@ && @GNULIB_STDIO_H_SIGPIPE@
# undef fputs
# define fputs rpl_fputs
extern int fputs (const char *string, FILE *stream);
#endif

#if @GNULIB_PUTS@ && @REPLACE_STDIO_WRITE_FUNCS@ && @GNULIB_STDIO_H_SIGPIPE@
# undef puts
# define puts rpl_puts
extern int puts (const char *string);
#endif

#if @GNULIB_FWRITE@ && @REPLACE_STDIO_WRITE_FUNCS@ && @GNULIB_STDIO_H_SIGPIPE@
# undef fwrite
# define fwrite rpl_fwrite
extern size_t fwrite (const void *ptr, size_t s, size_t n, FILE *stream);
#endif

#if @GNULIB_GETDELIM@
# if !@HAVE_DECL_GETDELIM@
/* Read input, up to (and including) the next occurrence of DELIMITER, from
