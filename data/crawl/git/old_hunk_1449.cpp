			goto finish;
		}

		if (get_sha1_hex(sb.buf + GIT_SHA1_HEXSZ + 1, to_obj)) {
			ret = error(invalid_line, sb.buf);
			goto finish;
		}

		if (copy_note_for_rewrite(c, from_obj, to_obj))
			ret = error(_("Failed to copy notes from '%s' to '%s'"),
					sha1_to_hex(from_obj), sha1_to_hex(to_obj));
	}

finish:
