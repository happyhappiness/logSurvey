 	{
 	  DBF (DB_VERBOSE,
                _("Recently tried and failed to update file `%s'.\n"));
+
+          /* If the file we tried to make is marked dontcare then no message
+             was printed about it when it failed during the makefile rebuild.
+             If we're trying to build it again in the normal rebuild, print a
+             message now.  */
+          if (file->dontcare && !rebuilding_makefiles)
+            {
+              file->dontcare = 0;
+              complain (file);
+            }
+
 	  return file->update_status;
 	}
 
