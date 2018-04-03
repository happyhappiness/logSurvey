def originP4BranchesExist():
        return gitBranchExists("origin") or gitBranchExists("origin/p4") or gitBranchExists("origin/p4/master")

def p4ChangesForPaths(depotPaths, changeRange, block_size):
    assert depotPaths
    assert block_size

    # Parse the change range into start and end
    if changeRange is None or changeRange == '':
        changeStart = '@1'
        changeEnd = '#head'
    else:
        parts = changeRange.split(',')
        assert len(parts) == 2
        changeStart = parts[0]
        changeEnd = parts[1]

    # Accumulate change numbers in a dictionary to avoid duplicates
    changes = {}

    for p in depotPaths:
        # Retrieve changes a block at a time, to prevent running
        # into a MaxScanRows error from the server.
        start = changeStart
        end = changeEnd
        get_another_block = True
        while get_another_block:
            new_changes = []
            cmd = ['changes']
            cmd += ['-m', str(block_size)]
            cmd += ["%s...%s,%s" % (p, start, end)]
            for line in p4_read_pipe_lines(cmd):
                changeNum = int(line.split(" ")[1])
                new_changes.append(changeNum)
                changes[changeNum] = True
            if len(new_changes) == block_size:
                get_another_block = True
                end = '@' + str(min(new_changes))
            else:
                get_another_block = False

    changelist = changes.keys()
    changelist.sort()
