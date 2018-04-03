 	    }
 	  else if (cmdleft != 0)
 	    /* Found one.  Cut the line short there before expanding it.  */
-	    *cmdleft = '\0';
+	    *(cmdleft++) = '\0';
 
 	  collapse_continuations (lb.buffer);
 
-	  /* Expand variable and function references before doing anything
-	     else so that special characters can be inside variables.  */
-	  p = variable_expand (lb.buffer);
-
-	  if (cmdleft == 0)
-	    /* Look for a semicolon in the expanded line.  */
-	    cmdleft = find_char_unquote (p, ";", 0);
+	  /* We can't expand the entire line, since if it's a per-target
+             variable we don't want to expand it.  So, walk from the
+             beginning, expanding as we go, and looking for "interesting"
+             chars.  The first word is always expandable.  */
+          wtype = get_next_mword(lb.buffer, NULL, &lb_next, &len);
+          switch (wtype)
+            {
+            case w_eol:
+              if (cmdleft != 0)
+                makefile_fatal (filename, lineno,
+                                "missing rule before commands");
+              else
+                /* This line contained a variable reference that
+                   expanded to nothing but whitespace.  */
+                continue;
+
+            case w_colon:
+            case w_dcolon:
+              /* We accept and ignore rules without targets for
+                 compatibility with SunOS 4 make.  */
+              no_targets = 1;
+              continue;
+
+            default:
+              break;
+            }
 
-	  if (cmdleft != 0)
-	    /* Cut the line short at the semicolon.  */
-	    *cmdleft = '\0';
+          p2 = variable_expand_string(NULL, lb_next, len);
+          while (1)
+            {
+              char *colonp;
+
+              lb_next += len;
+              if (cmdleft == 0)
+                {
+                  /* Look for a semicolon in the expanded line.  */
+                  cmdleft = find_char_unquote (p2, ";", 0);
+
+                  if (cmdleft != 0)
+                    {
+                      unsigned long p2_off = p2 - variable_buffer;
+                      unsigned long cmd_off = cmdleft - variable_buffer;
+                      char *pend = p2 + strlen(p2);
+
+                      /* Append any remnants of lb, then cut the line short
+                         at the semicolon.  */
+                      *cmdleft = '\0';
+
+                      /* One school of thought says that you shouldn't expand
+                         here, but merely copy, since now you're beyond a ";"
+                         and into a command script.  However, the old parser
+                         expanded the whole line, so we continue that for
+                         backwards-compatiblity.  Also, it wouldn't be
+                         entirely consistent, since we do an unconditional
+                         expand below once we know we don't have a
+                         target-specific variable. */
+                      (void)variable_expand_string(pend, lb_next, -1);
+                      lb_next += strlen(lb_next);
+                      p2 = variable_buffer + p2_off;
+                      cmdleft = variable_buffer + cmd_off + 1;
+                    }
+                }
+
+              colonp = find_char_unquote(p2, ":", 0);
+#if defined(__MSDOS__) || defined(WINDOWS32)
+	      /* The drive spec brain-damage strikes again...  */
+	      /* FIXME: is whitespace the only possible separator of words
+		 in this context?  If not, the `isspace' test below will
+		 need to be changed into a call to `index'.  */
+	      while (colonp && (colonp[1] == '/' || colonp[1] == '\\') &&
+		     colonp > p2 && isalpha(colonp[-1]) &&
+		     (colonp == p2 + 1 || isspace(colonp[-2])))
+		colonp = find_char_unquote(colonp + 1, ":", 0);
+#endif
+              if (colonp != 0)
+                break;
+
+              wtype = get_next_mword(lb_next, NULL, &lb_next, &len);
+              if (wtype == w_eol)
+                makefile_fatal (filename, lineno, "missing separator");
+
+              p2 += strlen(p2);
+              *(p2++) = ' ';
+              p2 = variable_expand_string(p2, lb_next, len);
+              /* We don't need to worry about cmdleft here, because if it was
+                 found in the variable_buffer the entire buffer has already
+                 been expanded... we'll never get here.  */
+            }
 
-	  p2 = next_token (p);
-	  if (*p2 == '\0')
-	    {
-	      if (cmdleft != 0)
-		makefile_fatal (filename, lineno,
-				"missing rule before commands");
-	      else
-		/* This line contained a variable reference that
-		   expanded to nothing but whitespace.  */
-		continue;
-	    }
-	  else if (*p2 == ':')
-	    {
-	      /* We accept and ignore rules without targets for
-		 compatibility with SunOS 4 make.  */
-	      no_targets = 1;
-	      continue;
-	    }
+	  p2 = next_token (variable_buffer);
 
 	  filenames = multi_glob (parse_file_seq (&p2, ':',
 						  sizeof (struct nameseq),
 						  1),
 				  sizeof (struct nameseq));
-	  if (*p2++ == '\0')
-	    makefile_fatal (filename, lineno, "missing separator");
+
+          if (!filenames)
+            {
+              /* We accept and ignore rules without targets for
+                 compatibility with SunOS 4 make.  */
+              no_targets = 1;
+              continue;
+            }
+          /* This should never be possible; we handled it above.  */
+	  assert(*p2 != '\0');
+          ++p2;
+
 	  /* Is this a one-colon or two-colon entry?  */
 	  two_colon = *p2 == ':';
 	  if (two_colon)
 	    p2++;
 
+          /* Test to see if it's a target-specific variable.  Copy the rest
+             of the buffer over, possibly temporarily (we'll expand it later
+             if it's not a target-specific variable).  PLEN saves the length
+             of the unparsed section of p2, for later.  */
+          if (*lb_next != '\0')
+            {
+              unsigned int l = p2 - variable_buffer;
+              plen = strlen(p2);
+              (void)variable_buffer_output(p2+plen,
+                                           lb_next, strlen(lb_next)+1);
+              p2 = variable_buffer + l;
+            }
+          wtype = get_next_mword(p2, NULL, &p, &len);
+          v_origin = o_file;
+          if (wtype == w_static && (len == (sizeof("override")-1)
+                                    && !strncmp(p, "override", len)))
+            {
+              v_origin = o_override;
+              (void)get_next_mword(p+len, NULL, &p, &len);
+            }
+          else if (wtype != w_eol)
+            wtype = get_next_mword(p+len, NULL, NULL, NULL);
+
+          if (wtype == w_varassign || v_origin == o_override)
+            {
+              record_target_var(filenames, p, two_colon, v_origin,
+                                filename, lineno);
+              filenames = 0;
+              continue;
+            }
+
+          /* This is a normal target, _not_ a target-specific variable.
+             Unquote any = in the dependency list.  */
+          find_char_unquote (lb_next, "=", 0);
+
 	  /* We have some targets, so don't ignore the following commands.  */
 	  no_targets = 0;
 
+          /* Expand the dependencies, etc.  */
+          if (*lb_next != '\0')
+            {
+              unsigned int l = p2 - variable_buffer;
+              (void)variable_expand_string(p2 + plen, lb_next, -1);
+              p2 = variable_buffer + l;
+
+              /* Look for a semicolon in the expanded line.  */
+              if (cmdleft == 0)
+                {
+                  cmdleft = find_char_unquote (p2, ";", 0);
+                  if (cmdleft != 0)
+                    *(cmdleft++) = '\0';
+                }
+            }
+
 	  /* Is this a static pattern rule: `target: %targ: %dep; ...'?  */
 	  p = index (p2, ':');
 	  while (p != 0 && p[-1] == '\\')
