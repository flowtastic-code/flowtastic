#pragma once
// GPL v3 License
// Copyright 2023--present Flowy developers

#include "xtensor-blas/xlinalg.hpp"
#include "xtensor/xbuilder.hpp"
#include "xtensor/xmanipulation.hpp"
#include "xtensor/xmath.hpp"
#include "xtensor/xtensor_forward.hpp"
#include <xtensor/xcsv.hpp>
#include <xtensor/xfixed.hpp>
#include <xtensor/xtensor.hpp>
#include <xtensor/xview.hpp>

namespace Flowy
{

using Vector2 = xt::xtensor_fixed<double, xt::xshape<2>>;
using Vector3 = xt::xtensor_fixed<double, xt::xshape<3>>;
using MatrixX = xt::xtensor<double, 2>;
using VectorX = xt::xtensor<double, 1>;

enum StorageDataType
{
    Short,
    Float,
    Double
};

} // namespace Flowy
