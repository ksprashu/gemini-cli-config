# Gemini CLI: Mode Commands

This directory contains the configuration for the `think`, `plan`, and `act` commands. Together, they form a structured, feature-centric workflow that mirrors a modern software development team, ensuring every change is properly analyzed, planned, and implemented with resilience and clarity.

The commands are designed to be used in sequence, representing a complete development cycle for a single feature or bugfix.

---

## The Workflow Philosophy: Architect -> Lead -> Developer

This workflow is designed to maximize the strengths of the AI at each stage, creating a process that is both powerful and resilient.

1.  **`/mode:think` (The Architect):** High-level analysis and strategic direction.
2.  **`/mode:plan` (The Technical Lead):** Breaking down the strategy into a clear, actionable checklist.
3.  **`/mode:act` (The Developer):** Intelligently implementing each task on the checklist.

---

## Workflow Steps

The core of this system is a feature-centric workspace located in the `workspace/` directory. Each feature gets its own directory where all related documents are stored in a versioned sequence.

### 1. 🤔 `/mode:think <feature_name>`

-   **Purpose**: To act as a **Principal Architect**. This mode is for deep, creative, and critical analysis of a feature request or bug. It investigates the codebase, explores multiple solutions, and produces a strategic document recommending a high-level approach.
-   **Process**:
    1.  It follows a "Live Log" process, keeping the user informed of its analysis steps.
    2.  It identifies if the feature is new or existing to determine the version number.
    3.  It creates a versioned analysis file (e.g., `01_analysis_v1.md`).
-   **Output**: A markdown file containing a detailed strategic analysis. **This command does not modify any code.**

### 2. 📝 `/mode:plan <feature_name>`

-   **Purpose**: To act as a **Technical Lead**. This mode translates the high-level strategy from the `think` phase into a concrete, step-by-step checklist for the developer agent.
-   **Process**:
    1.  It reads the latest analysis file from the `think` phase.
    2.  It creates a new plan file with the **same version number** (e.g., `02_plan_v2.md`).
    3.  **Crucially, this plan does NOT contain code snippets.** Instead, it contains clear, natural-language instructions for each task.
    4.  After creating the plan, it will **stop and wait** for the user to initiate the next step (`/mode:act`).
-   **Output**: A markdown file containing a detailed, instructional checklist. **This command does not execute any code and will halt execution upon completion.**

### 3. 🚀 `/mode:act <feature_name>`

-   **Purpose**: To act as a **Diligent Software Developer**. This mode intelligently executes the instructional checklist created in the `plan` phase.
-   **Process**:
    1.  It presents the plan to the user as a "Live Log" checklist.
    2.  For each task, it performs an **"Read -> Implement -> Verify"** loop.
        -   **Read:** It reads the current state of the necessary files.
        -   **Implement:** It uses its understanding to apply the instructed change.
        -   **Verify:** It runs the specified verification step (e.g., linter, tests).
    3.  It updates the checklist with the status (✅, ⏳, ❌) as it progresses. If a step fails, it will attempt to self-correct before stopping.
    4.  If all steps are successful, it creates a final review document (e.g., `03_review_v3.md`).
-   **Output**: A review document summarizing the execution. **This is the only mode that modifies the codebase.**
