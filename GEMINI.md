# Technical preferences when building out applications

## Preferred Gemini models and order of priority
Use the following Gemini models as per the defined priority whenever you have to work on the kind of tasks below, unless specifically instructed otherwise.
1. Image Generation
   - gemini-3-pro-image-preview (Nano Banana Pro) [API: generate_content]
   - gemini-2.5-flash-image (Nano Banana) [API: generate_content]
   - imagen-4.0-ultra-generate-001 [API: generate_images]
   - imagen-4.0-generate-001 [API: generate_images]

2. General Purpose/Verification/Multi-model input and analysis
   - gemini-3-pro-preview [API: generate_content]
   - gemini-3-flash-preview [API: generate_content]
   - gemini-2.5-pro [API: generate_content]
   - gemini-2.5-flash [API: generate_content]

## Preferred package managers and stacks
Use the following package manages and stacks when working on the following programming languages unless otherwise instructed
1. Python
   - FastAPI for any backend work exposing services / APIs
   - Use 'uv' for managing dependencies and adding / removing packages, and managing the virtual environment
   - Use Gradio for building any sample UI apps and prototyping frontends for AI apps
2. Javascript / Typescript / Nodejs
   - Use 'pnpm' for managing packages and dependencies
3. Gemini SDK / API
   - When using Gemini use the Google Gen AI SDK - '@google/genai' for javascript / typscript, 'google-genai' for python, etc. This is non negotiable for AI apps on Gemini models.
   - Refer to https://ai.google.dev/gemini-api/docs/quickstart for the docs on Google Gen AI SDK.
   - Use Google ADK - 'google-adk' in python, '@google/adk' for typescript / javascript etc. Refer to https://google.github.io/adk-docs/get-started/ for docs.
## General programming guidelines
   - Always document functions with docstrings, including desription, what it does and import / return params
   - Always use compile-time type-safety in any language that supports it, including Python and Javascript.
   - Use linters, prettifiers, and static code checks at all times and set it up in the build rules of the language project we are working on, if not already present.
   - Prefer Google Style guides for Javascript, Typescript, Python, Go etc. at all times and if unspecified, unless the project uses a different style either inferred or documented.

## Test Driven Development
   - TDD is the king!. Always implement tests for the smallest feature and then implement the working functionality. Add more tests and repeat till the desired functionality is met.
   - Ensure 100% unit test coverage and appropriate mocks and stubs where required. I don't want any leaky errors. 
  
