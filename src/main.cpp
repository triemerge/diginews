#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <cstdlib>
#include <thread>
#include <chrono>

// For convenience
using json = nlohmann::json;

// Callback function for libcurl to write data into a string
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string get_gemini_response(const std::string& prompt, const std::string& api_key) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if(curl) {
        std::string url = "https://generativelanguage.googleapis.com/v1beta/models/gemini-2.5-flash:generateContent?key=" + api_key;
        
        // Construct the JSON payload
        json payload = {
            {"contents", {
                {
                    {"parts", {
                        {{"text", prompt}}
                    }}
                }
            }}
        };

        std::string json_str = payload.dump();

        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_str.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
        
        if(res != CURLE_OK)
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }
    return readBuffer;
}

void update_readme(const std::string& news_content) {
    std::string filename = "README.md";
    std::ifstream file_in(filename);
    
    if (!file_in.is_open()) {
        std::cerr << "Could not open " << filename << std::endl;
        return;
    }

    std::stringstream buffer;
    buffer << file_in.rdbuf();
    std::string content = buffer.str();
    file_in.close();

    // Define markers
    std::string start_marker = "<!-- NEWS_START -->";
    std::string end_marker = "<!-- NEWS_END -->";

    size_t start_pos = content.find(start_marker);
    size_t end_pos = content.find(end_marker);

    if (start_pos != std::string::npos && end_pos != std::string::npos) {
        // Construct new content
        std::string new_content = content.substr(0, start_pos + start_marker.length());
        new_content += "\n" + news_content + "\n";
        new_content += content.substr(end_pos);

        std::ofstream file_out(filename);
        if (file_out.is_open()) {
            file_out << new_content;
            std::cout << "README.md updated successfully." << std::endl;
        } else {
            std::cerr << "Could not write to " << filename << std::endl;
        }
    } else {
        std::cerr << "Markers not found in README.md" << std::endl;
    }
}

int main() {
    const char* env_api_key = std::getenv("GEMINI_API_KEY");
    if (!env_api_key) {
        std::cerr << "GEMINI_API_KEY environment variable not found." << std::endl;
        return 1;
    }
    std::string api_key = env_api_key;

    std::string prompt = "Generate a concise digest of the top 5 most important tech news stories from the last 24 hours. Format it as a Markdown list with bold titles and short summaries. Include a 'Last Updated' timestamp at the top.";

    int max_retries = 5;
    for (int i = 0; i < max_retries; ++i) {
        if (i > 0) {
            std::cout << "Retrying request (" << i << "/" << max_retries << ")..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(10));
        }

        std::string response = get_gemini_response(prompt, api_key);
        
        if (response.empty()) {
            std::cerr << "Empty response from API." << std::endl;
            continue;
        }

        try {
            json response_json = json::parse(response);
            
            // Check for success
            if (response_json.contains("candidates") && !response_json["candidates"].empty()) {
                std::string generated_text = response_json["candidates"][0]["content"]["parts"][0]["text"];
                update_readme(generated_text);
                return 0; // Success!
            } 
            
            // Check for overload error (503)
            if (response_json.contains("error")) {
                int code = response_json["error"].value("code", 0);
                std::string msg = response_json["error"].value("message", "Unknown error");
                
                if (code == 503) {
                    std::cerr << "Server is overloaded (503). " << msg << std::endl;
                    continue; // Retry
                }
                
                // Fatal error
                std::cerr << "API Error " << code << ": " << msg << std::endl;
                return 1;
            }

        } catch (json::parse_error& e) {
            std::cerr << "JSON parse error: " << e.what() << std::endl;
        } catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    std::cerr << "Max retries exceeded." << std::endl;
    return 1;
}
