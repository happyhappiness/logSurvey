     va_list ap;
 
     if (edui_conf.program[0] == '\0')
-        strcpy(prog, EDUI_PROGRAM_NAME);
+        xstrncpy(prog, EDUI_PROGRAM_NAME, sizeof(prog));
     else
-        strncpy(prog, edui_conf.program, sizeof(prog));
+        xstrncpy(prog, edui_conf.program, sizeof(prog));
 
     if ((msg == NULL) || (strlen(prog) > 256)) {
         /* FAIL */
+/*
         snprintf(dbuf, sizeof(dbuf), "%s: local_printfx() EPIC FAILURE.\n", prog);
         fputs(dbuf, stderr);
+*/
+        debug("local_printfx() EPIC FAIL.\n");
         return;
     }
     sz = sizeof(dbuf);
