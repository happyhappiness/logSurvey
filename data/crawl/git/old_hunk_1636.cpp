						  branch1, branch2);

			if ((merge_status < 0) || !result_buf.ptr)
				ret = error(_("Failed to execute internal merge"));

			if (!ret && write_sha1_file(result_buf.ptr, result_buf.size,
						    blob_type, result->oid.hash))
				ret = error(_("Unable to add %s to database"),
					    a->path);

			free(result_buf.ptr);
			if (ret)
