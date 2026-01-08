# DigiNews

A fully automated GitHub repository that updates its own README.md daily with a curated tech news digest using C++ and the Gemini API.

## Daily Digest

<!-- NEWS_START -->
*No news yet. The first update will arrive shortly.*
<!-- NEWS_END -->

## How it works

This project uses a GitHub Action to:
1.  Setup a C++ environment (libcurl, nlohmann-json).
2.  Compile the `src/main.cpp` source code.
3.  Run the executable which fetches news from Google Gemini and updates this README.
4.  Commit the changes back to the repository.
