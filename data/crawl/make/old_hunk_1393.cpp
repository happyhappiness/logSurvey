	extern time_t time ();
	time (&now);
#endif
	if (mtime > now)
          error ("*** Warning: File `%s' has modification time in the future",
                 file->name);
      }
  }

