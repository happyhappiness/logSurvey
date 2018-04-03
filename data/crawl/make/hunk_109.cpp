     argv++;
 
   if (*argv == 0)
-    return 0;
+    {
+      /* Only a built-in or a null command - Still need to run term AST */
+      child->cstatus = VMS_POSIX_EXIT_MASK;
+      child->vms_launch_status = SS$_NORMAL;
+      /* TODO what is this "magic number" */
+      child->pid = 270163; /* Special built-in */
+      child->efn = 0;
+      vmsHandleChildTerm (child);
+      return 1;
+    }
 
   sprintf (procname, "GMAKE_%05x", getpid () & 0xfffff);
-  pnamedsc.dsc$w_length = strlen(procname);
+  pnamedsc.dsc$w_length = strlen (procname);
   pnamedsc.dsc$a_pointer = procname;
   pnamedsc.dsc$b_dtype = DSC$K_DTYPE_T;
   pnamedsc.dsc$b_class = DSC$K_CLASS_S;
 
-  in_string = 0;
+  /* Old */
   /* Handle comments and redirection.
      For ONESHELL, the redirection must be on the first line. Any other
      redirection token is handled by DCL, that is, the pipe command with
      redirection can be used, but it should not be used on the first line
      for ONESHELL. */
-  for (p = argv, q = cmd; *p; p++, q++)
+
+  /* VMS parser notes:
+     1. A token is any of DCL verbs, qualifiers, parameters, or punctuation.
+     2. Only MAX_DCL_TOKENS per line in both one line or command file mode.
+     3. Each token limited to MAC_DCL_TOKEN_LENGTH
+     4. If the line to DCL is greater than MAX_DCL_LINE_LENGTH then a
+        command file must be used.
+     5. Currently a command file must be used symbol substitution is to
+        be performed.
+     6. Currently limiting command files to 2 * MAX_DCL_TOKENS.
+
+     Build both a command file token list and command line token list
+     until it is determined that the command line limits are exceeded.
+  */
+
+  cmd_tkn_index = 0;
+  cmd_tokens[cmd_tkn_index] = NULL;
+  p = argv;
+
+  token.text = token_str;
+  token.length = 0;
+  token.cmd_errno = 0;
+  token.use_cmd_file = 0;
+
+  while (*p != 0)
     {
-      if (*p == '"')
-        in_string = !in_string;
-      if (in_string)
-        {
-          *q = *p;
-          continue;
-        }
+      /* We can not build this command so give up */
+      if (token.cmd_errno != 0)
+        break;
+
+      token.src = p;
+
       switch (*p)
         {
-        case '#':
-          *p-- = 0;
-          *q-- = 0;
+        case '\'':
+          if (vms_unix_simulation || unix_echo_cmd)
+            {
+              p = posix_parse_sq (&token);
+              UPDATE_TOKEN;
+              break;
+            }
+
+          /* VMS mode, the \' means that a symbol substitution is starting
+             so while you might think you can just copy until the next
+             \'.  Unfortunately the substitution can be a lexical function
+             which can contain embedded strings and lexical functions.
+             Messy.
+          */
+          p = vms_parse_quotes (&token);
+          UPDATE_TOKEN;
+          break;
+        case '"':
+          if (vms_unix_simulation)
+            {
+              p = posix_parse_dq (&token);
+              UPDATE_TOKEN;
+              break;
+            }
+
+          /* VMS quoted string, can contain lexical functions with
+             quoted strings and nested lexical functions.
+          */
+          p = vms_parse_quotes (&token);
+          UPDATE_TOKEN;
+          break;
+
+        case '$':
+          if (vms_unix_simulation)
+            {
+              p = posix_parse_dollar (&token);
+              UPDATE_TOKEN;
+              break;
+            }
+
+          /* Otherwise nothing special */
+          p = parse_text (&token, 0);
+          UPDATE_TOKEN;
           break;
         case '\\':
-          p++;
-          if (*p == '\n')
+          if (p[1] == '\n')
+            {
+              /* Line continuation, remove it */
+              p += 2;
+              break;
+            }
+
+          /* Ordinary character otherwise */
+          if (assignment_hack != 0)
+            assignment_hack++;
+          if (assignment_hack > 2)
+            {
+              assignment_hack = 0;          /* Reset */
+              if (use_pipe_cmd == nopipe)   /* force pipe use */
+                use_pipe_cmd = add_pipe;
+              token_str[0] = ';';              /* add ; token */
+              token_str[1] = 0;
+              UPDATE_TOKEN;
+            }
+          p = parse_text (&token, assignment_hack);
+          UPDATE_TOKEN;
+          break;
+        case '!':
+        case '#':
+          /* Unix '#' is VMS '!' which comments out the rest of the line.
+             Historically the rest of the line has been skipped.
+             Not quite the right thing to do, as the f$verify lexical
+             function works in comments.  But this helps keep the line
+             lengths short.
+          */
+          unix_echo_cmd = 0;
+          while (*p != '\n' && *p != 0)
             p++;
-          if (isspace ((unsigned char)*p))
+          break;
+        case '(':
+          /* Subshell, equation, or lexical function argument start */
+          p = parse_char (&token, 1);
+          UPDATE_TOKEN;
+          paren_level++;
+          break;
+        case ')':
+          /* Close out a paren level */
+          p = parse_char (&token, 1);
+          UPDATE_TOKEN;
+          paren_level--;
+          /* TODO: Should we diagnose if paren_level goes negative? */
+          break;
+        case '&':
+          if (isalpha (p[1]) && !vms_unix_simulation)
             {
-              do { p++; } while (isspace ((unsigned char)*p));
-              p--;
+              /* VMS symbol substitution */
+              p = parse_text (&token, 0);
+              token.use_cmd_file = 1;
+              UPDATE_TOKEN;
+              break;
             }
-          *q = *p;
+          if (use_pipe_cmd == nopipe)
+            use_pipe_cmd = add_pipe;
+          if (p[1] != '&')
+            p = parse_char (&token, 1);
+          else
+            p = parse_char (&token, 2);
+          UPDATE_TOKEN;
+          break;
+        case '|':
+          if (use_pipe_cmd == nopipe)
+            use_pipe_cmd = add_pipe;
+          if (p[1] != '|')
+            p = parse_char (&token, 1);
+          else
+            p = parse_char (&token, 2);
+          UPDATE_TOKEN;
           break;
+        case ';':
+          /* Separator - convert to a pipe command. */
+          unix_echo_cmd = 0;
         case '<':
-          if (have_newline==0)
+          if (use_pipe_cmd == nopipe)
+            use_pipe_cmd = add_pipe;
+          p = parse_char (&token, 1);
+          UPDATE_TOKEN;
+          break;
+        case '>':
+          if (use_pipe_cmd == nopipe)
+            use_pipe_cmd = add_pipe;
+          if (p[1] == '>')
             {
-              p = vms_redirect (&ifiledsc, ifile, p);
-              *q = ' ';
-              have_redirection = 1;
+              /* Parsing would have been simple until support for the >>
+                 append redirect was added.
+                 Implementation needs:
+                 * if not exist output file create empty
+                 * open/append gnv$make_temp??? output_file
+                 * define/user sys$output gnv$make_temp???
+                 ** And all this done before the command previously tokenized.
+                 * command previously tokenized
+                 * close gnv$make_temp???
+              */
+              p = parse_char (&token, 2);
+              append_token = cmd_tkn_index;
+              token.use_cmd_file = 1;
             }
           else
-            *q = *p;
+            p = parse_char (&token, 1);
+          UPDATE_TOKEN;
           break;
-        case '>':
-          if (have_newline==0)
+        case '/':
+          /* Unix path or VMS option start, read until non-path symbol */
+          if (assignment_hack != 0)
+            assignment_hack++;
+          if (assignment_hack > 2)
             {
-              have_redirection = 1;
-              if (*(p-1) == '2')
-                {
-                  q--;
-                  if (strncmp (p, ">&1", 3) == 0)
-                    {
-                      p += 2;
-                      strcpy (efile, "sys$output");
-                      efiledsc.dsc$w_length = strlen(efile);
-                      efiledsc.dsc$a_pointer = efile;
-                      efiledsc.dsc$b_dtype = DSC$K_DTYPE_T;
-                      efiledsc.dsc$b_class = DSC$K_CLASS_S;
-                    }
-                  else
-                    p = vms_redirect (&efiledsc, efile, p);
-                }
-              else
+              assignment_hack = 0;          /* Reset */
+              if (use_pipe_cmd == nopipe)   /* force pipe use */
+                use_pipe_cmd = add_pipe;
+              token_str[0] = ';';              /* add ; token */
+              token_str[1] = 0;
+              UPDATE_TOKEN;
+            }
+          p = parse_text (&token, assignment_hack);
+          UPDATE_TOKEN;
+          break;
+        case ':':
+          if ((p[1] == 0) || isspace (p[1]))
+            {
+              /* Unix Null command - treat as comment until next command */
+              unix_echo_cmd = 0;
+              p++;
+              while (*p != 0)
                 {
-                  if (*(p+1) == '>')
+                  if (*p == ';')
                     {
-                      have_append = 1;
-                      p += 1;
+                      /* Remove Null command from pipeline */
+                      p++;
+                      break;
                     }
-                  p = vms_redirect (&ofiledsc, ofile, p);
+                  p++;
                 }
-              *q = ' ';
+              break;
             }
+
+          /* String assignment */
+          /* := :== or : */
+          if (p[1] != '=')
+            p = parse_char (&token, 1);
+          else if (p[2] != '=')
+            p = parse_char (&token, 2);
           else
-            *q = *p;
+            p = parse_char (&token, 3);
+          UPDATE_TOKEN;
           break;
-        case '\n':
-          have_newline++;
-        default:
-          *q = *p;
+        case '=':
+          /* = or == */
+          /* If this is not an echo statement, this could be a shell
+             assignment.  VMS requires the target to be quoted if it
+             is not a macro substitution */
+          if (!unix_echo_cmd && vms_unix_simulation && (assignment_hack == 0))
+            assignment_hack = 1;
+          if (p[1] != '=')
+            p = parse_char (&token, 1);
+          else
+            p = parse_char (&token, 2);
+          UPDATE_TOKEN;
           break;
-        }
-    }
-  *q = *p;
-  while (isspace ((unsigned char)*--q))
-    *q = '\0';
-
-
-#define VMS_EMPTY_ECHO "write sys$output \"\""
-  if (have_newline == 0)
-    {
-      /* multiple shells */
-      if (strncmp(cmd, "builtin_", 8) == 0)
-        {
-          child->pid = 270163;
-          child->efn = 0;
-          child->cstatus = 1;
-
-          DB(DB_JOBS, (_("BUILTIN [%s][%s]\n"), cmd, cmd + 8));
+        case '+':
+        case '-':
+        case '*':
+          p = parse_char (&token, 1);
+          UPDATE_TOKEN;
+          break;
+        case '.':
+          /* .xxx. operation, VMS does not require the trailing . */
+          p = parse_text (&token, 0);
+          UPDATE_TOKEN;
+          break;
+        default:
+          /* Skip repetitive whitespace */
+          if (isspace (*p))
+            {
+              p = parse_char (&token, 1);
 
-          p = cmd + 8;
+              /* Force to a space or a tab */
+              if ((token_str[0] != ' ') ||
+                  (token_str[0] != '\t'))
+                token_str[0] = ' ';
+              UPDATE_TOKEN;
 
-          if ((*(p) == 'c') && (*(p + 1) == 'd')
-              && ((*(p + 2) == ' ') || (*(p + 2) == '\t')))
-            {
-              p += 3;
-              while ((*p == ' ') || (*p == '\t'))
+              while (isspace (*p))
                 p++;
-              DB(DB_JOBS, (_("BUILTIN CD %s\n"), p));
-              if (chdir(p))
-                return 0;
-              else
-                return 1;
-            }
-          else if ((*(p) == 'e')
-              && (*(p+1) == 'c')
-              && (*(p+2) == 'h')
-              && (*(p+3) == 'o')
-              && ((*(p+4) == ' ') || (*(p+4) == '\t') || (*(p+4) == '\0')))
-            {
-              /* This is not a real builtin, it is a built in pre-processing
-                 for the VMS/DCL echo (write sys$output) to ensure the to be echoed
-                 string is correctly quoted (with the DCL quote character '"'). */
-              char *vms_echo;
-              p += 4;
-              if (*p == '\0')
-                cmd = VMS_EMPTY_ECHO;
-              else
-                {
-                  p++;
-                  while ((*p == ' ') || (*p == '\t'))
-                    p++;
-                  if (*p == '\0')
-                    cmd = VMS_EMPTY_ECHO;
-                  else
-                    {
-                      vms_echo = alloca(strlen(p) + sizeof VMS_EMPTY_ECHO);
-                      strcpy(vms_echo, VMS_EMPTY_ECHO);
-                      vms_echo[sizeof VMS_EMPTY_ECHO - 2] = '\0';
-                      strcat(vms_echo, p);
-                      strcat(vms_echo, "\"");
-                      cmd = vms_echo;
-                    }
-                }
-              DB (DB_JOBS, (_("BUILTIN ECHO %s->%s\n"), p, cmd));
+              if (assignment_hack != 0)
+                assignment_hack++;
+              break;
             }
-          else
+
+          if (assignment_hack != 0)
+            assignment_hack++;
+          if (assignment_hack > 2)
             {
-              printf(_("Unknown builtin command '%s'\n"), cmd);
-              fflush(stdout);
-              return 0;
+              assignment_hack = 0;          /* Reset */
+              if (use_pipe_cmd == nopipe)   /* force pipe use */
+                use_pipe_cmd = add_pipe;
+              token_str[0] = ';';              /* add ; token */
+              token_str[1] = 0;
+              UPDATE_TOKEN;
             }
+          p = parse_text (&token, assignment_hack);
+          if (strncasecmp (token.text, "echo", 4) == 0)
+            unix_echo_cmd = 1;
+          else if (strncasecmp (token.text, "pipe", 4) == 0)
+            use_pipe_cmd = dcl_pipe;
+          UPDATE_TOKEN;
+          break;
         }
-      /* expand ':' aka 'do nothing' builtin for bash and friends */
-      else if (cmd[0]==':')
-        cmd[0] = '!';
     }
-  else
+
+  /* End up here with a list of tokens to build a command line.
+     Deal with errors detected during parsing.
+   */
+  if (token.cmd_errno != 0)
     {
-      /* todo: expand ':' aka 'do nothing' builtin for bash and friends */
-      /* For 'one shell' expand all the
-           builtin_echo
-         to
-           write sys$output ""
-         where one is  ......7 bytes longer.
-         At the same time ensure that the echo string is properly terminated.
-         For that, allocate a command buffer big enough for all possible expansions
-         (have_newline is the count), then expand, copy and terminate. */
-      char *tmp_cmd;
-      int nloff = 0;
-      int vlen = 0;
-      int clen = 0;
-      int inecho;
-
-      tmp_cmd = alloca(strlen(cmd) + (have_newline + 1) * 7 + 1);
-      tmp_cmd[0] = '\0';
-      inecho = 0;
-      while (cmd[nloff])
+      while (cmd_tokens[cmd_tkn_index] == NULL)
+        free (cmd_tokens[cmd_tkn_index++]);
+      child->cstatus = VMS_POSIX_EXIT_MASK | (MAKE_TROUBLE << 3);
+      child->vms_launch_status = SS$_ABORT;
+      /* TODO what is this "magic number" */
+      child->pid = 270163; /* Special built-in */
+      child->efn = 0;
+      errno = token.cmd_errno;
+      return 0;
+    }
+
+  /* Save any redirection to append file */
+  if (append_token != -1)
+    {
+      int file_token;
+      char * lastdot;
+      char * lastdir;
+      char * raw_append_file;
+      file_token = append_token;
+      file_token++;
+      if (isspace (cmd_tokens[file_token][0]))
+        file_token++;
+      raw_append_file = vmsify (cmd_tokens[file_token], 0);
+      /* VMS DCL needs a trailing dot if null file extension */
+      lastdot = strrchr(raw_append_file, '.');
+      lastdir = strrchr(raw_append_file, ']');
+      if (lastdir == NULL)
+        lastdir = strrchr(raw_append_file, '>');
+      if (lastdir == NULL)
+        lastdir = strrchr(raw_append_file, ':');
+      if ((lastdot == NULL) || (lastdot > lastdir))
         {
-          if (inecho)
-            {
-              if (clen < nloff - 1)
-                {
-                  memcpy(&tmp_cmd[vlen], &cmd[clen], nloff - clen - 1);
-                  vlen += nloff - clen - 1;
-                  clen = nloff;
-                }
-              inecho = 0;
-              tmp_cmd[vlen] = '"';
-              vlen++;
-              tmp_cmd[vlen] = '\n';
-              vlen++;
-            }
-          if (strncmp(&cmd[nloff], "builtin_", 8) == 0)
-            {
-              /* ??? */
-              child->pid = 270163;
-              child->efn = 0;
-              child->cstatus = 1;
-
-              DB (DB_JOBS, (_("BUILTIN [%s][%s]\n"), &cmd[nloff], &cmd[nloff+8]));
-              p = &cmd[nloff + 8];
-              if ((*(p) ==        'e')
-                  && (*(p + 1) == 'c')
-                  && (*(p + 2) == 'h')
-                  && (*(p + 3) == 'o')
-                  && ((*(p + 4) == ' ') || (*(p + 4) == '\t') || (*(p + 4) == '\0')))
-                {
-                  if (clen < nloff - 1)
-                    {
-                      memcpy(&tmp_cmd[vlen], &cmd[clen], nloff - clen - 1);
-                      vlen += nloff - clen - 1;
-                      clen = nloff;
-                      if (inecho)
-                        {
-                          inecho = 0;
-                          tmp_cmd[vlen] = '"';
-                          vlen++;
-                        }
-                      tmp_cmd[vlen] = '\n';
-                      vlen++;
-                    }
-                  inecho = 1;
-                  p += 4;
-                  while ((*p == ' ') || (*p == '\t'))
-                    p++;
-                  clen = p - cmd;
-                  memcpy(&tmp_cmd[vlen], VMS_EMPTY_ECHO,
-                      sizeof VMS_EMPTY_ECHO - 2);
-                  vlen += sizeof VMS_EMPTY_ECHO - 2;
-                }
-              else
-                {
-                  printf (_("Builtin command is unknown or unsupported in .ONESHELL: '%s'\n"), &cmd[nloff]);
-                  fflush(stdout);
-                  return 0;
-                }
-            }
-          nloff = nextnl(cmd, nloff + 1);
+          append_file = xmalloc (strlen (raw_append_file) + 1);
+          strcpy (append_file, raw_append_file);
+          strcat (append_file, ".");
         }
-      if (clen < nloff)
+      else
+        append_file = strdup(raw_append_file);
+    }
+
+  cmd_dsc = build_vms_cmd (cmd_tokens, use_pipe_cmd, append_token);
+  if (cmd_dsc->dsc$a_pointer == NULL)
+    {
+      if (cmd_dsc->dsc$w_length < 0)
         {
-          memcpy(&tmp_cmd[vlen], &cmd[clen], nloff - clen);
-          vlen += nloff - clen;
-          clen = nloff;
-          if (inecho)
-            {
-              inecho = 0;
-              tmp_cmd[vlen] = '"';
-              vlen++;
-            }
+          free (cmd_dsc);
+          child->cstatus = VMS_POSIX_EXIT_MASK | (MAKE_TROUBLE << 3);
+          child->vms_launch_status = SS$_ABORT;
+          /* TODO what is this "magic number" */
+          child->pid = 270163; /* Special built-in */
+          child->efn = 0;
+          return 0;
         }
 
-      tmp_cmd[vlen] = '\0';
-
-      cmd = tmp_cmd;
+      /* Only a built-in or a null command - Still need to run term AST */
+      free (cmd_dsc);
+      child->cstatus = VMS_POSIX_EXIT_MASK;
+      child->vms_launch_status = SS$_NORMAL;
+      /* TODO what is this "magic number" */
+      child->pid = 270163; /* Special built-in */
+      child->efn = 0;
+      vmsHandleChildTerm (child);
+      return 1;
     }
 
+  if (cmd_dsc->dsc$w_length > MAX_DCL_LINE_LENGTH)
+    token.use_cmd_file = 1;
+
+  DB(DB_JOBS, (_("DCL: %s\n"), cmd_dsc->dsc$a_pointer));
+
   /* Enforce the creation of a command file if "vms_always_use_cmd_file" is
      non-zero.
-     Then all the make environment variables are written as DCL symbol
-     assignments into the command file as well, so that they are visible
-     in the sub-process but do not affect the current process.
      Further, this way DCL reads the input stream and therefore does
      'forced' symbol substitution, which it doesn't do for one-liners when
-     they are 'lib$spawn'ed. */
+     they are 'lib$spawn'ed.
+
+     Otherwise the behavior is:
+
+     Create a *.com file if either the command is too long for
+     lib$spawn, or if a redirect appending to a file is desired, or
+     symbol substitition.
+  */
 
-  /* Otherwise the behavior is: */
-  /* Create a *.com file if either the command is too long for
-     lib$spawn, or the command contains a newline, or if redirection
-     is desired. Forcing commands with newlines into DCLs allows to
-     store search lists on user mode logicals.  */
-  if (vms_always_use_cmd_file || strlen (cmd) > (MAX_DCL_LINE_LENGTH - 30)
-      || (have_redirection != 0)
-      || (have_newline != 0))
+  if (vms_always_use_cmd_file || token.use_cmd_file)
     {
       FILE *outfile;
-      char c;
-      char *sep;
-      int alevel = 0;   /* apostrophe level */
-      int tmpstrlen;
-      char *tmpstr;
-      if (strlen (cmd) == 0)
-        {
-          printf (_("Error, empty command\n"));
-          fflush (stdout);
-          return 0;
-        }
+      int cmd_len;
 
-      outfile = output_tmpfile (&child->comname, "sys$scratch:CMDXXXXXX.COM");
+      outfile = output_tmpfile (&child->comname,
+                                "sys$scratch:gnv$make_cmdXXXXXX.com");
       /*                                          012345678901234567890 */
-#define TMP_OFFSET 12
-#define TMP_LEN 9
       if (outfile == 0)
         pfatal_with_name (_("fopen (temporary file)"));
       comnamelen = strlen (child->comname);
-      tmpstr = &child->comname[TMP_OFFSET];
-      tmpstrlen = TMP_LEN;
+
       /* The whole DCL "script" is executed as one action, and it behaves as
          any DCL "script", that is errors stop it but warnings do not. Usually
          the command on the last line, defines the exit code.  However, with
