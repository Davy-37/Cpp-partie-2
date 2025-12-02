#include "KNNString.h"
#include <algorithm>
#include <vector>

KNNString::KNNString(int k)
    : KNN<std::vector<std::string>>(k) {}


int KNNString::levenshteinDistance(const std::string& s1,
    const std::string& s2) {
    const std::size_t m = s1.size();
    const std::size_t n = s2.size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    for (std::size_t i = 0; i <= m; ++i) dp[i][0] = static_cast<int>(i);
    for (std::size_t j = 0; j <= n; ++j) dp[0][j] = static_cast<int>(j);

    for (std::size_t i = 1; i <= m; ++i) {
        for (std::size_t j = 1; j <= n; ++j) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            dp[i][j] = std::min({
                dp[i - 1][j] + 1,        
                dp[i][j - 1] + 1,        
                dp[i - 1][j - 1] + cost      
                });
        }
    }
    return dp[m][n];
}


double KNNString::similarityMeasure(const std::vector<std::string>& a,
    const std::vector<std::string>& b) const {
    std::size_t len = std::min(a.size(), b.size());
    int total = 0;
    for (std::size_t i = 0; i < len; ++i) {
        total += levenshteinDistance(a[i], b[i]);
    }
   
    return static_cast<double>(total);
}
