int
w32_kill(int pid, int sig)
{
  return ((process_kill((HANDLE)pid, sig) == TRUE) ? 0 : -1);
}

/* This function creates a temporary file name with the given extension
 * the unixy param controls both the extension and the path separator
 * return an xmalloc'ed string of a newly created temp file or die.  */
static char *
create_batch_filename(char const *base, int unixy)
{
  const char *const ext = unixy ? "sh" : "bat";
  const char *error = NULL;
  char temp_path[MAXPATHLEN]; /* need to know its length */
  unsigned path_size = GetTempPath(sizeof temp_path, temp_path);
  int path_is_dot = 0;
  unsigned uniq = 1;
  const unsigned sizemax = strlen (base) + strlen (ext) + 10;

  if (path_size == 0)
    {
      path_size = GetCurrentDirectory (sizeof temp_path, temp_path);
      path_is_dot = 1;
    }

  while (path_size > 0 &&
         path_size + sizemax < sizeof temp_path &&
         uniq < 0x10000)
    {
      unsigned size = sprintf (temp_path + path_size,
                               "%s%s-%x.%s",
                               temp_path[path_size - 1] == '\\' ? "" : "\\",
                               base, uniq, ext);
      HANDLE h = CreateFile (temp_path,  /* file name */
                             GENERIC_READ | GENERIC_WRITE, /* desired access */
                             0,                            /* no share mode */
                             NULL,                         /* default security attributes */
                             CREATE_NEW,                   /* creation disposition */
                             FILE_ATTRIBUTE_NORMAL |       /* flags and attributes */
                             FILE_ATTRIBUTE_TEMPORARY,     /* we'll delete it */
                             NULL);                        /* no template file */

      if (h == INVALID_HANDLE_VALUE)
        {
          const DWORD er = GetLastError();

          if (er == ERROR_FILE_EXISTS || er == ERROR_ALREADY_EXISTS)
            ++uniq;

          /* the temporary path is not guaranteed to exist */
          else if (path_is_dot == 0)
            {
              path_size = GetCurrentDirectory (sizeof temp_path, temp_path);
              path_is_dot = 1;
            }

          else
            {
              error = map_windows32_error_to_string (er);
              break;
            }
        }
      else
        {
          const unsigned final_size = path_size + size + 1;
          char *const path = (char *) xmalloc (final_size);
          memcpy (path, temp_path, final_size);
          CloseHandle (h);
          if (unixy)
            {
              char *p;
              int ch;
              for (p = path; (ch = *p) != 0; ++p)
                if (ch == '\\')
                  *p = '/';
            }
          return path; /* good return */
        }
    }

  if (error == NULL)
    error = _("Cannot create a temporary file\n");
  fatal (NILF, error);

  /* not reached */
  return NULL;
}
#endif /* WINDOWS32 */

