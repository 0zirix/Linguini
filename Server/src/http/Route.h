#pragma once

#include <string>
#include <unordered_map>
#include <vector>

struct Route {
	std::string name;
	std::string alias;
	std::string url;
	std::string method;
	std::string callback;
	std::unordered_map<std::string, std::string> params;
	std::vector<std::string> middlewares;

	inline void bindParams(const std::smatch& matches) {
		int i = 0;
		auto it = params.begin();

		for (auto it = params.begin(); it != params.end(); ++it, ++i) {
			for (int j = 1; j < matches.size(); ++j) {
				if (i == j - 1)
					it->second = matches[j].str();
			}
		}
	}
};
