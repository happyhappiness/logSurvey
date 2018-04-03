    # handle another chunk of streaming data
    def streamP4FilesCb(self, marshalled):

        # catch p4 errors and complain
        err = None
        if "code" in marshalled:
            if marshalled["code"] == "error":
                if "data" in marshalled:
                    err = marshalled["data"].rstrip()
        if err:
            f = None
            if self.stream_have_file_info:
                if "depotFile" in self.stream_file:
                    f = self.stream_file["depotFile"]
            # force a failure in fast-import, else an empty
            # commit will be made
            self.gitStream.write("\n")
            self.gitStream.write("die-now\n")
            self.gitStream.close()
            # ignore errors, but make sure it exits first
            self.importProcess.wait()
            if f:
                die("Error from p4 print for %s: %s" % (f, err))
            else:
                die("Error from p4 print: %s" % err)

        if marshalled.has_key('depotFile') and self.stream_have_file_info:
            # start of a new file - output the old one first
            self.streamOneP4File(self.stream_file, self.stream_contents)
