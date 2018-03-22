 		    char buf[UINTMAX_STRSIZE_BOUND];
 		    ERROR ((0, 0,
 			    _("File %s shrunk by %s bytes, padding with zeros"),
-			    p, STRINGIFY_BIGINT (sizeleft, buf)));
+			    quote (p), STRINGIFY_BIGINT (sizeleft, buf)));
 		    goto padit;		/* short read */
 		  }
 	      }
