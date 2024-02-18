# TODO list

## bordel

- [x] Test system
  - [ ] Proper test suite

Feature management system ideas:
- `features.h` + `features.mk`

Make related:
- [ ] Dependency system
  - [x] Automatically make
  - [ ] Fix submodules trying to relink deps
  - [x] Build dependency tree
  - [ ] Generate .d files
  - [ ] Depend on .d files
    - [ ] in ./Makefile
    - [ ] in ./submodules/common.mk
- [x] Add /third-party to compilation
- [ ] Better output

## Execution sources

- [x] `minishell` interactive
- [x] `minishell -c "cmd"`
  - `bash -c "echo meow"` exec la cmd
  - `bash -c "meow echo" "minishell"` exec la cmd, change le nom du shell
- [x] `echo "echo lol" | minishell`
- [ ] `minishell test.sh`
  - `bash anything.sh [arg1] [arg2]`, exec script, needs read perm, rejects binary executables 
  - shebang: redirects to `minishell <file>`
