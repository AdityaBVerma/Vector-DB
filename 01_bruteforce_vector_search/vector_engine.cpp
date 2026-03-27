#include "vector_engine.h"

#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>

void VectorEngine::insert(const std::vector<float>& embedding, const std::string& text) {
    embeddings.push_back(embedding);
    texts.push_back(text);
}

float cosine(const std::vector<float>& a, const std::vector<float>& b) {
    float dot = 0.0f, na = 0.0f, nb = 0.0f;

    int n = std::min(a.size(), b.size());

    for (int i = 0; i < n; i++) {
        dot += a[i] * b[i];
        na  += a[i] * a[i];
        nb  += b[i] * b[i];
    }

    if (na == 0.0f || nb == 0.0f) return 0.0f;

    return dot / (std::sqrt(na) * std::sqrt(nb));
}

std::vector<std::string> VectorEngine::search(const std::vector<float>& query) {
    std::priority_queue<
        std::pair<float, int>,
        std::vector<std::pair<float, int>>,
        std::greater<std::pair<float, int>>
    > pq;

    for (int i = 0; i < embeddings.size(); i++) {
        float sim = cosine(query, embeddings[i]);

        pq.push({sim, i});
        if (pq.size() > 10) {
            pq.pop();
        }
    }

    std::vector<std::string> ans;

    while (!pq.empty()) {
        ans.push_back(texts[pq.top().second]);
        pq.pop();
    }

    std::reverse(ans.begin(), ans.end());

    return ans;
}