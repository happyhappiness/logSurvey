            lines = (str_to_bytes(line) for line in lines)
            p.stdin.writelines(lines)
        except Exception:
            sys.stderr.write(
                '*** Error while generating commit email\n'
                '***  - mail sending aborted.\n'
                )
            try:
                # subprocess.terminate() is not available in Python 2.4
                p.terminate()
            except AttributeError:
                pass
            raise
        else:
            p.stdin.close()
