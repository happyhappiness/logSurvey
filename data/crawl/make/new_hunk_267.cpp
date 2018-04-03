          if (adjusted_now < adjusted_mtime)
            {
#ifdef NO_FLOAT
              OS (error, NILF,
                  _("Warning: File '%s' has modification time in the future"),
                  file->name);
#else
              double from_now =
                (FILE_TIMESTAMP_S (mtime) - FILE_TIMESTAMP_S (now)
