     {
       sprintf(errmsg,
               _("%s: Interrupt/Exception caught (code = 0x%lx, addr = 0x%lx)\n"),
-              prg, exrec->ExceptionCode, exrec->ExceptionAddress);
+              prg, exrec->ExceptionCode, (DWORD)exrec->ExceptionAddress);
       fprintf(stderr, errmsg);
       exit(255);
     }
