      *line = '\0';
      line = next_token (++line);
      if (*line != '\0')
	EXTRANEOUS ();

      s2 = variable_expand (s2);
      conditionals->ignoring[o] = (streq (s1, s2) == (cmdtype == c_ifneq));
    }

 DONE:
  /* Search through the stack to see if we're ignoring.  */
  for (i = 0; i < conditionals->if_cmds; ++i)
    if (conditionals->ignoring[i])
