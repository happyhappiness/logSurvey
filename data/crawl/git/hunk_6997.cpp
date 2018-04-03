 				resolve_delta(child, &base_obj, type);
 		}
 
-		if (check_sha1_signature(d->base.sha1, base_obj.data,
-				base_obj.size, typename(type)))
-			die("local object %s is corrupt", sha1_to_hex(d->base.sha1));
-		append_obj_to_pack(d->base.sha1, base_obj.data,
-			base_obj.size, type);
 		unlink_base_data(&base_obj);
 		display_progress(progress, nr_resolved_deltas);
 	}