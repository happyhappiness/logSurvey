        if not patch_succeeded:
            print "What do you want to do?"
            response = "x"
            while response != "s":
                response = raw_input("[s]kip this patch ")
            if response == "s":
                print "Skipping! Good luck with the next patches..."
                for f in editedFiles:
                    p4_revert(f)
                for f in filesToAdd:
                    os.remove(f)
                return False

        system(applyPatchCmd)
