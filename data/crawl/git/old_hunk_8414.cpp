
    (cmd, args) = parser.parse_args(sys.argv[2:], cmd);

gitdir = cmd.gitdir
if len(gitdir) == 0:
    gitdir = ".git"
    if not isValidGitDir(gitdir):
        cdup = os.popen("git rev-parse --show-cdup").read()[:-1]
        if isValidGitDir(cdup + "/" + gitdir):
            os.chdir(cdup)

if not isValidGitDir(gitdir):
    if isValidGitDir(gitdir + "/.git"):
        gitdir += "/.git"
    else:
        die("fatal: cannot locate git repository at %s" % gitdir)

os.environ["GIT_DIR"] = gitdir

if not cmd.run(args):
    parser.print_help()