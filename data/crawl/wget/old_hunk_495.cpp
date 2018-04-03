                 severity, quote (common_name), quote (host));
      success = false;
    }

  if (success)
    DEBUGP (("X509 certificate successfully verified and matches host %s\n",
