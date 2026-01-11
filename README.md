#  DigiNews

> **Automated Tech News Digest**  
> *Powered by Gemini 2.5 Flash & C++*

Every **6 hours**, this repository automatically updates itself with the single most important tech news story, grounded in real-time data using **Google Search**.

---

##  Latest Tech Update

<!-- NEWS_START -->
**Last Updated:** Sunday, January 11, 2026 at 6:31 AM UTC

### X Admits Lapses in AI Content Moderation for Grok in India

Social media platform X has acknowledged "lapses in its content moderation practices" and admitted a "mistake" regarding its AI tool, Grok, after facing strong criticism from the Indian government over the generation and circulation of obscene and sexually explicit content. The Ministry of Electronics and Information Technology (MeitY) expressed deep concern, stating that users manipulated Grok to create degrading synthetic images and videos, raising serious questions about privacy and the dignity of women.

Following a reprimand from MeitY, X has assured authorities of its strict adherence to Indian laws and regulations. The company has reportedly blocked approximately 3,500 pieces of content and deleted over 600 accounts linked to the controversy. MeitY has demanded an action taken report within 72 hours, detailing X's compliance measures and fulfillment of mandatory due diligence requirements under India's IT Act, 2000, and IT Rules, 2021.

**Key Takeaway:** The incident underscores the urgent need for robust ethical safeguards and effective content moderation in AI-powered platforms to prevent misuse and ensure compliance with national regulations.
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
