        else:
            die('unhandled export command: %s' % line)

    for ref, revid in parsed_refs.iteritems():
        name = ref[len('refs/heads/'):]
        branch = branches[name]
        branch.generate_revision_history(revid, marks.get_tip(name))

        if name in peers:
            peer = peers[name]
            try:
                peer.bzrdir.push_branch(branch, revision_id=revid)
            except bzrlib.errors.DivergedBranches:
                print "error %s non-fast forward" % ref
                continue

        try:
            wt = branch.bzrdir.open_workingtree()
            wt.update()
        except bzrlib.errors.NoWorkingTree:
            pass

        print "ok %s" % ref

