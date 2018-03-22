     while (name_head->prev)
       name_head = name_head->prev;
 }
+
+/* For error-reporting purposes, keep a doubly-linked list of unconsumed file
+   selection options.  The option is deemed unconsumed unless followed by one
+   or more file/member name arguments.  When archive creation is requested,
+   each file selection option encountered is pushed into the list.  The list
+   is cleared upon encountering a file name argument.
+
+   If the list is not empty when all arguments have been processed, an error
+   message is issued reporting the options that had no effect.
+
+   For simplicity, only a tail pointer of the list is maintained.
+*/
+   
+struct name_elt *unconsumed_option_tail;
+
+/* Push an option to the list */
+static void
+unconsumed_option_push (struct name_elt *elt)
+{
+  elt->prev = unconsumed_option_tail;
+  if (unconsumed_option_tail)
+    unconsumed_option_tail->next = elt;
+  unconsumed_option_tail = elt;
+}
+
+/* Clear the unconsumed option list */
+static void
+unconsumed_option_free (void)
+{
+  while (unconsumed_option_tail)
+    {
+      struct name_elt *elt = unconsumed_option_tail;
+      unconsumed_option_tail = unconsumed_option_tail->prev;
+      free (elt);
+    }
+}
+
+/* Report any options that have not been consumed */
+static void
+unconsumed_option_report (void)
+{
+  if (unconsumed_option_tail)
+    {
+      struct name_elt *elt;
+      
+      ERROR ((0, 0, _("The following options were used after any non-optional arguments in archive create or update mode.  These options are positional and affect only arguments that follow them.  Please, rearrange them properly.")));
+
+      elt = unconsumed_option_tail;
+      while (elt->prev)
+	elt = elt->prev;
 
+      while (elt)
+	{
+	  switch (elt->type)
+	    {
+	    case NELT_CHDIR:
+	      ERROR ((0, 0, _("-C %s has no effect"), quote (elt->v.name)));
+	      break;
+
+	    case NELT_OPTION:
+	      if (elt->v.opt.arg)
+		ERROR ((0, 0, _("--%s %s has no effect"),
+			file_selection_option_name (elt->v.opt.option),
+			quote (elt->v.opt.arg)));
+	      else
+		ERROR ((0, 0, _("--%s has no effect"),
+			file_selection_option_name (elt->v.opt.option)));
+	      break;
+	      
+	    default:
+	      break;
+	    }
+	  elt = elt->next;
+	}
+      
+      unconsumed_option_free ();
+    }
+}
+
 static void
 name_list_advance (void)
 {
