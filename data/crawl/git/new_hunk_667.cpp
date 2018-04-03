    real_cmd = p4_build_cmd(c)
    return write_pipe(real_cmd, stdin)

def read_pipe_full(c):
    """ Read output from  command. Returns a tuple
        of the return status, stdout text and stderr
        text.
    """
    if verbose:
        sys.stderr.write('Reading pipe: %s\n' % str(c))

    expand = isinstance(c,basestring)
    p = subprocess.Popen(c, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=expand)
    (out, err) = p.communicate()
    return (p.returncode, out, err)

def read_pipe(c, ignore_error=False):
    """ Read output from  command. Returns the output text on
        success. On failure, terminates execution, unless
        ignore_error is True, when it returns an empty string.
    """
    (retcode, out, err) = read_pipe_full(c)
    if retcode != 0:
        if ignore_error:
            out = ""
        else:
            die('Command failed: %s\nError: %s' % (str(c), err))
    return out

def read_pipe_text(c):
    """ Read output from a command with trailing whitespace stripped.
        On error, returns None.
    """
    (retcode, out, err) = read_pipe_full(c)
    if retcode != 0:
        return None
    else:
        return out.rstrip()

def p4_read_pipe(c, ignore_error=False):
    real_cmd = p4_build_cmd(c)
    return read_pipe(real_cmd, ignore_error)