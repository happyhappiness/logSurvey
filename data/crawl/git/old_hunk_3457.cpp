		die(_("reference repository '%s' is not a local repository."),
		    item->string);

	strbuf_addf(&alternate, "%s/objects", ref_git);
	add_to_alternates_file(alternate.buf);
	strbuf_release(&alternate);