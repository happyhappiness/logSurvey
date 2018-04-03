
    ## Should move this out, doesn't use SELF.
    def readP4Files(self, files):
        filesForCommit = []
        filesToRead = []

        for f in files:
            includeFile = True
            for val in self.clientSpecDirs:
                if f['path'].startswith(val[0]):
                    if val[1] <= 0:
                        includeFile = False
                    break

            if includeFile:
                filesForCommit.append(f)
                if f['action'] != 'delete':
                    filesToRead.append(f)

        filedata = []
        if len(filesToRead) > 0:
            filedata = p4CmdList('-x - print',
                                 stdin='\n'.join(['%s#%s' % (f['path'], f['rev'])
                                                  for f in filesToRead]),
                                 stdin_mode='w+')

            if "p4ExitCode" in filedata[0]:
                die("Problems executing p4. Error: [%d]."
                    % (filedata[0]['p4ExitCode']));

        j = 0;
        contents = {}
