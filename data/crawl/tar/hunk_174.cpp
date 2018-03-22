 	{
 	  if (type && !silent)
 	    ERROR ((0, 0,
+		    /* TRANSLATORS: Second %s is a type name (gid_t,uid_t,etc.) */
 		    _("Archive octal value %.*s is out of %s range"),
 		    (int) (where - where1), where1, type));
 	  return -1;
