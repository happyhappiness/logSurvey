		args[i++] = path;
		args[i] = NULL;

		failed = run_command_v_opt_cd_env(args, 0, NULL, env);
		strbuf_release(&arg0);
		if (failed)
			return error("There was a problem with the editor '%s'.",
					editor);
	}

	if (!buffer)
		return 0;
	if (strbuf_read_file(buffer, path, 0) < 0)
		return error("could not read file '%s': %s",
				path, strerror(errno));
	return 0;
}
