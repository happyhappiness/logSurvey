    case ENFILE:
#endif
    case ENOMEM:
      {
        const char *err = strerror (makefile_errno);
        OS (fatal, reading_file, "%s", err);
      }
    }

  /* If the makefile wasn't found and it's either a makefile from
