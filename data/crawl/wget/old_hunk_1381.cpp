          ++errcnt;
          break;
        case line_unknown_command:
          fprintf (stderr, _("%s: Unknown command `%s' in %s at line %d.\n"),
                   exec_name, com, file, ln);
          ++errcnt;
          break;
        case line_empty:
