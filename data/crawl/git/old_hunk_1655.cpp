			oidcpy(&result->oid, &a->oid);
		else if (S_ISREG(a->mode)) {
			mmbuffer_t result_buf;
			int merge_status;

			merge_status = merge_3way(o, &result_buf, one, a, b,
						  branch1, branch2);

			if ((merge_status < 0) || !result_buf.ptr)
				die(_("Failed to execute internal merge"));

			if (write_sha1_file(result_buf.ptr, result_buf.size,
					    blob_type, result->oid.hash))
				die(_("Unable to add %s to database"),
				    a->path);

			free(result_buf.ptr);
			result->clean = (merge_status == 0);
		} else if (S_ISGITLINK(a->mode)) {
			result->clean = merge_submodule(result->oid.hash,
