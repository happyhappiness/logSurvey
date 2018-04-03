       return 0;
     }
 
-  DEBUGPR (_("Must remake target `%s'.\n"));
+  DBF (DB_BASIC, _("Must remake target `%s'.\n"));
 
   /* It needs to be remade.  If it's VPATH and not reset via GPATH, toss the
      VPATH.  */
   if (!streq(file->name, file->hname))
     {
-      if (debug_flag)
-        {
-          print_spaces (depth);
-          printf(_("  Ignoring VPATH name `%s'.\n"), file->hname);
-          fflush(stdout);
-        }
+      DB (DB_BASIC, (_("  Ignoring VPATH name `%s'.\n"), file->hname));
       file->ignore_vpath = 1;
     }
 
