            lines = (str_to_bytes(line) for line in lines)
            p.stdin.writelines(lines)
        except Exception:
            self.environment.get_logger().error(
                '*** Error while generating commit email\n'
                '***  - mail sending aborted.\n'
                )
            if hasattr(p, 'terminate'):
                # subprocess.terminate() is not available in Python 2.4
                p.terminate()
            else:
                import signal
                os.kill(p.pid, signal.SIGTERM)
            raise
        else:
            p.stdin.close()
