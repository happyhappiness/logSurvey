      switch (err)
        {
        case HOSTERR: case CONIMPOSSIBLE: case FWRITEERR: case FOPENERR:
        case FTPNSFOD: case FTPLOGINC: case FTPNOPASV: case CONTNOTSUPPORTED:
        case UNLINKERR: case WARC_TMP_FWRITEERR:
          /* Fatal errors, give up.  */
          if (warc_tmp != NULL)
              fclose (warc_tmp);
