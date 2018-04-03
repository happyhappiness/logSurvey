
/* Note this absorbs a semicolon and is safe to use in conditionals.  */
#define BADARGS(func)  do {                                                   \
    fatal (reading_file, "insufficient arguments to function `%s'", func);    \
  } while (0)

static char *
expand_function (o, function, text, end)
