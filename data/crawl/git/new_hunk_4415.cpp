	}
	strbuf_release(&buf);
	if (fclose(show_out))
		die_errno(_("failed to close pipe to 'show' for object '%s'"),
			  sha1_to_hex(object));
	if (finish_command(&show))
		die(_("failed to finish 'show' for object '%s'"),
		    sha1_to_hex(object));
}

