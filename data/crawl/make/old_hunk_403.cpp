static void
child_out (const struct child *child, const char *msg, int out)
{
  int outfd = out ? child->outfd : child->errfd;

  if (outfd >= 0)
    {
      int t = strlen (msg);
      int l;
      lseek (outfd, 0, SEEK_END);
      while (t)
        {
          EINTRLOOP (l, write (outfd, msg, t));
          if (l == t)
            break;
          if (l < 0)
            {
              perror ("write()");
              break;
            }
          t -= l;
          msg += l;
        }
    }
  else
    {
      FILE *outf = out ? stdout : stderr;
      fputs (msg, outf);
      fflush (outf);
    }
}

