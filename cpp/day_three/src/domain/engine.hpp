#pragma once
#include "./rucksack.hpp"
#include <optional>

namespace Domain {
using Priority = int;
using namespace Domain;

Priority prioritizeSack(Rucksack);
} // namespace Domain
