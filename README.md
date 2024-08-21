# WIP ```README```

![minishelln](https://github.com/biralavor/42_minishell/assets/80487147/9718ee86-fbb4-4625-b6cf-56176eb9d1a0)


- [x] Makefile working and calling minUnit tester :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.0.1]
- [x] Test development with multiple files call, avoiding a monolith file :tada: [https://github.com/biralavor/42_minishell/pull/31]
- [x] Lexer :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.2]
- [x] Parser + Syntaxe Grammar :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.3]
- [x] SubShell + Binary Tree + Environment Variables :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.4]
- [x] Execution :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.6]
- [x] Built-ins :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.6]
- Next Steps on Project Management:
  - [ ] Expansion Variables
  - [ ] HereDoc Redirect
  - [ ] Signals Control


# Minishell
> The terminal is a file, therefor it treats all as ```strings```

![Screenshot from 2024-07-15 19-26-19](https://github.com/user-attachments/assets/2e1d496e-029d-4a42-a11e-bc3f00e6d3d8)

> [!IMPORTANT]
> # The Code flow, in a Big Picture
> After calling the `readline()` to capture user's input in the `main()`, our code goes basically like this:
> 
> 1. Check for initial erros, like: unmatched quotes or parenthesis
> 2. [With Automata State in lexer (token labeling), create the token list.](https://github.com/biralavor/42_minishell#2-lexer)
> 3. [Parse specific strings](https://github.com/biralavor/42_minishell#3-parser)
> 4. [Verify sintax, similar languague grammar](https://github.com/biralavor/42_minishell#4-syntax-grammar)
> 5. [Apply Redirect rules, if detected](https://github.com/biralavor/42_minishell#5-redirects-manager)
> 6. [Build the Binary Tree, in recursive mode](https://github.com/biralavor/42_minishell#6-build-the-binary-tree-in-recursive-mode)
> 7. [Execute from the Binary Tree](https://github.com/biralavor/42_minishell#7-execution)

![Screenshot from 2024-08-20 15-11-03](https://github.com/user-attachments/assets/4c8e518f-fec8-493f-b47c-13f6001683a5)


## 2. Lexer
- Identify user input as Tokens:

![Screenshot from 2024-08-05 16-42-40](https://github.com/user-attachments/assets/46778f94-5c54-4bfd-bdab-08b3c74dc5f9)


## 3. Parser
- The hability to label specific strings as tokens, like below:
  
Check this test: `echo oi > tudo > bem com voce > ?`
![Screenshot from 2024-07-15 19-29-04](https://github.com/user-attachments/assets/52c15a56-6cdc-48d5-b7c0-91a1d2e81ba0)

## 4. Syntax Grammar
- The goal here is to create syntax grammar validations to avoid have a future binary tree with execution erros
- We created similar automata states, just to have a better workflow
  
![Screenshot from 2024-08-05 16-58-40](https://github.com/user-attachments/assets/5b259735-d293-4537-916b-49218f20f573)


## 5. Redirects Manager
- The goal here is to:
  - Detects if there is more then one redirect type
  - If so, move tokens to a new order due an easier futher execution
    
Check this test: `echo oi > tudo > bem com voce > ?`
![Screenshot from 2024-08-05 16-56-17](https://github.com/user-attachments/assets/e88007e9-aedf-4ff1-954b-5c1698bd1c2b)

## 6. Build the Binary Tree, in recursive mode

![Screenshot from 2024-08-21 10-32-59](https://github.com/user-attachments/assets/678f6672-5e2a-40da-b14d-cbc7e27f452e)


## 7. Execution
- ![Screenshot from 2024-08-20 09-42-39](https://github.com/user-attachments/assets/98e84684-d146-46c2-b885-dd8a63294d19)

## Built-ins
We have two built-in categories: with argument, and without arguments, like the image below.
Therefor, also have a `bool builtin_detector()` and `void builtin_manager` for both types of built-ins:
![Screenshot from 2024-08-20 09-51-04](https://github.com/user-attachments/assets/b76bf67a-50a2-40fc-b7fc-ee9df47aab0d)

### built-in detector
![Screenshot from 2024-08-20 15-02-07](https://github.com/user-attachments/assets/d875d654-ca3d-49b8-976f-8bd33555e2d4)

### built-in manager:
![Screenshot from 2024-08-20 15-03-49](https://github.com/user-attachments/assets/5a1317c8-901d-4ec5-b35c-b81ccb1e949e)

### built-in runners, like:
![Screenshot from 2024-08-20 15-04-45](https://github.com/user-attachments/assets/f8eab4cf-872f-475d-af50-8c9668988b97)

# 42sp Team Project:
- Thais Malheiros -> https://github.com/Thais-Malheiros/
- Bira Lavor -> https://github.com/biralavor/
