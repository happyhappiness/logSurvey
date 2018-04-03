static void
child_out (const struct child *child, const char *msg, int out)
{
  int fd = out ? child->outfd : child->errfd;

  if (fd >= 0)
    {
      int len = strlen (msg);

      lseek (fd, 0, SEEK_END);
      while (1)
        {
          int b;
          EINTRLOOP (b, write (fd, msg, len));
          if (b == len)
            break;
          if (b <= 0)
            return;
          len -= b;
          msg += b;
        }
    }
  else
    {
      FILE *f = out ? stdout : stderr;
      fputs (msg, f);
      fflush (f);
    }
}

