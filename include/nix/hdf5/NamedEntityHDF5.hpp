// Copyright (c) 2013, German Neuroinformatics Node (G-Node)
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted under the terms of the BSD License. See
// LICENSE file in the root of the Project.

#ifndef NIX_NAMED_ENTITY_HDF5_H
#define NIX_NAMED_ENTITY_HDF5_H

#include <string>
#include <iostream>

#include <nix.hpp>
#include <nix/hdf5/EntityHDF5.hpp>

namespace nix {
namespace hdf5 {



/**
 * Base class for all NIX entities e.g. Block, Section etc.
 */
class NamedEntityHDF5 : virtual public base::INamedEntity, public EntityHDF5 {

public:

    /**
     * Standard constructor
     */
    NamedEntityHDF5(File file, Group group, const std::string &id, const std::string &_type, const std::string &_name);

    /**
     * Standard constructor that preserves the creation time.
     */
    NamedEntityHDF5(File file, Group group, const std::string &id, const std::string &_type, const std::string &_name, time_t time);


    void type(const std::string &type);


    std::string type() const;


    void name(const std::string &name);


    std::string name() const;


    boost::optional<std::string> definition() const;


    void definition(const std::string &definition);


    void definition(const none_t t);


    int compare(const INamedEntity &other) const;


    ~NamedEntityHDF5();

};


} // namespace hdf5
} // namespace nix

#endif // NIX_NAMED_ENTITY_HDF5_H
