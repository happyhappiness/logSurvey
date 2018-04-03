      if (!strchr(in_org, '@') && !strchr(*out, '@'))
        debug_logprintf ("converted '%s' (%s) -> '%s' (%s)\n", in_org, fromcode, *out, tocode);
      else
        debug_logprintf ("logging suppressed, strings may contain password\n");
    }
    return false;
}
