         && product <= ts && ts <= ORDINARY_MTIME_MAX))
    {
      char buf[FILE_TIMESTAMP_PRINT_LEN_BOUND + 1];
      const char *f = fname ? fname : _("Current time");
      ts = s <= OLD_MTIME ? ORDINARY_MTIME_MIN : ORDINARY_MTIME_MAX;
      file_timestamp_sprintf (buf, ts);
      OSS (error, NILF,
           _("%s: Timestamp out of range; substituting %s"), f, buf);
    }

  return ts;
