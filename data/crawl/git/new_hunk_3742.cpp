		free(ref_git);
		ref_git = ref_git_git;
	} else if (!is_directory(mkpath("%s/objects", ref_git)))
		die(_("reference repository '%s' is not a local repository."),
		    item->string);

	strbuf_addf(&alternate, "%s/objects", ref_git);