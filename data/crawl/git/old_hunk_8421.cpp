        result.update(entry)
    return result;

try:
    opts, args = getopt.getopt(sys.argv[1:], "", [ "continue", "git-dir=", "origin=", "reset", "master=",
                                                   "submit-log-subst=", "log-substitutions=", "interactive",
