# Repo Command Palette

This directory contains an expert set of commands designed to streamline your Git workflow, separating your local development from remote synchronization for maximum efficiency and a clean project history.

## The Workflow Philosophy

This command suite is built on a simple, powerful idea:

1.  **Save Locally (Inner Loop):** Your day-to-day work should be fast and offline. You should be able to create clean, atomic checkpoints of your work without worrying about the state of the remote repository.
2.  **Sync Remotely (Outer Loop):** When you're ready to share your work or get updates from others, a single, powerful command should handle all the complexities of integrating with remote repositories.

---

## Commands

### `/repo:commit`

*   **Purpose:** A high-frequency assistant for your "inner loop" development. It operates **exclusively on your local machine**.
*   **Description:** This command automates the creation of clean, atomic, local commits. It analyzes all uncommitted changes, groups them into logical commits, and generates conventional commit messages.

*   **Execution Flow:**
    1.  **Phase 1: Pre-flight Checks:** Verifies there are uncommitted changes to process.
    2.  **Phase 2: Commit Planning:** Autonomously analyzes the `git diff` to group changes logically (e.g., by feature, docs, dependencies) and generates conventional commit messages for each group. It then presents this plan to you for approval.
    3.  **Phase 3: Execution:** Upon your approval, it stages and commits each group of files as planned.
    4.  **Phase 4: Final Review:** Runs `git status` to ensure the working directory is clean.
    5.  **Phase 5: Final Summary:** Displays a log of the commits that were just created.

### `/repo:sync`

*   **Purpose:** A comprehensive tool for your "outer loop" synchronization with `origin` and `upstream` remotes.
*   **Description:** This command intelligently synchronizes your local repository, ensuring a clean, linear history. It's designed to handle everything from fetching updates to suggesting pull requests.

*   **Execution Flow:**
    1.  **Phase 1: Pre-flight Checks:** Automatically stashes any uncommitted changes, fetches all remotes, and identifies the `upstream` repository and default branch.
    2.  **Phase 2: Core Synchronization:** Updates the local default branch from `upstream` (if it exists), then pushes it to `origin`. It then rebases your current feature branch onto the updated default branch to incorporate the latest changes.
    3.  **Phase 3: Contribution Analysis:** Checks if your fork is ahead of the `upstream` repository. If it is, and no pull request exists, it will suggest creating one.
    4.  **Phase 4: Verification & Cleanup:** Restores any changes that were auto-stashed at the beginning and runs a final `git status` to ensure the repository is clean.
    5.  **Phase 5: Finalization:** Displays a consolidated summary report of all actions performed.

---

## Recommended Workflow

1.  As you work on a feature, use `/repo:commit` frequently to commit your progress in a series of small, logical steps.
2.  When you are ready to push your work or get the latest updates from the main branch, run `/repo:sync` once. It will take all the neat commits you made and seamlessly integrate them with the remote repository.
