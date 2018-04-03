 	return NULL;
       }
     /* Do all systems have h_addr_list, or is it a newer thing?  If
-       the latter, use address_list_new_one.  */
-    al = address_list_new (hptr->h_addr_list);
+       the latter, use address_list_from_single.  */
+    al = address_list_from_vector (hptr->h_addr_list);
   }
 #endif
 
+  /* Print the addresses determined by DNS lookup, but no more than
+     three.  */
   if (!silent)
-    logprintf (LOG_VERBOSE, _("done.\n"));
+    {
+      int i;
+      int printmax = al->count <= 3 ? al->count : 3;
+      for (i = 0; i < printmax; i++)
+	{
+	  logprintf (LOG_VERBOSE, "%s",
+		     pretty_print_address (al->addresses + i));
+	  if (i < printmax - 1)
+	    logputs (LOG_VERBOSE, ", ");
+	}
+      if (printmax != al->count)
+	logputs (LOG_VERBOSE, ", ...");
+      logputs (LOG_VERBOSE, "\n");
+    }
 
   /* Cache the lookup information. */
   if (opt.dns_cache)
