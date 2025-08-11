# Gemini CLI

![Build Status](https://img.shields.io/badge/build-passing-brightgreen)
![Version](https://img.shields.io/badge/version-1.0-blue)
![License](https://img.shields.io/badge/license-MIT-green)

## Description

The Gemini CLI is a powerful, AI-driven command-line interface designed to understand and execute complex software engineering tasks. It leverages a large language model to streamline development workflows through a structured, multi-step process of analysis, planning, and execution.

This project contains the complete configuration, command definitions, and operational data for the Gemini CLI. Its architecture is modular and configuration-driven, centered around a `Think -> Plan -> Act` workflow, making it a flexible and extensible tool for developers.

## Key Features

-   **AI-Powered Task Execution:** Understands natural language requests to perform complex software engineering tasks.
-   **Structured Workflow:** Follows a `Think -> Plan -> Act` process for robust and predictable task handling.
-   **Configuration-Driven:** Define custom commands and behaviors easily using simple `.toml` files.
-   **Workspace Management:** Organizes all task-related files (analysis, plans, reviews) in a dedicated `workspace` directory.
-   **Extensible Architecture:** Designed to be modular, allowing for the addition of new commands and extensions.

## Tech Stack

-   **Core:** Shell, TOML, Markdown, JSON
-   **AI Model:** Google Gemini Family

## Installation and Setup

The Gemini CLI is a self-contained application. The primary setup involves ensuring the directory structure is intact and the necessary configuration files are present.

1.  **Prerequisites:**
    *   A compatible shell environment (e.g., bash, zsh).
    *   Access to the Google Gemini API.

2.  **Clone the repository:**
    ```bash
    git clone <repository-url>
    ```

3.  **Install Dependencies:**
    There are no external packages to install via a package manager.

4.  **Configure Environment:**
    *   Ensure your Google Cloud credentials are set up in `oauth_creds.json`.
    *   Review and customize settings in `settings.json` as needed.

## Usage

The primary way to use the Gemini CLI is by invoking one of its core operational modes or a custom command.

**Example: Enhancing a feature**

1.  **Think:** Analyze the requirements for the new feature.
    ```bash
    gemini think "Enhance the login feature with multi-factor authentication"
    ```
2.  **Plan:** Create a detailed implementation plan based on the analysis.
    ```bash
    gemini plan "Enhance the login feature with multi-factor authentication"
    ```
3.  **Act:** Execute the plan to implement the feature.
    ```bash
    gemini act "Enhance the login feature with multi-factor authentication"
    ```

## Running Tests

There is no automated test suite for this project. Verification is performed by manually executing the different modes and commands and checking their outputs, as demonstrated in the development of the `/setup:feature` command.

## Contributing

Contributions are welcome! If you have ideas for new features or improvements, please follow this process:

1.  Fork the repository.
2.  Create a new branch (`git checkout -b feature/your-feature-name`).
3.  Make your changes.
4.  Submit a pull request with a clear description of your changes.

## License

This project is licensed under the MIT License.
