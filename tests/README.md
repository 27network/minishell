# tests

Welcome to the minishell testing framework:tm:

## Structure

The tests are contained in multiple `.test` files, which each contain a command per line.  

Those commands are then executed with both `minishell` and `bash`, and their outputs are compared.

## Special cases

Here are some rules built-in:
- If an output line starts with the path to the shell (usually because of errors), the path is replaced with `%DUMMYSHELL%`
  - Example: `bash: line 1: test: No such file or directory` -> `%DUMMYSHELL%: line 1: [...]`

## The `.test` file format

The `.test` format is a simple collection of one-line commands, separated by newlines.

There are however two special cases:
- If the line starts with a `#`, it is considered a comment and disregarded
- If the line starts with a `:`, it is considered as a special command for the test runner.

### The special `:` commands

Commands are read sequentially, meaning that once a command is found in a file, it will be applied to every following test.

- `:ENV`
  - This allows to set an environment variable (Ex: `:ENV TESTCMD=echo`)
- `:TIMEOUT`
  - Allows setting a custom execution timeout, in milliseconds (Ex: `:TIMEOUT 10000`, for 10 seconds)
