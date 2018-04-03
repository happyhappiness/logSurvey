    {
      FILE *f = out ? stdout : stderr;
      fputs (msg, f);
      putc ('\n', f);
      fflush (f);
    }
}

