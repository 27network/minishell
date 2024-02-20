# TODO list

## Goals

- [x] 0.0.x: Basic setup, submodules, Makefiles, dependencies
- [x] 0.1.x: Shell-like input w/ readline, basic prompt
- [ ] 0.2.x: Tokenizer, environment manager, bin hash table, `execve`
- [ ] 0.3.x: Execution structure
- [ ] 0.4.x: Lexer & Parser (part 1)
- [ ] 0.5.x: Builtins (part 1), manager, dynamic registration
- [ ] 0.6.x: To be defined

## bordel

- [x] Test system
  - [ ] Proper test suite

Feature management system ideas:
- `features.h` + `features.mk`

Make related:
- [x] Dependency system
  - [x] Automatically make
  - [x] Fix submodules trying to relink deps
  - [x] Build dependency tree
  - [x] Generate .d files
  - [x] Depend on .d files
    - [x] in ./Makefile
    - [x] in ./submodules/common.mk
  - [x] Fix bug where .c files dont recompile .o
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
