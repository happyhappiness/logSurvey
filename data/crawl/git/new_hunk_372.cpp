		if (run_command(&store))
			ret = error(_("cannot store %s"), stash_sha1.buf);
		else
			fprintf(stderr,
				_("Applying autostash resulted in conflicts.\n"
				  "Your changes are safe in the stash.\n"
				  "You can run \"git stash pop\" or"
				  " \"git stash drop\" at any time.\n"));
	}

	strbuf_release(&stash_sha1);