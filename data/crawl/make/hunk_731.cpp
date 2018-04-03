   if (! ISDB (DB_VERBOSE))
     {
       sprintf(errmsg,
-              _("%s: Interrupt/Exception caught (code = 0x%x, addr = 0x%x)\n"),
+              _("%s: Interrupt/Exception caught (code = 0x%lx, addr = 0x%lx)\n"),
               prg, exrec->ExceptionCode, exrec->ExceptionAddress);
       fprintf(stderr, errmsg);
       exit(255);
     }
 
   sprintf(errmsg,
-          _("\nUnhandled exception filter called from program %s\nExceptionCode = %x\nExceptionFlags = %x\nExceptionAddress = %x\n"),
+          _("\nUnhandled exception filter called from program %s\nExceptionCode = %lx\nExceptionFlags = %lx\nExceptionAddress = %lx\n"),
           prg, exrec->ExceptionCode, exrec->ExceptionFlags,
           exrec->ExceptionAddress);
 
