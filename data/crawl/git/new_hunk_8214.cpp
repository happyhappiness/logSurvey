        if not files:
            return

        filedata = p4CmdList('-x - print',
                             stdin='\n'.join(['%s#%s' % (f['path'], f['rev'])
                                              for f in files]),
                             stdin_mode='w+')
        if "p4ExitCode" in filedata[0]:
            die("Problems executing p4. Error: [%d]."
                % (filedata[0]['p4ExitCode']));

        j = 0;
        contents = {}