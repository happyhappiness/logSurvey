 		strbuf_reset(&(msg->buf));
 
 		if (launch_editor(path, &(msg->buf), NULL)) {
-			die("Please supply the note contents using either -m" \
-			    " or -F option");
+			die(_("Please supply the note contents using either -m" \
+			    " or -F option"));
 		}
 		stripspace(&(msg->buf), 1);
 	}
