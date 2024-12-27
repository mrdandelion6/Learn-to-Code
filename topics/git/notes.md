# git notes

welcome to my git notes. in this document, we will start with the basics of git and then move on to more advanced topics. we will cover the following topics:
- what is git?
- git vs github
- stages of git tracked files
- common git commands
- git branches
- git merging
  - fast-forward merge
  - recursive three-way merge
  - squash merge
  - rebase and merge
- git lfs
- advanced git usage
  - git cherry-pick
  - git stash
  - git reset
  - git revert
  - git reflog
  - git bisect
  - git hooks
  - git submodules
  - git tags
  - git remotes
  - git fetch

git is a version control system. it allows you to track changes to files over time. it is used to coordinate work between multiple people.

imagine you want to write a book with a friend. you could email each other the book back and forth, but that would be a mess. instead, you could use git to keep track of the changes you make to the book. you could each work on your own copy of the book, and then use git to merge your changes together.

## git vs github

git is a version control system. github is a website that hosts git repositories.

## git lfs

## git branches
a branch in git is essentially a lightweight movable *pointer* to a specific commit in your repository's history.

think of your codebase as a tree. the main trunk (usually called `main` or `master`) represents the primary codebase, and branches are separate pathhs of development that diverge from this main line.

before we explore some important branch concepts, we will first motivate why we use branches.

### why use branches ?

#### parallel development
- multiple devs can work on *different features* simultaneously without interfering with each other (don't have to serialize pushes and pulls with team)

#### isolation of changes
- changes in one branch don't affect other branches until they are explicitly merged
- if a feature implementation goes wrong, it doesn't impact the stable main branch
- you can easily abandon or modify changes without affecting the main codebase

#### feature management
- each new feature can be made it its own branch
- code review becomes easier as changes are grouped logically by features
- features can be developed and tested independently before being integrated

#### version control
- different versions of your software can exist simultaneously
- you can maintain multiple versions for different environments (dev, staging, prod)
- quick rollback capabalities if issues are discovered

### core branch concepts
#### the default branch
- when you initialize a git repo, git creates a default branch. this branch is traditionally called `master` but not more often called `main`.
- this branch is typically considered the "official" version of your codebase.
- each commit on this branch should represent a *stable* version of your code.
#### branch references
- every branch is actually just a 41 byte text file containing the SHA-1 hash of the commit it points to 
- when you create a new branch, git simply creates a new pointer--it doesn't create a new set of files
- the special pointer `HEAD` tells git which branch you are currently working on

### common branch types
#### feature branches
```bash
git checkout -b feature/user-authentication
```
- putting `feature/` doesn't do anything special like create a category. it is not a keyword either. it simply names the branch  
- used for developing new features
- usually branched from and merged back into main branch
- naming convention usually follows: `feature/feature-name`

#### relrease branches
```bash
git checkout -b release/1.0.0
```
- created when preparing for a new release
- allow for last minute bug fixes without disrupting ongoing development
- named `release/version-number`
for example, suppose we have a main branch with new features:
```
main branch: v2.0 (in dev)
- feature A (complete)
- feature B (complete)
- feature C (in dev)
```
if we want to release without waiting for feature C, we can create a release branch that contnains only features A and B completed.
```bash
git checkout -b release/2.0
```
now we have:
- `main` branch continues with feature C development, no need to stop any development here
- `release/2.0` contains only completed features A and B

now to even further demonstrate, suppose we later on find a bug in our release 2.0. since we have it as its own isolated branch, we can:
- create a fix branch from the release branch 
- fix the bug
- merge fix back into release
- merge fix back into main
like so
```bash
# create fix branch from release branch
git checkout -b hotfix/feature-A-crash release/2.0

# fix bug abd test fix

# merge fix into release
git checkout release/2.0
git merge hotfix/feature-A-crash

# merge into main
git checkout main
git merge hotfix/feature-A-crash
```

#### hotfix branches
```
git checkout -b hotfix/security-path
```
- used for quick fixes to production issues as we saw above
- branched from main or product (release) branch
- merged into both production and development branches (eg. release and main branches)
- named like `hotfix/issue-description`

#### development branch
for larger teams and projects, you might also have a dev branch:
```
git checkout -b dev
```
the idea is that we use the `main` branch for production only and protect it from direct commits.

main branch should be:
- always contain production-ready code
- should be stable at all times
- directly reflect what's in production
- usually protected from direct commits

dev branch:
- integration branch for features
- may be unstable at times
- used as the base for new feature branches
- contains all completed features for next release
```bash
git checkout dev
git pull origin dev # get latest changes
git checkout -b feature/login # new feature branch
```

example workflow:
```bash
# start in dev
git checkout dev 
git checkout -b feature/new-dashboard # work on a feature, create new branch

# work on feature
git commit -m "add dashboard layout"
git commit -m "add data charts"

# feature completed, merge to dev
git checkout dev
git merge feature/new-dashboard

# prepare for release
git checkout -b release/1.1.0

# testing and bugfixes in release branch
# once release branch is stable
git checkout main
git merge release/1.1.0

# keep dev updated with bugfixes
git checkout dev
git merge release/1.1.0
```
the above workflow is known as **gitflow**. your workflow will most definitely vary depending on your team. for instance, you might not want to merge the release branch into dev if some configuration files are different for production vs. development. it really depends.

### advanced branch concepts
#### remote trackinng branches
- branches that track changes in remote repositories
- named like `origin/main` or `origin/feature-branch`
```bash
git branch -u origin/feature-branch # set up tracking
```

#### branch protection rules
- configure rules to prevent direct pushes to important branches
- for example, in github repository settings, protect `main` branch
- require pull request reviews before merging
- enforce status checks (CI/CD) before merging

#### git flow
- a specific branching model for project management
- defines strict branch purposes and merge flows
- suitable for projects with scehduled releases
- recall our example with dev branch, that was a git flow practice

## git merging

a merge combines changes from different **branches**. this allows us to cimbine work from different branches. the significance of being able to work on different branches is all explained above. once we want to join branches together, we do a merge.

there are 4 types of merging:
1. fast-forward merge
2. three-way merge
3. squash merge
4. rebase and merge

### merging scenarios
there are two scenarios in which you will have to merge branches.

1. local branches merge
2. remote merging

#### local branches merge
suppose we have a branch `feature` and a branch `main` locally, and we merge them. in order to do this we would do the following
```bash
git checkout main
git merge feature
```

#### remote merging
now suppose we want to merge the local `main` branch with the remote one. we would do the following:
```bash
git fetch origin
git merge origin/main
```
or you could simply do:
```bash
git pull
```

in the following sections you will see some simple merge examples and see how merging exactly works.

### basic merge example
suppose we have a feature branch we want to merge into main:
```bash
git checkout main # go to main branch first
git merge feature # merge feature branch into main
```
it's important to understand that **merging only affects the branch we are on**, so if we want to update `main` with `feature`, then we checkout to `main` first. we say that `main` is the **target branch** and `feature` is the **source branch**.

we will further explain what the above merging does. suppose this is a chain of the commits for `main` and `feature`:
```
main    A --- B --- C
              |
feature       D --- E
```
above, we see that the head of `main` is C, in other words `main` points to commit C. similarly, `feature` points to commit E. we can also see that `feature` was branched from `main` at commit B.

now when checkout into `main` and merge `feature` into it, the following happens:
```
main    A --- B --- C --- F
              |         /
feature       D --- E /
```
now after the merge, a new commit F has been made. `main` points to F, and `feature` remains pointing to E! the edge from E to F doesn't mean `feature` now points to F, it just means E is a parent of F. 

but how exactly do we carry out this merge? in what way do C and E become combined to form F? we now take a look at different ways merges take place.

### fast-forward merge 
- occurs when the target and source branches have not diverged
- happens automatically, no need for manual merging
- simply moves the pointer forward for the target branch
- does not create a new commitn
- maintains a linear history
- eg) when `main` hasn't changed since `feature` branch was created
```
main      A --- B --- C 
                      |
feature               D --- E --- F --- G
```
then we merge
```bash
git checkout main
git merge feature
```
and the our commits become like this
```
main      A --- B --- C --- D --- E --- F --- G
                                          \
feature                                     \ G 
```
note that `feature`'s history was not wiped or anything, we simply restructured the graph. the edges show the commit history. also `G --- G` is a bit misleading, it does not mean there are two separate commits for G. it just meants `feature` and `main` both point to the G commit.

### recursive three-way merge 
- the default merge strategy for when there is a branch divergence
- creates a new merge commit
- combimes changes frm both branches
- preserves commit history
- shows explicit branch structure
- branch divergences happen often when multiple devs work on different features in parallel

for example, consider the following commit graph:
```
main   A --- B --- C
             |
feature      D --- E
```
we see that `main` and `feature` have diverged. now git needs to compare three points to merge:
- the common ancestor B, also known as the **base version**
- the tip of the target C
- the tip of the source E

after the merge we get something like what we shouled in the *basic merge example*:
```
main   A --- B --- C --- F
             |         /
feature      D --- E /
```
a new commit F gets created that combines E and C. this commit uses the three points mentioned before. we need the common ancestor to determine what the differences were. it serves as a reference to when the divergent branches were the same.

#### resolving merge

we will demonstrate how exactly F gets created. here is the algorithm:
1. identify the base (this is B)
2. for each line/chunk of code compare all three versions
  - if base -> A changed but base -> B didn't, use A's line/chunk
  - if base -> B changed but base -> A didn't, use B's line/chunk
  - if both changed the same way, use either
  - if both changed different **flag as a conflict**
3. for conflicts, the system will
  - modify the conflicted file
  - mark the conflicting sections with special markers `<<<<<<`, `=======`, `>>>>>>>`.
  - include both versions
  - require manual intervention to choose which version to keep

for example, if both sides modified the same line:
```
base:      print("hello")
A:         print("hi")
B:         print("hey")
```
upon running `git merge`, git will modify the conflicted file and mark it like so:
```
<<<<<<< HEAD
print("hi")
=======
print("hey")
>>>>>>> feature
```
below `HEAD` and above the `==` we have the code for the target branch. below `==` and above `feature` we have the code for the source branch. to resolve this, we need to choose the proper code between `HEAD` and `feature` and remove all the markers:
```
print("i resolved the conflict!")
```
until you resolve the conflicts, you won't be able to push or pull any changes from remote.

## git lfs

