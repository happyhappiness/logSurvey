    if isValidGitDir(gitdir + "/.git"):
        gitdir += "/.git"
    else:
        dir("fatal: cannot locate git repository at %s" % gitdir)

os.environ["GIT_DIR"] = gitdir
