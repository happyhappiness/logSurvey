    fflush (f))
#endif

#if @GNULIB_GETDELIM@
# if !@HAVE_DECL_GETDELIM@
/* Read input, up to (and including) the next occurrence of DELIMITER, from
