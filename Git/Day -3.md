# Basics
---
**Git** : version control System is a tools that helps to track changes in code( track the history, collaborate).

- Git is a Version control System . It is:
  
 Popular
 
free & open Source

fast & scalable

---
**Github** : It is a website that allows developers to store and manage their code using Git.
```bash
https://github.com
```
#Setting up Git
-Visual studio Code
- Window ( Git Bash)
---
 1.  **Check version of Git**
    ```bash
    git --version
    or
    git --v
    ```
2. List out all files
   ```bash
   ls
3. Clear window
   ```bash
   clear
4. Find working directory
   ```bash
   pwd
5. Display hidden file
   ```bash
   ls -a
   ```
   -Here 'a' means all files.

  ~ - this tilde symbol shows that I 'm in my root directory or folder.

# configuring Git
- Configuring Git involves setting up your identity, specifying preferences, and defining various settings to tailor Git to your workflow.
- Here are some common configurations you might want to set up:

**1. Set Your Identity:**
Configure your name and email address. These will be associated with your commits.
```bash
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"
```
**2. Set Your Preferred Text Editor:**
```bash
git config --global core.editor "vim"
```
**3. Check Your Configuration:**
Verify your configuration settings:
```bash
git config --list
```
**Clone & Status** 
- Clone- Cloning  repository on our local machine
  ```bash
  git clone<-some link->

Status - Displays the state of the code
```bash
git status
```
**Change directory
```bash
cd <folder_name>
```
# Types of status

1. Untracked: new files that git doesn't yet track
2. modified: changed
3. staged: The file is ready to be committed
4. unmodified: unchanged
   
   









    




