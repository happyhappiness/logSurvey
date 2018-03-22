 	}
       else
 	{
-	  sprintf (message, _("Could only read %lu of %lu bytes"),
+	  sprintf (message,
+		   ngettext ("Could only read %lu of %lu byte",
+			     "Could only read %lu of %lu bytes",
+			     bytes),
 		   (unsigned long) status, (unsigned long) bytes);
 	  report_difference (message);
 	}
