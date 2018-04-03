 
 		if ((flags & TRANSPORT_RECURSE_SUBMODULES_ON_DEMAND) && !is_bare_repository()) {
 			struct ref *ref = remote_refs;
+			struct sha1_array commits = SHA1_ARRAY_INIT;
+
 			for (; ref; ref = ref->next)
-				if (!is_null_oid(&ref->new_oid) &&
-				    !push_unpushed_submodules(ref->new_oid.hash,
-					    transport->remote->name))
-				    die ("Failed to push all needed submodules!");
+				if (!is_null_oid(&ref->new_oid))
+					sha1_array_append(&commits, ref->new_oid.hash);
+
+			if (!push_unpushed_submodules(&commits, transport->remote->name)) {
+				sha1_array_clear(&commits);
+				die("Failed to push all needed submodules!");
+			}
+			sha1_array_clear(&commits);
 		}
 
 		if ((flags & (TRANSPORT_RECURSE_SUBMODULES_ON_DEMAND |
 			      TRANSPORT_RECURSE_SUBMODULES_CHECK)) && !is_bare_repository()) {
 			struct ref *ref = remote_refs;
 			struct string_list needs_pushing = STRING_LIST_INIT_DUP;
+			struct sha1_array commits = SHA1_ARRAY_INIT;
 
 			for (; ref; ref = ref->next)
-				if (!is_null_oid(&ref->new_oid) &&
-				    find_unpushed_submodules(ref->new_oid.hash,
-					    transport->remote->name, &needs_pushing))
-					die_with_unpushed_submodules(&needs_pushing);
+				if (!is_null_oid(&ref->new_oid))
+					sha1_array_append(&commits, ref->new_oid.hash);
+
+			if (find_unpushed_submodules(&commits, transport->remote->name,
+						&needs_pushing)) {
+				sha1_array_clear(&commits);
+				die_with_unpushed_submodules(&needs_pushing);
+			}
+			string_list_clear(&needs_pushing, 0);
+			sha1_array_clear(&commits);
 		}
 
 		push_ret = transport->push_refs(transport, remote_refs, flags);