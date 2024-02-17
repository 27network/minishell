# minishell

Or as we like to call it:

##### The pain of my existence and the thorn of my soul.

## The structure

`minishell` is split into multiple independant-ish modules:

- submodules/**tokenizer**

- submodules/**lexer**

- submodules/**parser**

- submodules/**cli**
  - The **C**ommand **L**ine **I**nterface, allows for configuring, executing, and prompting minishell

- submodules/**executor**
  - An AST consumer that executes commands

- submodules/**shared**
  - Shared constants/systems
