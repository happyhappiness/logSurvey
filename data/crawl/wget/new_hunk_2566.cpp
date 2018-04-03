
      /* Parse the line.  */
      switch (parse_line (line, &com, &val, &comind))
        {
        case line_ok:
          /* If everything is OK, set the value.  */
          if (!setval_internal (comind, com, val))
            {
              fprintf (stderr, _("%s: Error in %s at line %d.\n"),
                       exec_name, file, ln);
              ++errcnt;
            }
          break;
        case line_syntax_error:
          fprintf (stderr, _("%s: Syntax error in %s at line %d.\n"),
                   exec_name, file, ln);
          ++errcnt;
          break;
        case line_unknown_command:
          fprintf (stderr, _("%s: Unknown command `%s' in %s at line %d.\n"),
                   exec_name, com, file, ln);
          ++errcnt;
          break;
        case line_empty:
          break;
        default:
          abort ();
        }
      xfree_null (com);
      xfree_null (val);
      xfree (line);
