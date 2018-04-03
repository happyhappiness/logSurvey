    def run(self, args):
        sync = P4Sync()
        sync.run([])
        print "Rebasing the current branch"
        oldHead = read_pipe("git rev-parse HEAD").strip()
        system("git rebase p4")
        system("git diff-tree --stat --summary -M %s HEAD" % oldHead)
        return True
