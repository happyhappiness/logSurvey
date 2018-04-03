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
      else if (cmd[0]==':' && cmd[1]=='\0')
        {
          cmd = "continue";
        }
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
  /* Create a *.com file if either the command is too long for
     lib$spawn, or the command contains a newline, or if redirection
     is desired. Forcing commands with newlines into DCLs allows to
