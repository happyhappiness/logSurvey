      return ftp_parse_unix_ls (file, 0);
    case ST_WINNT:
      {
        /* Detect whether the listing is simulating the UNIX format */
        FILE *fp;
        int   c;
        fp = fopen (file, "rb");
        if (!fp)
        {
          logprintf (LOG_NOTQUIET, "%s: %s\n", file, strerror (errno));
          return NULL;
        }
        c = fgetc(fp);
        fclose(fp);
        /* If the first character of the file is '0'-'9', it's WINNT
           format. */
        if (c >= '0' && c <='9')
          return ftp_parse_winnt_ls (file);
        else
          return ftp_parse_unix_ls (file, 1);
      }
