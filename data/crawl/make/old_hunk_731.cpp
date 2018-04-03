  if (! ISDB (DB_VERBOSE))
    {
      sprintf(errmsg,
              _("%s: Interrupt/Exception caught (code = 0x%x, addr = 0x%x)\n"),
              prg, exrec->ExceptionCode, exrec->ExceptionAddress);
      fprintf(stderr, errmsg);
      exit(255);
    }

  sprintf(errmsg,
          _("\nUnhandled exception filter called from program %s\nExceptionCode = %x\nExceptionFlags = %x\nExceptionAddress = %x\n"),
          prg, exrec->ExceptionCode, exrec->ExceptionFlags,
          exrec->ExceptionAddress);

