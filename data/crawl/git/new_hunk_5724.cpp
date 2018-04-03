                filesForCommit.append(f)
                if f['action'] not in ('delete', 'purge'):
                    filesToRead.append(f)
                else:
                    filesToDelete.append(f)

        # deleted files...
        for f in filesToDelete:
            self.streamOneP4Deletion(f)

        if len(filesToRead) > 0:
            self.stream_file = {}
            self.stream_contents = []
            self.stream_have_file_info = False

	    # curry self argument
	    def streamP4FilesCbSelf(entry):
		self.streamP4FilesCb(entry)

	    p4CmdList("-x - print",
		'\n'.join(['%s#%s' % (f['path'], f['rev'])
                                                  for f in filesToRead]),
	        cb=streamP4FilesCbSelf)

            # do the last chunk
            if self.stream_file.has_key('depotFile'):
                self.streamOneP4File(self.stream_file, self.stream_contents)

    def commit(self, details, files, branch, branchPrefixes, parent = ""):
        epoch = details["time"]
        author = details["user"]
	self.branchPrefixes = branchPrefixes

        if self.verbose:
            print "commit into %s" % branch
