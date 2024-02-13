# TODO list

## bordel

- [x] Test system
  - [ ] Proper test suite

## Code design

- [ ] `features.h`
- [ ] Submodules
  - [ ] Makefiles :3

## Execution

- [ ] `minishell` interactive
- [ ] `minishell -c "cmd"`
  - `bash anything [bla bla]` ignore tout après, exec script
  - `bash -c "echo meow"` exec la cmd
  - `bash -c "meow echo" "minishell"` exec la cmd, change le nom du shell
- [ ] `echo "echo lol" | minishell`
- [ ] `minishell test.sh`
- [ ] shebang?
