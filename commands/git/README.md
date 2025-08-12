# Git Sync Command

This directory contains the configuration for the `/git:sync` command, a powerful tool for synchronizing a forked Git repository.

## Command: `/git:sync`

### Description

The `/git:sync` command automates the process of updating a forked repository. It's designed to seamlessly bring your local environment up-to-date with the original parent repository (referred to as `upstream`) and then push those updates to your own forked repository (referred to as `origin`).

The command provides a real-time log of its operations, indicating the success, failure, or status of each step.

### Synchronization Process

The `/git:sync` command follows a comprehensive, multi-phase process to ensure a safe and thorough synchronization:

1.  **Pre-flight Checks:**
    *   It begins by checking for any uncommitted changes in your local repository. If it finds any, it automatically stashes them with a descriptive message.
    *   It records the name of your current branch to return to it at the end of the process.

2.  **Remote & Upstream Management:**
    *   The command verifies that an `upstream` remote is configured. If not, it attempts to automatically identify and add the parent repository as the `upstream`.
    *   It then fetches the latest changes from both the `origin` and `upstream` remotes, pruning any stale branches.

3.  **Core Synchronization:**
    *   The command identifies the default branch (usually `main` or `master`).
    *   It switches to the default branch and merges the latest changes from the `upstream` repository into your local repository.
    *   The updated local branch is then pushed to your `origin` remote.

4.  **Feature Branch & Finalization:**
    *   The command switches back to your original branch.
    *   If you were on a feature branch, it automatically rebases that branch onto the newly updated default branch.
    *   The rebased feature branch is then safely force-pushed to `origin` using the `--force-with-lease` option to prevent overwriting remote changes.
    *   Finally, if any changes were stashed at the beginning of the process, they are reapplied.

5.  **Final Summary:**
    *   Upon completion, the command displays a consolidated report of all the actions it performed.

### Autonomous Logic

A key feature of the `/git:sync` command is its ability to determine and execute the synchronization strategy autonomously. It is designed to make all decisions about the necessary Git operations without requiring user input on *what* to do next.

However, please note that for security reasons, the Gemini CLI will still ask for your confirmation before running each `git` or `gh` command.

The command will only pause its autonomous logic and prompt for user intervention if it encounters a situation that it cannot resolve on its own, such as a merge or rebase conflict.