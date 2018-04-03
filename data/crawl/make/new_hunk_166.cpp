        }
      if (hIn == INVALID_HANDLE_VALUE)
        {
          ON (error, NILF,
              _("windows32_openpipe: DuplicateHandle(In) failed (e=%ld)\n"), e);
          return -1;
        }
    }
