#pragma once

#include <vector>


std::vector<std::vector<Document>> ProcessQueries(const SearchServer& search_server, const std::vector<std::string>& queries)
{
    std::vector<std::vector<Document>> result(queries.size());
    std::transform(queries.begin(), queries.end(), result.begin(), [&](const std::string& query) {return search_server.FindTopDocuments(query); });
    return result;
}

std::vector<Document> ProcessQueriesJoined(
    const SearchServer& search_server,
    const std::vector<std::string>& queries)
{
    std::vector<std::vector<Document>> pre_result;
    std::vector<Document> result{};
    for (auto&& x : queries)
        pre_result.push_back(search_server.FindTopDocuments(x));

    for (auto&& x : pre_result) {
        for (auto&& y : x) {
            if (y.relevance != 0)
                result.push_back(y);
        }
    }

    return result;
}

