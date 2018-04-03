		}
	}

	if (apply_fragments(&buf, patch) < 0)
		return -1; /* note with --reject this succeeds. */
	patch->result = strbuf_detach(&buf, &patch->resultsize);

	if (0 < patch->is_delete && patch->resultsize)
		return error("removal patch leaves file contents");