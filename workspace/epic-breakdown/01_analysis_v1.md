# Strategic Analysis: epic-breakdown (Version 1)

## 1. Problem Definition & Goal
- **Task:** The current `think -> plan -> act` workflow is excellent for implementing single, well-defined features. However, it lacks a preliminary step to handle large-scale ideas or "epics" and decompose them into those manageable features.
- **Goal:** Introduce a new capability that allows a user to provide a high-level epic or application concept and receive a structured list of smaller, implementable features as output. This output will then serve as the input for the existing `think` command.

## 2. Investigation & Findings
- **Evidence:** I have analyzed the prompts for the existing `think`, `plan`, and `act` commands in `/commands/mode/`.
- **Current Architecture:** The system uses a sequential, file-based workflow (`think` -> `plan` -> `act`) where each mode builds upon the output of the previous one. Communication between modes is handled via versioned markdown files stored in dedicated `workspace/[feature_name]` directories. The entire workflow is fundamentally feature-centric.
- **Dependencies & Integration Points:** The new command must integrate seamlessly at the beginning of this workflow. Its output (a list of features) needs to be in a format that can be easily fed into the `/mode:think` command, one feature at a time.

## 3. Strategic Options Analysis
### Option A: A New "Epic" Mode (`/mode:epic`)
- **Description:** Introduce a new, distinct command, `/mode:epic`. This command would take a high-level user prompt (the epic), analyze it, and generate a single markdown file (e.g., `00_epic_breakdown.md`) within a new `workspace/epic_[epic_name]` directory. This file would contain a checklist or list of identified features.
- **Pros:**
    -   Creates a clear and logical separation of concerns between "epic decomposition" and "feature implementation."
    -   Follows the existing, successful paradigm of using distinct modes for distinct stages of work.
    -   Provides a clean handoff point, giving the user control over which feature to tackle next and when.
- **Cons:**
    -   Adds another top-level command for the user to learn, slightly extending the core workflow (`epic` -> `think` -> `plan` -> `act`).

### Option B: A Scaffolding Command (`/setup:epic`)
- **Description:** Create a new command within the `setup` group, such as `/setup:epic`. This command would take the epic description and immediately generate a complete directory structure for all identified sub-features (e.g., `workspace/feature-a`, `workspace/feature-b`, etc.), potentially pre-populating each with a boilerplate `01_analysis_v1.md`.
- **Pros:**
    -   Highly automated, reducing manual setup for the user.
    -   Keeps the core `mode` commands focused purely on the implementation lifecycle.
- **Cons:**
    -   Can feel too "magical" and less transparent, as it creates a large number of files and directories at once.
    -   Removes the user from the loop, as they don't get a chance to review the feature breakdown before the workspace is scaffolded.

### Option C: Enhance the `think` command
- **Description:** Modify the `/mode:think` command to intelligently detect whether the input prompt is a high-level epic or a specific feature. If it detects an epic, it would first perform the breakdown, save the list, and then automatically proceed with the analysis of the first feature on that list.
- **Pros:**
    -   Avoids adding any new commands, simplifying the user-facing API.
- **Cons:**
    -   Overloads the `think` command, violating the Single Responsibility Principle and making its internal logic more complex.
    -   It assumes the user wants to immediately start working on the first feature, which may not be the case.
    -   Blurs the clear line that currently exists between the different modes of operation.

## 4. Recommendation & High-Level Plan
### Recommended Strategy
**Option A: A New "Epic" Mode (`/mode:epic`)** is the recommended strategy.

This approach is the most robust and scalable. It respects the project's established configuration-driven and mode-based architecture. It introduces a clear, dedicated step for epic decomposition that logically precedes the feature-implementation workflow. This separation provides a clean handoff (the `00_epic_breakdown.md` file) and empowers the user to review the proposed features before committing to implementation, maintaining the deliberate and transparent nature of the Gemini CLI.

### High-Level Action Plan
- **Component:** `commands/mode/`
  - **Action:** Create a new command file `epic.toml` to define the prompt and behavior for the `/mode:epic` command.
- **Component:** `commands/mode/epic.toml` (New File)
  - **Action:** Write a detailed prompt for the `epic` mode. This prompt should instruct the AI to:
    1.  Take a user's high-level requirement.
    2.  Break it down into a list of smaller, actionable features.
    3.  Create a new directory named `workspace/epic_[epic_name]`.
    4.  Generate a markdown file `00_epic_breakdown_v1.md` inside this new directory, containing the list of features.
- **Component:** `GEMINI.md` & `README.md`
  - **Action:** Update the project documentation to include the new `/mode:epic` command, explaining its purpose and how it fits into the overall workflow.
- **Component:** `commands/mode/README.md`
  - **Action:** Update the README in the `mode` directory to describe the new `epic` command and its relationship to `think`, `plan`, and `act`.

## 5. Success Criteria
The new command is successful when a user can provide a prompt like, "I want to build a blog application," and the `/mode:epic` command generates a markdown file containing a list of features such as "User Authentication," "Create/Edit Posts," "Comment System," and "Admin Dashboard."
