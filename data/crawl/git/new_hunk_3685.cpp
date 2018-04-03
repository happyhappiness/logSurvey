    ref = parser[1]
    parser.next()

    if ref.startswith('refs/heads/'):
        name = ref[len('refs/heads/'):]
        branch = branches[name]
    else:
        die('unknown ref')

    commit_mark = parser.get_mark()
    parser.next()
