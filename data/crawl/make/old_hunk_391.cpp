        return NULL;
      }

    symp = dlsym (*dlp, symname);
    if (! symp)
      fatal (flocp, _("Failed to load symbol %s from %s: %s"),
