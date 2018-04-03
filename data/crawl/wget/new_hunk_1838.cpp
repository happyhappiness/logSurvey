          break;
        case FT_UNKNOWN:
          logprintf (LOG_NOTQUIET, _("%s: unknown/unsupported file type.\n"),
                     quote (f->name));
          break;
        }       /* switch */

