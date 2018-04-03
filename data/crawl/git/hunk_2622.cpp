 		if ((flags & TRANSPORT_RECURSE_SUBMODULES_ON_DEMAND) && !is_bare_repository()) {
 			struct ref *ref = remote_refs;
 			for (; ref; ref = ref->next)
-				if (!is_null_sha1(ref->new_sha1) &&
-				    !push_unpushed_submodules(ref->new_sha1,
+				if (!is_null_oid(&ref->new_oid) &&
+				    !push_unpushed_submodules(ref->new_oid.hash,
 					    transport->remote->name))
 				    die ("Failed to push all needed submodules!");
 		}
