

    def getClientSpec(self):
        specList = p4CmdList("client -o")
        if len(specList) != 1:
            die('Output from "client -o" is %d lines, expecting 1' %
                len(specList))

        # dictionary of all client parameters
        entry = specList[0]

        # just the keys that start with "View"
        view_keys = [ k for k in entry.keys() if k.startswith("View") ]

        # hold this new View
        view = View()

        # append the lines, in order, to the view
        for view_num in range(len(view_keys)):
            k = "View%d" % view_num
            if k not in view_keys:
                die("Expected view key %s missing" % k)
            view.append(entry[k])

        self.clientSpecDirs = view
        if self.verbose:
            for i, m in enumerate(self.clientSpecDirs.mappings):
                    print "clientSpecDirs %d: %s" % (i, str(m))

    def run(self, args):
        self.depotPaths = []
