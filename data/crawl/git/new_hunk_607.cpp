		 * Prerequisites have object name that is optionally
		 * followed by SP and subject line.
		 */
		if (parse_oid_hex(buf.buf, &oid, &p) ||
		    (*p && !isspace(*p)) ||
		    (!is_prereq && !*p)) {
			if (report_path)
				error(_("unrecognized header: %s%s (%d)"),
				      (is_prereq ? "-" : ""), buf.buf, (int)buf.len);
			status = -1;
			break;
		} else {
			if (is_prereq)
				add_to_ref_list(&oid, "", &header->prerequisites);
			else
				add_to_ref_list(&oid, p + 1, &header->references);
		}
	}

