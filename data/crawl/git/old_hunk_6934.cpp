		args[i++] = path;
		args[i] = NULL;

		if (run_command_v_opt_cd_env(args, 0, NULL, env))
			die("There was a problem with the editor %s.", editor);
		strbuf_release(&arg0);
	}

	if (!buffer)
		return;
	if (strbuf_read_file(buffer, path, 0) < 0)
		die("could not read message file '%s': %s",
		    path, strerror(errno));
}
