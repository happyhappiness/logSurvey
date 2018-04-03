    global verbose
    verbose = cmd.verbose
    if cmd.needsGit:
        gitdir = cmd.gitdir
        if len(gitdir) == 0:
            gitdir = ".git"
            if not isValidGitDir(gitdir):
                gitdir = read_pipe("git rev-parse --git-dir").strip()
                if os.path.exists(gitdir):
                    cdup = read_pipe("git rev-parse --show-cdup").strip()
                    if len(cdup) > 0:
                        os.chdir(cdup);

        if not isValidGitDir(gitdir):
            if isValidGitDir(gitdir + "/.git"):
                gitdir += "/.git"
            else:
                die("fatal: cannot locate git repository at %s" % gitdir)

        os.environ["GIT_DIR"] = gitdir

    if not cmd.run(args):
        parser.print_help()