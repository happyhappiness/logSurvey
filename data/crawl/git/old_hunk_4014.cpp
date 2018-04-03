
        # Use time from top-most change so that all git p4 clones of
        # the same p4 repo have the same commit SHA1s.
        res = p4CmdList("describe -s %d" % newestRevision)
        newestTime = None
        for r in res:
            if r.has_key('time'):
                newestTime = int(r['time'])
        if newestTime is None:
            die("\"describe -s\" on newest change %d did not give a time")
        details["time"] = newestTime

        self.updateOptionDict(details)
        try: