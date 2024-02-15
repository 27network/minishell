#!/usr/bin/python3
# -*- coding: utf-8 -*-

"""This is NOT meant to be maintainable lmao"""

import os
from pathlib import Path
import subprocess
import sys

__version__ = "0.0.3"
__author__ = "kiroussa <oss@xtrm.me>"

# because of course we need a fucking banner
BANNER = f"""
                   __    __       __      
   ____ ___  _____/ /_  / /______/ /______
  / __ `__ \/ ___/ __ \/ __/ ___/ __/ ___/
 / / / / / (__  ) / / / /_(__  ) /_/ /    
/_/ /_/ /_/____/_/ /_/\__/____/\__/_/   v{__version__}
                                by {__author__}
                                          
"""

BASH_BIN = "/bin/bash"
MSH_BIN  = "../minishell"

# bash symlink, for testing
MSH_BIN  = "../dummyshell"


def run(test_dir: Path, should_log: bool = True) -> tuple[int, int]:
    """Finds and runs every test in the provided directory.
    """

    return (0, 0)


def main():
    print("\033[2J\033[H", end="")
    print(BANNER)

    no_logs = "--no-logs" in sys.argv
    if no_logs:
        print("[i] Writing logs is disabled by a CLI flag\n")

    bash_bin_file = Path(BASH_BIN)
    if not bash_bin_file.exists() or not os.access(BASH_BIN, os.X_OK):
        print("[!] Bash binary file doesn't exist or isn't executable")
        return
    msh_bin_file = Path(MSH_BIN)
    if not msh_bin_file.exists() or not os.access(MSH_BIN, os.X_OK):
        print("[!] msh binary file doesn't exist or isn't executable")
        return

    curr = Path(".")
    (success, total) = run(curr, not no_logs)

    if total == 0:
        print("[?] No tests found... huh?")
        return
    
    print()
    if total == success:
        print("[*] Successfully ran {}/{} tests".format(success, total))
    else:
        print("[*] Some tests failed ({}/{} passed), check logs".format(success, total))


if __name__ == '__main__':
    main()
