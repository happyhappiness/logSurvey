  /* Found one: skip past it and any whitespace after it.  */
  line = next_token (line + len);

#define EXTRANEOUS() error (flocp, _("extraneous text after '%s' directive"), cmdname)

  /* An 'endif' cannot contain extra text, and reduces the if-depth by 1  */
  if (cmdtype == c_endif)
    {
      if (*line != '\0')
        EXTRANEOUS ();

      if (!conditionals->if_cmds)
        fatal (flocp, _("extraneous '%s'"), cmdname);

      --conditionals->if_cmds;

