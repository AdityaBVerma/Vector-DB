#pragma once
#include <vector>
#include <string>

class VectorEngine {
public:
    std::vector<std::vector<float>> embeddings;
    std::vector<std::string> texts;

    void insert(const std::vector<float>& embedding, const std::string& text);
    std::vector<std::string> search(const std::vector<float>& query);
};