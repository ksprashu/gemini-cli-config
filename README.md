# Gemini CLI Config

![Build Status](https://img.shields.io/badge/build-passing-brightgreen)
![Version](https://img.shields.io/badge/version-1.0.0-blue)
![License](https://img.shields.io/badge/license-MIT-green)

## Description

This repository contains the configuration files for the Gemini CLI, a powerful command-line tool for AI-assisted software development. It provides a structured, configuration-driven workflow that enables developers to analyze, plan, and execute coding tasks with the help of AI, ensuring consistency and high-quality output.

## Key Features

*   **Structured Development Workflow:** Implements a `think`, `plan`, and `act` methodology for systematic feature development.
*   **Expert Git Workflow:** Provides `/repo:save` for rapid, local-only atomic checkpoints and `/repo:sync` for intelligently synchronizing with remote repositories using best practices.
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

You have two options for installing these configurations. You can either copy the files directly or use symbolic links to automatically sync any changes from this repository.

---

### Option 1: Copy Files (Simple)

This method is straightforward and involves copying the files into your Gemini configuration directory.

1.  **Copy the Core `GEMINI.md` Template:**
    This file provides a foundational set of instructions for the AI.
    ```bash
    cp GEMINI.cp ~/.gemini/GEMINI.md
    ```

2.  **Copy the Command Palettes:**
    You can copy all command palettes or pick and choose the ones you want.

    *   **To copy all commands:**
        ```bash
        cp -r commands/* ~/.gemini/commands/
        ```
    *   **To copy specific command palettes (e.g., `repo` and `mode`):**
        ```bash
        mkdir -p ~/.gemini/commands
        cp -r commands/repo ~/.gemini/commands/
        cp -r commands/mode ~/.gemini/commands/
        cp -r commands/setup ~/.gemini/commands/
        ```

3.  **Copy the Settings File:**
    This file includes pre-configured MCP (Multi-Context Prompt) servers for GitHub and Context7.
    > **Warning:** This will overwrite your existing `settings.json`. If you have existing settings, you should merge the files manually.

    ```bash
    cp settings.json ~/.gemini/
    ```

---

### Option 2: Use Symbolic Links (Recommended for Developers)

This method links the configuration files from this repository directly to your Gemini setup. Any time you run `git pull` to get the latest updates, your CLI is instantly updated.

> **Note:** Make sure you are in the root of this cloned repository before running these commands.

1.  **Link the Core `GEMINI.md` Template:**
    This links the base AI instructions file.
    ```bash
    # Remove the copied file if it exists
    rm -f ~/.gemini/GEMINI.md
    # Create the symbolic link
    ln -s "$(pwd)/GEMINI.cp" ~/.gemini/GEMINI.md
    ```

2.  **Link Your Desired Command Palettes:**
    Instead of linking the entire `commands` folder, you can link specific command palettes. This allows you to choose which sets of commands you want to use.

    ```bash
    # Create the commands directory if it doesn't exist
    mkdir -p ~/.gemini/commands

    # Example: Link the 'repo', 'mode', and 'setup' palettes
    ln -s "$(pwd)/commands/repo" ~/.gemini/commands/repo
    ln -s "$(pwd)/commands/mode" ~/.gemini/commands/mode
    ln -s "$(pwd)/commands/setup" ~/.gemini/commands/setup
    ```

3.  **A Note on `settings.json`:**
    We **do not** recommend symlinking the `settings.json` file, as it contains your personal preferences which you don't want to overwrite. Instead, you should manually merge the `mcpServers` configuration from this repository's `settings.json` into your own `~/.gemini/settings.json` file.

---

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

You should see the new commands like `/repo:save`, `/repo:sync`, and `/mode:think` listed in the output.

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