            if (!strchr(in_org, '@') && !strchr(*out, '@'))
              debug_logprintf ("converted '%s' (%s) -> '%s' (%s)\n", in_org, fromcode, *out, tocode);
            else
              debug_logprintf ("%s: logging suppressed, strings may contain password\n", __func__);
          }
          return true;
        }
