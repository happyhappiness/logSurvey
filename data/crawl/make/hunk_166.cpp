         }
       if (hIn == INVALID_HANDLE_VALUE)
         {
-          error (NILF, _("windows32_openpipe: DuplicateHandle(In) failed (e=%ld)\n"), e);
+          ON (error, NILF,
+              _("windows32_openpipe: DuplicateHandle(In) failed (e=%ld)\n"), e);
           return -1;
         }
     }
