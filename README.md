# Gemini CLI Config

![Build Status](https://img.shields.io/badge/build-passing-brightgreen)
![Version](https://img.shields.io/badge/version-1.0.0-blue)
![License](https://img.shields.io/badge/license-MIT-green)

## Description

This repository contains the configuration files for the Gemini CLI, a powerful command-line tool for AI-assisted software development. It provides a structured, configuration-driven workflow that enables developers to analyze, plan, and execute coding tasks with the help of AI, ensuring consistency and high-quality output.

## Key Features

*   **Structured Development Workflow:** Implements a `think`, `plan`, and `act` methodology for systematic feature development.
*   **Automated Git Operations:** Includes a sophisticated `/git:sync` command to keep forked repositories up-to-date with upstream changes.
*   **Automated Documentation:** Commands to generate and maintain key project documents like `README.md`, `GEMINI.md`, and system design documents.
*   **Configuration-Driven:** Command behavior is defined in simple `.toml` files, making it easy to customize and extend.

## Tech Stack

*   **Primary Language:** TOML (for command configuration)
*   **Execution Environment:** Gemini CLI

## How to Configure Your Gemini CLI

This repository provides a powerful set of configurations to enhance your Gemini CLI. Follow these steps to set up your environment.

### 1. Prerequisites

*   You must have the [Gemini CLI](https://github.com/google/gemini-cli) installed and initialized.
*   You should have a `~/.gemini/` directory in your home folder.

### 2. Clone This Repository

First, clone this repository to a location of your choice on your local machine.

```bash
git clone https://github.com/ksprashanth/gemini-cli-config.git
cd gemini-cli-config
```

### 3. Install the Configurations

You can either copy all the configurations or pick and choose the ones you need.

#### Option A: Install Everything (Recommended)

This is the quickest way to get started.

1.  **Copy the Core `GEMINI.md` Template:**
    This file provides a foundational set of instructions for the AI.
    ```bash
    cp GEMINI.cp ~/.gemini/GEMINI.md
    ```

2.  **Copy All Commands:**
    This will give you access to all the custom commands like `/git:sync` and the `/mode:*` workflow.
    ```bash
    cp -r commands/ ~/.gemini/
    ```

3.  **Copy the Settings File:**
    This file includes pre-configured MCP (Multi-Context Prompt) servers for GitHub and Context7.
    > **Warning:** This will overwrite your existing `settings.json`. If you have existing settings, you should merge the files manually.

    ```bash
    cp settings.json ~/.gemini/
    ```

#### Option B: Install Specific Components

If you only want certain commands or settings, you can copy them individually.

*   **To copy only the `git` commands:**
    ```bash
    mkdir -p ~/.gemini/commands/git
    cp commands/git/* ~/.gemini/commands/git/
    ```

*   **To copy only the `mode` workflow commands:**
    ```bash
    mkdir -p ~/.gemini/commands/mode
    cp commands/mode/* ~/.gemini/commands/mode/
    ```

### 4. Configure the GitHub MCP Server

To use the powerful GitHub integration (which enables the AI to interact with GitHub repositories), you need to create a Personal Access Token (PAT).

1.  **Create a GitHub PAT:**
    *   Go to [github.com/settings/tokens](https://github.com/settings/tokens) and click **"Generate new token"**.
    *   Give it a descriptive name (e.g., "gemini-cli").
    *   Set an expiration date.
    *   Under **"Repository access"**, select **"All repositories"** or choose the specific ones you want the AI to access.
    *   Grant the following permissions under **"Repository permissions"**:
        *   `Contents`: Read & Write
        *   `Pull Requests`: Read & Write
        *   `Issues`: Read & Write
        *   `Metadata`: Read-Only (this is the default)
    *   Click **"Generate token"** and copy the token immediately.

2.  **Set the Environment Variable:**
    The `settings.json` file is configured to read the token from an environment variable named `GITHUB_PERSONAL_ACCESS_TOKEN`. You need to add this to your shell's startup file.

    *   **For Zsh (macOS default):**
        ```bash
        echo 'export GITHUB_PERSONAL_ACCESS_TOKEN="YOUR_TOKEN_HERE"' >> ~/.zshrc
        source ~/.zshrc
        ```

    *   **For Bash:**
        ```bash
        echo 'export GITHUB_PERSONAL_ACCESS_TOKEN="YOUR_TOKEN_HERE"' >> ~/.bash_profile
        source ~/.bash_profile
        ```
    > **Remember to replace `YOUR_TOKEN_HERE` with the actual token you copied from GitHub.**

### 5. Verify the Installation

You're all set! Restart the Gemini CLI. Once it has loaded, type the following command in the Gemini CLI prompt to see if the new commands are available:

`/help`

You should see the new commands like `/git:sync` and `/mode:think` listed in the output.


## Running Tests

This project does not contain an automated test suite. The configurations are tested by executing the commands within the Gemini CLI.

## Contributing

Contributions are welcome! If you have ideas for new commands or improvements to existing ones, please follow this workflow:

1.  Fork the repository.
2.  Create a new branch (`git checkout -b feature/your-feature-name`).
3.  Make your changes and commit them with a descriptive message.
4.  Push to the branch (`git push origin feature/your-feature-name`).
5.  Open a Pull Request.

## License

This project is licensed under the MIT License.
