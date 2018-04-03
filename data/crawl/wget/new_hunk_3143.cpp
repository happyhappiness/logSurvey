int frontcmp PARAMS ((const char *, const char *));
void fork_to_background PARAMS ((void));

#ifdef HAVE_STDARG_H
char *aprintf PARAMS ((const char *, ...))
     GCC_FORMAT_ATTR (1, 2);
#else  /* not HAVE_STDARG_H */
char *aprintf ();
#endif /* not HAVE_STDARG_H */

void touch PARAMS ((const char *, time_t));
int remove_link PARAMS ((const char *));
int file_exists_p PARAMS ((const char *));
