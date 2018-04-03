            else:
                die("unknown modifier %s for %s" % (modifier, path))

        system("git diff-tree -p --diff-filter=ACMRTUXB \"%s^\" \"%s\" | patch -p1" % (id, id))

        for f in filesToAdd:
            system("p4 add %s" % f)
