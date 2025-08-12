# Gemini CLI: Setup Commands

This directory contains commands designed to bootstrap and maintain key project documentation and configuration files. These commands analyze the codebase to generate high-quality, structured documents that are essential for developers and AI collaborators.

## Command Overview

### `/setup:readme`

-   **Purpose:** Creates or intelligently updates the root `README.md` file.
-   **Workflow:** This command analyzes the entire project to generate a professional and comprehensive `README.md`. It infers the project's name, description, tech stack, installation steps, usage instructions, and testing procedures from the codebase and metadata files (like `package.json`). If a `README.md` already exists, it enhances it based on best practices.

### `/setup:design`

-   **Purpose:** Generates a comprehensive system design document located at `docs/design.md`.
-   **Workflow:** It performs a deep scan of the repository to understand the architecture. Using the 4+1 architectural view model, it generates detailed explanations and Mermaid UML diagrams for the system's logical, development, process, and deployment views. It also documents the core data model and cross-cutting concerns like security and scalability.

### `/setup:features`

-   **Purpose:** Generates and maintains a set of agile Product Feature Documents.
-   **Workflow:** This command is non-destructive. It discovers features by analyzing implementation review files (`03_review_v*.md`), design documents, and the source code itself. For any newly discovered features, it generates individual PRD files in `docs/features/` and appends a link to them in the master index file, `docs/features.md`.

### `/setup:gemini`

-   **Purpose:** Bootstraps or updates the `GEMINI.md` file, which serves as a foundational context guide for AI models.
-   **Workflow:** It analyzes the project to infer coding conventions, architectural patterns, key technologies, and development workflows. It generates a detailed `GEMINI.md` file while carefully preserving a special user-defined section. This allows human developers to provide explicit instructions and overrides that guide AI collaboration, ensuring generated code aligns with project standards.
