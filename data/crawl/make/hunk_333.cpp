   FILE_TIMESTAMP ts = product + offset;
 
   if (! (s <= FILE_TIMESTAMP_S (ORDINARY_MTIME_MAX)
-	 && product <= ts && ts <= ORDINARY_MTIME_MAX))
+         && product <= ts && ts <= ORDINARY_MTIME_MAX))
     {
       char buf[FILE_TIMESTAMP_PRINT_LEN_BOUND + 1];
       ts = s <= OLD_MTIME ? ORDINARY_MTIME_MIN : ORDINARY_MTIME_MAX;
       file_timestamp_sprintf (buf, ts);
       error (NILF, _("%s: Timestamp out of range; substituting %s"),
-	     fname ? fname : _("Current time"), buf);
+             fname ? fname : _("Current time"), buf);
     }
 
   return ts;
