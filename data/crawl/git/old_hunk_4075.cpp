            if not self.canChangeChangelists():
                die("Cannot preserve user names without p4 super-user or admin permissions")

        if self.verbose:
            print "Origin branch is " + self.origin

