        sys.stderr.write('Reading pipe: %s\n' % str(c))

    expand = isinstance(c,basestring)
    p = subprocess.Popen(c, stdout=subprocess.PIPE, shell=expand)
    pipe = p.stdout
    val = pipe.read()
    if p.wait() and not ignore_error:
        die('Command failed: %s' % str(c))

    return val

def p4_read_pipe(c, ignore_error=False):
    real_cmd = p4_build_cmd(c)
