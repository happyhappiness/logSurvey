    {
      FILE *f = out ? stdout : stderr;
      fputs (msg, f);
      fflush (f);
      putc ('\n', f);
    }
}

