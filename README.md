# Git 101

Project to learn git commands!

![Git Notes](/mindmap.png "Git Notes")

# Guide

This guide will walk you through using this repository to learn common Git commands.

## 1. Getting Started: Exploring the Repository

First, let's look at the repository's structure.

### Commit History

To see the commit history, including all branches, in a compact and graphical way, run:

```bash
git log --all --decorate --oneline --graph
```

You'll see a history of commits, with branches pointing to specific commits. This shows how the different feature branches (`feature-add`, `feature-mul`, `feature-sub`) diverged from the `main` branch.

### Branches

To list all the branches in the repository, run:

```bash
git branch -a
```
This will show you the local branches (`main`, `docs-instr`, `feature-add`, etc.) and any remote branches.

## 2. Navigating the Repository

### Switching Branches with `checkout`

Your current branch is `docs-instr`. Let's switch to the `main` branch:

```bash
git checkout main
```

Now, let's explore the `feature-mul` branch, which has commits that are not in `main`:

```bash
git checkout feature-mul
```

You can see the files as they exist in this branch. To go back to the `main` branch:

```bash
git checkout main
```

### Viewing a Previous State with `checkout`

You can also use `checkout` to see the repository at a specific point in time. Find a commit hash from the `git log` command (e.g., `862cbc6`) and run:

```bash
git checkout 862cbc6
```
This puts you in a "detached HEAD" state. You can look around, but don't make changes. To get back to your branch, just check it out again:
```bash
git checkout main
```

## 3. Undoing Changes

### Reverting a Commit with `revert`

The `revert` command is a safe way to undo a commit because it creates a new commit that reverses the changes.

Let's say you want to undo the changes from the commit `4a8bad2` ("docs: change repo description") on the `docs-instr` branch.

First, switch to that branch:
```bash
git checkout docs-instr
```

Now, revert the commit:
```bash
git revert 4a8bad2
```
A new commit will be created that undoes the changes from the original commit.

### Resetting to a Previous Commit with `reset`

`reset` is a more powerful and potentially destructive command. Let's practice with a "soft" reset, which is the safest.

Imagine you're on the `feature-mul` branch and you want to go back to the commit `e12c01f`, but keep the changes from `9c203d4` as unstaged changes.

```bash
git checkout feature-mul
git reset --soft e12c01f
```
Now if you run `git status`, you will see the changes from `9c203d4` are ready to be committed.

To discard the reset, you can use `git reset --hard`:
```bash
git reset --hard feature-mul
```
**Warning**: `git reset --hard` will discard all your local changes.

## 4. Integrating Changes

### Merging Branches with `merge`

The `feature-add` branch has already been merged into `main` with a merge commit. Let's try merging another branch. We will merge `feature-sub` into `main`.

First, make sure you are on the `main` branch:
```bash
git checkout main
```

Now, merge the `feature-sub` branch:
```bash
git merge feature-sub
```
This will create a new merge commit.

### Rebasing Branches with `rebase`

Rebase is an alternative to merging. It results in a cleaner, linear history. Let's rebase the `feature-mul` branch onto `main`.

First, switch to the `feature-mul` branch:
```bash
git checkout feature-mul
```

Now, rebase it onto `main`:
```bash
git rebase main
```
This will take the commits from `feature-mul` and apply them on top of the latest commit in `main`.

After the rebase, you can go back to `main` and merge `feature-mul`.
```bash
git checkout main
git merge feature-mul
```
This time, it will be a "fast-forward" merge, meaning it just moves the `main` branch pointer forward to match `feature-mul` without creating a merge commit.
