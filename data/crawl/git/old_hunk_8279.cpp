        if not files:
            return

        filedata = p4CmdList('print %s' % ' '.join(['"%s#%s"' % (f['path'],
                                                                 f['rev'])
                                                    for f in files]))

        j = 0;
        contents = {}