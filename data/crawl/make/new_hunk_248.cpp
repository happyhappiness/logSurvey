  /* Found one: skip past it and any whitespace after it.  */
  line = next_token (line + len);

#define EXTRATEXT() OS (error, flocp, _("extraneous text after '%s' directive"), cmdname)
#define EXTRACMD()  OS (fatal, flocp, _("extraneous '%s'"), cmdname)

  /* An 'endif' cannot contain extra text, and reduces the if-depth by 1  */
  if (cmdtype == c_endif)
    {
      if (*line != '\0')
        EXTRATEXT ();

      if (!conditionals->if_cmds)
        EXTRACMD ();

      --conditionals->if_cmds;

