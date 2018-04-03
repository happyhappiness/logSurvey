    case ENFILE:
#endif
    case ENOMEM:
      fatal (reading_file, "%s", strerror (makefile_errno));
    }

  /* If the makefile wasn't found and it's either a makefile from
