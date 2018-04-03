          break;
        case FT_UNKNOWN:
          logprintf (LOG_NOTQUIET, _("%s: unknown/unsupported file type.\n"),
                     quotearg_style (escape_quoting_style, f->name));
          break;
        }       /* switch */

src/ChangeLog | 4 ++++
src/main.c    | 5 +++--
2 files changed, 7 insertions(+), 2 deletions(-)
