 			die(_("%s - not something we can merge"), argv[0]);
 		if (remoteheads->next)
 			die(_("Can merge only exactly one commit into empty head"));
-		read_empty(get_object_hash(remote_head->object), 0);
-		update_ref("initial pull", "HEAD", get_object_hash(remote_head->object),
+		read_empty(remote_head->object.oid.hash, 0);
+		update_ref("initial pull", "HEAD", remote_head->object.oid.hash,
 			   NULL, 0, UPDATE_REFS_DIE_ON_ERR);
 		goto done;
 	}
