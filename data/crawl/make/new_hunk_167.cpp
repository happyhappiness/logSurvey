        }
      if (hErr == INVALID_HANDLE_VALUE)
        {
          ON (error, NILF,
              _("windows32_openpipe: DuplicateHandle(Err) failed (e=%ld)\n"), e);
          return -1;
        }
    }

  if (! CreatePipe (&hChildOutRd, &hChildOutWr, &saAttr, 0))
    {
      ON (error, NILF, _("CreatePipe() failed (e=%ld)\n"), GetLastError());
      return -1;
    }

