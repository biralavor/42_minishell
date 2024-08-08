# WIP ```README```

![minishelln](https://github.com/biralavor/42_minishell/assets/80487147/9718ee86-fbb4-4625-b6cf-56176eb9d1a0)


- [x] Makefile working and calling minUnit tester :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.0.1]

- [x] Test development with multiple files call, avoiding a monolith file :tada: [https://github.com/biralavor/42_minishell/pull/31]

- [x] Lexer :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.2]

- [x] Project Planning - Parser + Syntaxe Grammar :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.3]

- [x] Next Steps on Project Management - Environment :tada: [https://github.com/biralavor/42_minishell/releases/tag/v0.4]
- [ ] Next Steps on Project Management - Expansion Variables
- [ ] Next Steps on Project Management - Built-ins
- [ ] Next Steps on Project Management - Signals Control
- [ ] Next Steps on Project Management - Execution


# Minishell
> The terminal is a file, therefor it treats all as ```strings```

![Screenshot from 2024-07-15 19-26-19](https://github.com/user-attachments/assets/2e1d496e-029d-4a42-a11e-bc3f00e6d3d8)



## Lexer
- Identify user input as Tokens:

![Screenshot from 2024-08-05 16-42-40](https://github.com/user-attachments/assets/46778f94-5c54-4bfd-bdab-08b3c74dc5f9)


## Parser
- The hability to label specific strings as tokens, like below:
  
Check this test: `echo oi > tudo > bem com voce > ?`
![Screenshot from 2024-07-15 19-29-04](https://github.com/user-attachments/assets/52c15a56-6cdc-48d5-b7c0-91a1d2e81ba0)

## Syntax Grammar
- The goal here is to create syntax grammar validations to avoid have a future binary tree with execution erros
- We created similar automata states, just to have a better workflow
  
![Screenshot from 2024-08-05 16-58-40](https://github.com/user-attachments/assets/5b259735-d293-4537-916b-49218f20f573)


## Redirects Manager
- The goal here is to:
  - Detects if there is more then one redirect type
  - If so, move tokens to a new order due an easier futher execution
    
Check this test: `echo oi > tudo > bem com voce > ?`
![Screenshot from 2024-08-05 16-56-17](https://github.com/user-attachments/assets/e88007e9-aedf-4ff1-954b-5c1698bd1c2b)


## Execution
- xx

# 42sp Team Project:
- Thais Malheiros -> https://github.com/Thais-Malheiros/
- Bira Lavor -> https://github.com/biralavor/
