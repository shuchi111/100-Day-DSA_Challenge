**Advanced GitHub**
---
Git Workflow
---
![image](https://github.com/shuchi111/100-Day-DSA_Challenge/assets/107612618/543debb2-7bdd-46ec-b661-5cf9b28e863c)

# Git Branches
- In Git, branches are a fundamental concept that allows you to diverge from the main line of development and work on different features, bug fixes, or improvements concurrently.

  ![image](https://github.com/shuchi111/100-Day-DSA_Challenge/assets/107612618/47b552e7-3a55-4c9a-aad7-0a7a266fee45)
  
- **merging code**
  
  Way-1:
  ```bash
  git diff <-branch_name->                   ( to compare commits, branches, files & more)
  git merge <-branch_name->                   ( to merge 2 branches )
  ```
  
  Way -2:
  
  Create a PR

 # Pull Request
 - It lets you tell others about changes you've pushed to a branch in a repository on GitHub.
# Pull command 

- It is used to fetch and download content from a remote repo and immediately update the local repo to match that content.

```bash
  git pull origin main
```

# Resolving merge conflicts 

- An event that takes place when Git is unable to automatically resolve differences in  code between two commits.

```bash
git diff main

```
**merge**
```bash
git merge <branch_name>
```
It will show some conflicts then we have to decide manually.

# Undoing Changes
- case 1: Staged Changes
  ```bash
  git reset <-file_name->
  git reset

- case 2: committed changes ( for one commit )
  ```bash
  git reset HEAD~1

- case 3: committed changes ( for maby commits )
  ```bash
  git reset <- commit hash->
  git reset --hard <-commit hash ->


# Fork
---
A fork is a new repository that shares code and visibility settings with the origin "upstream"
repository.
- Fork is a rough copy.
---
  

![image](https://github.com/shuchi111/100-Day-DSA_Challenge/assets/107612618/3bada536-f0a0-4959-97fb-abbe5128f834)

