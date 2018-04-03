			      TRANSPORT_RECURSE_SUBMODULES_ONLY)) &&
		    !is_bare_repository()) {
			struct ref *ref = remote_refs;
			struct sha1_array commits = SHA1_ARRAY_INIT;

			for (; ref; ref = ref->next)
				if (!is_null_oid(&ref->new_oid))
					sha1_array_append(&commits,
							  &ref->new_oid);

			if (!push_unpushed_submodules(&commits,
						      transport->remote->name,
						      pretend)) {
				sha1_array_clear(&commits);
				die("Failed to push all needed submodules!");
			}
			sha1_array_clear(&commits);
		}

		if (((flags & TRANSPORT_RECURSE_SUBMODULES_CHECK) ||
