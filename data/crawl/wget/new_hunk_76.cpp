             name exists, we just remove it and create the directory
             anyway.  */
          DEBUGP (("Removing %s because of directory danger!\n", t));
          if (unlink (t))
            logprintf (LOG_NOTQUIET, "Failed to unlink %s (%d): %s\n",
                       t, errno, strerror(errno));
        }
    }
  res = make_directory (t);
