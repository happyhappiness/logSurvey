			strbuf_addstr(sb, data->rest);
	} else if (is_atom("deltabase", atom, len)) {
		if (data->mark_query)
			data->info.delta_base_sha1 = data->delta_base_oid.hash;
		else
			strbuf_addstr(sb,
				      oid_to_hex(&data->delta_base_oid));
	} else
		die("unknown format element: %.*s", len, atom);
}
