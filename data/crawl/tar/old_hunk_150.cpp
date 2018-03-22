    }
}

/* Decode MODE from its binary form in a stat structure, and encode it
   into a 9-byte string STRING, terminated with a NUL.  */

void
decode_mode (mode_t mode, char *string)
{
  *string++ = mode & S_IRUSR ? 'r' : '-';
  *string++ = mode & S_IWUSR ? 'w' : '-';
  *string++ = (mode & S_ISUID
	       ? (mode & S_IXUSR ? 's' : 'S')
	       : (mode & S_IXUSR ? 'x' : '-'));
  *string++ = mode & S_IRGRP ? 'r' : '-';
  *string++ = mode & S_IWGRP ? 'w' : '-';
  *string++ = (mode & S_ISGID
	       ? (mode & S_IXGRP ? 's' : 'S')
	       : (mode & S_IXGRP ? 'x' : '-'));
  *string++ = mode & S_IROTH ? 'r' : '-';
  *string++ = mode & S_IWOTH ? 'w' : '-';
  *string++ = (mode & S_ISVTX
	       ? (mode & S_IXOTH ? 't' : 'T')
	       : (mode & S_IXOTH ? 'x' : '-'));
  *string = '\0';
}

/* Report an error associated with the system call CALL and the
   optional name NAME.  */
static void
call_arg_error (char const *call, char const *name)
{
  int e = errno;
  /* TRANSLATORS: %s after `Cannot' is a function name, e.g. `Cannot open'.
     Directly translating this to another language will not work, first because
     %s itself is not translated.
     Translate it as `%s: Function %s failed'. */
  ERROR ((0, e, _("%s: Cannot %s"), quotearg_colon (name), call));
}

/* Report a fatal error associated with the system call CALL and
   the optional file name NAME.  */
static void
call_arg_fatal (char const *call, char const *name)
{
  int e = errno;
  /* TRANSLATORS: %s after `Cannot' is a function name, e.g. `Cannot open'.
     Directly translating this to another language will not work, first because
     %s itself is not translated.
     Translate it as `%s: Function %s failed'. */
  FATAL_ERROR ((0, e, _("%s: Cannot %s"), quotearg_colon (name),  call));
}

/* Report a warning associated with the system call CALL and
   the optional file name NAME.  */
static void
call_arg_warn (char const *call, char const *name)
{
  int e = errno;
  /* TRANSLATORS: %s after `Cannot' is a function name, e.g. `Cannot open'.
     Directly translating this to another language will not work, first because
     %s itself is not translated.
     Translate it as `%s: Function %s failed'. */
  WARN ((0, e, _("%s: Warning: Cannot %s"), quotearg_colon (name), call));
}

void
chdir_fatal (char const *name)
{
  call_arg_fatal ("chdir", name);
}

void
chmod_error_details (char const *name, mode_t mode)
{
  int e = errno;
  char buf[10];
  decode_mode (mode, buf);
  ERROR ((0, e, _("%s: Cannot change mode to %s"),
	  quotearg_colon (name), buf));
}

void
chown_error_details (char const *name, uid_t uid, gid_t gid)
{
  int e = errno;
  ERROR ((0, e, _("%s: Cannot change ownership to uid %lu, gid %lu"),
	  quotearg_colon (name), (unsigned long) uid, (unsigned long) gid));
}

void
close_error (char const *name)
{
  call_arg_error ("close", name);
}

void
close_warn (char const *name)
{
  call_arg_warn ("close", name);
}

void
close_diag (char const *name)
{
