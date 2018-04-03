		 * Prerequisites have object name that is optionally
		 * followed by SP and subject line.
		 */
		if (get_sha1_hex(buf.buf, sha1) ||
		    (buf.len > 40 && !isspace(buf.buf[40])) ||
		    (!is_prereq && buf.len <= 40)) {
			if (report_path)
				error(_("unrecognized header: %s%s (%d)"),
				      (is_prereq ? "-" : ""), buf.buf, (int)buf.len);
			status = -1;
			break;
		} else {
			if (is_prereq)
				add_to_ref_list(sha1, "", &header->prerequisites);
			else
				add_to_ref_list(sha1, buf.buf + 41, &header->references);
		}
	}

