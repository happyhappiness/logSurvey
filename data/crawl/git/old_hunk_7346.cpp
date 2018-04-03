
    ## Should move this out, doesn't use SELF.
    def readP4Files(self, files):
        for f in files:
            for val in self.clientSpecDirs:
                if f['path'].startswith(val[0]):
                    if val[1] > 0:
                        f['include'] = True
                    else:
                        f['include'] = False
                    break

        files = [f for f in files
                 if f['action'] != 'delete' and
                 (f.has_key('include') == False or f['include'] == True)]

        if not files:
            return []

        filedata = p4CmdList('-x - print',
                             stdin='\n'.join(['%s#%s' % (f['path'], f['rev'])
                                              for f in files]),
                             stdin_mode='w+')
        if "p4ExitCode" in filedata[0]:
            die("Problems executing p4. Error: [%d]."
                % (filedata[0]['p4ExitCode']));

        j = 0;
        contents = {}
