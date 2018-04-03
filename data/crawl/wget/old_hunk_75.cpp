       */
      if (i == opt.backups)
        {
          sprintf (to, "%s%s%d%s", fname, SEP, i, AVS);
          delete (to);
        }
#endif
      sprintf (to, "%s%s%d", fname, SEP, i);
      sprintf (from, "%s%s%d", fname, SEP, i - 1);
      rename (from, to);
    }

  sprintf (to, "%s%s%d", fname, SEP, 1);
  rename(fname, to);
}

static bool no_proxy_match (const char *, const char **);
