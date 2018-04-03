            else:
                # catch "git p4 sync" with no new branches, in a repo that
                # does not have any existing p4 branches
                if len(args) == 0:
                    if not self.p4BranchesInGit:
                        die("No remote p4 branches.  Perhaps you never did \"git p4 clone\" in here.")

                    # The default branch is master, unless --branch is used to
                    # specify something else.  Make sure it exists, or complain
                    # nicely about how to use --branch.
                    if not self.detectBranches:
                        if not branch_exists(self.branch):
                            if branch_arg_given:
                                die("Error: branch %s does not exist." % self.branch)
                            else:
                                die("Error: no branch %s; perhaps specify one with --branch." %
                                    self.branch)

                if self.verbose:
                    print "Getting p4 changes for %s...%s" % (', '.join(self.depotPaths),
                                                              self.changeRange)
