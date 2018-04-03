                filesForCommit.append(f)
                if f['action'] not in ('delete', 'purge'):
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
        while j < len(filedata):
            stat = filedata[j]
            j += 1
            text = ''
            while j < len(filedata) and filedata[j]['code'] in ('text', 'unicode', 'binary'):
                text += filedata[j]['data']
                del filedata[j]['data']
                j += 1

            if not stat.has_key('depotFile'):
                sys.stderr.write("p4 print fails with: %s\n" % repr(stat))
                continue

            if stat['type'] in ('text+ko', 'unicode+ko', 'binary+ko'):
                text = re.sub(r'(?i)\$(Id|Header):[^$]*\$',r'$\1$', text)
            elif stat['type'] in ('text+k', 'ktext', 'kxtext', 'unicode+k', 'binary+k'):
                text = re.sub(r'\$(Id|Header|Author|Date|DateTime|Change|File|Revision):[^$\n]*\$',r'$\1$', text)

            contents[stat['depotFile']] = text

        for f in filesForCommit:
            path = f['path']
            if contents.has_key(path):
                f['data'] = contents[path]

        return filesForCommit

    def commit(self, details, files, branch, branchPrefixes, parent = ""):
        epoch = details["time"]
        author = details["user"]

        if self.verbose:
            print "commit into %s" % branch
