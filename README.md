# DigiNews

A fully automated GitHub repository that updates its own README.md daily with a curated tech news digest using C++ and the Gemini API.

## Daily Digest

<!-- NEWS_START -->
Last Updated: 2024-07-27 10:30 UTC

*   **Apple Intelligence & iOS 18 Rollout**
    Apple continues to detail its new AI capabilities, "Apple Intelligence," integrated into upcoming iOS 18, iPadOS 18, and macOS Sequoia. Features include enhanced Siri, on-device writing tools, and image generation, with a strong emphasis on privacy and optional ChatGPT integration. Public betas are now widely available for testing.

*   **OpenAI's Shifting Safety Focus**
    OpenAI recently established a new "safety and security committee" to advise on critical AI decisions, following the disbandment of its Superalignment team. This move comes as the company continues to integrate GPT-4o into products and explores new partnerships, including reported discussions with Apple and Microsoft for broader AI deployment.

*   **Nvidia's Unstoppable Market Cap**
    Nvidia's valuation continues its rapid ascent, briefly surpassing tech giants like Apple and even Microsoft to become one of the world's most valuable companies. This surge is fueled by relentless demand for its high-performance AI chips (GPUs), essential for training and deploying large language models.

*   **Google's AI Search Overviews & Gemini Expansion**
    Google is making adjustments and addressing feedback regarding its AI Overviews in search results, aiming to balance helpfulness with accuracy, particularly after some controversial initial responses. Concurrently, the company is pushing the integration of its Gemini AI model more broadly across its suite of products and services.

*   **EU Digital Markets Act (DMA) Enforcement Heats Up**
    Regulatory pressure from the European Union is intensifying under the Digital Markets Act (DMA), with reports suggesting potential antitrust charges are imminent for tech giants like Apple (over App Store policies) and Meta (regarding data usage and user choice), signaling a new era of stricter digital market oversight.
<!-- NEWS_END -->

## How it works

This project uses a GitHub Action to:
1.  Setup a C++ environment (libcurl, nlohmann-json).
2.  Compile the `src/main.cpp` source code.
3.  Run the executable which fetches news from Google Gemini and updates this README.
4.  Commit the changes back to the repository.
