**Git and GitHub**

Git is a powerful distributed version control system that is widely used for source code management and collaboration.
1. Initialize a repository:
   
 ```bash
   git init
```
2. Clone a Repository:
   
 ```bash
   git clone <repository_url>
```
3. Configure User Information:
   
  ```bash
  git config --global user.name "Your Name"
  git config --global user.email "your.email@example.com"
```
4. Check repository status:

~~~bash
   git status
   ~~~
5. Add changes to staging Area:

 ```bash
   git add <file_name>
```
To add all changes:

```bash
  git add .

  ```
6. Commit Changes:
```bash
   git commit -m "commit messages"
```
7. View commit History:
```bash
    git log
```
8. Create a Branch:
```bash
   git branch <branch_name>
```
9. Switch to a Branch:
```bash
    git checkout <branch_name>
```
 **Or in newer versions of Git:**
```bash
   git switch <branch_name>
```
10. Create and switch to a new Branch:
```bash
    git checkout -b <new_branch_name>
```
 **Or in newer versions of Git:**
```bash
    git switch -c <new_branch_name>
  ```
11. Merge Branches:

    ```bash
    git merge <branch_name>
    ```
    delete branch
    ```bash
    git branch -d <branch_name>
    ```
   
13. Pull changes from a Remote Repository:
    ```bash
    git pull origin <branch_name>
14. Push Changes to a remote Repository:
    ```bash
    git push origin <branch_name>
15. Show Remote Repository:
    ```bash
    git remote -v
16. Fetch Changes from a Remote Repository
    ```bash
    git fetch
17. Undo Changes in Working Directory:
    ```bash
    git checkout -- <file_name>

18. Discard Changes in the staging Area:
    ```bash
    git reset

19. Undo the last commit:
    ```bash
    git reset HEAD^

20. Create and Apply a patch:
- A patch file in the context of Git is a text file that contains the differences between two sets of source code. It essentially represents the changes made to a set of files. The purpose of a patch file is to allow these changes to be applied to another copy of the code, bringing it up-to-date with the modifications made in the original version.

    ```bash
    git diff > patchfile
    git apply < patchfile

20. Ignore Files:
    ***Create a file named .gitignore and list the files/directories to be ignored**

   ---
   Some git command
   ---
```bash 
   git help
   git help <command>
```
 

 


   


