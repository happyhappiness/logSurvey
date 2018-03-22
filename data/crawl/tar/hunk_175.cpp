 	  quotearg_buffer (buf, sizeof buf, where0, lim - where, o);
 	  if (!silent)
 	    ERROR ((0, 0,
+		    /* TRANSLATORS: Second %s is a type name (gid_t,uid_t,etc.) */
 		    _("Archive contains %.*s where numeric %s value expected"),
 		    (int) sizeof buf, buf, type));
 	}
