#!/usr/bin/python3
# -*- coding: utf-8 -*-

"""This is NOT meant to be maintainable lmao"""

import os
import pathlib
import subprocess
import sys

__version__ = "0.0.1"
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

def main():
    print("\033[2J\033[H", end="")
    print(BANNER)

    no_logs = "--no-logs" in sys.argv
    if no_logs:
        print("[i] Writing logs is disabled by a CLI flag\n")

    bash_bin_file = pathlib.Path(BASH_BIN)
    if not bash_bin_file.exists() or not os.access(BASH_BIN, os.X_OK):
        print("[!] Bash binary file doesn't exist or isn't executable")
        return
    msh_bin_file = pathlib.Path(MSH_BIN)
    if not msh_bin_file.exists() or not os.access(MSH_BIN, os.X_OK):
        print("[!] msh binary file doesn't exist or isn't executable")
        return

    curr = pathlib.Path(".")
    logs_path = pathlib.Path("logs")
    test_files = list(curr.rglob("*.test"))
    success = 0
    total = 0
    for file in test_files:
        print("[*] Running {}".format(file))
        env = os.environ.copy()
        timeout = 5000

        def handle_command(cmd):
            print("\t[i] Handling tester command '{}'".format(cmd))
            if cmd.startswith("ENV "):
                name, value = cmd[4:].split('=')
                value = os.path.expandvars(value)
                env[name] = value
            elif cmd.startswith("TIMEOUT "):
                timeout = int(cmd[len("TIMEOUT "):])
            else:
                print("\t[!] Unknown command '{}'".format(cmd))

        with file.open('r') as file:
            for line in file:
                if line.endswith("\n"):
                    line = line[:-1]
                if line.startswith("#"): continue
                if line.strip() == "": continue
                if line.startswith(":"):
                    handle_command(line[1:])
                    continue
                total += 1
                print("\t[*] Executing '{}'... ".format(line), end="")
                try:
                    process = subprocess.Popen([BASH_BIN, "-c", line], env=env, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
                    output, _ = process.communicate(timeout=timeout/1000.0)
                    output = output.decode('utf-8')
                    lines = output.split("\n")
                    new_lines = []
                    for l in lines:
                        if l.startswith(BASH_BIN):
                            new_lines.append("%DUMMYSHELL%" + l[len(BASH_BIN):])
                        else:
                            new_lines.append(l)
                    output = "\n".join(new_lines)
                    res_bash = (output, process.returncode)
                except subprocess.TimeoutExpired:
                    print("Timeout ({})".format(BASH_BIN))
                    continue
                except Exception as e:
                    print("Error: {}".format(e))
                    continue

                try:
                    process = subprocess.Popen([MSH_BIN, "-c", line], env=env, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
                    output, _ = process.communicate(timeout=timeout/1000.0)
                    output = output.decode('utf-8')
                    lines = output.split("\n")
                    new_lines = []
                    for l in lines:
                        if l.startswith(MSH_BIN):
                            new_lines.append("%DUMMYSHELL%" + l[len(MSH_BIN):])
                        else:
                            new_lines.append(l)
                    output = "\n".join(new_lines)
                    res_msh = (output, process.returncode)
                except subprocess.TimeoutExpired:
                    print("Timeout ({})".format(MSH_BIN))
                    continue
                except Exception as e:
                    print("Error: {}".format(e))
                    continue

                if res_bash == res_msh:
                    print("Success")
                    success += 1
                else:
                    print("Failed")
                    if res_bash[1] != res_msh[1]:
                        print("\t\t[!] Return codes differ: bash={} msh={}".format(res_bash[1], res_msh[1]))
                    if res_bash[0] != res_msh[0]:
                        if no_logs:
                            print("\t\t[!] Outputs differ, but logs are disabled")
                            print("\t\tBash:")
                            lines = [f"\t\t\t{l}" for l in res_bash[0].split("\n")]
                            print("\n".join(lines))
                            print("\t\tMinishell:")
                            lines = [f"\t\t\t{l}" for l in res_msh[0].split("\n")]
                            print("\n".join(lines))
                        else:
                            bash_output = logs_path / (file.name + ".bash.log")
                            msh_output =  logs_path / (file.name + ".msh.log")
                            bash_output.parent.mkdir(parents=True, exist_ok=True)

                            with bash_output.open('w') as f:
                                f.write(res_bash[0])
                            with msh_output.open('w') as f:
                                f.write(res_msh[0])
                            
                            print("\t\t[!] Outputs differ, see logs: bash={} msh={}".format(bash_output, msh_output))


    if total == 0:
        print("No tests found... bruh")
        return
    
    print()
    if total == success:
        print("[*] Successfully ran {}/{} tests".format(success, total))
    else:
        print("[*] Some tests failed ({}/{} passed), check logs".format(success, total))


if __name__ == '__main__':
    main()

