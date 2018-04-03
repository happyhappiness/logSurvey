                (FILE_TIMESTAMP_S (mtime) - FILE_TIMESTAMP_S (now)
                 + ((FILE_TIMESTAMP_NS (mtime) - FILE_TIMESTAMP_NS (now))
                    / 1e9));
              error (NILF, _("Warning: File `%s' has modification time %.2g s in the future"),
                     file->name, from_now);
#endif
              clock_skew_detected = 1;
            }
