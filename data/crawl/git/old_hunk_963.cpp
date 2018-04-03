
		strbuf_expand(&expanded_path, interpolated_path,
			      expand_path, &context);
		strlcpy(interp_path, expanded_path.buf, PATH_MAX);
		strbuf_release(&expanded_path);
		loginfo("Interpolated dir '%s'", interp_path);

