            else:
                die("unknown modifier %s for %s" % (modifier, path))

        diffcmd = "git diff-tree -p --diff-filter=ACMRTUXB \"%s^\" \"%s\"" % (id, id)
        patchcmd = diffcmd + " | patch -p1"

        if os.system(patchcmd + " --dry-run --silent") != 0:
            print "Unfortunately applying the change failed!"
            print "What do you want to do?"
            response = "x"
            while response != "s" and response != "a" and response != "w":
                response = raw_input("[s]kip this patch / [a]pply the patch forcibly and with .rej files / [w]rite the patch to a file (patch.txt) ")
            if response == "s":
                print "Skipping! Good luck with the next patches..."
                return
            elif response == "a":
                os.system(patchcmd)
                if len(filesToAdd) > 0:
                    print "You may also want to call p4 add on the following files:"
                    print " ".join(filesToAdd)
                if len(filesToDelete):
                    print "The following files should be scheduled for deletion with p4 delete:"
                    print " ".join(filesToDelete)
                die("Please resolve and submit the conflict manually and continue afterwards with git-p4 submit --continue")
            elif response == "w":
                system(diffcmd + " > patch.txt")
                print "Patch saved to patch.txt in %s !" % self.clientPath
                die("Please resolve and submit the conflict manually and continue afterwards with git-p4 submit --continue")

        system(patchcmd)

        for f in filesToAdd:
            system("p4 add %s" % f)
