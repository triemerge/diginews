﻿#  DigiNews

> **Automated Tech News Digest**  
> *Powered by Gemini 2.5 Flash & C++*

Every **6 hours**, this repository automatically updates itself with the single most important tech news story, grounded in real-time data using **Google Search**.

---

##  Latest Tech Update

<!-- NEWS_START -->
**Last Updated:** Friday, January 23, 2026 at 6:33 PM UTC

### Anthropic's Claude AI Outperforms Human Engineers in Hiring Tests, Forcing Test Redesign

AI startup Anthropic has encountered a unique challenge in its hiring process as its advanced Claude models, particularly Opus 4 and 4.5, have begun to outperform human candidates on complex engineering tests. The take-home test, designed to assess performance engineers in optimizing code for a simulated accelerator, has been repeatedly redesigned by Anthropic's performance optimization team lead, Tristan Hume. Initially intended to differentiate top human talent, the latest Claude versions were able to match or exceed the performance of most human applicants under the given time constraints, making it difficult for the company to distinguish between top human candidates and its most capable AI. While humans can still outperform the models with unlimited time, the rapid advancement of Claude's capabilities has necessitated the creation of three new versions of the test to maintain its utility as an evaluation tool. Anthropic is also releasing the original take-home test as an open challenge.

**Key Takeaway:** The ability of advanced AI models like Claude to outperform human engineers in complex coding optimization tests highlights a significant leap in AI capabilities, signaling profound implications for future hiring practices and the evolving nature of technical work.
<!-- NEWS_END -->

---

##  How It Works

This project leverages the power of **GitHub Actions** and **Google's Gemini 2.5 Flash** model to deliver high-quality, grounded tech news.

1.  **Timed Trigger**: A workflow runs automatically every 6 hours.
2.  **C++ Engine**: The system spins up and compiles a custom C++ application (`src/main.cpp`).
3.  **AI Analysis**: It sends a request to the Gemini API with **Google Search Grounding** enabled.
4.  **Self-Correction**: The output is validated and committed back to this `README.md`.

---

<div align="center">

*Stay updated with the bleeding edge of technology.*

</div>
