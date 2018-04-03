#endif
#endif
          {
            error("*** Warning: File `%s' has modification time in the future (%ld > %ld)",
                  file->name, mtime, now);
            clock_skew_detected = 1;
          }
      }
