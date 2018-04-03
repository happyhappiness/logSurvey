    ref = parser[1]
    parser.next()

    if ref != 'refs/heads/master':
        die("bzr doesn't support multiple branches; use 'master'")

    commit_mark = parser.get_mark()
    parser.next()
