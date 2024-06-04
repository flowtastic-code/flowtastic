#pragma once
// GPL v3 License
// Copyright 2023--present Flowy developers
#include "flowy/include/asc_file.hpp"
#include "flowy/include/config.hpp"
#include "flowy/include/definitions.hpp"
#include "flowy/include/lobe.hpp"
#include "flowy/include/topography.hpp"
#include "flowy/include/topography_file.hpp"
#include <filesystem>
#include <memory>
#include <random>
#include <vector>

namespace Flowy
{
class MrLavaLoba;

class Simulation
{
public:
    friend class MrLavaLoba;
    Simulation( const Config::InputParams & input, std::optional<int> rng_seed );

    Config::InputParams input;

    Topography topography_initial;   // Stores the initial topography, before any simulations are run
    Topography topography_thickness; // Stores the height_difference between initial and final topography
    Topography topography;           // The topography, which is modified during the simulation
    std::vector<Lobe> lobes;         // Lobes per flows

    static Topography construct_initial_topography( const Config::InputParams & input );

    void compute_cumulative_descendents( std::vector<Lobe> & lobes ) const;

    void write_lobe_data_to_file( const std::vector<Lobe> & lobes, const std::filesystem::path & output_path );

    bool stop_condition( const Vector2 & point, double radius ) const;

    void write_avg_thickness_file();

    std::unique_ptr<TopographyFile>
    get_file_handle( const Topography & topography, OutputQuantitiy output_quantity ) const;

    void run();

private:
    int rng_seed;
    std::mt19937 gen{};
};

} // namespace Flowy
