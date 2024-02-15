# mshtst

Welcome to the dumb minishell testing framework:tm:

## Prerequisites

For this tester to function (i.e. start testing stuff), you need to have implemented at least the following in your `minishell`:
- Line reading
- Some sort of output
- `echo $?` (optional, pass `--no-exit-code` to disable)

## Usage

First, clone this repository and `cd` into it (Preferably clone it into your `minishell` folder/repo):
```bash
git clone https://github.com/seekrs/mshtst.git

cd mshtst
```

You might need to give run permissions to the main script:
```bash
chmod +x ./mshtst.py
```

Then you can run it:
```bash
./mshtst.py
mshtst v0.1.1 - minishell tester 
https://github.com/seekrs/mshtst 

Usage:
  ./mshtst [OPTIONS] [path/to/your/minishell] [path/to/bash] [<test files...>]

Options:
  --no-logs         Don't produce any logs
  --no-exit-code    Disable the checking of exit codes

  -h, --help        Print help
  -V, --version     Print version
```
