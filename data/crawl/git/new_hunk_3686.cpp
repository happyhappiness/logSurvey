    ref = parser[1]
    parser.next()

    # ugh
    if parser.check('commit'):
        parse_commit(parser)
