#  DigiNews

> **Automated Tech News Digest**  
> *Powered by Gemini 2.5 Flash & C++*

Every **6 hours**, this repository automatically updates itself with the single most important tech news story, grounded in real-time data using **Google Search**.

---

##  Latest Tech Update

<!-- NEWS_START -->
**Last Updated:** Monday, January 12, 2026 at 6:36 AM UTC

### Meta Deactivates Over Half a Million Underage Accounts Following Australian Social Media Ban

Meta has announced that it deactivated more than 544,000 accounts belonging to users under 16 across its Facebook, Instagram, and Threads platforms in Australia. This action comes in the wake of a new Australian ban on social media for individuals under the age of 16, which came into effect a month prior. The deactivated accounts include 330,639 on Instagram, 173,497 on Facebook, and 39,916 on Threads.

The company began deactivating these accounts between December 4 and December 11, 2025, after the ban became law. Meta stated that ongoing compliance with the new regulation will be a "multi-layered process" that they will continue to refine, while reiterating concerns about establishing age online without a universal industry standard. Other major platforms affected by the ban, including Twitch, Kick, YouTube, X, TikTok, and Reddit, had also implemented age checks by December 10, 2025. The Australian government's eSafety commissioner has reportedly inquired about the number of deactivated accounts but has not yet released the data. The effectiveness of the ban and how teens might circumvent it by migrating to other platforms not initially covered is being closely monitored globally.

**Key Takeaway:** Meta's mass deactivation of underage accounts in Australia marks a significant, immediate consequence of new social media regulations, highlighting the challenges and impacts of age verification and online child safety policies on major tech platforms.
<!-- NEWS_END -->

---

##  How It Works

This project leverages the power of **GitHub Actions** and **Google's Gemini 2.5 Flash** model to deliver high-quality, grounded tech news.

1.  **Timed Trigger**: A workflow runs automatically every 6 hours.
2.  **C++ Engine**: The system spins up and compiles a custom C++ application (`src/main.cpp`).
3.  **AI Analysis**: It sends a request to the Gemini API with **Google Search Grounding** enabled.
4.  **Self-Correction**: The output is validated and committed back to this `README.md`.

### The System Prompt

To ensure high relevance and accuracy, we use a strictly engineered prompt:

> "Provide exactly one single most important latest tech news story from the last 6 hours. Ground this news with a Google Search to ensure it is accurate and up-to-date. Quality is more important than quantity..."

---

<div align="center">

*Stay updated with the bleeding edge of technology.*

</div>
