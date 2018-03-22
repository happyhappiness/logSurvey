 	}
       if (*arc == '\0')
 	{
-	  p = new_name (CURRENT_FILE_NAME, cur);
-	  if (interactive_option && !confirm ("delete", p))
+	  char *p = new_name (directory_name, cur);
+	  if (! interactive_option || confirm ("delete", p))
 	    {
-	      free (p);
-	      continue;
+	      if (verbose_option)
+		fprintf (stdlis, _("%s: Deleting %s\n"),
+			 program_name, quote (p));
+	      if (! remove_any_file (p, 1))
+		{
+		  int e = errno;
+		  ERROR ((0, e, _("%s: Cannot remove"), quotearg_colon (p)));
+		}
 	    }
-	  if (verbose_option)
-	    fprintf (stdlis, _("%s: Deleting %s\n"), program_name, p);
-	  if (!remove_any_file (p, 1))
-	    ERROR ((0, errno, _("Error while deleting %s"), p));
 	  free (p);
 	}
 
     }
-  delete_accumulator (accumulator);
+  free (current_dir);
   free (archive_dir);
-
-#undef CURRENT_FILE_NAME
 }
