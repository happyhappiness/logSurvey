 	    next_cursor[-2] = '\0';
 	  unquote_string (name_end + 4);
 	  if (rename (name, name_end + 4))
-	    ERROR ((0, errno, _("Cannot rename %s to %s"), name, name_end + 4));
+	    ERROR ((0, errno, _("%s: Cannot rename to %s"),
+		    quotearg_colon (name), quote_n (1, name_end + 4)));
 	  else if (verbose_option)
 	    WARN ((0, 0, _("Renamed %s to %s"), name, name_end + 4));
 	}
