        else:
            die('unhandled export command: %s' % line)

    branch = parser.repo

    for ref, revid in parsed_refs.iteritems():
        if ref == 'refs/heads/master':
            branch.generate_revision_history(revid, marks.get_tip('master'))
            if peer:
                try:
                    branch.push(peer, stop_revision=revid)
                except bzrlib.errors.DivergedBranches:
                    print "error %s non-fast forward" % ref
                    continue

            try:
                wt = branch.bzrdir.open_workingtree()
                wt.update()
            except bzrlib.errors.NoWorkingTree:
                pass

        print "ok %s" % ref

