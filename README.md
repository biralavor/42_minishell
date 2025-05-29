# Minishell, a tiny version of Bash -> B.orn A.gain SH.ell

<img src="https://github.com/user-attachments/assets/aad813db-13ee-4665-bed0-d444a0c1dcdf" width="525" height="225" />
<br>

| ![minishell_with_bonus_logo](https://github.com/user-attachments/assets/ea55cd2c-7a14-4d8d-9bb0-6f416f7982ba) | The terminal is a file, <br> therefor it treats all inputs as `strings` | ![minishell_grade_107](https://github.com/user-attachments/assets/fce51403-942a-4210-9385-7865ef74fa7f) |
| :-: | :-: | :-: |


> [!IMPORTANT]
> ## Our Code Flow, in a Big Picture
> After calling the `readline()` to capture user's input in the `main()`, our code goes basically like this:
> 
> 1. [Define Tokens and Check for initial errors, like: unmatched quotes or parentheses](https://github.com/biralavor/42_minishell#1-tokenization)
> 2. [With Automata State in Lexer (token labeling), create the token list.](https://github.com/biralavor/42_minishell#2-lexer)
> 3. [Parse (or verify sintax, similar language grammar)](https://github.com/biralavor/42_minishell#3-parser-or-syntax-grammar)
> 4. [Apply Redirect rules in Parse, if detected](https://github.com/biralavor/42_minishell#4-apply-redirect-rules-in-parse)
> 5. Check HereDoc
> 6. [Build the Binary Tree, in recursive mode](https://github.com/biralavor/42_minishell#5-build-the-binary-tree-in-recursive-mode)
> 7. [Preparing Execution in Binary Tree](https://github.com/biralavor/42_minishell#6-preparing-execution-in-binary-tree)
> 8. [Execute](https://github.com/biralavor/42_minishell#7-execute)
> > 8.1 [Expansion of special tokens](https://github.com/biralavor/42_minishell#71-expansion-of-special-tokens)
> > 
> > 8.2 [Built-ins](https://github.com/biralavor/42_minishell#72-built-ins)
> > 
> > 8.3 [Command Manager](https://github.com/biralavor/42_minishell#73-command-manager)

![Screenshot from 2024-08-20 15-11-03](https://github.com/user-attachments/assets/4c8e518f-fec8-493f-b47c-13f6001683a5)

## Our Development Status
- [x] Makefile working and calling minUnit tester :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.0.1]
- [x] Test development with multiple files call, avoiding the **horrible monolith** file :tada: [https://github.com/biralavor/42_minishell/pull/31]
- [x] Lexer :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.2]
- [x] Parser + Syntaxe Grammar :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.3]
- [x] SubShell + Binary Tree + Environment Variables :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.4]
- [x] Execution :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.6]
- [x] Built-ins :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.6]
- [x] Variables Expansion :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.7]
- [x] Redirects of all types, except HereDoc :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.9.5]
- [x] HereDoc Redirect :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.9.0]
- [x] Signals Control -> Ctrl+C and Ctrl+D :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.9.6]
- [x] Memory Leaks Management at: Lexer, Parser :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.9.8]
- [x] Memory Leaks Management at: Expansion, Builtins :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.9.8]
- [x] Memory Leaks Management at: Manage Single Command :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.9.8]
- [x] Memory Leaks Management at: HereDoc, when Ctrl+C is activated :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.9.9.8]
- [x] Signals Control -> Ctrl + \ :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.9.9.8]
- Next Steps on Project Management:
  - [ ] Norminette
- Possible Bonus Development:
  - [ ] If `&&` were inside `()`, it should execute with priority (SUBSHELL)
  - [ ] If `||` were inside `()`, it should execute with priority (SUBSHELL)
  - [ ] Expansion for wildcards (*)

## But first, let's talk about our TDD - Test Driven Development
What we are testing, until so far:
- initial_errors, like unmachted quotes and parentheses
- mixed quotes
- crazy parentheses counter
- creating the token linked list
- syntax validations for `words`, `pipes`, `and`, `or`, `pipes` mixed with `and` and `or`
- syntax validations for `redirect_input`, `redirect_output`, `redirect_output_append`, `redirect_heredoc`, `mixed redirects`, `subshell`
- syntax rules for `archive`, `word_after_archive`, `redirect_with_another_redirect`
- syntax rules for `reorganize_redirects`

![Screenshot from 2024-07-15 19-26-19](https://github.com/user-attachments/assets/2e1d496e-029d-4a42-a11e-bc3f00e6d3d8)

## 1. Tokenization
- Define Tokens for possible user's input:

![Screenshot from 2024-08-05 16-42-40](https://github.com/user-attachments/assets/46778f94-5c54-4bfd-bdab-08b3c74dc5f9)

## 2. Lexer
- The hability to label specific strings as tokens, like below:
  
Check this test: `echo oi > tudo > bem com voce > ?`

![Screenshot from 2024-07-15 19-29-04](https://github.com/user-attachments/assets/52c15a56-6cdc-48d5-b7c0-91a1d2e81ba0)


## 3. Parser, or Syntax Grammar
- The goal here is to create syntax grammar validations to avoid have a future binary tree with execution erros
- We created **Automata States**, just to have a better workflow
  
![Screenshot from 2024-08-05 16-58-40](https://github.com/user-attachments/assets/5b259735-d293-4537-916b-49218f20f573)


## 4. Apply Redirect rules in Parse
- The goal here is to:
  - Detects if there is more then one redirect type
  - If so, it move tokens to a new order, for an easier futher execution
    
> Remember this test from **Lexer**? `echo oi > tudo > bem com voce > ?`
> 
> ![Screenshot from 2024-07-15 19-29-04](https://github.com/user-attachments/assets/52c15a56-6cdc-48d5-b7c0-91a1d2e81ba0)
> 
Now, we got un updated result:

![Screenshot from 2024-08-05 16-56-17](https://github.com/user-attachments/assets/e88007e9-aedf-4ff1-954b-5c1698bd1c2b)


## 6. Build the Binary Tree, in recursive mode
![Screenshot from 2024-09-12 12-29-38](https://github.com/user-attachments/assets/d248f2b5-46f8-4e70-9125-6df4f3a1cf0c)


## 7. Preparing Execution in Binary Tree
The Binary Tree will be executed, following the metacharacters rules:

![Screenshot from 2024-09-12 12-28-23](https://github.com/user-attachments/assets/4f5e1700-3176-4b6a-a67e-bf556620e4b7)

## 8. Execute

![Screenshot from 2024-09-12 12-36-59](https://github.com/user-attachments/assets/5521ac35-07e8-46d1-aa8d-5b5bd9a78187)

### 8.1. Expansion of special tokens
- Expansion for:
  - Quotes `"`
  - tilde `~`
  - dollar sign `$`

![Screenshot from 2024-09-12 12-16-10](https://github.com/user-attachments/assets/5ced977f-8e35-4a2a-87de-6759c711ea71)


### 8.2 Built-ins
- Built-in Detectors
- Built-in Manager
- Built-in Runners

Built-ins, if detected, or classic commands. Therefor, also have a `bool builtin_detector()` and `void builtin_manager` for both types of built-ins.
If the input isn't a Built-in, it runs `execve`. We have two built-in categories for our `minishell` version:
 - Builtins without argument, like: `env`, `pwd`, `exit`.
 - Builtins with argument, like: `echo`, `cd`, `export`, `unset`.

#### Built-in Detectors
![Screenshot from 2024-08-20 15-02-07](https://github.com/user-attachments/assets/d875d654-ca3d-49b8-976f-8bd33555e2d4)

#### Built-in Manager
![Screenshot from 2024-08-20 15-03-49](https://github.com/user-attachments/assets/5a1317c8-901d-4ec5-b35c-b81ccb1e949e)

#### Built-in Runners, goes like this:
![Screenshot from 2024-08-20 15-04-45](https://github.com/user-attachments/assets/f8eab4cf-872f-475d-af50-8c9668988b97)

### 8.3 Command Manager
![Screenshot from 2024-09-12 12-49-23](https://github.com/user-attachments/assets/bd21e13a-79f9-4029-a767-9a48b5350555)


# 42sp Team Project:
- Thais Malheiros -> https://github.com/Thais-Malheiros/
- Bira Lavor -> https://github.com/biralavor/

> All 42 Badges -- the astronomer Human Coder -- were done by Larissa Cristina [@mewmewdevart](https://github.com/mewmewdevart/42Badges)
