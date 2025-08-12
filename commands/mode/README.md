# Gemini CLI: Mode Commands

This directory contains the configuration for the `think`, `plan`, and `act` commands, which together form a structured, feature-centric workflow for software development. This workflow ensures that every change is properly analyzed, planned, and executed in a safe and versioned manner.

The commands are designed to be used in sequence:

1.  **`/mode:think`**: Analyze the problem and create a strategic plan.
2.  **`/mode:plan`**: Create a detailed, step-by-step implementation plan.
3.  **`/mode:act`**: Execute the implementation plan and document the results.

---

## Workflow

The core of this system is a feature-centric workspace located in the `workspace/` directory. Each feature gets its own directory where all related documents are stored in a versioned sequence.

### 1. 🤔 `/mode:think <feature_name>`

-   **Purpose**: To act as a principal engineer or solution architect. This mode is for deep analysis of a feature request or bug. It investigates the codebase and produces a strategic document outlining the problem, exploring options, and recommending a high-level approach.
-   **Process**:
    1.  It first checks if a directory for `<feature_name>` exists in the `workspace/`.
    2.  If the feature is **new**, it creates the directory and a version 1 analysis file: `workspace/<feature_name>/01_analysis_v1.md`.
    3.  If the feature is **existing**, it finds the latest analysis version and creates the next one (e.g., `01_analysis_v3.md` if `v2` was the latest).
-   **Output**: A markdown file containing a detailed strategic analysis. **This command does not modify any code.**

### 2. 📝 `/mode:plan <feature_name>`

-   **Purpose**: To act as a senior engineer. This mode translates the strategy from the `think` phase into a concrete, step-by-step implementation plan.
-   **Process**:
    1.  It locates the **latest** analysis file (e.g., `01_analysis_v3.md`) for the given `<feature_name>`.
    2.  It creates a new plan file with the **same version number** (e.g., `02_plan_v3.md`). This plan contains specific commands, code changes, and verification steps.
-   **Output**: A markdown file containing a detailed implementation plan. **This command does not execute any code.**

### 3. 🚀 `/mode:act <feature_name>`

-   **Purpose**: To act as a diligent software engineer. This mode executes the implementation plan created in the `plan` phase.
-   **Process**:
    1.  It locates the **latest** plan file (e.g., `02_plan_v3.md`).
    2.  It presents the plan to the user as a checklist and executes each step sequentially.
    3.  It verifies each step before proceeding and updates the checklist with the status (✅, ❌).
    4.  If all steps are successful, it creates a final review document with the **same version number** (e.g., `03_review_v3.md`).
-   **Output**: A review document summarizing the execution and its outcome. **This is the only mode that modifies the codebase.**