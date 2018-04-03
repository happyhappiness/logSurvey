                if len(filesToDelete):
                    print "The following files should be scheduled for deletion with p4 delete:"
                    print " ".join(filesToDelete)
                die("Please resolve and submit the conflict manually and continue afterwards with git-p4 submit --continue")
            elif response == "w":
                system(diffcmd + " > patch.txt")
                print "Patch saved to patch.txt in %s !" % self.clientPath
                die("Please resolve and submit the conflict manually and continue afterwards with git-p4 submit --continue")

        system(applyPatchCmd)

