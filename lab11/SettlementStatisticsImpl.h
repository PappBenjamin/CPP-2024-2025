#ifndef SETTLEMENTSTATISTICSIMPL_H
#define SETTLEMENTSTATISTICSIMPL_H

#include "SettlementStatistics.h"
#include <map>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>

class SettlementStatisticsImpl : public SettlementStatistics {

private:
    std::multimap<std::string, Settlement> settlements;

public:
    explicit SettlementStatisticsImpl(const std::string& filename);

    int numSettlements() const override;
    int numCounties() const override;
    int numSettlementsByCounty(const std::string& county) const override;
    std::vector<Settlement> findSettlementsByCounty(const std::string& county) const override;
    Settlement findSettlementsByNameAndCounty(const std::string& name, const std::string& county) const override;
    Settlement maxPopulation() const override;
    Settlement minPopulation() const override;
    std::vector<Settlement> findSettlementsByName(const std::string& name) override;
};

#endif // SETTLEMENTSTATISTICSIMPL_H
