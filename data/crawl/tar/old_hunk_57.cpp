    {
    case XGLTYPE:
      {
        if (!read_header0 (&dummy))
          return false;
        xheader_decode (&dummy); /* decodes values from the global header */
        tar_stat_destroy (&dummy);
        if (!real_s_name)
          {
            /* We have read the extended header of the first member in
               this volume. Put it back, so next read_header works as
               expected. */
            current_block = record_start;
          }
        break;
      }

