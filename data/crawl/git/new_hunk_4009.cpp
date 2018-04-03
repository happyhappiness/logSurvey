    m = { '0100755': 'x', '0120000': 'l' }
    return m.get(mode, '')

def get_config(config):
    cmd = ['git', 'config', '--get', config]
    process = subprocess.Popen(cmd, stdout=subprocess.PIPE)
    output, _ = process.communicate()
    return output

class Marks:

    def __init__(self, path):
