 	  {
 	    register struct file *f = d->file;
 	    if (f->double_colon)
-	      {
-		do
-		  {
-		    if (f->deps == 0 && f->cmds != 0)
-		      {
-			/* This makefile is a :: target with commands, but
-			   no dependencies.  So, it will always be remade.
-			   This might well cause an infinite loop, so don't
-			   try to remake it.  (This will only happen if
-			   your makefiles are written exceptionally
-			   stupidly; but if you work for Athena, that's how
-			   you write your makefiles.)  */
-
-			if (debug_flag)
-			  printf ("Makefile `%s' might loop; not remaking it.\n",
-				  f->name);
-
-			if (last == 0)
-			  read_makefiles = d->next;
-			else
-			  last->next = d->next;
+	      do
+		{
+		  if (f->deps == 0 && f->cmds != 0)
+		    {
+		      /* This makefile is a :: target with commands, but
+			 no dependencies.  So, it will always be remade.
+			 This might well cause an infinite loop, so don't
+			 try to remake it.  (This will only happen if
+			 your makefiles are written exceptionally
+			 stupidly; but if you work for Athena, that's how
+			 you write your makefiles.)  */
+
+		      if (debug_flag)
+			printf ("Makefile `%s' might loop; not remaking it.\n",
+				f->name);
+
+		      if (last == 0)
+			read_makefiles = d->next;
+		      else
+			last->next = d->next;
 
-			/* Free the storage.  */
-			free ((char *) d);
+		      /* Free the storage.  */
+		      free ((char *) d);
 
-			d = last == 0 ? 0 : last->next;
+		      d = last == 0 ? 0 : last->next;
 
-			break;
-		      }
-		    f = f->prev;
-		  }
-		while (f != NULL);
-	      }
+		      break;
+		    }
+		  f = f->prev;
+		}
+	      while (f != NULL);
 	    if (f == NULL || !f->double_colon)
 	      {
 		if (makefile_mtimes == 0)
