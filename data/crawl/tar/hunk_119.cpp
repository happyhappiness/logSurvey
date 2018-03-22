   return stat_info->is_dumpdir;
 }
 
+static bool
+dumpdir_ok (char *dumpdir)
+{
+  char *p;
+  int has_tempdir = 0;
+  int expect = 0;
+  
+  for (p = dumpdir; *p; p += strlen (p) + 1)
+    {
+      if (expect && *p != expect)
+	{
+	  ERROR ((0, 0,
+		  _("Malformed dumpdir: expected '%c' but found %#3o"),
+		  expect, *p));
+	  return false;
+	}
+      switch (*p)
+	{
+	case 'X':
+	  if (has_tempdir)
+	    {
+	      ERROR ((0, 0,
+		      _("Malformed dumpdir: 'X' duplicated")));
+	      return false;
+	    }
+	  else
+	    has_tempdir = 1;
+	  break;
+	  
+	case 'R':
+	  if (p[1] == 0)
+	    {
+	      if (!has_tempdir)
+		{
+		  ERROR ((0, 0,
+			  _("Malformed dumpdir: empty name in 'R'")));
+		  return false;
+		}
+	      else
+		has_tempdir = 0;
+	    }
+	  expect = 'T';
+	  break;
+	    
+	case 'T':
+	  if (expect != 'T')
+	    {
+	      ERROR ((0, 0,
+		      _("Malformed dumpdir: 'T' not preceeded by 'R'")));
+	      return false;
+	    }  
+	  if (p[1] == 0 && !has_tempdir)
+	    {
+	      ERROR ((0, 0,
+		      _("Malformed dumpdir: empty name in 'T'")));
+	      return false;
+	    }
+	  expect = 0;
+	  break;
+	  
+	case 'N':
+	case 'Y':
+	case 'D':
+	  break;
+
+	default:
+	  /* FIXME: bail out? */
+	  break;
+	}
+    }
+
+  if (expect)
+    {
+      ERROR ((0, 0,
+	      _("Malformed dumpdir: expected '%c' but found end of data"),
+	      expect));
+      return false;
+    }
+
+  if (has_tempdir)
+    WARN ((0, 0, _("Malformed dumpdir: 'X' never used")));
+
+  return true;
+}
+      
 /* Examine the directories under directory_name and delete any
    files that were not there at the time of the back-up. */
-void
-purge_directory (char const *directory_name)
+static bool
+try_purge_directory (char const *directory_name)
 {
   char *current_dir;
   char *cur, *arc, *p;
-
+  char *temp_stub = NULL;
+  
   if (!is_dumpdir (&current_stat_info))
-    {
-      skip_member ();
-      return;
-    }
+    return false;
 
   current_dir = savedir (directory_name);
 
   if (!current_dir)
-    {
-      /* The directory doesn't exist now.  It'll be created.  In any
-	 case, we don't have to delete any files out of it.  */
-
-      skip_member ();
-      return;
-    }
-
+    /* The directory doesn't exist now.  It'll be created.  In any
+       case, we don't have to delete any files out of it.  */
+    return false;
+
+  /* Verify if dump directory is sane */
+  if (!dumpdir_ok (current_stat_info.dumpdir))
+    return false;
+	
   /* Process renames */
   for (arc = current_stat_info.dumpdir; *arc; arc += strlen (arc) + 1)
     {
-      if (*arc == 'R')
+      if (*arc == 'X')
+	{
+#define TEMP_DIR_TEMPLATE "tar.XXXXXX"	  
+	  size_t len = strlen (arc + 1);
+	  temp_stub = xrealloc (temp_stub, len + 1 + sizeof TEMP_DIR_TEMPLATE);
+	  memcpy (temp_stub, arc + 1, len);
+	  temp_stub[len] = '/';
+	  memcpy (temp_stub + len + 1, TEMP_DIR_TEMPLATE,
+		  sizeof TEMP_DIR_TEMPLATE);
+	  if (!mkdtemp (temp_stub))
+	    {
+	      ERROR ((0, errno,
+		      _("Cannot create temporary directory using template %s"),
+		      quote (temp_stub)));
+	      free (temp_stub);
+	      free (current_dir);
+	      return false;
+	    }
+	}
+      else if (*arc == 'R')
 	{
 	  char *src, *dst;
 	  src = arc + 1;
 	  arc += strlen (arc) + 1;
 	  dst = arc + 1;
 
+	  if (*src == 0)
+	    src = temp_stub;
+	  else if (*dst == 0)
+	    dst = temp_stub;
+	    
 	  if (!rename_directory (src, dst))
 	    {
+	      free (temp_stub);
 	      free (current_dir);
 	      /* FIXME: Make sure purge_directory(dst) will return
 		 immediately */
-	      return;
+	      return false;
 	    }
 	}
     }
+
+  free (temp_stub);
   
   /* Process deletes */
   p = NULL;
