    global branches, peers
    global transports

    marks = None
    is_tmp = False
    gitdir = os.environ.get('GIT_DIR', None)

    if len(args) < 3:
        die('Not enough arguments.')

    if not gitdir:
        die('GIT_DIR not set')

    alias = args[1]
    url = args[2]

