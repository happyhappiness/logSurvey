 		if (create_symref(head_ref.buf,
 				  remote_head_points_at->peer_ref->name,
 				  msg) < 0)
-			die("unable to update %s", head_ref.buf);
+			die(_("unable to update %s"), head_ref.buf);
 		strbuf_release(&head_ref);
 	}
 }
