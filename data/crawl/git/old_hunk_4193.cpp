		if (!askpass)
			askpass = getenv("SSH_ASKPASS");
		if (askpass && *askpass)
			return do_askpass(askpass, prompt);
	}

	r = git_terminal_prompt(prompt, flags & PROMPT_ECHO);
	if (!r)
		die_errno("could not read '%s'", prompt);
	return r;
}
