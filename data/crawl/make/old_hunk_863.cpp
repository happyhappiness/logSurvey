
	  /* Restore state.  */
	  conditionals = save;
	  reading_file = &fileinfo;
	}
#undef	word1eq
      else if (try_variable_definition (&fileinfo, p, o_file, 0))
	/* This line has been dealt with.  */
	;
      else if (lb.buffer[0] == '\t')
	{
	  p = collapsed;	/* Ignore comments.  */
	  while (isblank ((unsigned char)*p))
	    ++p;
	  if (*p == '\0')
	    /* The line is completely blank; that is harmless.  */
	    continue;
	  /* This line starts with a tab but was not caught above
	     because there was no preceding target, and the line
	     might have been usable as a variable definition.
	     But now it is definitely lossage.  */
	  fatal(&fileinfo, _("commands commence before first target"));
	}
      else
	{
	  /* This line describes some target files.  This is complicated by
             the existence of target-specific variables, because we can't
             expand the entire line until we know if we have one or not.  So
             we expand the line word by word until we find the first `:',
             then check to see if it's a target-specific variable.

             In this algorithm, `lb_next' will point to the beginning of the
             unexpanded parts of the input buffer, while `p2' points to the
             parts of the expanded buffer we haven't searched yet. */

          enum make_word_type wtype;
          enum variable_origin v_origin;
          char *cmdleft, *semip, *lb_next;
          unsigned int len, plen = 0;
          char *colonp;

	  /* Record the previous rule.  */

	  record_waiting_files ();
          tgts_started = fileinfo.lineno;

	  /* Search the line for an unquoted ; that is not after an
             unquoted #.  */
	  cmdleft = find_char_unquote (lb.buffer, ";#", 0);
	  if (cmdleft != 0 && *cmdleft == '#')
	    {
	      /* We found a comment before a semicolon.  */
	      *cmdleft = '\0';
	      cmdleft = 0;
	    }
	  else if (cmdleft != 0)
	    /* Found one.  Cut the line short there before expanding it.  */
	    *(cmdleft++) = '\0';
          semip = cmdleft;

	  collapse_continuations (lb.buffer);

	  /* We can't expand the entire line, since if it's a per-target
             variable we don't want to expand it.  So, walk from the
             beginning, expanding as we go, and looking for "interesting"
             chars.  The first word is always expandable.  */
          wtype = get_next_mword(lb.buffer, NULL, &lb_next, &len);
          switch (wtype)
            {
            case w_eol:
              if (cmdleft != 0)
                fatal(&fileinfo, _("missing rule before commands"));
              /* This line contained something but turned out to be nothing
                 but whitespace (a comment?).  */
              continue;

            case w_colon:
            case w_dcolon:
              /* We accept and ignore rules without targets for
                 compatibility with SunOS 4 make.  */
              no_targets = 1;
              continue;

            default:
              break;
            }

          p2 = variable_expand_string(NULL, lb_next, len);
          while (1)
            {
              lb_next += len;
              if (cmdleft == 0)
                {
                  /* Look for a semicolon in the expanded line.  */
                  cmdleft = find_char_unquote (p2, ";", 0);

                  if (cmdleft != 0)
                    {
                      unsigned long p2_off = p2 - variable_buffer;
                      unsigned long cmd_off = cmdleft - variable_buffer;
                      char *pend = p2 + strlen(p2);

                      /* Append any remnants of lb, then cut the line short
                         at the semicolon.  */
                      *cmdleft = '\0';

                      /* One school of thought says that you shouldn't expand
                         here, but merely copy, since now you're beyond a ";"
                         and into a command script.  However, the old parser
                         expanded the whole line, so we continue that for
                         backwards-compatiblity.  Also, it wouldn't be
                         entirely consistent, since we do an unconditional
                         expand below once we know we don't have a
                         target-specific variable. */
                      (void)variable_expand_string(pend, lb_next, (long)-1);
                      lb_next += strlen(lb_next);
                      p2 = variable_buffer + p2_off;
                      cmdleft = variable_buffer + cmd_off + 1;
                    }
                }

              colonp = find_char_unquote(p2, ":", 0);
#if defined(__MSDOS__) || defined(WINDOWS32)
	      /* The drive spec brain-damage strikes again...  */
	      /* Note that the only separators of targets in this context
		 are whitespace and a left paren.  If others are possible,
		 they should be added to the string in the call to index.  */
	      while (colonp && (colonp[1] == '/' || colonp[1] == '\\') &&
		     colonp > p2 && isalpha ((unsigned char)colonp[-1]) &&
		     (colonp == p2 + 1 || strchr (" \t(", colonp[-2]) != 0))
		colonp = find_char_unquote(colonp + 1, ":", 0);
#endif
              if (colonp != 0)
                break;

              wtype = get_next_mword(lb_next, NULL, &lb_next, &len);
              if (wtype == w_eol)
                break;

              p2 += strlen(p2);
              *(p2++) = ' ';
              p2 = variable_expand_string(p2, lb_next, len);
              /* We don't need to worry about cmdleft here, because if it was
                 found in the variable_buffer the entire buffer has already
                 been expanded... we'll never get here.  */
            }

	  p2 = next_token (variable_buffer);

          /* If the word we're looking at is EOL, see if there's _anything_
             on the line.  If not, a variable expanded to nothing, so ignore
             it.  If so, we can't parse this line so punt.  */
          if (wtype == w_eol)
            {
              if (*p2 != '\0')
                /* There's no need to be ivory-tower about this: check for
                   one of the most common bugs found in makefiles...  */
                fatal (&fileinfo, _("missing separator%s"),
                       !strneq(lb.buffer, "        ", 8) ? ""
                       : _(" (did you mean TAB instead of 8 spaces?)"));
              continue;
            }

          /* Make the colon the end-of-string so we know where to stop
             looking for targets.  */
          *colonp = '\0';
	  filenames = multi_glob (parse_file_seq (&p2, '\0',
						  sizeof (struct nameseq),
						  1),
				  sizeof (struct nameseq));
          *p2 = ':';

          if (!filenames)
            {
              /* We accept and ignore rules without targets for
                 compatibility with SunOS 4 make.  */
              no_targets = 1;
              continue;
            }
          /* This should never be possible; we handled it above.  */
	  assert (*p2 != '\0');
          ++p2;

	  /* Is this a one-colon or two-colon entry?  */
	  two_colon = *p2 == ':';
	  if (two_colon)
	    p2++;

          /* Test to see if it's a target-specific variable.  Copy the rest
             of the buffer over, possibly temporarily (we'll expand it later
             if it's not a target-specific variable).  PLEN saves the length
             of the unparsed section of p2, for later.  */
          if (*lb_next != '\0')
            {
              unsigned int l = p2 - variable_buffer;
              plen = strlen (p2);
              (void) variable_buffer_output (p2+plen,
                                             lb_next, strlen (lb_next)+1);
              p2 = variable_buffer + l;
            }

          /* See if it's an "override" keyword; if so see if what comes after
             it looks like a variable definition.  */

          wtype = get_next_mword (p2, NULL, &p, &len);

          v_origin = o_file;
          if (wtype == w_static && (len == (sizeof ("override")-1)
                                    && strneq (p, "override", len)))
            {
              v_origin = o_override;
              wtype = get_next_mword (p+len, NULL, &p, &len);
            }

          if (wtype != w_eol)
            wtype = get_next_mword (p+len, NULL, NULL, NULL);

          if (wtype == w_varassign)
            {
              /* If there was a semicolon found, add it back, plus anything
                 after it.  */
              if (semip)
                {
                  *(--semip) = ';';
                  variable_buffer_output (p2 + strlen (p2),
                                          semip, strlen (semip)+1);
                }
              record_target_var (filenames, p, two_colon, v_origin, &fileinfo);
              filenames = 0;
              continue;
            }

          /* This is a normal target, _not_ a target-specific variable.
             Unquote any = in the dependency list.  */
          find_char_unquote (lb_next, "=", 0);

	  /* We have some targets, so don't ignore the following commands.  */
	  no_targets = 0;

          /* Expand the dependencies, etc.  */
          if (*lb_next != '\0')
            {
              unsigned int l = p2 - variable_buffer;
              (void) variable_expand_string (p2 + plen, lb_next, (long)-1);
              p2 = variable_buffer + l;

              /* Look for a semicolon in the expanded line.  */
              if (cmdleft == 0)
                {
                  cmdleft = find_char_unquote (p2, ";", 0);
                  if (cmdleft != 0)
                    *(cmdleft++) = '\0';
                }
            }

	  /* Is this a static pattern rule: `target: %targ: %dep; ...'?  */
	  p = strchr (p2, ':');
	  while (p != 0 && p[-1] == '\\')
	    {
	      register char *q = &p[-1];
	      register int backslash = 0;
	      while (*q-- == '\\')
		backslash = !backslash;
	      if (backslash)
		p = strchr (p + 1, ':');
	      else
		break;
	    }
#ifdef _AMIGA
	  /* Here, the situation is quite complicated. Let's have a look
	    at a couple of targets:

		install: dev:make

		dev:make: make

		dev:make:: xyz

	    The rule is that it's only a target, if there are TWO :'s
	    OR a space around the :.
	  */
	  if (p && !(isspace ((unsigned char)p[1]) || !p[1]
                     || isspace ((unsigned char)p[-1])))
	    p = 0;
#endif
#if defined (WINDOWS32) || defined (__MSDOS__)
          do {
            check_again = 0;
            /* For MSDOS and WINDOWS32, skip a "C:\..." or a "C:/..." */
            if (p != 0 && (p[1] == '\\' || p[1] == '/') &&
		isalpha ((unsigned char)p[-1]) &&
		(p == p2 + 1 || strchr (" \t:(", p[-2]) != 0)) {
              p = strchr (p + 1, ':');
              check_again = 1;
            }
          } while (check_again);
#endif
	  if (p != 0)
	    {
	      struct nameseq *target;
	      target = parse_file_seq (&p2, ':', sizeof (struct nameseq), 1);
	      ++p2;
	      if (target == 0)
		fatal (&fileinfo, _("missing target pattern"));
	      else if (target->next != 0)
		fatal (&fileinfo, _("multiple target patterns"));
	      pattern = target->name;
	      pattern_percent = find_percent (pattern);
	      if (pattern_percent == 0)
		fatal (&fileinfo, _("target pattern contains no `%%'"));
              free((char *)target);
	    }
	  else
	    pattern = 0;

	  /* Parse the dependencies.  */
	  deps = (struct dep *)
	    multi_glob (parse_file_seq (&p2, '\0', sizeof (struct dep), 1),
			sizeof (struct dep));

	  commands_idx = 0;
	  if (cmdleft != 0)
	    {
	      /* Semicolon means rest of line is a command.  */
	      unsigned int len = strlen (cmdleft);

	      cmds_started = fileinfo.lineno;

	      /* Add this command line to the buffer.  */
	      if (len + 2 > commands_len)
		{
		  commands_len = (len + 2) * 2;
		  commands = (char *) xrealloc (commands, commands_len);
		}
	      bcopy (cmdleft, commands, len);
	      commands_idx += len;
	      commands[commands_idx++] = '\n';
	    }

	  continue;
	}

      /* We get here except in the case that we just read a rule line.
	 Record now the last rule we read, so following spurious
	 commands are properly diagnosed.  */
      record_waiting_files ();
      no_targets = 0;
    }

  if (conditionals->if_cmds)
    fatal (&fileinfo, _("missing `endif'"));

  /* At eof, record the last rule.  */
  record_waiting_files ();

  freebuffer (&lb);
  free ((char *) commands);
  fclose (infile);

  reading_file = 0;

  return 1;
}

/* Execute a `define' directive.
   The first line has already been read, and NAME is the name of
   the variable to be defined.  The following lines remain to be read.
   LINENO, INFILE and FILENAME refer to the makefile being read.
   The value returned is LINENO, updated for lines read here.  */

static void
do_define (name, namelen, origin, infile, flocp)
     char *name;
     unsigned int namelen;
     enum variable_origin origin;
     FILE *infile;
     struct floc *flocp;
{
  struct linebuffer lb;
  unsigned int nlines = 0;
  unsigned int length = 100;
  char *definition = (char *) xmalloc (100);
  register unsigned int idx = 0;
  register char *p;

  /* Expand the variable name.  */
  char *var = (char *) alloca (namelen + 1);
