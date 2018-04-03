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

