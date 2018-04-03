 
     if ((msg == NULL) || (strlen(prog) > 256)) {
         /* FAIL */
-        /*
-                snprintf(dbuf, sizeof(dbuf), "%s: local_printfx() EPIC FAILURE.\n", prog);
-                fputs(dbuf, stderr);
-        */
         debug("local_printfx() EPIC FAIL.\n");
         return;
     }
