
verbose = False

def write_pipe(c, str):
    if verbose:
        sys.stderr.write('writing pipe: %s\n' % c)

    pipe = os.popen(c, 'w')
    val = pipe.write(str)
    if pipe.close():
        sys.stderr.write('Command failed: %s' % c)
        sys.exit(1)

    return val

def read_pipe(c, ignore_error=False):
    if verbose:
        sys.stderr.write('reading pipe: %s\n' % c)

    pipe = os.popen(c, 'rb')
    val = pipe.read()
    if pipe.close() and not ignore_error:
        sys.stderr.write('Command failed: %s\n' % c)
        sys.exit(1)

    return val


def read_pipe_lines(c):
    if verbose:
        sys.stderr.write('reading pipe: %s\n' % c)
    ## todo: check return status
    pipe = os.popen(c, 'rb')
    val = pipe.readlines()
    if pipe.close():
        sys.stderr.write('Command failed: %s\n' % c)
        sys.exit(1)

    return val

