   make_access ();
   if (getloadavg (&load, 1) != 1)
     {
-      static int lossage = 0;
+      static int lossage = -1;
       /* Complain only once for the same error.  */
-      if (lossage == 0 || errno != lossage)
-	perror_with_name ("cannot enforce load limit: ", "getloadavg");
+      if (lossage == -1 || errno != lossage)
+	{
+	  if (errno == 0)
+	    /* An errno value of zero means getloadavg is just unsupported.  */
+	    error ("cannot enforce load limits on this operating system");
+	  else
+	    perror_with_name ("cannot enforce load limit: ", "getloadavg");
+	}
       lossage = errno;
       load = 0;
     }
