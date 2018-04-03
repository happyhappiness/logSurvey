    if isValidGitDir(gitdir + "/.git"):
        gitdir += "/.git"
    else:
        die("fatal: cannot locate git repository at %s" % gitdir)

os.environ["GIT_DIR"] = gitdir
