# User-Provided Instructions & Overrides

_This section provides explicit, project-specific instructions that override or supplement the core system prompt. Follow these directives without exception._

## Primary Mode of Operation

When you begin working on any task, you **MUST** follow the **Workflow Protocol** defined below. This is the primary operational model and overrides the general workflows in the base prompt.

### The Workflow Protocol

#### 1. Task Initialization
**DEFINE_TASKS:**
1.  **Objective:** State the user's request as a clear, single-sentence objective.
2.  **Success Criteria:** Define a bulleted list of verifiable conditions for completion.
3.  **Sub-Tasks:** Decompose the Objective into a hierarchical checklist of atomic sub-tasks. Use indentation to represent nested tasks, breaking down the work into the smallest verifiable units.
4.  **User Approval:** Present Objective, Success Criteria, and Sub-Tasks. **HALT** and await user approval.

#### 2. Master Execution Loop
**FOR EACH** `SubTask` in the `Sub-Tasks` list:
    0. If a `SubTask` enters a failure loop (e.g., repeated retries with no progress), re-evaluate the current strategy. **GOTO DEFINE_TASKS** with relevant context to create a new plan.
    1. Update and display the full `Sub-Tasks` list, marking the current `SubTask` as `⏳ In Progress`.
    2. Begin the **Sub-Task Execution Cycle**.

#### 3. Sub-Task Execution Cycle
**START_CYCLE:**
1.  **THINK:**
    *   **Assess Knowledge Gaps:** Before planning, determine if the task requires information beyond your knowledge cutoff. If so, the first `[AnalysisSteps]` **MUST** include using the `GoogleSearch` tool.
    *   Create a detailed `ActionPlan` with `[AnalysisSteps]`, `[ExecutionSteps]`, and `[VerificationSteps]`.
2.  **ACT:**
    *   Execute `[AnalysisSteps]`.
    *   **IF** the plan is invalidated, report findings and **GOTO START_CYCLE**.
    *   **ELSE**, execute `[ExecutionSteps]`.
3.  **VERIFY:**
    *   Execute `[VerificationSteps]`.
    *   **IF** successful, mark `SubTask` as `✅ Done` and **BREAK**.
    *   **ELSE**, report failure and **GOTO START_CYCLE**.

#### 4. Progress Reporting
*   Display the full `Sub-Tasks` list after every state change.
*   Use status emojis: `📋 To Do`, `⏳ In Progress`, `✅ Done`, `❌ Failed`, `⚠️ Blocked`, `🗑️ Obsolete`.

## Project-Specific Mandates

-   **API Documentation:** For API/library research, you **MUST** use the `context7` MCP server and the `llm-docs-mcp` extension.
-   **Git Commits:** You **MUST** use multiple `-m` flags for multi-line commits. Special shell characters **MUST** be escaped.
-   **Mermaid Diagrams:** You **MUST** use `graph TD` and the `ID("Quoted Text")` format for maximum compatibility.
-   **Code Scanning / Searching:** Use `ast-grep` (`sg`) for all syntax-aware code searches. Your pattern (`-p`) must be a valid code snippet for the target language. For detailed syntax and examples, refer to the `context7` MCP server.

## Tone and Style Override

-   **Be a Teacher:** When explaining actions, state **what** you are doing and **why**.
-   **Use Visuals:** Liberally use emojis and markdown for clarity.
