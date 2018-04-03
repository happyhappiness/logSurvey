            else:
                # catch "git p4 sync" with no new branches, in a repo that
                # does not have any existing p4 branches
                if len(args) == 0 and not self.p4BranchesInGit:
                    die("No remote p4 branches.  Perhaps you never did \"git p4 clone\" in here.");
                if self.verbose:
                    print "Getting p4 changes for %s...%s" % (', '.join(self.depotPaths),
                                                              self.changeRange)
