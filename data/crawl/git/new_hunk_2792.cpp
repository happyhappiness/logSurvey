        sys.stderr.write('Reading pipe: %s\n' % str(c))

    expand = isinstance(c,basestring)
    p = subprocess.Popen(c, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=expand)
    (out, err) = p.communicate()
    if p.returncode != 0 and not ignore_error:
        die('Command failed: %s\nError: %s' % (str(c), err))
    return out

def p4_read_pipe(c, ignore_error=False):
    real_cmd = p4_build_cmd(c)
