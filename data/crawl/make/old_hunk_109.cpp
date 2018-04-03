    argv++;

  if (*argv == 0)
    return 0;

  sprintf (procname, "GMAKE_%05x", getpid () & 0xfffff);
  pnamedsc.dsc$w_length = strlen(procname);
  pnamedsc.dsc$a_pointer = procname;
  pnamedsc.dsc$b_dtype = DSC$K_DTYPE_T;
  pnamedsc.dsc$b_class = DSC$K_CLASS_S;

  in_string = 0;
  /* Handle comments and redirection.
     For ONESHELL, the redirection must be on the first line. Any other
     redirection token is handled by DCL, that is, the pipe command with
     redirection can be used, but it should not be used on the first line
     for ONESHELL. */
  for (p = argv, q = cmd; *p; p++, q++)
    {
      if (*p == '"')
        in_string = !in_string;
      if (in_string)
        {
          *q = *p;
          continue;
        }
      switch (*p)
        {
        case '#':
          *p-- = 0;
          *q-- = 0;
          break;
        case '\\':
          p++;
          if (*p == '\n')
            p++;
          if (isspace ((unsigned char)*p))
            {
              do { p++; } while (isspace ((unsigned char)*p));
              p--;
            }
          *q = *p;
          break;
        case '<':
          if (have_newline==0)
            {
              p = vms_redirect (&ifiledsc, ifile, p);
              *q = ' ';
              have_redirection = 1;
            }
          else
            *q = *p;
          break;
        case '>':
          if (have_newline==0)
            {
              have_redirection = 1;
              if (*(p-1) == '2')
                {
                  q--;
                  if (strncmp (p, ">&1", 3) == 0)
                    {
                      p += 2;
                      strcpy (efile, "sys$output");
                      efiledsc.dsc$w_length = strlen(efile);
                      efiledsc.dsc$a_pointer = efile;
                      efiledsc.dsc$b_dtype = DSC$K_DTYPE_T;
                      efiledsc.dsc$b_class = DSC$K_CLASS_S;
                    }
                  else
                    p = vms_redirect (&efiledsc, efile, p);
                }
              else
                {
                  if (*(p+1) == '>')
                    {
                      have_append = 1;
                      p += 1;
                    }
                  p = vms_redirect (&ofiledsc, ofile, p);
                }
              *q = ' ';
            }
          else
            *q = *p;
          break;
        case '\n':
          have_newline++;
        default:
          *q = *p;
          break;
        }
    }
  *q = *p;
  while (isspace ((unsigned char)*--q))
    *q = '\0';


#define VMS_EMPTY_ECHO "write sys$output \"\""
  if (have_newline == 0)
    {
      /* multiple shells */
      if (strncmp(cmd, "builtin_", 8) == 0)
        {
          child->pid = 270163;
          child->efn = 0;
          child->cstatus = 1;

          DB(DB_JOBS, (_("BUILTIN [%s][%s]\n"), cmd, cmd + 8));

          p = cmd + 8;

          if ((*(p) == 'c') && (*(p + 1) == 'd')
              && ((*(p + 2) == ' ') || (*(p + 2) == '\t')))
            {
              p += 3;
              while ((*p == ' ') || (*p == '\t'))
                p++;
              DB(DB_JOBS, (_("BUILTIN CD %s\n"), p));
              if (chdir(p))
                return 0;
              else
                return 1;
            }
          else if ((*(p) == 'e')
              && (*(p+1) == 'c')
              && (*(p+2) == 'h')
              && (*(p+3) == 'o')
              && ((*(p+4) == ' ') || (*(p+4) == '\t') || (*(p+4) == '\0')))
            {
              /* This is not a real builtin, it is a built in pre-processing
                 for the VMS/DCL echo (write sys$output) to ensure the to be echoed
                 string is correctly quoted (with the DCL quote character '"'). */
              char *vms_echo;
              p += 4;
              if (*p == '\0')
                cmd = VMS_EMPTY_ECHO;
              else
                {
                  p++;
                  while ((*p == ' ') || (*p == '\t'))
                    p++;
                  if (*p == '\0')
                    cmd = VMS_EMPTY_ECHO;
                  else
                    {
                      vms_echo = alloca(strlen(p) + sizeof VMS_EMPTY_ECHO);
                      strcpy(vms_echo, VMS_EMPTY_ECHO);
                      vms_echo[sizeof VMS_EMPTY_ECHO - 2] = '\0';
                      strcat(vms_echo, p);
                      strcat(vms_echo, "\"");
                      cmd = vms_echo;
                    }
                }
              DB (DB_JOBS, (_("BUILTIN ECHO %s->%s\n"), p, cmd));
            }
          else
            {
              printf(_("Unknown builtin command '%s'\n"), cmd);
              fflush(stdout);
              return 0;
            }
        }
      /* expand ':' aka 'do nothing' builtin for bash and friends */
      else if (cmd[0]==':')
        cmd[0] = '!';
    }
  else
    {
      /* todo: expand ':' aka 'do nothing' builtin for bash and friends */
      /* For 'one shell' expand all the
           builtin_echo
         to
           write sys$output ""
         where one is  ......7 bytes longer.
         At the same time ensure that the echo string is properly terminated.
         For that, allocate a command buffer big enough for all possible expansions
         (have_newline is the count), then expand, copy and terminate. */
      char *tmp_cmd;
      int nloff = 0;
      int vlen = 0;
      int clen = 0;
      int inecho;

      tmp_cmd = alloca(strlen(cmd) + (have_newline + 1) * 7 + 1);
      tmp_cmd[0] = '\0';
      inecho = 0;
      while (cmd[nloff])
        {
          if (inecho)
            {
              if (clen < nloff - 1)
                {
                  memcpy(&tmp_cmd[vlen], &cmd[clen], nloff - clen - 1);
                  vlen += nloff - clen - 1;
                  clen = nloff;
                }
              inecho = 0;
              tmp_cmd[vlen] = '"';
              vlen++;
              tmp_cmd[vlen] = '\n';
              vlen++;
            }
          if (strncmp(&cmd[nloff], "builtin_", 8) == 0)
            {
              /* ??? */
              child->pid = 270163;
              child->efn = 0;
              child->cstatus = 1;

              DB (DB_JOBS, (_("BUILTIN [%s][%s]\n"), &cmd[nloff], &cmd[nloff+8]));
              p = &cmd[nloff + 8];
              if ((*(p) ==        'e')
                  && (*(p + 1) == 'c')
                  && (*(p + 2) == 'h')
                  && (*(p + 3) == 'o')
                  && ((*(p + 4) == ' ') || (*(p + 4) == '\t') || (*(p + 4) == '\0')))
                {
                  if (clen < nloff - 1)
                    {
                      memcpy(&tmp_cmd[vlen], &cmd[clen], nloff - clen - 1);
                      vlen += nloff - clen - 1;
                      clen = nloff;
                      if (inecho)
                        {
                          inecho = 0;
                          tmp_cmd[vlen] = '"';
                          vlen++;
                        }
                      tmp_cmd[vlen] = '\n';
                      vlen++;
                    }
                  inecho = 1;
                  p += 4;
                  while ((*p == ' ') || (*p == '\t'))
                    p++;
                  clen = p - cmd;
                  memcpy(&tmp_cmd[vlen], VMS_EMPTY_ECHO,
                      sizeof VMS_EMPTY_ECHO - 2);
                  vlen += sizeof VMS_EMPTY_ECHO - 2;
                }
              else
                {
                  printf (_("Builtin command is unknown or unsupported in .ONESHELL: '%s'\n"), &cmd[nloff]);
                  fflush(stdout);
                  return 0;
                }
            }
          nloff = nextnl(cmd, nloff + 1);
        }
      if (clen < nloff)
        {
          memcpy(&tmp_cmd[vlen], &cmd[clen], nloff - clen);
          vlen += nloff - clen;
          clen = nloff;
          if (inecho)
            {
              inecho = 0;
              tmp_cmd[vlen] = '"';
              vlen++;
            }
        }

      tmp_cmd[vlen] = '\0';

      cmd = tmp_cmd;
    }

  /* Enforce the creation of a command file if "vms_always_use_cmd_file" is
     non-zero.
     Then all the make environment variables are written as DCL symbol
     assignments into the command file as well, so that they are visible
     in the sub-process but do not affect the current process.
     Further, this way DCL reads the input stream and therefore does
     'forced' symbol substitution, which it doesn't do for one-liners when
     they are 'lib$spawn'ed. */

  /* Otherwise the behavior is: */
  /* Create a *.com file if either the command is too long for
     lib$spawn, or the command contains a newline, or if redirection
     is desired. Forcing commands with newlines into DCLs allows to
     store search lists on user mode logicals.  */
  if (vms_always_use_cmd_file || strlen (cmd) > (MAX_DCL_LINE_LENGTH - 30)
      || (have_redirection != 0)
      || (have_newline != 0))
    {
      FILE *outfile;
      char c;
      char *sep;
      int alevel = 0;   /* apostrophe level */
      int tmpstrlen;
      char *tmpstr;
      if (strlen (cmd) == 0)
        {
          printf (_("Error, empty command\n"));
          fflush (stdout);
          return 0;
        }

      outfile = output_tmpfile (&child->comname, "sys$scratch:CMDXXXXXX.COM");
      /*                                          012345678901234567890 */
#define TMP_OFFSET 12
#define TMP_LEN 9
      if (outfile == 0)
        pfatal_with_name (_("fopen (temporary file)"));
      comnamelen = strlen (child->comname);
      tmpstr = &child->comname[TMP_OFFSET];
      tmpstrlen = TMP_LEN;
      /* The whole DCL "script" is executed as one action, and it behaves as
         any DCL "script", that is errors stop it but warnings do not. Usually
         the command on the last line, defines the exit code.  However, with
