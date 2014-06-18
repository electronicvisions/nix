// Copyright (c) 2013, German Neuroinformatics Node (G-Node)
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted under the terms of the BSD License. See
// LICENSE file in the root of the Project.

#ifndef NIX_SELECTION_H
#define NIX_SELECTION_H

#include <nix/NDSize.hpp>
#include <nix/Hydra.hpp>
#include <nix/hdf5/hdf5include.hpp>
#include <nix/hdf5/DataSpace.hpp>

#include <nix/Platform.hpp>

namespace nix {
namespace hdf5 {


class NIXAPI Selection {

public:

    enum class Preset {
        None = 0,
        All  = 1
    };

    enum class Mode {
        Set  = H5S_SELECT_SET,
        Or   = H5S_SELECT_OR,
        And  = H5S_SELECT_AND,
        Xor  = H5S_SELECT_XOR,
        NotA = H5S_SELECT_NOTA,
        NotB = H5S_SELECT_NOTB
    };

    Selection() {}
    Selection(const H5::DataSpace &ds) : space(ds) {}
    Selection(const Selection &sel) : space(sel.space) {}
    template<typename T> Selection (const T &value);

    Selection& operator=(const Selection &other) { space = other.space; return *this; }

    void select(const NDSize &count, const NDSize &start, Mode mode = Mode::Set);
    void select(Preset set);
    void offset(const NDSSize &offset);

    H5::DataSpace& h5space() { return space; }
    const H5::DataSpace& h5space() const { return space; }
    bool isValid() const { return space.selectValid(); }
    void bounds(NDSize &start, NDSize &end) const { space.getSelectBounds(start.data(), end.data()); }
    NDSize size() const;
    size_t rank() const {return static_cast<size_t>(space.getSimpleExtentNdims()); }

private:
    H5::DataSpace space;
};

template<typename T>
Selection::Selection (const T &value)
{
    const Hydra<const T> hydra(value);
    NDSize size = hydra.shape();
    space = DataSpace::create(size, true);
}


} // namespace hdf5
} // namespace nix

#endif //NIX_SELECTION_H
